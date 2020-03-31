#include <iostream>
#include <fstream>
#include <string>
//#include "genstack.h"
#include "delim.h"

using namespace std;

bool error = false;

int delim::openfile(string file){

  string fileName = file;
  ifstream inputFile;

  inputFile.open(fileName);
      if (!inputFile) {
       cout << "Unable to open file .cpp" << endl;
       //return false;
       exit(1); //exit the program
      }

  cout << "this the correct input for a file. Now checking file for proper syntax..." << endl;

////////////////////////////////
//checking brackets section//
//////////////////////////////

  string line;
  int Brakline = 0;
  int errorline = 0;

  while(getline(inputFile,line)){
      bool commentline = false;
      bool sline = false;
      // this is to skip if it is a comment and not get confused
    for(int i= 0; i < line.length(); i++){
      char character = line[i];
      //checkign if its a comment
        if(character == '/'){
          commentline = true;
        }
        if(character == '"' && sline == false){
          //opening the string
          sline = true;
        }
			  else if (character == '"' && sline == true){
          //closing the string
          sline = false;
        }
        //so if comment is false, then the line is not a comment and we can do some WERK on that fella
        if (commentline == false && sline== false){

              // if the character = a beginning bracket then we will push the bracket onto the stack
              if (character == '(' || character  == '{' || character  == '['){
    					genstack.push(character);
              // potentioally making the open bracket line the error line if there is no corresponding line
    					Brakline = errorline;
            }//end of ( if

              //have to check each ending bracket separetly
              else if(character == ')'){

                //if the stack is empty, this is a syntax error. will set error as true and return the line with error
                if (genstack.isEmpty()){
          						error = true;
                      //returning the entire line with the error.
          						cout <<  "SYNTAX ERROR ON LINE: "<< errorline << endl; // no matching bracket
    					  }

      					if (genstack.peek() != ')'){
                      // meaning the expected bracket is the wrong type.
                      char result;
                      char expected;
                      result = genstack.peek();

                      // checking what the actual bracket shouldve been.
                      if(result == '('){
                        expected = ')';
                      }
                      else if(result == '{'){
                        expected = '}';
                      }
                      else if(result == '['){
                        expected = ']';
                      }
                      else if(result == ')'){
                        expected = '(';
                      }
                      else if(result == '}'){
                        expected = '{';
                      }
                      else if(result == ']'){
                        expected = '[';
                      }
          						cout << "SYNTAX ERROR ON LINE: "<< errorline << endl;  //wrong matching bracket
                      error = true;
      					}
    					  genstack.pop();
              }// end of ) if


        }// end of big if maybe??
    }// end of for loop
}//end of while loop

  inputFile.close();
//   //return true;
return 1;
}


//constructors
delim::delim(){}
delim::~delim(){}
