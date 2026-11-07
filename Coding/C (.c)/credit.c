#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool validation(string number);

int main(void)
{
    string number;
    int length;

    while (true)
    {
        number = get_string("Number: ");
        length = strlen(number);

        bool all_digits = true;
        for (int i = 0; i < length; i++)
        {
            if (!isdigit(number[i]))
            {
                all_digits = false;
            }
        }
        if (all_digits)
        {
            break;
        }
    }

    if (!validation(number))
    {
        printf("INVALID\n");
        return 0;
    }

    if (length == 15 && number[0] == '3' && (number[1] == '4' || number[1] == '7'))
    {
        printf("AMEX\n");
    }

    else if (length == 16 && number[0] == '5' && (number[1] >= '1' && number[1] <= '5'))
    {
        printf("MASTERCARD\n");
    }

    else if ((length == 13 || length == 16) && number[0] == '4')
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }

    return 0;
}

bool validation(string number)
{
    int length = strlen(number);
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        int digit = number[length - 1 - i] - '0';

        if (i % 2 == 1)
        {
            int product = digit * 2;
            sum += (product / 10) + (product % 10);
        }
        else
        {
            sum += digit;
        }
    }

    return (sum % 10 == 0);
}
