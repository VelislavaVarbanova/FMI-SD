#include <iostream>
#include <cassert>
#ifndef TOKENIZER_H
#define TOKENIZER_H


class tokenizer
{
public:
    struct Token
    {
        public:
        enum TokenType {OPEN_PAR, 
                        CLOSE_PAR, 
                        NUMBER, 
                        OPERATOR,
                        EOE};
        TokenType type;
        char symbol;
        int value;
    };

    tokenizer(std :: istream&);
    //Token getNextToken();
    //bool hasMoreTokens();

    bool isWhiteSpace(char);
    bool isDigit(char c);
    friend std::ostream& operator>>(std::istream &in, Token &t);

    std :: istream& in;
    void clearWhiteSpace(std::istream&in); //std::istream&in
};



#endif