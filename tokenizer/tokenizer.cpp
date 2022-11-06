#include "tokenizer.h"

bool tokenizer :: isWhiteSpace(char c)
{
    return c == ' ' ||
           c == '\r' || // also a new line symbol
           c == '\n' ||
           c == '\t';
}

void tokenizer :: clearWhiteSpace(std::istream&in)
{
    while (isWhiteSpace(in.peek()))
    {
        in.get();
    }
}

bool tokenizer :: isDigit(char c)
{
    return c >= '0' && c <= '9';
}

std::ostream& operator>>(std::istream &in, tokenizer :: Token &t)
{
    tokenizer :: clearWhiteSpace(in);
    char next = in.peek();

    if (!in || in.eof())
    {
        return in;
    }
    
    if (tokenizer :: isDigit(next))
    {
        t.type = tokenizer :: Token :: NUMBER;
        in >> t.value;
        t.symbol = 0;
    }else
    {
        switch (next)
        {
        case '+': case '-': case '*': case '/': 
            t.type = tokenizer :: Token :: OPERATOR;
            break;
        case '(':
            t.type = tokenizer :: Token :: OPEN_PAR;
            break;
        case ')':
            t.type = tokenizer :: Token :: CLOSE_PAR;
            break;
        case '!':
            t.type = tokenizer :: Token :: EOE;
            break;   
        default: throw "Unrecognized token";
            break;
        }
        t.symbol = next;
        t.value = 0;
        in.get();
    }
    return in;
}; //?