#include "delim.h"
/////////////////////////////
// will return either 1 or 2
//-1 = error
// 2 = no error
/////////////////////////

//constructors
delim::delim(){
  //creating a stack for the brackets
  m_brack = new genstack<char>();
}
//deconstructor
delim::~delim(){
  delete m_brack;
}
//checking syntax
int delim::openFile(string fileinput){

  ifstream userfile;
  string choice = "1";
  string line;
//while the user wants a file
  while (choice[0] == '1'){
    m_brack->remove();
    userfile.open(fileinput);

    if(!userfile){
      cout << "Unable to open file" << endl;
      //exit the program if unable to open the file
      exit(1);
    }
    cout << endl;
    cout << "now checking file for proper syntax...." << endl;
    cout << endl;

    int lineNumber = 0;
    char endingbrak = '0';

    if (userfile.is_open()){
      while (!userfile.eof()){
        lineNumber++;
        getline(userfile, line);
        if (!userfile.fail()){
          for (int i = 0; i < line.size(); ++i){
            //////////////////////////////////
            //checking bracket section///////
            ////////////////////////////////
            if (i == line.size() - 1 && !m_brack->isEmpty()){
              //if missing the end paran return -1 for error
              if (m_brack->top() == '(' && !(line[i] == ')')){
                cout << "Syntax Error on line " << lineNumber <<  " Missing ')' " << endl;
                cout << endl;
                cout << "now fix your error!" << endl;
                return -1;
              }
              //if missing the end ], return -1 for error
              else if (m_brack->top() == '[' && !(line[i] == ']')){
                cout << "Syntax Error on line " << lineNumber << " Missing ']' " << endl;
                cout << endl;
                cout << "now fix your error!" << endl;
                return -1;
              }
            }
            //adding brackets onto the stack
            if (line[i] == '(' || line[i] == '[' || line[i] == '{'){
              m_brack->push(line[i]);
            }else if (line[i] == ')' || line[i] == ']' || line[i] == '}'){
              //if the bracket stack is empty, means that there is an unwanted bracket
              if (m_brack->isEmpty()){
                cout << "Syntax Error on line: " << lineNumber << endl;
                cout << "Extra '" << line[i] << "'"<<endl;
                cout << endl;
                cout << "now fix your error!" << endl;
                return -1;
              }else{
                //if ending paran is not found, return an error
                if (m_brack->top() == '(' && line[i] != ')'){
                  cout << "Syntax Error on line: " << lineNumber << endl;
                  cout << "Missing ) , found '" << line[i] << "' ." << endl;
                  cout << endl;
                  cout << "now fix your error!" << endl;
                  return -1;
                }
                //same but for ]
                else if (m_brack->top() == '[' && line[i] != ']'){
                  cout << "Syntax Error on line: " << lineNumber << endl;
                  cout << "Missing ] , found '" << line[i] << "' ." << endl;
                  cout << endl;
                  cout << "now fix your error!" << endl;
                  return -1;
                }
                //same but for }
                else if (m_brack->top() == '{' && line[i] != '}'){
                  cout << "Syntax Error on line: " << lineNumber << endl;
                  cout << "Missing } , found '" << line[i] << "' ." << endl;
                  cout << endl;
                  cout << "now fix your error!" << endl;
                  return -1;
                }
                m_brack->pop();
              }
            }
            endingbrak = line[i];
          }
        }
      } // ending brak for while look while going over the sourcecode
      //now checking the stack
      if (m_brack->isEmpty()){
        // if no leftover brackets ...
        cout << "Congrats! your code is error free! No syntax errors found. " << endl;
        cout << endl;
        // will return 2 at the end of the class
      }else{
        // if left over brackets, will say what they expected
        if (m_brack->top() == '(') {
          cout << "Syntax Error on line: " << lineNumber << endl;
          cout << "Expecting a ')'" << endl;
          cout << endl;
          cout << "now fix your error!" << endl;
          cout << endl;
          return -1;
          // if left over brackets, will say what they expected
        }else if (m_brack->top() == '[')  {
          cout << "Syntax Error on line: " << lineNumber << endl;
          cout << "Expecting a ']' " << endl;
          cout << endl;
          cout << "now fix your error!" << endl;
          cout << endl;
          return -1;
          // if left over brackets, will say what they expected
        }  else if (m_brack->top() == '{'){
          cout << "Syntax Error on line: " << lineNumber << endl;
          cout << "Expecting a '}' " << endl;
          cout << endl;
          cout << "now fix your error!" << endl;
          cout << endl;
          return -1;
        }
      }
    }else {
      cout << "File not found" << endl;
    }
    userfile.close();
    //asking user if they want to check another file
    cout << "Want to check another file? [yes = 1 , no = 2] : ";
    cin >> choice;
    while (choice[0] != '1' && choice[0] != '2'){
      cout << "Incorrect input! Please enter '1' or '2'. " << endl;
      cout << "Want to check another file? [1/2] :" << endl;
      cin >> choice;
    }
    //starting the while loop again
    if (choice[0] == '1'){
      cout << "welcome to the syntax checker!" << endl;
      cout << "Please enter the file name : ";
      cin >> fileinput;
      cout << endl;
    }
    }
    //else exit out
  return 2;
}
//////
//have left: got to account for the other brackets, {} and []
// have to make sure error line is outputting the right LINE
// basically check to see if it output works once it actyally compiles
//                       // meaning the expected bracket is the wrong type.
//                       char result;
//                       char expected;
//                       result = genstack.peek();
//
//                       // checking what the actual bracket shouldve been.
//                       if(result == '('){
//                         expected = ')';
//                       }
//                       else if(result == '{'){
//                         expected = '}';
//                       }
//                       else if(result == '['){
//                         expected = ']';
//                       }
//                       else if(result == ')'){
//                         expected = '(';
//                       }
//                       else if(result == '}'){
//                         expected = '{';
//                       }
//                       else if(result == ']'){
//                         expected = '[';
//                       }
//           						cout << "SYNTAX ERROR ON LINE: "<< errorline << "expected/missing bracket: " << expected << endl;  //wrong matching bracket
//                       error = true;
