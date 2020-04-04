#ifndef DELIM_H
#define DELIM_H
//header class for the delim.cpp
#include <iostream>
#include <fstream>
#include "genstack.h"
#include "genstack.cpp"

using namespace std;

class delim{
  public:
    //constructors
    delim();
    ~delim();
    //main function
    int openFile(string fileinput);

  private:
    //creating delim stack to check for open delims
    genstack<char>* m_brack;
};
#endif
