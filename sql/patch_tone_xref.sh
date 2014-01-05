#!/bin/sh
#mysql -s -u music -e "select SeqNum, p.group_area, p.number, tone_1_ref, tone_2_ref, tone_3_ref, tone_4_ref from patch_list p where group_area = \"Preset D\"" JV1080
mysql -u music -e "select SeqNum, p.group_area, p.number, tone_1_ref, tone_2_ref, tone_3_ref, tone_4_ref from patch_list p" JV1080
