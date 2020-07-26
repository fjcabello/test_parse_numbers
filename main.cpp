#include "exercise.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void file_filtering(ifstream *in) {
    string line;
    Filtering *f = new Filtering();
    while ( getline (*in,line) )
        {               
            cout << f->filter(line) << '\n';
        }
    delete f;        
};

int main(int argc, char* argv[])
{   
    string line;
    string str; 
    if(argc > 1){
        ifstream myfile (argv[1]);
        if (myfile.is_open())
        {
            file_filtering(&myfile);
            myfile.close();
        }
        myfile.close();
    } else  {
        cerr << "main_app input_file\n";
    }
  return 0;
};