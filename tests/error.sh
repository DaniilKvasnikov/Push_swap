#!/bin/sh
ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
./push_swap $ARG
./push_swap $ARG | ./checker $2 $ARG
./push_swap $ARG | wc -l