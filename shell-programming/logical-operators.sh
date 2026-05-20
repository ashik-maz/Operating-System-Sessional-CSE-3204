#! /bin/bash

if [[ -f "$1" && -r "$1" ]]; then
	echo "File exist and readable"
fi
