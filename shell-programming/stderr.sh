#!/bin/bash 
do_something() { 
if [ ! -f "important_file.txt" ]; then 
echo "Error: important_file.txt not found!" >&2 
return 1 # non-zero indicates failure 
fi 
} 
echo "File exists!" 
do_something 
# Check if an error occurred 
if [ $? -ne 0 ]; then 
echo "Script encountered an error" >&2 
exit 1 # exit with non-zero status 
fi
