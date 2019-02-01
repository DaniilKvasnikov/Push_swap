#!/bin/sh
ARG="3 2 one 0"; printf "\
sa\n\
rra\n\
pb\
" | ./checker $1 $ARG;

echo ""

ARG="3 2 2"; printf "\
sa\n\
rra\n\
pb\
" | ./checker $1 $ARG;

echo ""

ARG="3 2 21474836470"; printf "\
sa\n\
rra\n\
pb\
" | ./checker $1 $ARG;

echo ""

ARG=; printf "\
sa\n\
rra\n\
pb\
" | ./checker $1 $ARG;

echo ""

ARG="3 2 1"; printf "\
sa\n\
ee\n\
pb\
" | ./checker $1 $ARG;

echo ""

ARG="3 2 1"; ./checker -v $ARG;