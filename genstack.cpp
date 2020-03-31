#include "genstack.h"

using namespace std;

//template class also known as general classes

template< class T>
//default constructor
genstack<T>::genstack(){

  myArray = new char[128];
  mSize = 128;
  top = -1;

}
//overloaded constructor
template <class T>
genstack<T>::genstack(int max){

  myArray = new char[max];
  mSize = max;
  top = -1;

}

template <class T>
//overloaded constructor
genstack<T>::~genstack(){
// FIGURE THIS OUT
  delete [] myArray;
}

template <class T>
void genstack<T>::push(T data){
  // check if full b4 inserting and increase the size if so
  if(isFull()){
      int newsize = mSize *2;
      T *newarray = new T[newsize];

      for(int i=0; i< newsize; i++){
        newarray[i] = myArray[i];
      }
    mSize = newsize;
    delete [] myArray;
    myArray = newarray;
  }
  myArray[++top] = data;
}

template <class T>
T genstack<T>::pop(){
  // check if its empty
  if(isEmpty()){
    throw "Stack is empty error!";
    return 0;
  }else{
    // befor eyou remove
    //post decrement, have not removed the other value from the array
    return myArray[top--];
  }
}

template <class T>
T genstack<T>::peek(){
  if(isEmpty()){
    throw "Stack is empty error!";
    return 0;
  }else{
  //tells us what is at the top of the stack
  return myArray[top];
  }
}

template <class T>
bool genstack<T>::isFull(){
  //checks if the array is full
  return(top == mSize -1);
}

template <class T>
bool genstack<T>::isEmpty(){
  // checks if the array is empty
  return(top == -1);
}
