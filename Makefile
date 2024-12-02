forky: forky.c pattern1.c pattern2.c pattern3.c
	gcc -o forky pattern1.c pattern2.c pattern3.c forky.c -lm

results:
	echo "Pattern 1 with n = 4:" > results.txt
	./forky 1 4 2>> results.txt

	echo "\nPattern 2 with n = 5:" >> results.txt
	./forky 2 5 2>> results.txt

	echo "\nPattern 3 with n = 4:" >> results.txt
	./forky 3 4 2>> results.txt

clean:
	rm -f forky