#! /bin/bash
echo "Number 1 "
read a
echo "number 2"
read b
result=$(echo "$a + $b" | bc -l)
echo "sum: $result"
