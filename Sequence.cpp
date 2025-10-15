/**
* Sequence.cpp
 * Project 3
 * CS 3100
 * Lucas Sperati
 *
 * This file implements all the methods and the class that is used for the sequence.
 */
#include "Sequence.h"
#include <iostream>
#include <exception>

using namespace std;
#include <stdexcept>


//makes empty sequence
//default constructor
Sequence::Sequence() {
    sz = 0;
    head = nullptr;
    tail = nullptr;
}
//parameterized constructor
Sequence::Sequence(size_t sz) {
    this->sz = sz;
    this->head = nullptr;
    this->tail = nullptr;

    //string for the current item that is between next and prev
    std::string nodeItemString;
    //makes the head node and initializes head with the nodeItemString
    head = new SequenceNode(nodeItemString);
    //sets currentNodePointer to the head
    SequenceNode* currentNodePointer = head;


    //for loop that creates empty nodes of size sz
    for (size_t i = 1; i < sz; i++) {
        //makes new node
        SequenceNode* nextNode = new SequenceNode(nodeItemString);
        //sets the next pointer to the newly created nextNode
        currentNodePointer->next = nextNode;
        //sets the prev pointer to the previous node
        nextNode->prev = currentNodePointer;
        //sets currentNodePointer to the nextNode to be made
        currentNodePointer = nextNode;

    }
    //since by the end the currentNodePointer will be at the very end, it is set to tail
    tail = currentNodePointer;
}

//deep copy of sequence
Sequence::Sequence(const Sequence& s) {
    this->sz = s.sz;

    //makes new copy node, gets the item that's there, and sets it to the head of the deep copy
    //s.head->item reads what's in the first node of the sequence. It took me forever to do this
    //one line smh
    head = new SequenceNode(s.head->item);
    //sets the currentNodePointer to head and points to the copy's head
    SequenceNode* currentNodePointer = head;
    //sets originalNodePointer to the head and then sets it to the node next to it
    //since head is already assigned to the first node and is already in the
    //copy sequence
    SequenceNode* originalNodePointer = s.head->next;

    //while loop that adds each item in the original sequence to the copy
    // generated the while loop and I just went with it

    while (originalNodePointer != nullptr) {
        //makes a new node and puts the item inside the originalNodePointer inside
        SequenceNode* copyNode = new SequenceNode(originalNodePointer->item);
        //sets the next pointer to the copyNode
        currentNodePointer->next = copyNode;
        //sets the prev pointer to the previous node
        copyNode->prev = currentNodePointer;
        //moves currentNodePointer to the new copyNode
        currentNodePointer = copyNode;
        //moves originalNodePointer to the next node
        originalNodePointer = originalNodePointer->next;
    }
    //once the loop ends tail is set to currentNodePointer since that would be the last node
    tail = currentNodePointer;

}

//deletes all the memory sequence used and releases memory
Sequence::~Sequence() {
    clear();
}

//current sequence is released and replaced with the deep copy. A reference
//to the copied sequence is returned (return *this;)
Sequence& Sequence::operator=(const Sequence& s) {
    //removes the current sequence
    clear();
    //sets the size to the deep copies size
    this->sz = s.sz;//autofilled by clion
    //sets the head of the main sequence to the head of the item in the copy
    this->head = new SequenceNode(s.head->item);//autofilled by clion
    //sets mainNodePointer to the head to the copy of the deep
    SequenceNode* mainNodePointer = head;//autofilled by clion
    //sets copyNodePointer to the next node in the deep sequence
    SequenceNode* deepNodePointer = s.head->next;//autofilled by clion

    //while the deepNodePointer isn't null so a cop can be made
    while (deepNodePointer != nullptr) {//autofilled by clion
        //sets the next item in deepNodePointer to newCopyNode
        SequenceNode* newCopyNode = new SequenceNode(deepNodePointer->item);//autofilled by clion
        //sets the next pointer to the newCopyNode
        mainNodePointer->next = newCopyNode;//autofilled by clion
        //sets the prev pointer to the mainNodePointer
        newCopyNode->prev = mainNodePointer;//autofilled by clion
        //sets mainNodePointer to newCopyNode
        mainNodePointer = newCopyNode;
        //moves the deepNodePointer forward one
        deepNodePointer = deepNodePointer->next;
    }
    //sets tail to the mainNodePointer since that's where it would be
    tail = mainNodePointer;
    //think this just returns the new sequence?
    return *this;
}


//Satisfies (position >=0 && position <= last_index())
//The return value is a reference to the item at index position in the sequence
//Throws an exception if the position is outside the bounds of the sequence
std::string& Sequence::operator[] (size_t position) {
    //sets currentNode equal to the head
    SequenceNode* currentNode = head;
    //throws exception if position is greater or equal to the size
    if (position >= sz) {
        throw std::invalid_argument("position is outside bounds of sequence");
    }
    for (size_t i = 0; i < position; i++) {
        //moves through the sequence until the position is found and currentNode
        //is set to it
        currentNode = currentNode->next;
    }
    return currentNode->item;
}

//the value of the item is appended to the sequence
void Sequence::push_back(std::string item) {
    //sets currentNode equal to the item
    SequenceNode* currentNode = new SequenceNode(item);
    //sets tail's next slot equal to the currentNode
    tail->next = currentNode;
    //new node points back to old tail
    currentNode->prev = tail;
    //makes the currentNode the tail
    tail = currentNode;
    //increases size by one
    sz += 1;
}

//The item at the end of the sequence is deleted and the size of the sequence is
//reduced by one. If the sequence was empty it throws an exception
void Sequence::pop_back() {
    //if the size is 0 it throws and exception
    if (sz == 0) {
        throw std::invalid_argument("sequence is empty!");
    }
    //sets currentNode to the tail
    SequenceNode* currentNode = tail;
    //moves the tail back one node
    tail = tail->prev;
    //if the size would equal one then tail->next would make an error
    //since nullptr has no ->next
    if (tail != nullptr) {
        //sets the next node to the new tail to nullptr
        tail->next = nullptr;
    }
    //removes currentNode
    delete currentNode;
    //decreases size by one
    sz -= 1;
}

//The position satisfies (position >=0 && position <= last_index())
//The value of the item is inserted at position and the size of the
//sequence is increased by one. Throws an exception if the position
//is outside the bounds of the sequence
void Sequence::insert(size_t position, std::string item) {
    if (position >= sz) {
        throw std::invalid_argument("position is outside bounds of sequence");
    }
    SequenceNode* currentNode = head;

    //tail case
    //if the position is at the tail
    if (position == sz) {
        //just does push_back on the new node
        this->push_back(item);

    }
    //head case
    //if the item is being inserted at the tail
    else if (position == 0) {
        SequenceNode* newNode = new SequenceNode(item);
        //sets the prev of current node to new node
        currentNode->prev = newNode;
        //sets new node next to the current node
        newNode->next = currentNode;
        //sets the head to the newNode
        head = newNode;
        //increases size
        sz += 1;
    }
    else{
        //loops to position
        //(-1 because you're placing new node at position 5 you need to go forward 4 times)
        for (size_t i = 0; i < position - 1; i++) {
            currentNode = currentNode->next;
        }
        //node for the newly made Node
        SequenceNode* newNode = new SequenceNode(item);
        //node for the next node
        SequenceNode* nextNode;
        //sets nextNode to the node after current
        nextNode = currentNode->next;
        //sets currentNode next to new
        currentNode->next = newNode;
        //sets nextNode's prev to newNode
        nextNode->prev = newNode;
        //sets nextNode prev to the current
        newNode->prev = currentNode;
        //sets new.next to nextNode
        newNode->next = nextNode;
        sz += 1;
    }

}

//returns the first element in the sequence. If the sequence is empty
//it throws an exception
std::string Sequence::front() const{
    //if the head is nullptr then the sequence is empty
    if (head == nullptr) {
        throw std::invalid_argument("head is empty!");
    }
    //returns the item at the head
    return head->item;
}

//returns the last element in the sequence. If the sequence is empty
//it throws an exception.
std::string Sequence::back() const{
    //returns the item at the tail
    //if the tail is nullptr then it throws an exception
    if (tail == nullptr) {
        throw std::invalid_argument("tail is empty!");
    }
    return tail->item;

}

//return true if the sequence has no elements, otherwise returns false
bool Sequence::empty() const {
    if (sz == 0) {
        return true;
    }
    return false;
}

//returns the number of elements in the sequence
size_t Sequence::size() const{
    return sz;
}

//All items in the sequence are deleted and the memory associated with
//the sequence is released, resetting the sequence to an empty state that
//can have items re-inserted
void Sequence::clear() {
    //sets currentNode to the head of the sequence
    SequenceNode* currentNode = head;
    //whileloop that goes through the node. clion generated it again
    while (currentNode != nullptr) {
        //sets nextNode next element after currentNode so currentNode can be deleted
        SequenceNode* nextNode = currentNode->next; //clion generated. think it works from what i've googled
        //deletes what's in currentNode
        delete currentNode; //clion generated
        //moves currentNode to the nextNode
        currentNode = nextNode; //clion generated
    }
    //resets everything at the end
    head = nullptr;
    tail = nullptr;
    sz = 0;

    //literally clion just autofilled the entire method. from what i've googled I think
    //it works probably. Clion ain't ai either so im keeping it.
}


//The item at position is removed and the memory is released
//If it's called at an invalid position it throws an exception
void Sequence::erase(size_t position) {
    //if the position is greater than size then its at an invalid position
    if (position > sz) {
        throw std::invalid_argument("position is at invalid position");
    }
    SequenceNode* currentNode = head;
    //for loop to get the node at the position
    for (size_t i = 0; i < position; i++) {
        currentNode = currentNode->next;
    }
    //if deleting the head
    if (position == 0 && sz > 1) {
        head = currentNode->next;
    }
    //if not deleting head
    else if (position > 0 && position < sz) {
        //sets the prevNode to the previous of currentNode
        SequenceNode* prevNode = currentNode->prev;
        //sets the next of prevNode to the next of currentNode
        prevNode->next = currentNode->next;
        //if it's deleting tail
        if (prevNode->next == nullptr) {
            tail = prevNode;
        }
    }
    //deletes the currentNode to be deleted
    delete currentNode;
    sz -= 1;
}


//The items in the sequence at (position ... (position + count - 1))
//are deleted and their memory is released. If called with an invalid position
//and/or count it throws an exception
void Sequence::erase(size_t position, size_t count) {
    //if the count and position gets greater than size then it throws an exception
    if (count + position >= sz) {
        throw std::invalid_argument("position is at invalid position");
    }
    //goes through each of the counts and then erases the node at the position
    /*A B C D (node)  (pos = 1, count = 2)
     *0 1 2 3 (position)
     *Start at position B
     *Removes B and C
     *A points to D
     */
    for (size_t i = 0; i < count; i++) {
        erase(position + i);
    }
}
