forky: forky.c
	gcc -o forky pattern1.c pattern2.c pattern3.c forky.c

results: forky
	(echo "Pattern 1:"; ./forky 1 7; \
	echo "Pattern 2:"; ./forky 2 6; \
	echo "Pattern 3:"; ./forky 3 4) \
		> results.txt

clean:
	rm -f forky