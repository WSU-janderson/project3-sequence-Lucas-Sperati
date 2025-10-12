#include "Sequence.h"
#include <iostream>
#include <exception>

using namespace std;

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

    std::string nodeString;
    head = new SequenceNode(nodeString);
    SequenceNode* current = head;
    //for loop that creates empty nodes of size sz
    for (size_t i = 0; i < sz; i++) {

    }
}

//deep copy of sequence
Sequence::Sequence(const Sequence& s) {
    this->sz = s.sz;
}

//deletes all the memory sequence used and releases memory
Sequence::~Sequence() {
    clear();
}

//current sequence is released and replaced with the deep copy. A reference
//to the copied sequence is returned (return *this;)
Sequence& Sequence::operator=(const Sequence& s) {

}

//Satisfies (position >=0 && position <= last_index())
//The return value is a reference to the item at index position in the sequence
//Throws an exception if the position is outside the bounds of the sequence
std::string& Sequence::operator[] (size_t position) {

}

//the value of the item is appended to the sequence
void Sequence::push_back(std::string& item) {

}

//The item at the end of the sequence is deleted and the size of the sequence is
//reduced by one. If the sequence was empty it throws an exception
void Sequence::pop_back() {

}

//The position satisfies (position >=0 && position <= last_index())
//The value of the item is inserted at position and the size of the
//sequence is increased by one. Throws an exception if the position
//is outside the bounds of the sequence
void Sequence::insert(size_t position, std::string item) {

}

//returns the first element in the sequence. If the sequence is empty
//it throws an exception
std::string Sequence::front() const{

}

//returns the last element in the sequence. If the sequence is empty
//it throws an exception.
std::string Sequence::back() const{

}

//return true if the sequence has no elements, otherwise returns false
bool Sequence::empty() const {

}

//returns the number of elements in the sequence
size_t Sequence::size() const{

}

//All items in the sequence are deleted and the memory associated with
//the sequence is released, resetting the sequence to an empty state that
//can have items re-inserted
void Sequence::clear() {

}

//The item at position is removed and the memory is released
//If it's called at an invalid position it throws an exception
void Sequence::erase(size_t position) {

}

//The items in the sequence at (position ... (position + count - 1))
//are deleted and their memory is released. If called with an invalid position
//and/or count it throws an exception
void Sequence::erase(size_t position, size_t count) {

}


