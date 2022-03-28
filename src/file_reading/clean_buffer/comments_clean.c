/*
** EPITECH PROJECT, 2020
** COREWAR
** File description:
** Delete all comments
*/

#include "my.h"
#include "asm.h"

int define_comment_len(char *buffer, int hashtag_index)
{
    int comment_len = 0;

    for (int i = hashtag_index; buffer[i] != '\0'; i++){
        if (buffer[i] == '\n')
            break;
        comment_len++;
    }
    return (comment_len);
}

char *delete_this_comment(char *buffer, int hashtag_index)
{
    int comment_len = define_comment_len(buffer, hashtag_index);
    int buffer_len = my_strlen(buffer), new_buffer_index = 0;
    int new_buffer_size = buffer_len - comment_len;
    char *new_buffer = malloc(sizeof(char) * new_buffer_size + 1);
    char continue_parsing = TRUE, is_in_double_quote = FALSE;
    new_buffer[new_buffer_size] = '\0';
    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        if (buffer[i] == '#' && !is_in_double_quote)
            continue_parsing = FALSE;
        if (buffer[i] == '\n')
            continue_parsing = TRUE;
        if (continue_parsing == TRUE){
            new_buffer[new_buffer_index] = buffer[i];
            new_buffer_index++;
        }
    }
    free(buffer);
    return (new_buffer);
}

char *delete_comments(char *buffer)
{
    char there_are_comment = FALSE;
    char is_in_double_quote = FALSE;
    int hashtag_index = 0;

    for (int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '"')
            is_in_double_quote = !is_in_double_quote;
        if (buffer[i] == '#' && !is_in_double_quote){
            there_are_comment = TRUE;
            hashtag_index = i;
            break;
        }
    }
    if (there_are_comment){
        buffer = delete_this_comment(buffer, hashtag_index);
        delete_comments(buffer);
    }
    else
        return (buffer);
}
