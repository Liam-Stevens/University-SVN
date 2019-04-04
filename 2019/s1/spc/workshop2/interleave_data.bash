#!/bin/bash
rm output2.csv

(paste -d '\n' $1 $2) >> output2.csv

