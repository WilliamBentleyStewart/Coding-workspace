#include <cs50.h>
#include <stdio.h>
#include <string.h>

int printRow(int row, int height);

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(!(height >= 1 && height <= 8));

    for(int i = 1; i <= height; i++)
    {
        printRow(i, height);
    }
}

int printRow(int row, int height)
{
    for (int k = 0; k < (height - row); k++)
    {
        printf(" ");
    }
    for(int j = 0; j < row; j++)
    {
        printf("#");
    }
    
    printf("\n");
    return 0;
}
