//Crypt Word Substitution App

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//Declaring Functions
bool check_alpha(string s[]);
int substitute(string key[]);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (check_alpha(argv))
        {
            //If the condition is true, execute program
            substitute(argv);
        }
        else
        {
            printf("Key must contain 26 alpha characters.\n");
            return 1;
        }
    }
    else
    {
        printf("NEED KEY\n");
        return 1;
    }
}

//Substitution Function
int substitute(string key[])
{
    string plainText  = get_string("plaintext: ");

    // loop evaluating each imput digit lenght number of times
    for (int i = 0; i < strlen(plainText) ; i++)
    {
        if (isalpha(plainText[i]))
        {
            if (plainText[i] == toupper(plainText[i]))
            {
                //If number is Uppercase
                plainText[i] = toupper(key[1][(26 + (tolower((int)(plainText[i])) - 123))]);
            }
            else
            {
                //If number is lowercase
                plainText[i] = tolower(key[1][ 26 + (((int)(plainText[i])) - 123)]);
            }
        }
    }
    //Print final result and return 0
    printf("ciphertext: %s\n", plainText);
    return 0;
}


//Function for string that is alpha and equal to 26
bool check_alpha(string s[])
{
    int count = 0;

    for (int i = 0; i < 26 ; i++)
    {
        if (isalpha(tolower(s[1][i])))
        {
            //check if value is redundant
            for (int j = i + 1 ; j < 26 ; j++)
            {
                //comparing value of s[i] is  equal to s[j]
                if (tolower(s[1][i]) == tolower(s[1][j]))
                {
                    //Assign value to the digit so it deos not repeat itself
                    s[1][j] = '0';
                    return false;
                }
            }

            count++;
        }
    }
    // If the lenght is equal to the total number of alpha chars return true
    if (count == strlen(s[1]))
    {
        return true;
    }
    else
    {
        return false;
    }
}