//Nidhi vedantam
//2328859
#include <iostream>

using namespace std;

template<class T>
class genstack{
  public:
    genstack(); // default
    genstack(int max); // overloaded constructor
    ~genstack();

    //functions
    void push(T data); // insert
    T pop(); // remove

    //helper functions
    bool isFull();
    bool isEmpty();
    T peek();
    int mSize; // max size of myStack
    int top; // variable to keep track of indices representing the top of our stack

    T *myArray;
    //if we know the starting point, its continuos

};
