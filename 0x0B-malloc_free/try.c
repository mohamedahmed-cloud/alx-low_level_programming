#include "main.h"
#include "stdio.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int count_word(char *str);
int *volume_Word(char *str,int w,  int *arr);
char **store(char **matrix, int *volume, char *str);

/**
 * strtow -returns a pointer to an array of strings (words)
 * @str: string to return from it array of string.
 * Return:  NULL if str == NULL or str == ""
*/
char **strtow(char *str)
{
    int w = count_word(str);
    char **matrix;
    int *volume;
    int arr[w];
    int size, i;
    // printf("%d\n", w);
    volume = volume_Word(str, w, arr);
    size = w;
    matrix = (char **) malloc(size * sizeof(char *));
    for (i = 0; i < size; i++)
        matrix[i] = (char *) malloc((volume[i] + 1) * sizeof(char));
    matrix = store(matrix, volume, str);
    return matrix;
}

/**
 * count_word - count the word in string.
 * @str: string to count word from it.
 * Return: return no. of words.
*/
int count_word(char *str)
{
    int w = 0, i = 0;
    char c = ' ';

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ' && c != ' ')
            w++;
        c = str[i];
    }
    if (c != ' ')
        w++;
    return (w);
}

/**
 * volume_Word - To give me the volume of each word.
 * @str: the string.
 * @w: the number of word.
*/
int *volume_Word(char *str,int w,  int *arr)
{
    int i = 0, start = 0, end = 0, c = 0, j = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
        {
            start = i;
            c = 1;
        }
        else if (c == 1 && str[i] == ' ')
            end = i;
        if (start != 0 && end != 0)
        {
            arr[j] = end - start;
            j++;
            start = 0;
            end = 0;
            c = 0;
        }
    }
    if (start)
        arr[j] = i - start;

    return (arr);
}

char **store(char **matrix, int *volume, char *str)
{
    char *temp;
    int i = 0, start = 0, end = 0, c = 0, j = 0, t = 0, m = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
        {
            start = i;
            temp = (char *) malloc((volume[j] + 1) * sizeof(char));
            j++;
            c = 1;
        }
        if (c)
        {
            temp[t] = str[i];
            t++;
        }
        if (c == 1 && (str[i + 1] == ' ' || str[i + 1] == '\0'))
        {
            temp[t] = '\0';
            matrix[m] = temp;
            // temp = NULL;
            m++;
            t = 0;
            c = 0;
        }
    }

    return matrix;
}
