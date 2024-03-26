// https://cs50.harvard.edu/x/2024/psets/4/recover/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check that user enters only one argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");

    // Check if card could not be opened
    if (card == NULL)
    {
        printf("Cannot open file.");
        return 1;
    }

    BYTE buffer[512];
    int image_count = 0;
    FILE *output = NULL;
    char *filename = malloc(8 * sizeof(char));

    // Read the chunks of 512 bytes
    while (fread(buffer, sizeof(BYTE), 512, card))
    {
        // Look for JPEG signature in each 512 bytes
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            // Will close the previous jpg file
            if (image_count > 0)
            {
                fclose(output);
            }

            // Create file name
            sprintf(filename, "%03i.jpg", image_count);

            // Open output file
            output = fopen(filename, "w");

            image_count++;
        }

        // Write to output file
        if (output != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, output);
        }

    }

    // Free memory and close files
    free(filename);
    fclose(output);
    fclose(card);

    return 0;
}