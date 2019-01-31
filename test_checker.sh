#!/bin/sh
ARG="3 2 1 0"; printf "\
rra\n\
pb\n\
sa\n\
rra\n\
pa\
" | ./checker $1 $ARG;

echo ""

ARG="3 2 1 0"; printf "\
sa\n\
rra\n\
pb\
" | ./checker $1 $ARG;

echo ""

ARG="3 2 one 0"; printf "\
sa\n\
rra\n\
pb\
" | ./checker $1 $ARG;