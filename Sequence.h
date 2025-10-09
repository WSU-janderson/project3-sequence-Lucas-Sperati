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