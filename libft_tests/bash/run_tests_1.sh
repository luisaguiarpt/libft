#!/bin/bash

# Script for functions that only take an int as input

# Define color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# List of system function names
SYS_FUNCS=("toupper" "tolower" "isprint" "isascii" "isalnum" "isdigit" "isalpha") 

for func in "${SYS_FUNCS[@]}"; do
	ft_exec="bin/ft_$func"
	sys_exec="bin/sys_$func"

	echo -e "\nTesting ft_$func: "
	
	for i in {1..10}; do
		rand_int=$(./bin/gen_rand_str 1)
		arg="$rand_int"
		output_sys=$($sys_exec "$arg")
		echo "$output_sys\n"
		output_ft=$($ft_exec "$arg")
		echo "$output_ft\n"
		input_display="\"$rand_int\""

		# Convert numeric output to character for display
		char_sys=$(printf \\$(printf '%03o' $output_sys))
		char_ft=$(printf \\$(printf '%03o' $output_ft))

		if [ "$output_sys" = "$output_ft" ]; then
			echo -e "${GREEN}[PASS]${NC} $input_display -> $char_ft (sys: $char_sys)"
		else
			echo -e "${RED}[FAIL]${NC} $input_display"
			echo -e " Expected: '$char_sys' ($output_sys)"
			echo -e " Got: '$char_ft' ($output_ft)"
		fi
	done
done
