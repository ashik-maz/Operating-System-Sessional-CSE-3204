#!/bin/bash

FILE="userdata.txt"

# create file if not exists
touch "$FILE"

while true; do
    echo "====== MENU ======"
    echo "1. Sign Up"
    echo "2. Log In"
    echo "3. Delete User"
    echo "4. Exit"
    read -p "Choose option: " choice

    case $choice in

    1)
        read -p "Enter username: " username
        read -s -p "Enter password: " pass
        echo

        if grep -q "^$username " "$FILE"; then
            echo "User already exists ❌"
        else
            echo "$username $pass" >> "$FILE"
            echo "Signup successful ✅"
        fi
        ;;

    2)
        read -p "Enter username: " username
        read -s -p "Enter password: " pass
        echo

        if grep -q "^$username $pass$" "$FILE"; then
            echo "Welcome $username 🎉"
        else
            echo "Invalid username or password ❌"
        fi
        ;;

    3)
        read -p "Enter username to delete: " username

        if grep -q "^$username " "$FILE"; then
            sed -i "/^$username /d" "$FILE"
            echo "User deleted 🗑️"
        else
            echo "User not found ❌"
        fi
        ;;

    4)
        echo "Goodbye 👋"
        break
        ;;

    *)
        echo "Invalid option ⚠️"
        ;;

    esac

    echo
done
