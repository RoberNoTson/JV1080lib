#!/bin/sh
# load patch_list table with updated tone data
# NOTE: the JV must be enabled to allow Bank and Program Change messages

declare -a Result;
declare -a SeqNum;
declare -a group_area;
declare -a group_spec;
declare -a wave_num;
declare -a sysex;

# assign correct Group/Number values
function parseData {
    if [ ${sysex[10]} = "00" -a ${sysex[11]} = "01" ]; then wave_group="Internal A"; fi;
    if [ ${sysex[10]} = "00" -a ${sysex[11]} = "02" ]; then wave_group="Internal B"; fi;
    if [ ${sysex[10]} = "02" -a ${sysex[11]} = "02" ]; then wave_group="Expansion A"; fi;
    if [ ${sysex[10]} = "02" -a ${sysex[11]} = "10" ]; then wave_group="Expansion B"; fi;
    if [ ${sysex[10]} = "02" -a ${sysex[11]} = "62" ]; then wave_group="Expansion C"; fi;
    let wave_num=0x${sysex[12]}*16;
    let wave_num=wave_num+0x${sysex[13]}+1;
}

# switch into patch mode
P=`amidi -l |grep Turtle |gawk '{printf "%s",$2}'`
if [ $P ]; then
  amidi -p $P -S "F0 41 10 6A 12 00 00 00 00 01 7F F7";
else
  exit;		# OOPS! No connection to JV
fi
# Query loop through patch_list database by SeqNum
Result=(`mysql -s -u music -e "select SeqNum, p.group_area, p.number from patch_list p order by SeqNum" JV1080`)
let count=`echo ${#Result[@]}`;
let looper=0;
let y=0;
while (( $looper < $count )); do
  SeqNum[y]=${Result[$looper]};
  group_area[y]=${Result[$looper+1]};
  group_spec[y]=${Result[$looper+2]};
  wave_num[y]=${Result[$looper+3]};
  let looper=looper+4;
  let y=y+1;
done

# start of big WHILE loop
let count=count/4;
let looper=0;
while (( $looper < $count )); do
  # figure the parms to set the JV to the desired Patch
  if [ ${group_area[looper]} = "Preset" ]; then
    MSB="51";
    let y=${wave_num[looper]};
    let y=y-1;
    PC=`printf "%X" $y`;
    if [ ${group_spec[looper]} = "A" ]; then LSB="00"; fi;
    if [ ${group_spec[looper]} = "B" ]; then LSB="01"; fi;
    if [ ${group_spec[looper]} = "C" ]; then LSB="02"; fi;
    if [ ${group_spec[looper]} = "D" ]; then LSB="03"; fi;
  fi

  if [ ${group_area[looper]} = "Expansion" ]; then
    MSB="54";
    let y=${wave_num[looper]};
    if (( $y > 128 )); then let y=y-128; fi
    let y=y-1;   
    PC=`printf "%X" $y`;
    let y=${wave_num[looper]};
    if [ ${group_spec[looper]} = "A" ]; then
      if (( $y < 129 )); then
	LSB="00";
      else
	LSB="01";
      fi
    fi
    if [ ${group_spec[looper]} = "B" ]; then
      if (( $y < 129 )); then
	LSB="02";
      else
	LSB="03";
      fi
    fi
    if [ ${group_spec[looper]} = "C" ]; then
      if (( $y < 129 )); then
	LSB="04";
      else
	LSB="05";
      fi
    fi
    if [ ${group_spec[looper]} = "D" ]; then
      if (( $y < 129 )); then
	LSB="06";
      else
	LSB="07";
      fi
    fi
  fi
# select the requested patch number
  amidi -p $P -S "B0 00 $MSB B0 20 $LSB C0 $PC"
  sleep 1
# get the Tone data, update the database
  # Tone 1
  sysex=(`amidi -p $P -S "F0 41 10 6A 11 03 00 10 00 00 00 00 05 68 F7"; amidi -p $P -d -t 1`);
  if [ ${sysex[9]} = "01" ]; then
    parseData;
    echo "update patch_list set tone_1_ref = (select distinct(SeqNum) from wave_list where group_area = \"$wave_group\" and number = $wave_num limit 1) where SeqNum = ${SeqNum[$looper]}"
    mysql -s -u music -e "update patch_list set tone_1_ref = (\
    select distinct(SeqNum) from wave_list where group_area = \"$wave_group\" \
    and number = $wave_num limit 1) where SeqNum = ${SeqNum[$looper]}" JV1080;
  else
    echo set tone_1_ref to NULL;
    mysql -s -u music -e "update patch_list set tone_1_ref = null where SeqNum = ${SeqNum[$looper]}" JV1080;
  fi
  # Tone 2
  sysex=(`amidi -p $P -S "F0 41 10 6A 11 03 00 12 00 00 00 00 05 66 F7"; amidi -p $P -d -t 1`);
  if [ ${sysex[9]} = "01" ]; then
    parseData;
    echo "update patch_list set tone_2_ref = (select distinct(SeqNum) from wave_list where group_area = \"$wave_group\" and number = $wave_num limit 1) where SeqNum = ${SeqNum[$looper]}"
    mysql -s -u music -e "update patch_list set tone_2_ref = (\
    select distinct(SeqNum) from wave_list where group_area = \"$wave_group\" \
    and number = $wave_num limit 1) where SeqNum = ${SeqNum[$looper]}" JV1080;
  else
    echo set tone_2_ref to NULL;
    mysql -s -u music -e "update patch_list set tone_2_ref = null where SeqNum = ${SeqNum[$looper]}" JV1080;
  fi
  # Tone 3
  sysex=(`amidi -p $P -S "F0 41 10 6A 11 03 00 14 00 00 00 00 05 64 F7"; amidi -p $P -d -t 1`);
  if [ ${sysex[9]} = "01" ]; then
    parseData;
    echo "update patch_list set tone_3_ref = (select distinct(SeqNum) from wave_list where group_area = \"$wave_group\" and number = $wave_num limit 1) where SeqNum = ${SeqNum[$looper]}"
    mysql -s -u music -e "update patch_list set tone_3_ref = (\
    select distinct(SeqNum) from wave_list where group_area = \"$wave_group\" \
    and number = $wave_num limit 1) where SeqNum = ${SeqNum[$looper]}" JV1080;
  else
    echo set tone_3_ref to NULL;
    mysql -s -u music -e "update patch_list set tone_3_ref = null where SeqNum = ${SeqNum[$looper]}" JV1080;
  fi
  # Tone 4
  sysex=(`amidi -p $P -S "F0 41 10 6A 11 03 00 16 00 00 00 00 05 62 F7"; amidi -p $P -d -t 1`);
  if [ ${sysex[9]} = "01" ]; then
    parseData;
    echo "update patch_list set tone_4_ref = (select distinct(SeqNum) from wave_list where group_area = \"$wave_group\" and number = $wave_num limit 1) where SeqNum = ${SeqNum[$looper]}"
    mysql -s -u music -e "update patch_list set tone_4_ref = (\
    select distinct(SeqNum) from wave_list where group_area = \"$wave_group\" \
    and number = $wave_num limit 1) where SeqNum = ${SeqNum[$looper]}" JV1080;
  else
    echo set tone_4_ref to NULL;
    mysql -s -u music -e "update patch_list set tone_4_ref = null where SeqNum = ${SeqNum[$looper]}" JV1080;
  fi
  let looper=looper+1;
  sleep 1
done	# end of the big WHILE loop
