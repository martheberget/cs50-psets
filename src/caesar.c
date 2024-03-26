// https://cs50.harvard.edu/x/2024/psets/2/caesar/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string text);
char rotate(char c, int key);

int main(int argc, string argv[])
{
    int key;

    // Check that command-line only contains a single argument
    if (argc == 2)
    {
        if (!(only_digits(argv[1])))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            // Convert argv[1] from a 'string' to an 'int'
            key = atoi(argv[1]);

            // Prompt user for plaintext
            string plaintext = get_string("plaintext: ");

            printf("ciphertext: ");

            for (int i = 0; i < strlen(plaintext); i++)
            {
                char c = rotate(plaintext[i], key);
                printf("%c", c);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}

bool only_digits(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (!(isdigit(text[i])))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int key)
{
    if (!(isalpha(c)))
    {
        return c;
    }
    else
    {
        if (isupper(c))
        {
            char new_c = ((c - 65 + key) % 26) + 65;
            return new_c;
        }
        else
        {
            char new_c = ((c - 97 + key) % 26) + 97;
            return new_c;
        }
    }
}