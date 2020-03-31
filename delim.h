#ifndef DELIM_H
#define DELIM_H

#include "genstack.cpp"
#include "genstack.h"
#include <iostream>
#include <iostream>

using namespace std;

class delim{
  public:
    //constructor
    delim();
    //deconstructor
    ~delim();

    int openfile(string file);
};

#endif
