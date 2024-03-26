// https://cs50.harvard.edu/x/2024/psets/1/mario/more/

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    // Prompting the user for valid input
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);


    // For each row
    for (int i = 0; i < height; i++)
    {

        // Print spaces
        for (int k = height - i; k > 1; k--)
        {
            printf(" ");
        }

        // Print left hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Print gap
        for (int l = 0; l < 2; l++)
        {
            printf(" ");
        }

        // Print right hashes
        for (int m = 0; m <= i; m++)
        {
            printf("#");
        }

        printf("\n");
    }

}