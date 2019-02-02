#!/bin/sh
make
valgrind --leak-check=full ./push_swap 1 2 3
sleep 2
valgrind --leak-check=full ./push_swap 3 2 1
sleep 2
valgrind --leak-check=full ./push_swap
sleep 2
valgrind --leak-check=full ./push_swap 2 a
sleep 2
valgrind --leak-check=full ./push_swap 2 2
sleep 2
valgrind --leak-check=full ./checker 1 2 3
sleep 2
valgrind --leak-check=full ./checker 3 2 1
sleep 2
valgrind --leak-check=full ./checker
sleep 2
valgrind --leak-check=full ./checker 2 a
sleep 2
valgrind --leak-check=full ./checker 2 2
sleep 2