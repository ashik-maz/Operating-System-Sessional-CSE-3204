#! /bin/bash
file="userdata.txt"

read -p "Enter Username: " username
read -s -p "Enter PAssword: " password

if [ ! -f "$file" ]; then
	echo "userdata.txt not exist!"
	exit 1
fi

while read user pass 
do
	if [ "$user" = "$username" ] && [ "$pass" = "$password" ]; then
		echo 
		echo "Welcome $user"
		exit 0
	fi
done < "$file"

echo "Invalid username or pass"
