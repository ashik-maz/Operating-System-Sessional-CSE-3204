#! /bin/bash
if [ $1 -gt 10 ]; then
	echo "Number is greater than 10"
elif [ $1 -eq 10 ]; then
	echo "Number is equal to 10"
else 
	echo "Less than 10"
fi
