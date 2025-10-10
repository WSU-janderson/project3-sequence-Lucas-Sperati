#include <string>
using namespace std;

class Sequence {
public: //variables maybe
    size_t sz; // size_t == unsigned long long

public://methods maybe
    //default constructor
    Sequence();

    //parameterized constructor
    Sequence(size_t sz);

    //TODO no idea if I need this. Just following
    //linked list example.
    //This all makes a deep copy of the Sequence
    //copy constructor - can make deep copy
    Sequence(const Sequence& other);
    //assignment operator
    Sequence& operator=(const Sequence& other);
    //deconstructor
    ~Sequence();
    //todo end stuff idk if I need

    //getters would go here if I need them, might not tho

    //setters here, same boat

    //methods
    void push_back(const string& item);
    void pop_back();
    void insert(size_t position, const string& item);
    void front();
    void back();
    void empty();
    void size();
    void clear();
    void erase(size_t position);
    void erase(size_t position, const string& count);

    friend ostream& operator<<(ostream & os, const Sequence& s);
};

class SequenceNode {
    public: //public so you don't need getters or setters

    //pointer to next Node. If node is the tail, next is
    //nullptr
    SequenceNode* next;

    //pointer to previous Node. If node is the head, prev
    //is nullptr
    SequenceNode* prev;

    //the element being stored in the node
    std::string item;


    //default constructor that makes sure next and prev
    //are set to nullptr
    SequenceNode() : next(nullptr), prev(nullptr) {}

    //parameterized constructor, next and prev are set to
    //nullptr and the node's element is set to the given
    //value
    SequenceNode(std::string& item) : next(nullptr), prev(nullptr), item(item) {}
};