// https://cs50.harvard.edu/x/2024/psets/2/readability/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get text from user
    string text = get_string("Text: ");

    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);

    // Calculate the Coleman-Liau index
    double L = (double) letter_count / word_count * 100;
    double S = (double) sentence_count / word_count * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Return based on index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Returns the number of letters in the text
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (islower(text[i]) || isupper(text[i]))
        {
            count++;
        }
    }
    return count;
}

// Returns the number of words in the text
int count_words(string text)
{

    int i = 0;
    int word = 1;
    while (text[i] != '\0')
    {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t')
        {
            word++;
        }
        i++;
    }
    return word;
}

// Returns the number of sentences
int count_sentences(string text)
{
    int i = 0;
    int sentences = 0;
    while (text[i] != '\0')
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
        i++;
    }
    return sentences;
}

