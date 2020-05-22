#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //declaring a variable height
    int height;

    //asking a height of the pyramid util get an answers between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //building the pyramid
    for (int i = 0; i < height; i++)
    {
        for (int n = height - i - 1; n > 0; n--)
        {
            printf(" ");
        }

        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
