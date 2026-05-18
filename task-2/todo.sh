#!/bin/bash

file="todo.txt"

# Add task
if [ "$1" = "add" ]; then
    echo "[] $2" >> "$file"
fi

# List tasks
if [ "$1" = "list" ]; then
    n=1
    while read line
    do
        echo "$n. $line"
        n=$((n+1))
    done < "$file"
fi

# Mark task as done
if [ "$1" = "done" ]; then
    sed -i "${2}s/\[\]/[x]/" "$file"
fi

# Clear tasks
if [ "$1" = "clear" ]; then
    > "$file"
fi

# Search task
if [ "$1" = "search" ]; then
    grep -i "$2" "$file"
fi
