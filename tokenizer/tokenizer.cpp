#include "tokenizer.h"

bool tokenizer :: isWhiteSpace(char c)
{
    return c == ' ' ||
           c == '\r' || // also a new line symbol
           c == '\n' ||
           c == '\t';
}

void tokenizer :: clearWhiteSpace()
{
    while (isWhiteSpace(in.peek()))
    {
        in.get();
    }
}

