#!/bin/sh
# load perf_list table with Perfs and patches

declare -a sysex;
declare -a Result;
#declare -n SeqNum;
declare -a group_area;
declare -a patch_num;

# assign correct Group/Number values
function parseData {
    if [ ${sysex[0]} = "03" ]; then patch_group="Preset A"; fi;
    if [ ${sysex[0]} = "04" ]; then patch_group="Preset B"; fi;
    if [ ${sysex[0]} = "05" ]; then patch_group="Preset C"; fi;
    if [ ${sysex[0]} = "06" ]; then patch_group="Preset D"; fi;
    let patch_num=0x${sysex[1]}*16;
    let patch_num=patch_num+0x${sysex[2]}+1;
}

# switch into perf mode
P=`amidi -l |grep Turtle |gawk '{printf "%s",$2}'`
if [ $P ]; then
  amidi -p $P -S "F0 41 10 6A 12 00 00 00 00 00 00 F7";
else
  echo OOPS! No connection to JV
  exit;
fi

# process Preset A
let x=0;
while [[ $x -lt 32 ]]; do
  # select Preset A
  X=`printf "%X" $x`;
  amidi -p $P -S "BF 00 51 BF 20 00 CF $X"
  # get Perf name
  pn=`amidi -p $P -S "F0 41 10 6A 11 01 00 00 00 00 00 00 0C 73 F7"; amidi -p $P -t 1 -d |cut -d " " -f 10-21 | xxd -r -p`;
  let x=x+1;
  query="insert into performance_list values(DEFAULT, $x, \"${pn}\", \"Preset A\"";
  let y=0;
  while [[ $y -lt 16 ]]; do
    let Y=$y+16;
    Z=`printf "%X" $Y`;
    sysex=(`amidi -p $P -S "F0 41 10 6A 11 01 00 $Z 03 00 00 00 03 7F F7"; amidi -p $P -t 1 -d|cut -d " " -f 10-12`);
    parseData;
    SeqNum=`mysql -s -s -u music -e "select SeqNum from patch_list where number = ${patch_num} and group_area = \"${patch_group}\"" JV1080`;
    if [[ -z $SeqNum ]]; then
      echo Error retrieving data for ${patch_group} ${patch_num}
      echo Abandoning update
      exit;
    fi;
    query="$query, $SeqNum";
    let y=y+1;
  done
   query="$query)";
  echo $query;
  echo $query |mysql -u music JV1080;
done

# process Preset B
let x=0;
while [[ $x -lt 32 ]]; do
  # select Preset B
  X=`printf "%X" $x`;
  amidi -p $P -S "BF 00 51 BF 20 01 CF $X"
  # get Perf name
  pn=`amidi -p $P -S "F0 41 10 6A 11 01 00 00 00 00 00 00 0C 73 F7"; amidi -p $P -t 1 -d |cut -d " " -f 10-21 | xxd -r -p`;
  let x=x+1;
  query="insert into performance_list values(DEFAULT, $x, \"${pn}\", \"Preset B\"";
  let y=0;
  while [[ $y -lt 16 ]]; do
    let Y=$y+16;
    Z=`printf "%X" $Y`;
    sysex=(`amidi -p $P -S "F0 41 10 6A 11 01 00 $Z 03 00 00 00 03 7F F7"; amidi -p $P -t 1 -d|cut -d " " -f 10-12`);
    parseData;
    SeqNum=`mysql -s -s -u music -e "select SeqNum from patch_list where number = ${patch_num} and group_area = \"${patch_group}\"" JV1080`;
    if [[ -z $SeqNum ]]; then
      echo Error retrieving data for ${patch_group} ${patch_num}
      echo Abandoning update
      exit;
    fi;
    query="$query, $SeqNum";
    let y=y+1;
  done
   query="$query)";
  echo $query;
  echo $query |mysql -u music JV1080;
done

