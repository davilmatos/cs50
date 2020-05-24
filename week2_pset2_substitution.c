/*pseudo code
1-get the key OK
2-validade the key OK
    check length OK
    check for non alpha characters OK
    check for repeated characters (case insensitive) OK
3-get plaintext OK
4-encipher OK
    each alpha characters determines whats letter it maps to OK
    preserve case from the plaintext OK
    leave non-alpha characters as-is OK
5-print ciphertext OK
*/
#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//creating the variabels for the key, the original text e and the cipher text
string key;
string plaintext;
string userMsg;

int main(int argc, string argv[])
{
    //checking the number of comand line arguments
    if (argc != 2)
    {
        printf("Error, you must provide 2 arguments like this: ./substitution key\n");
        return 1;
    };

    //checking the length of the key
    int keyLength = 0;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        keyLength++;
    };
    if (keyLength != 26)
    {
        printf("Error, your key must have 26 characters\n");
        return 1;
    };

    //checking for non alpha characters
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Error, your key must have only alphabetic characters\n");
            return 1;
        };
    };

    //checking repeated characters
    char upperCharI;
    char upperCharJ;
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        upperCharI = toupper(argv[1][i]);
        //printf("charI%i: %c\n", i, upperCharI);
        for (int j = i + 1; argv[1][j] != '\0'; j++)
        {
            upperCharJ = toupper(argv[1][j]);
            //printf("charJ%i: %c\n", j, upperCharJ);
            if (upperCharI == upperCharJ)
            {
                printf("Error, never repeat a character in the key\n");
                return 1;
            };
        };
    };

    //get the plaintext
    plaintext = get_string("Please, digit the plaintext: ");
    printf("plaintext: %s\n", plaintext);
    userMsg = plaintext;
    key = argv[1];

    //cipher each letter, but leave non-alpha characters as-is
    for (int i = 0; userMsg[i] != '\0'; i++)
    {
        if (isalpha(userMsg[i]) != '\0' && islower(userMsg[i]) != '\0')
        {
            userMsg[i] = tolower(key[userMsg[i] - 97]);
        }
        else if (isalpha(userMsg[i]) != '\0' && isupper(userMsg[i]) != '\0')
        {
            userMsg[i] = toupper(key[userMsg[i] - 65]);
        }
    };
    printf("ciphertext: %s\n", userMsg);
    return 0;
};
