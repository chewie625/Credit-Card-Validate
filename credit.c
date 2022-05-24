#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>


//function prototype
long give_digit(long input);
bool legit (long card_no);
string begins_with(string cc, int x);

int main(void)
{
    string cc_string = get_string("Input: ");
    //printf("String Lenght %li\n", strlen(cc_string));
    //printf("CC begins with %s\n", begins_with(cc_string, 1));
    //printf("First 2 digit is %c%c\n", cc_string[0], cc_string[1]);
    if ( strlen(cc_string) == 15 && legit(atol(cc_string)) && strcmp(begins_with(cc_string, 2), "37") == 0)
    {
        printf("AMEX\n");
    }
   else if ( strlen(cc_string) == 16 && legit(atol(cc_string)) && strcmp(begins_with(cc_string, 1), "5") == 0)
    {
        printf("MASTERCARD\n");
    }
    else if ( strlen(cc_string) >= 13 && legit(atol(cc_string)) && strcmp(begins_with(cc_string, 1), "4") == 0)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}


bool legit (long card_no)
{

    //long cc = get_long("Number: ");
    int i = 1;
    long sum1 = 0;
    long sum2 = 0;
    while (card_no > 0 && i >= 1)
    {
        if (i % 2 == 0 && give_digit (card_no) * 2 >= 10)
        {
            sum1 += give_digit(give_digit (card_no) * 2) + 1;
            card_no/=10;
            i++;
        }
        else if (i % 2 == 0)
        {
            sum1 += give_digit(card_no) * 2;
            card_no/=10;
            i++;
        }
        else
        {
            sum2 += give_digit(card_no);
            card_no/=10;
            i++;
        }
    }
    int Total = sum1 + sum2;
    if ( give_digit(Total) == 0 )
    {
        return true;
    }
    return false;

}


//function that returns a single digit from the input
long give_digit(long input)
{
    long n = input % 10;
    return n;
}

//begins_with returns first 1 or 2 digit of the credit card no.
string begins_with(string cc, int x)
{
    if (x == 1)
    {
        char c[2] = {cc[0],'\0'};
        string y = c;
        return y;
    }
    else if (x == 2)
    {
        char c[3] = {cc[0], cc[1], '\0'};
        string y = c;
        return y;
    }
    else
    {
        return 0;
    }
}