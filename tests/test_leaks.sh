#!/bin/sh
make
valgrind ./push_swap 1 2 3
sleep 2
valgrind ./push_swap 10 9 8 7 6 5 4 3 2 1 0
sleep 2
valgrind ./push_swap 3 2 1
sleep 2
valgrind ./push_swap
sleep 2
valgrind ./push_swap 2 a
sleep 2
valgrind ./push_swap 2 2
sleep 2
valgrind ./checker 1 2 3
sleep 2
valgrind ./checker 3 2 1
sleep 2
valgrind ./checker
sleep 2
valgrind ./checker 2 a
sleep 2
valgrind ./checker 2 2
sleep 2