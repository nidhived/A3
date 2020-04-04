#ifndef STACKEX_H
#define STACKEX_H
//class for stack empty error exception!!!
#include <iostream>
#include <exception>
using namespace std;

class StackEx : public exception{
public:
  virtual const char* what() const throw(){
    return "Stack empty ERROR!";
  }
};

#endif
