#include <stdio.h>
#include <string.h>
#include "include/lexer.h"
#include "include/token.h"
#include "include/io.h"

int main(int argc, char *argv[])
{
    lexer_T *lexer = init_lexer(get_file_contents(argv[1]));

    token_T *token = (void *)0;

    FILE *file = fopen("symbol_table.txt", "w");
    if (file == NULL)
    {
        printf("error opening file");
        return 1;
    }
    while ((token = lexer_get_next_token(lexer)) != (void *)0)
    {
        char tokenName[64];
        switch (token->type)
        {
        case 0:
            strcpy(tokenName, "TOKEN_ID");
            break;
        case 1:
            strcpy(tokenName, "TOKEN_EQUALS");
            break;
        case 2:
            strcpy(tokenName, "TOKEN_WORD");
            break;
        case 3:
            strcpy(tokenName, "TOKEN_LPAREN");
            break;
        case 4:
            strcpy(tokenName, "TOKEN_RPAREN");
            break;
        case 5:
            strcpy(tokenName, "TOKEN_KEYWORD");
            break;
        case 6:
            strcpy(tokenName, "TOKEN_ADDITION");
            break;
        case 7:
            strcpy(tokenName, "TOKEN_SUBTRACTION");
            break;
        case 8:
            strcpy(tokenName, "TOKEN_MULTIPLICATION");
            break;
        case 9:
            strcpy(tokenName, "TOKEN_DIVISION");
            break;
        case 10:
            strcpy(tokenName, "TOKEN_EXPONENT");
            break;
        case 11:
            strcpy(tokenName, "TOKEN_INTDIV");
            break;
        case 12:
            strcpy(tokenName, "TOKEN_MODULUS");
            break;
        case 13:
            strcpy(tokenName, "TOKEN_SLCOMMENT");
            break;
        case 14:
            strcpy(tokenName, "TOKEN_MLCOMMENT");
            break;
        case 15:
            strcpy(tokenName, "TOKEN_INVALID");
            break;
        case 16:
            strcpy(tokenName, "TOKEN_NUM");
            break;
        case 17:
            strcpy(tokenName, "TOKEN_DECIMAL");
            break;
        case 18:
            strcpy(tokenName, "TOKEN_RESVWORD");
            break;
        case 19:
            strcpy(tokenName, "TOKEN_GREATERTHAN");
            break;
        case 20:
            strcpy(tokenName, "TOKEN_GREATERTHANOREQUALS");
            break;
        case 21:
            strcpy(tokenName, "TOKEN_LESSTHAN");
            break;
        case 22:
            strcpy(tokenName, "TOKEN_LESSTHANOREQUALS");
            break;
        case 23:
            strcpy(tokenName, "TOKEN_ISEQUALTO");
            break;
        case 24:
            strcpy(tokenName, "TOKEN_OPERATOR");
            break;
        case 25:
            strcpy(tokenName, "TOKEN_NOTEQUAL");
            break;
        case 26:
            strcpy(tokenName, "TOKEN_LBRACKET");
            break;
        case 27:
            strcpy(tokenName, "TOKEN_RBRACKET");
            break;
        case 28:
            strcpy(tokenName, "TOKEN_LBRACE");
            break;
        case 29:
            strcpy(tokenName, "TOKEN_RBRACE");
            break;
        case 30:
            strcpy(tokenName, "TOKEN_SEMICOLON");
            break;
        case 31:
            strcpy(tokenName, "TOKEN_COMMA");
            break;
        case 32:
            strcpy(tokenName, "TOKEN_NOISEWORD");
            break;
        case 33:
            strcpy(tokenName, "TOKEN_DOT");
            break;
        case 34:
            strcpy(tokenName, "TOKEN_LETTER");
            break;
        case 35:
            strcpy(tokenName, "TOKEN_COLON");
            break;
        }
        fprintf(file, "%s--------%s\n", token->value, tokenName);

        // printf("( %d\t%s )\n", token->type, token->value);
    }

    printf("Symbol Table successfully printed!\n");

    return 0;
}