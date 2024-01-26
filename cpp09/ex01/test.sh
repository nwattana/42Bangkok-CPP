#!/bin/bash

./RPN "0" | grep "0" > /dev/null && echo "case 1 OK" || echo "case 1 KO"
./RPN | grep "Usage" > /dev/null && echo "case 2 OK" || echo "case 2 KO"
./RPN "(1 + 1)" | grep "ERROR" > /dev/null && echo "case 3 OK" || echo "case 3 KO"
./RPN "+" | grep "ERROR" > /dev/null && echo "case 4 OK" || echo "case 4 KO"
./RPN "" "" | grep "Usage" > /dev/null && echo "case 5 OK" || echo "case 5 KO"
./RPN "1 2 3" "4 5 6" | grep "Usage" > /dev/null && echo "case 6 OK" || echo "case 6 KO"
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" | grep "42" > /dev/null && echo "case 7 OK" || echo "case 7 KO"
./RPN "7 7 * 7 -" | grep "42" > /dev/null && echo "case 8 OK" || echo "case 8 KO"
./RPN "1 2 * 2 / 2 * 2 4 - +" | grep "0" > /dev/null && echo "case 9 OK" || echo "case 9 KO"