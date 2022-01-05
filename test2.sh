#!/bin/bash

for (( n = 1; n < 7; n++ )); do
	for (( s = 1; s < 4; s++ )); do
		for (( e = 1; e < 4; e++ )); do
			(( $s == $e )) && continue
			# ./towers -n $n -s $s -e $e > ./solutions/$n$s$e
			if ! cmp --quiet solutions/$n$s$e <(./towers -n $n -s $s -e $e) ;
			then
				echo -en "\033[33m(!!)\033[0m "
				echo "Something might be wrong on with these parameters:"
				echo "  disks = $n"
				echo "  start = $s"
				echo "  end   = $e"
				echo "Try running the following to see what's going on:"
				echo "vimdiff solutions/$n$s$e <(./towers -n $n -s $s -e $e)"
				exit 1
			fi
		done
	done
done
echo -e "\033[32mTest passed :D\033[0m"
