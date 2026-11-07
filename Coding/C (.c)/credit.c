#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool checksum(string number, int length);

int main(void)
{
    string number = get_string("Enter a credit card number: ");
    int length = strlen(number);
    int first = number[0];
    int second = number[1];

    if (checksum(number, length))
    {
        // length of a AMEX card, ascii decimal values for comparement numbers (34 & 37);
        if (length == 15 && ((first == 51 && second == 52) || (first == 51 && second == 55)))
        {
            printf("AMEX\n");
        }
        // length of a Mastercard, ascii decimal values for comparement numbers (51, 52, 53, 54 & 55);
        else if (length == 16 && ((first == 53 && second == 49) || (first == 53 && second == 50) || (first == 53 && second == 51) || (first == 53 && second == 52) || (first == 53 && second == 53)))
        {
            printf("MASTERCARD\n");
        }
        // length of a Visa card, ascii decimal values for comparement numbers (4);
        else if ((length == 13 || length == 16) && (first == 52))
        {
            printf("VISA\n");
        }
        // length of a AMEX card, ascii decimal values for comparement numbers (34, 37);
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
         printf("INVALID\n");
    }
}


bool checksum(string number, int length)
{
    int totalSum = 0;
    bool multiply = false;
    int digit;

    // count down, reading from end
    for (int i = length - 1; i >= 0; i--)
    {
        //convert string number to real number;
        digit = number[i] - '0';

        if (multiply)
        {
            //Focused Multiply, do the mutlplication process
            int focusMul = digit * 2;

            totalSum += (focusMul / 10) + (focusMul % 10);
        }
        else
        {
            totalSum += digit;
        }

        multiply = !multiply;
    }
    return (totalSum % 10 == 0);
}
