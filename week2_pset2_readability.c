#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//creating the variable to save the text input
string text;

//creating the variable to count letters, words and sentences of the input
float letters = 0;
float words = 1;
float sentences = 0;

//declaring the functions to count letters, words and sentences of the input and say grade
float countLetters(string anyString);
float countWords(string anyString);
float countSentences(string anyString);
float sayGrade(float l, float w, float s);

int main(void)
{
    //getting the input text from the user e priting the number of letters, words and sentences
    text = get_string("Text: ");

    //counting letters, words and sentences from the input
    countLetters(text);
    countWords(text);
    countSentences(text);

    //output the grade
    sayGrade(letters, words, sentences);

};

//function to count letters
float countLetters(string anyString)
{
    for (int i = 0; anyString[i] != '\0'; i++)
    {
        if (isalpha(anyString[i]) != 0)
        {
            letters++;
        }

    }
    return letters;
};

//function to count words assuming the string never start or end with space
float countWords(string anyString)
{
    for (int i = 0; anyString[i] != '\0'; i++)
    {
        if ((anyString[i] == ' ') && (anyString[i + 1] != ' '))
        {
            words++;
        }
    }
    return words;
};

//function to count sentences assuming that each . ! ? indicates one sentence
float countSentences(string anyString)
{
    for (int i = 0; anyString[i] != '\0'; i++)
    {
        if ((anyString[i] == '.') || (anyString[i] == '!') || (anyString[i] == '?'))
        {
            sentences++;
        }
    }
    return sentences;
};

//function to say grade
float sayGrade(float l, float w, float s)
{
    float grade = (0.0588 * (100 / w) * l) - (0.296 * (100 / w) * s) - 15.8;
    //return grade;
    if (grade >= 16)
    {
        return printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        return printf("Before Grade 1\n");
    }
    else
    {
        return printf("Grade %.f\n", grade);
    }
};
