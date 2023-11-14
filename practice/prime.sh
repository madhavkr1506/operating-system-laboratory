read num1 num2
for((i = num1; i<=num2; i++)) do
	prime=true
	for((j = 2; j<=i/2; j++)) do
		if [ $((i%j)) -eq 0 ]; then
			prime=false
			break
		fi
	done
	if [ "$prime" = true ]; then
		echo $i
	fi
done

