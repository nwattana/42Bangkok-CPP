#!/bin/bash

# RED='\033[0;31m'
# GREEN='\033[0;32m'
# CLEAR='\033[0m'

# if [ ! -f PmergeMe ]; then
# 	echo -e "${RED}Error: PmergeMe not found.${CLEAR}"
# 	echo "Please compile the program first."
# 	exit 1
# fi
# echo -e "${GREEN}Testing...${CLEAR}"
# maximum argument 120000
echo "========================================"
./PmergeMe `shuf -i 0-1000000 -n 5 | tr "\n" " "`
echo "========================================"
./PmergeMe `shuf -i 0-1000000 -n 3000 | tr "\n" " "`
echo "========================================"
./PmergeMe `shuf -i 0-1000000 -n 6000 | tr "\n" " "`
echo "========================================"
# ./PmergeMe `shuf -i 0-1000000 -n 128000 | tr "\n" " "`
# ./PmergeMe `shuf -i 0-1000000 -n 128000 | tr "\n" " "`

# if [ $? -ne 0 ]; then
# 	echo -e "${RED}Error: Program exited with non-zero status.${CLEAR}"
# 	exit 1
# fi

# if [ ! -f output.txt ]; then
# 	echo -e "${RED}Error: output.txt not found.${CLEAR}"
# 	exit 1
# elif [ ! -s output.txt ]; then
# 	echo -e "${RED}Error: output.txt is empty.${CLEAR}"
# 	exit 1
# else
# 	echo -e "${GREEN}Success!${CLEAR}"
# 	cat output.txt
# 	rm -f output.txt
# 	exit 0
# fi
