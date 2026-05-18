#!/bin/bash

FILE="todo.txt"

case "$1" in

add)
    echo "[ ] $2" >> "$FILE"
    echo "Task added!"
    ;;

list)
    if [ ! -f "$FILE" ]; then
        echo "No tasks found"
        exit 0
    fi

    nl -s'. ' "$FILE"
    ;;

done)
    if [ -z "$2" ]; then
        echo "Please provide task number."
        exit 1
    fi

    sed -i "${2}s/\[ \]/[x]/" "$FILE"
    echo "Task marked as done!"
    ;;

clear)
    > "$FILE"
    echo "Todo list cleared"
    ;;

search)
    if [ -z "$2" ]; then
        echo "Please provide a keyword."
        exit 1
    fi

    grep -i "$2" "$FILE"
    ;;

*)
    echo "Usage:"
    echo "./todo.sh add \"task\""
    echo "./todo.sh list"
    echo "./todo.sh done <task_number>"
    echo "./todo.sh clear"
    echo "./todo.sh search \"keyword\""
    ;;
esac
