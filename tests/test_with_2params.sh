#!/bin/sh
ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
./push_swap $ARG
./push_swap $ARG | ./checker $3 $ARG
./push_swap $ARG | wc -l