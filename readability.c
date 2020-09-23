// Grade Calculator for a text

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string s  = get_string("Text: ");
    int n = strlen(s);
    int words = 1, sentence = 0, letters = 0;

    //repeat for the total ammount of characters in the string
    for (int i = 0; i < n; i++)
    {
        //calculate the ammount of words
        if (((s[i]) == ' ') || (((s[i]) == ' ') && ((s[i + 1]) == ' ')))
        {
            words++;
        }
        //calculate the number of sentences
        else if (((s[i]) == '.') || ((s[i]) == '!') || ((s[i]) == '?'))
        {
            sentence++;
        }
        //calculare the number of letters
        else if ((tolower(s[i]) >= 'a') && (tolower(s[i]) <= 'z'))
        {
            letters++;
        }
    }

    //calculate index
    //index = 0.0588 * L - 0.296 * S - 15.8
    double index = (0.0588 * ((double)letters * 100 / words)) - (0.296 * ((double)sentence * 100 / words)) - 15.8 ;

    if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)(round(index)));
    }
}