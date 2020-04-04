//Nidhi vedantam
//2328859
// based on the algorithm given in the textbook
#ifndef GENSTACK_H
#define GENSTACK_H
#include "StackEx.h"
#include <iostream>

using namespace std;
//template classes, also known as general classes, easier to reuse code and not have to
//make new code for each data type. 
template <typename T>
class genstack
{
  public:
    //default constructor
    genstack();
    //overlpaded constructor
    genstack(int cap);
    ~genstack();

    //main functions
    //insert
    void push(const T& t);
    //remove
    void pop() throw(StackEx);

    //helper functions
    //returns how many elements are in the stack
    int currentsize() const;
    //returns the top element
    const T& top() const throw(StackEx);
    //returns true or false of the stack is empty
    bool isEmpty() const;
    //returns true or false of the stack if full
    bool isFull() const;
    //removes the top elemt of the stack
    void remove();

  private:
    T* myArray;
    int cap;
    int first;

};

#endif

//cpp in the header file

//template class also known as general classes

// template <class T>
// //default constructor
// genstack<T>::genstack(){
//
//   myArray = new char[mSize];
//   mSize = 128;
//   top = -1;
//
// }
// //overloaded constructor
// template <class T>
// genstack<T>::genstack(int max){
//
//   myArray = new char[max];
//   mSize = max;
//   top = -1;
//
// }
//
