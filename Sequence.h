#include <string>
using namespace std;

class Sequence {
public: //variables maybe
    size_t sz; // size_t == unsigned long long


    //methods maybe
    //default constructor
    Sequence();

    //todo added =0 here and removed it in .cpp
    //parameterized constructor
    Sequence(size_t sz = 0);


    //This all makes a deep copy of the Sequence
    //copy constructor - can make deep copy
    Sequence(const Sequence& s);
    //assignment operator
    Sequence& operator=(const Sequence& s);
    //deconstructor
    ~Sequence();

    //getters would go here if I need them, might nt tho

    //setters here, same boat

    //methods
    string& operator[] (size_t position);
    void push_back(string& item);
    void pop_back();
    void insert(size_t position, string item);
    string front() const;
    string back() const;
    bool empty() const;
    size_t size() const;
    void clear();
    void erase(size_t position);
    void erase(size_t position, size_t count);

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