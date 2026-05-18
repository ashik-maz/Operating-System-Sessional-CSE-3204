#! /bin/bash
read -p "Enter username:" username
read -s -p "Enter pass: " pass
echo

if grep -q  "^$username $pass$" userdata.txt; then
	echo "Welcome $username"
else 
	echo "Invalid username or password"
fi
