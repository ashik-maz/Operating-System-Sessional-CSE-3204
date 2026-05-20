#! /bin/bash

do_something() {
	if [ ! -f "im.txt" ];then
		echo "Error: im.txt not exixt!" >&2
		return 1
	fi
	echo "File exist"
}
do_something
# Check if an error occurred 
if [ $? -ne 0 ]; then 
echo "Script encountered an error" >&2 
exit 1 # exit with non-zero status 
fi 
