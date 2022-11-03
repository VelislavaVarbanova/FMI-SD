#include <iostream>
#include <cassert>


class tokenizer
{
public:
    struct Token
    {
        enum TokenType {OPEN_PAR, 
                        CLOSE_PAR, 
                        NUMBER, 
                        OPERATOR};
        TokenType type;
        char symbol;
        int value;
    };

    tokenizer(std :: istream&);
    //Token getNextToken();
    //bool hasMoreTokens();

    static bool isWhiteSpace(char);
    bool isDigit(char c);
    //std::ostream& operator>>(std::istream &in, Token &t);


private:
    std :: istream& in;
    void clearWhiteSpace(); //std::istream&in
};



