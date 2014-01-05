awk -F\, '{printf "insert into patch_list \(\) values\(%d,\"%s\",\"Expansion A\",\"tbd\"\);\n",$1, $2}' ./JV1080-Orch_Patch_load.csv |mysql -u music JV1080

awk -F\, '{printf "insert into patch_list \(\) values\(%d,\"%s\",\"Expansion B\",\"%s\"\);\n",$1, $2, $3}' ./JV1080-Orch2_Patch_load.csv |mysql -u music JV1080

awk -F\, '{printf "insert into patch_list \(\) values\(%d,\"%s\",\"Expansion C\",\"%s\"\);\n",$1, $2, $3}' ./JV1080-Sampler-Patch_load.csv |mysql -u music JV1080

awk -F\, '{printf "insert into wave_list \(\) values\(%d,\"%s\",\"Expansion A\",\"tbd\"\);\n",$1, $2}' ./JV1080-Orch_Wave_load.csv |mysql -u music JV1080

awk -F\, '{printf "insert into wave_list \(\) values\(%d,\"%s\",\"Expansion B\",\"tbd\"\);\n",$1, $2}' ./JV1080-Orch2_Wave_load.csv |mysql -u music JV1080

awk -F\, '{printf "insert into wave_list \(\) values\(%d,\"%s\",\"Expansion C\",\"tbd\"\);\n",$1, $2}' ./JV1080-Sampler-Wave_load.csv |mysql -u music JV1080

awk -F\, '{printf "insert into patch_list \(\) values\(%d,\"%s\",\"%s\",\"tbd\"\);\n",$1, $2, $3}' ./JV1080_Patch_list.csv |mysql -u music JV1080

awk -F\, '{printf "insert into wave_list \(\) values\(%d,\"%s\",\"%s\",\"tbd\"\);\n",$3, $1, $2}' ./JV1080_internal_waves.csv |mysql -u music JV1080

