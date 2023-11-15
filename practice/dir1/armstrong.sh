read num
sum=0
total_digit=${#num}
real_no=$num
while [ $num -gt 0 ]; do
	digit=$((num % 10))
	sum=$((sum + digit ** total_digit))
	num=$((num / 10))
done
if [ $sum -eq $real_no ]; then
	echo $real_no is a armstrong number
else
	echo it is not a armstrong number
fi

