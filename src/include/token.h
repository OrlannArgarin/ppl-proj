#ifndef TOKEN_H
#define TOKEN_H
typedef struct TOKEN_STRUCT
{
    enum
    {
        TOKEN_ID,
        TOKEN_EQUALS,
        TOKEN_WORD,
        TOKEN_LPAREN,
        TOKEN_RPAREN,
        TOKEN_KEYWORD,
        TOKEN_ADDITION,
        TOKEN_SUBTRACTION,
        TOKEN_MULTIPLICATION,
        TOKEN_DIVISION,
        TOKEN_EXPONENT,
        TOKEN_INTDIV,
        TOKEN_MODULUS,
        TOKEN_SLCOMMENT,
        TOKEN_MLCOMMENT,
        TOKEN_INVALID,
        TOKEN_NUM,
        TOKEN_DECIMAL,
        TOKEN_RESVWORD,
        TOKEN_GREATERTHAN,
        TOKEN_GREATERTHANOREQUALS,
        TOKEN_LESSTHAN,
        TOKEN_LESSTHANOREQUALS,
        TOKEN_ISEQUALTO,
        TOKEN_OPERATOR,
        TOKEN_NOTEQUAL,
        TOKEN_LBRACKET,
        TOKEN_RBRACKET,
        TOKEN_LBRACE,
        TOKEN_RBRACE,
        TOKEN_SEMICOLON,
        TOKEN_COMMA,
        TOKEN_NOISEWORD,
        TOKEN_DOT,
        TOKEN_LETTER,
        TOKEN_COLON
    } type;

    char *value;
} token_T;

token_T *init_token(int type, char *value);
#endif // !TOKEN_H
