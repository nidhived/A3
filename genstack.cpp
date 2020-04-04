#include "genstack.h"
//inclduing header class

//constructors
template <typename T>
genstack<T>::genstack(){
  cap = 128;
  first = -1;
  myArray = new T[cap];
}
//overloaded
template <typename T>
genstack<T>::genstack(int max){
  cap= max;
  first = -1;
  myArray = new T[cap];
}
//deconstructor will delete
template <typename T>
genstack<T>::~genstack(){
  delete this->myArray;
}
// push onto the stack
template <typename T>
void genstack<T>::push(const T& t){
  //first checking if the stack is empty
  if (!this->isFull()){
    this->myArray[++first] = t;
  }else{
    //increase the size of the stack
    cap *= 2;
    T* newArray = new T[cap];
    for (int i = 0; i < this->currentsize(); ++i){
      newArray[i] = myArray[i];
    }
    myArray = newArray;
    this->myArray[++first] = t;
    newArray = NULL;
    delete [] newArray;
  }
}
//popping values off the stack
template <typename T>
void genstack<T>::pop() throw(StackEx){
  if (!this->isEmpty()){
    --first;
  }else{
    //if stack is empty cannot pop, throw exception class
    throw StackEx();
  }
}
// to find out the current size of the stack
template <typename T>
int genstack<T>::currentsize() const{
  return first + 1;
}
// to see if the stack is empty
template <typename T>
bool genstack<T>::isEmpty() const{
  return (first == -1);
}
//to check if the stack is full
template <typename T>
bool genstack<T>::isFull() const
{
  return (first == cap - 1);
}
// to check the top value of the stack
template <typename T>
const T& genstack<T>::top() const throw(StackEx){
  if (!this->isEmpty()){
    return this->myArray[first];
  }else{
    throw StackEx();
  }
}
//remove the first value of the stack 
template <typename T>
void genstack<T>::remove(){
  this->first = -1;
}



/////////////////////
// #include "genstack.h"

// //////////////
