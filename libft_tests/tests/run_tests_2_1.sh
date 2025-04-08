#!/bin/bash

# Script for toupper and tolower

# Define color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# List of system function names
SYS_FUNCS=("atoi") 

for func in "${SYS_FUNCS[@]}"; do
	ft_exec="bin/ft_$func"
	sys_exec="bin/sys_$func"

	echo -e "\nTesting ft_$func: "
	
	for i in {1..10}; do
		rand_int=$(./bin/gen_rand_str 10)
		arg="$rand_int"
		output_sys=$($sys_exec "$arg")
		output_ft=$($ft_exec "$arg")
		input_display="\"$rand_int\""

		if [ "$output_sys" = "$output_ft" ]; then
			echo -e "${GREEN}[PASS]${NC} $input_display -> $output_ft (sys: $output_sys)"
		else
			echo -e "${RED}[FAIL]${NC} $input_display"
			echo -e " Expected: '$output_sys'"
			echo -e " Got: '$output_ft'"
		fi
	done
done
