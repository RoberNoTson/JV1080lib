#!/bin/sh
# global change

for n in `find . -name "*.cpp"`; do `sed -i.BAK s/"updates_enabled"/"state_table->updates_enabled"/g $n`; done
