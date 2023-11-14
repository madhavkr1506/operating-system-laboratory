read string
input="$string"
output=$(echo "$input" | rev)
if [ "$input" == "$output" ]; then
	echo $input is a palindrome number
else
	echo $input is not a palindrome number
fi

