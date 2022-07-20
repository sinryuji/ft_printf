#!/bin/bash

current_state=$(<current_state.txt)

if [ $current_state == "m1" ]
then
	change_state="intel"
	mv ft_printf.c other_version/ft_printf_m1.c
	mv ft_printf.h other_version/ft_printf_m1.h
	mv ft_printf_num.c other_version/ft_printf_num_m1.c
	mv ft_printf_string.c other_version/ft_printf_string_m1.c
	mv other_version/ft_printf_intel.c ft_printf.c
	mv other_version/ft_printf_intel.h ft_printf.h
	mv other_version/ft_printf_num_intel.c ft_printf_num.c
	mv other_version/ft_printf_string_intel.c ft_printf_string.c
	printf "state change $current_state -> $change_state\n"
	rm current_state.txt
	echo $change_state > current_state.txt
fi
if [ $current_state == "intel" ]
then
	change_state="m1"
	mv ft_printf.c other_version/ft_printf_intel.c
	mv ft_printf.h other_version/ft_printf_intel.h
	mv ft_printf_num.c other_version/ft_printf_num_intel.c
	mv ft_printf_string.c other_version/ft_printf_string_intel.c
	mv other_version/ft_printf_m1.c ft_printf.c
	mv other_version/ft_printf_m1.h ft_printf.h
	mv other_version/ft_printf_num_m1.c ft_printf_num.c
	mv other_version/ft_printf_string_m1.c ft_printf_string.c
	printf "state change $current_state -> $change_state\n"
	rm current_state.txt
	echo $change_state > current_state.txt
fi

printf "current_state : ${change_state}\n"
