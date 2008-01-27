#!/bin/bash

INCLUDES='"geekcode.h"'

usage() {
	cat <<-EOF
	generate_object_file.sh [-h] file

	Generates object or header code from .pre files. Generates object code by
	default.

	-h		Generate header file instead of object code.
	EOF
}

e_usage() {
	{
		echo "Invalid command line."
		echo
		usage
	} >&2
	exit 1
}

file_header() {
	cat <<-EOF
	/*
	 * Generated file, do not edit.
	 */
	EOF

	for include in $@; do
		echo "#include $include"
	done

	echo
}


object_file() {
	file_header $INCLUDES

	sed -e 's/{ \(\w*\):/const struct stuff \1[] = {/' \
		-e 's/^}/\tSENTINEL\n};/' \
		-e 's/"}/"},/' $1
}

header_file() {
	local HEADER

	file_header $INCLUDES
	if [[ -n $1 ]]; then
		HEADER=$(echo ${1%%.*} | tr [:lower:] [:upper:])
		echo -e "#ifndef _${HEADER}_H\n#define _${HEADER}_H\n"
	fi

	sed -e 's/{ \(\w*\):/extern const struct stuff \1[];/' -e '/\t/d' -e '/}/d' $1
	if [[ -n HEADER ]]; then
		echo -e "\n#endif /* _${HEADER}_H */"
	fi
}

case $# in
	0)
		e_usage
		;;
	1)
		if [[ ${1:0:1} == "-" ]]; then
			e_usage
		fi
		object_file $1
		;;
	2)
		if [[ $1 == "-h" ]]; then
			header_file $2
		elif [[ $2 == "-h" ]]; then
			header_file $1
		else
			e_usage
		fi
		;;
	*)
		e_usage
		;;
esac
