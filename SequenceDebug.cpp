/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
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
    mySequence[4] = "pointer";
    cout << mySequence[0] << endl;

    return 0;
}
//test
