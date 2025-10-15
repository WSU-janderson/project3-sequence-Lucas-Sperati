/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 * Lucas Sperati
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>

#include "Sequence.h"

using namespace std;

int main() {
    Sequence mySequence(5);
    mySequence[0] = "function";
    mySequence[1] = "parameter";
    mySequence.push_back("hello");
    //mySequence[4] = "pointer";
    mySequence.push_back("hi");
    cout << mySequence << "|" << endl;
    mySequence.pop_back();
    cout << mySequence << "|" << endl;
    mySequence.insert(1, "insert");
    cout << mySequence << "|" << endl;
    cout << "front is: " << mySequence.front() << endl;
    cout << "back is: " << mySequence.back() << endl;
    cout << "is empty: " << mySequence.empty() << endl;
    cout << "size: " << mySequence.size() << endl;
    mySequence.erase(2);
    cout << mySequence << "|" << endl;
    mySequence.push_back("one");
    mySequence.push_back("two");
    mySequence.push_back("three");
    cout << mySequence << "|" << endl;
    cout << "size: " << mySequence.size() << endl;
    mySequence.erase(1,3);
    cout << mySequence << "|" << endl;

    Sequence mysequenceCopy(5);
    mysequenceCopy = mySequence;
    cout << mysequenceCopy << "|" << endl;
    return 0;
}
//test
