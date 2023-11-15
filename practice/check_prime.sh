read num
prime=true
for((i=2; i<= num/2; i++)); do
	if [ $((num%i)) -eq 0 ]; then
		prime=false
		break
	fi
done
if [ $prime = true ]; then
	echo $num is a prime number
else
	echo $num is not a prime number
fi 
