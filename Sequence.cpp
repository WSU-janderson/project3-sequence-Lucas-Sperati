#include "Sequence.h"
#include <iostream>
#include <exception>

using namespace std;

Sequence::Sequence(size_t sz) {
    this->sz = sz;
}

Sequence::Sequence(const Sequence& s) {
    this->sz = s.sz;
}

Sequence::~Sequence() {
    clearList();
}

Sequence& Sequence::operator=(const Sequence& s) {

}

std::string& Sequence::operator[] (size_t position) {

}

void Sequence::push_back(std::string& item) {

}

void Sequence::pop_back() {

}

void Sequence::insert(size_t position, std::string item) {

}

std::string Sequence::front() const{

}

std::string Sequence::back() const{

}

bool Sequence::empty() const {

}

size_t Sequence::size() const{

}

void Sequence::clear() {

}

void Sequence::erase(size_t position) {

}

void Sequence::erase(size_t position, size_t count) {

}
