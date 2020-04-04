#include "StackEx.h"
#include "delim.h"
//#include "delim.h"
#include <iostream>

//test that the stack works
int main(int argc, char** argv){

// making an object for the delim checker
  delim* sourcecode = new delim();

// if the user doesnt enter a file, it will end the program
// and ask them to provide a file
  if (argc < 2){
    cout << "Please provide a file!" << endl;
    return 1;
  }

  string fileinput = argv[1];
  sourcecode ->openFile(fileinput);

  delete sourcecode;
  return 0;
}

// myStack->push('R');
//   myStack->push('e');
//   myStack->push('n');
//   myStack->push('e');
//
//   cout << "popping: " << myStack->pop() << endl;
//   cout << "peek-a-boo: " << myStack->peek() << endl;
//
//   myStack->push('F');
//   cout << "peek-a-boo: " << myStack->peek() << endl;
//
//   while (!myStack->isEmpty()){
//   cout << "popping: " << myStack->pop() << endl;
// }
//   cout << "is stack empty? " << myStack->isEmpty() << endl;
//
//   delete myStack;
//   return 0;
// }
