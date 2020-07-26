#ifndef __EXERCISE_HPP
#define __EXERCISE_HPP

#include <iostream>
#include <string>
#include <map>
#include <tuple> 
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

string do_filtering(string s);

class Filtering {
      
    public:        
        Filtering();    
        string filter(string &s);
        // split and find_words should be private, but I made it public to simplify utest    
        vector<tuple<string,string>> split(const string  &str, const string & delimiters);        
        tuple<bool, long, int> find_word(string &sub);

    private:
    // Private methods
        map<string, tuple<long,int>> digits;         
};

#endif