/*pseudo code
1-make program with comand line argument
2-check if the comand line argument is number (digits one by one char)
3-transform the comand line argument string in int
4-ask for a plain text
5-letter by letter, mantain upper or lower anda rotate
6-if its not letter, print the char
7-print the cipher text*/

#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//creating the key and the user message variables;
int key;
string userMsg;
string plaintext;

int main(int argc, string argv[])
{
    //validation of the number of the comand line arguments
    if (argc != 2)
    {
        printf("Error, please use: ./caesar key\n");
        return 1;
    }
    else
    {
        //validation of each char of the second comand line argument
        for (int i = 0; argv[1][i] != '\0'; i++)
        {
            if (isdigit(argv[1][i]) != 2048)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }

    //if there is only two comand line arguments and the second is a string, then transform to int
    key = atoi(argv[1]);

    //get the plain text from the user
    plaintext = get_string("Digit the plain text: ");
    printf("plaintext: %s\n", plaintext);
    userMsg = plaintext;

    //add the key to every char of the plaintext, wrapping around the alphabet if th letter is upper or lower case
    //returning (output) in the and the ciphertext
    for (int i = 0; userMsg[i] != '\0'; i++)
    {
        if ((isalpha(userMsg[i]) != 0) && (islower(userMsg[i]) != 0))
        {
            //test: printf("userMsg%i: %c\n", i, userMsg[i]);
            int letterInAscii = userMsg[i];
            //test: printf("letterInAscii%i: %i\n", i, letterInAscii);
            int newLetterInAscii = ((((letterInAscii - 97) + key) % 26) + 97);
            //test: printf("newLetterInAscii%i: %i\n", i, newLetterInAscii);
            userMsg[i] = newLetterInAscii;
            //test: printf("userMsg%i: %c\n", i, userMsg[i]);
        }
        else if ((isalpha(userMsg[i]) != 0) && (isupper(userMsg[i]) != 0))
        {
            //test: printf("userMsg%i: %c\n", i, userMsg[i]);
            int letterInAscii = userMsg[i];
            //test: printf("letterInAscii%i: %i\n", i, letterInAscii);
            int newLetterInAscii = ((((letterInAscii - 65) + key) % 26) + 65);
            //test: printf("newLetterInAscii%i: %i\n", i, newLetterInAscii);
            userMsg[i] = newLetterInAscii;
            //test: printf("userMsg%i: %c\n", i, userMsg[i]);
        }
    }
    printf("ciphertext: %s\n", userMsg);
    return 0;
};
