#!/bin/bash
rm output.csv
(paste -d "," $1 <(cut -d',' -f2 $2)) >> output.csv;

paste -d '\n' <(sort -k1 <(cut -d',' -f1 $1)) <(sort -k1 <(cut -d',' -f1 $2))


