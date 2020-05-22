#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //asking the value of the change
    float changeInDollars;
    do
    {
        changeInDollars = get_float("Change owed: ");
    }
    while (changeInDollars < 0);

    //converting dollars to cents
    int changeInCents = round(changeInDollars * 100);

    // testing variable printf("%i\n", changeInCents);

    //counting coins
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int coins = 0;

    //counting quartes;
    while (changeInCents >= 25)
    {
        quarters++;
        changeInCents -= 25;

    };

    //counting dimes;
    while (changeInCents >= 10)
    {
        dimes++;
        changeInCents -= 10;

    };

    //counting nickels;
    while (changeInCents >= 5)
    {
        nickels++;
        changeInCents -= 5;

    };

    //cointing pennies;
    while (changeInCents >= 1)
    {
        pennies++;
        changeInCents -= 1;

    };

    //testing counting
    //printf("Rest of change: %i, Quarters: %i, Dimes: %i, Nickels: %i, Pennies: %i\n", changeInCents, quarters, dimes, nickels, pennies);
    
    //counting coins
    coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}
