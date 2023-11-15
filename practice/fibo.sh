read num
a=0
b=1
if [ $num -eq 1 ]; then
	echo $a
fi
if [ $num -eq 2 ]; then
	echo $b
fi
echo $a
echo $b
for((i=3; i<=num; i++)); do
	c=$(($a + $b))
	echo $c
	a=$b
	b=$c
done
