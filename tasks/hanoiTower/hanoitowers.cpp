#include <stack>
#include <iostream>

struct Game
{
    std::stack<int> source, aux, destination;
};

void move(std::stack<int> &source,
            std::stack<int> &aux,
            std::stack<int> &destination, int k)
{
    if (k == 0)
    {
        return;
    }
    // Game subgame = {game.source, game.destination, game.aux};
    // move(subgame, k-1);
    // subgame.destination.push(subgame.source.top()); subgame.source.pop();
    // Game subgame2 = {subgame.aux, subgame.source, subgame.destination};
    // move(subgame2, k-1);
    
    move(source, destination, aux, k-1);
    destination.push(source.top());source.pop();
    move(aux, source, destination, k-1);
}

template <typename T>
void printStack(std::stack<int> s)
{
    if (s.empty())
    {
        return;
    }
    int top = s.top();s.pop();
    printStack(s);
    std::cout << "-" << top;
}

void printBoard(Game g)
{
    std::cout << "|";
    printStack<int>(g.source);
    std::cout << std::endl;
    std::cout << "|";
    printStack<int>(g.aux);
    std::cout << std::endl;
    std::cout << "|";
    printStack<int>(g.destination);
    std::cout << std::endl;

}


int main()
{
    Game g;
    g.source.push(3);
    g.source.push(2);
    g.source.push(1);
    printBoard(g);

    move(source, aux, destination,3);
}