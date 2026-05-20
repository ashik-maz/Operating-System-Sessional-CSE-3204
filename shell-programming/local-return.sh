#! /bin/bash
add() {
	local sum=$(($1 +$2))
	echo $sum
}
result=$(add 2 2)
echo "The sum is $result"
