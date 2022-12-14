#include <iostream>

template <typename T>
struct Maybe
{
    T value; 
    bool defined;
    Maybe():defined(false){}
    Maybe(const T &v):value(v),defined(true){}
};

template <typename T>
class BinOrdTree
{
    public:
    BinOrdTree();
    BinOrdTree(const BinOrdTree<T>&);

    void add(const T&);
    void addRec(const T&);
    void toDotty(std::ostream&);

    std::vector<T> leaves();
    std::vector<T> level(int k);

    bool member(const T& x);
    size_t size();
    //bool checkOrder();

    BinOrdTree<T>& operator=(const BinOrdTree<T>&);

    void printLevels();

    ~BinOrdTree();

    private:
    struct Box
    {
        T data;
        Box* left;
        Box* right;
    };

    Box* root;

    std::vecrot<T> leaves(Box*);
    std::vector<T> level(Box*, int k);
    
    void addHelper(Box *&, const T&);
    void toDotty(Box *, std::ostream &out);
    void printDotStatements(Box*, std::ostream &out);

    Box* copy(const Box*);
    void clear(Box* root);

    bool member(Box *,const T&);
    size_t count(Box *);
    //bool checkOrder(box *,const Maybe<T>&, const Maybe<T>&);
};