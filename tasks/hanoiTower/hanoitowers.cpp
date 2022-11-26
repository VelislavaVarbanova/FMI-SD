#include <stack>
#include <iostream>

struct Game
{
    //std::stack<int> source, aux, destination;
    std::stack<int> poles[3];
};

// void move(std::stack<int> &source,
//             std::stack<int> &aux,
//             std::stack<int> &destination, int k)
// {
//     if (k == 0)
//     {
//         return;
//     }
//     // Game subgame = {game.source, game.destination, game.aux};
//     // move(subgame, k-1);
//     // subgame.destination.push(subgame.source.top()); subgame.source.pop();
//     // Game subgame2 = {subgame.aux, subgame.source, subgame.destination};
//     // move(subgame2, k-1);
    
//     move(source, destination, aux, k-1);
//     destination.push(source.top());source.pop();
//     move(aux, source, destination, k-1);
// }

template <typename T>
void printStack(std::stack<T> s)
{
    if (s.empty())
    {
        return;
    }
    int top = s.top();s.pop();
    printStack(s);
    std::cout << "-" << top;
}

class HanoiGame
{
    public:

    HanoiGame(int k)
    {
        while (k > 0)
        {
            state.poles[0].push(k);
            k--;
        }
    }

    void move(char source,
                char aux,
                char destination, int k)
    {
        if (k == 0)
        {
            return;
        }
        
        move(source,destination,aux,k-1);
        std::cout << "Please move 1 disk from " << source << " to " << destination << std::endl;
        performMove(source,destination);
        printBoard();
        std::cin.get();
        move(aux,source,destination,k-1);
    }

    void play()
    {
        printBoard();
        std :: cin.get();
        move ('A','B','C', state.poles[0].size());
    }

    private:
    Game state;

    void performMove(char source, char destination)
    {
        int sourceIndex = source - 'A';
        int destinationIndex = destination - 'A';
        state.poles[destinationIndex].push(state.poles[sourceIndex].top());
        state.poles[sourceIndex].pop();
    }

    void printBoard()
    {
        // std::cout << "|";
        // printStack<int>(g.source);
        // std::cout << std::endl;
        // std::cout << "|";
        // printStack<int>(g.aux);
        // std::cout << std::endl;
        // std::cout << "|";
        // printStack<int>(g.destination);
        // std::cout << std::endl;
        for (std::stack<int> pole : state.poles)
        {
            std::cout << "|";
            printStack<int>(pole);
            std::cout << std:: endl;
        }
    }
};

int main()
{
    // Game g;
    // g.source.push(3);
    // g.source.push(2);
    // g.source.push(1);
    // printBoard(g);

    // move(source, aux, destination,3);
    HanoiGame game(8);

    game.play();
}