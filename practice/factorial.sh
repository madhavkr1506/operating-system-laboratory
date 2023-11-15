read num
fac=1
while [ $num -gt 1 ]; do
	fac=$((fac * num))
	num=$((num - 1))
done
echo $fac
