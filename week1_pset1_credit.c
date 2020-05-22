#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int main(void)
{
    //asking for the card number
    long card;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    //creating variables to test if its a valid number
    long cardWithoutLastDigit = 0;
    int digitX2 = 0;
    int otherDigits = 0;
    int sumOfFirtsPartOfDigits = 0;
    int sumOfSecondPartOfDigits = 0;
    int sumOfAllDigits = 0;

    //sum of the first part of digits for the test
    for (long i = card; i > 9; i /= 100)
    {
        for (int j = 0; j < 1; j++)
        {
            cardWithoutLastDigit = i / 10;
            digitX2 = (cardWithoutLastDigit % 10) * 2;

            if (digitX2 > 9)
            {
                digitX2 = (digitX2 / 10) + (digitX2 % 10);
            }
        }
        sumOfFirtsPartOfDigits = sumOfFirtsPartOfDigits + digitX2;
    }

    //sum of the second part of digits for the test
    for (long n = card; n > 0; n /= 100)
    {
        for (int x = 0; x < 1; x++)
        {
            otherDigits = n % 10;
        }
        sumOfSecondPartOfDigits = sumOfSecondPartOfDigits + otherDigits;
    }

    //sum of all digits and testing if its valid
    sumOfAllDigits = sumOfFirtsPartOfDigits + sumOfSecondPartOfDigits;
    //if (sumOfAllDigits % 10 != 0)
    //{
    //    printf("INVALID\n");
    //}

    //checking the number of digits
    int numberOfDigits = 0;
    for (long i = card; i > 9; i /= 10)
    {
        numberOfDigits++;
    }
    numberOfDigits++;

    //finding the first 2 digits
    long firstTwoDigits = card;
    for (long i = card; i > 99; i /= 10)
    {
        firstTwoDigits /= 10;
    }

    //validating according to the type and the first 2 digits
    if ((numberOfDigits == 15) && ((firstTwoDigits == 34) || (firstTwoDigits == 37)) && (sumOfAllDigits % 10 == 0))
    {
        printf("AMEX\n");
    }
    else if ((numberOfDigits == 16) && ((firstTwoDigits == 51) || (firstTwoDigits == 52) || (firstTwoDigits == 53) ||
                                        (firstTwoDigits == 54) || (firstTwoDigits == 55)) && (sumOfAllDigits % 10 == 0))
    {
        printf("MASTERCARD\n");
    }
    else if (((numberOfDigits == 13) || (numberOfDigits == 16)) && (firstTwoDigits / 10 == 4) && (sumOfAllDigits % 10 == 0))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    //tests
    //printf("soma primeiros digitos: %i\n", sumOfFirtsPartOfDigits);
    //printf("soma segundos digitos: %i\n", sumOfSecondPartOfDigits);
    //printf("numero de digitos: %i\n", numberOfDigits);
    //printf("dois primeiros digitos: %li\n", firstTwoDigits);
    //printf("soma de todos os digitos: %i\n", sumOfAllDigits);
}
