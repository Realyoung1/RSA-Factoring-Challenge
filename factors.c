#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
/**
 * read_textfile- read and sent to stdout a number of charss.
 *
 *@filename: name of file
 *@letters: number of letters
 * Return: Number of printed chars.
 */
int main(int ac, char **av)
{
	int i, j, flag, fd, h;
	int leido = 0;
	long int number, number2, k;
	char *buf, *buf2;
	int letters = 100;

	leido = leido;
	ac = ac;
	number = 0;
	fd = open(av[1], O_RDONLY);
	buf = malloc(1000 * sizeof(char));
	buf2 = malloc(120 * sizeof(char));
	leido = read(fd, buf, letters);
 	i = 0;
	while (buf[i] != 0)
	{
		j = 0;
		for (h = 0; h <= 100; h++)
			buf2[h] = 0;
		while (buf[i] != 10)
			 {
				 buf2[j] = buf[i];
				 i++;
				 j++;
			 }
		number = atol(buf2);
		flag = 0;
		for (k = 2; k < number /2 && flag == 0; k++)
		{
			if (number % k == 0)
				flag = 1;
		}
		number2 = number / (k - 1);
		printf("%li=%li*%li\n", number, number2, k - 1);
		i++;
	}
	free(buf);
	free(buf2);
	close(fd);
	return(0);
}#!/usr/bin/env bash
# is a factors challenge

check_factor()
{
	if [ $# -ne 3 ];
        then
                args=("$@")
                count=0
                num2=1
                for a in ${args[*]};
                do
                        if [ $count -gt 1 ];
                        then
                                num2=$(echo $a*$num2 | bc)
                        fi
                        count=$((count + 1))
                done
        else
                num2=$3
        fi

        num1=$2
        num=$(echo "$1" | tr ':' '=')

        result=$(echo "if($num2 > $num1) 1 else 0" | bc)
	        if ((result == 1)); then
		        numcp=$num1
		        num1=$num2
		        num2=$numcp
                fi

        echo "$num$num1*$num2"
}

if [ $# -ne 1 ]
then
        echo 'Usage: factors <file>'
        exit 1
else

        while read i
        do

                result=$(factor "$i")
                check_factor $result

        done < "$1"
fi
