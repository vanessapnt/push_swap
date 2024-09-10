#include "push_swap.h"

static  int count_words(char *s, char  c)
{
    int    outside_word;
    int     count;

    count = 0;
    while(*s)
    {
        outside_word = 1;
        while(*s == c)
            s++;
        while(*s != c && *s)
        {
            if (outside_word)
            {
                count++;
                outside_word = 0;
            }
            s++;
        }
    }
    return (count);
}

static  char    *get_next_word(char *s, char   c)
{
    static  int cursor;
    int         i;
    int         len;
    char        *word;

    i = 0;
    len = 0;
    while(s[cursor] == c)
        cursor++;
    while(s[cursor+len] != c && s[cursor+len])
        len++;
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return(NULL);
    while(i < len)
        word[i++] = s[cursor++];
    word[i] = '\0';
    return(word);
}

char **ft_split(char *s, char c)
{
    int     words_number;
    int     i;
    char    **result_string;
    
    i = 0;
    words_number = count_words(s, c);
    if (!words_number)
        exit(1);
    result_string = malloc(sizeof(char *) * (words_number + 2));
    if (!result_string)
        return(NULL);
    while (words_number-- >= 0)
    {
        if(i == 0)
        {
            result_string[i] = malloc(sizeof(char));
            if (!result_string[i])
                return(NULL);
            result_string[i++][0] = '\0';
        }
        else 
            result_string[i++] = get_next_word(s, c);
    }
    result_string[i] = NULL;
    return(result_string);
}
