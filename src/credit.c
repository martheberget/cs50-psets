// https://cs50.harvard.edu/x/2024/psets/1/credit/

#include <cs50.h>
#include <stdio.h>
#include <math.h>

long num_length(long number);
long checksum(long number);
long digits = 0;

int main(void)
{
    long number;
    bool isValid = false;
    number = 4003600000000014;
    digits = num_length(number);

    printf("%li\n", checksum(number));
    /*do
    {
        number = get_long("Number: ");
        //int digits = num_length(number);
        checksum(number);
        //if (digits == 13 || digits == 16 || digits == 15)
        isValid = true;
    }
    while(isValid == false);
    */

}

long num_length(long number)
{
    long count = 0;
    while (number != 0)
    {
        number = number / 10;
        count++;
    }
    return count;
}

long checksum(long number)
{
    long sum1 = 0;
    long sum2 = 0;

    for (long i = 1; i <= digits; i++)
    {
        long n = (remainderl(number, pow(10, i)) / pow(10, i-1));
        n *= 2;
        printf("%li\n", n);
        if (i % 2 == 0)
        {
            sum2 += n;
        } else
        {
            sum1 += n;
        }
    }
    return sum1;
}