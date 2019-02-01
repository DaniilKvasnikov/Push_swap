#!/bin/sh
ARG="2 1 3 6 5 8"; ./push_swap $ARG

echo ""

ARG="0 one 2 3"; ./push_swap $ARG

echo ""

ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

echo ""

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $1 $ARG
