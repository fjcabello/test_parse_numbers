#include "exercise.hpp"

Filtering::Filtering(){           
    this->digits["zero"] = {1,0};
    this->digits["one"] = {1,1};
    this->digits["two"] = {1,2};
    this->digits["three"] = {1,3};
    this->digits["four"] = {1,4};
    this->digits["five"] = {1,5};
    this->digits["six"] = {1,6};
    this->digits["seven"] = {1,7};
    this->digits["eight"] = {1,8};
    this->digits["nine"] = {1,9};
    this->digits["ten"] = {1,10};
    this->digits["eleven"] = {1,11};
    this->digits["twelve"] = {1,12};
    this->digits["thirteen"] = {1,13};
    this->digits["fourteen"] = {1,14};
    this->digits["fifteen"] = {1,15};
    this->digits["sixteen"] = {1,16};
    this->digits["seventeen"] = {1,17};
    this->digits["eighteen"] = {1,18};
    this->digits["nineteen"] = {1,19};
    this->digits["twenty"] = {1,20};
    this->digits["thirty"] = {1,30};
    this->digits["forty"] = {1,40};
    this->digits["fifty"] = {1,50};
    this->digits["sixty"] = {1,60};
    this->digits["seventy"] = {1,70};
    this->digits["eighty"] = {1,80};
    this->digits["ninety"] = {1,90};
    this->digits["hundred"] = {100,0};
    this->digits["thousand"] = {1000,0};
    this->digits["million"] = {1000000,0};
    this->digits["billion"] = {1000000000,0};
    this->digits["trillion"] = {1000000000000,0};  
    this->digits["and"] = {1,0};
};


tuple<bool, long, int> Filtering::find_word(string &sub) {
    auto iter = digits.find(sub);
    if (iter != digits.end() ) {  
        long scale = get<0>(iter->second);
        long increment = get<1>(iter->second);
        return make_tuple(true, scale, increment);
    }
    return make_tuple(false, -1,-1);
}   

vector<tuple<string,string>> Filtering::split(const string  &str, const string & delimiters) {
    vector<tuple<string,string>> v;
    int start = 0;
    auto pos = str.find_first_of(delimiters, start);
    while(pos != string::npos) {
        string sub = str.substr(start, pos- start);
        tuple<string,string> t =  make_tuple(sub, string(1,str.at(pos)));
        //cout << "sub: " << sub << " delimiter: '" << string(1,str.at(pos)) << "'\n";
        v.push_back(t);
        start = pos + 1;
        pos = str.find_first_of(delimiters, start);
    }
    if(start < str.length()) {// ignore trailing delimiter
        string sub = str.substr(start, str.length() - start); 
        tuple<string,string> t =  make_tuple(sub, "");
        v.push_back(t); // add what's left of the string
        //cout << "sub: " << sub << " delimiter: '" << "" << "'\n";
    }
    
    return v;
}

string Filtering::filter(string &input_string){

    bool ret;
    long scale;
    int increment;
    bool number_found = false;
    string sresult = "";
    long current  = 0;
    long result = 0;
    string last_number_delimiter = "";

    vector<tuple<string,string>> v = split(input_string, "\n\t ,.?!:;");

    for(int i=0; i < v.size(); i++) {
        string token, delimiter;
        std::tie(token, delimiter) = v.at(i);
        //std::cout <<  "token:" << token << " delimiter: '"  << delimiter << "'\n";

        std::tie(ret, scale, increment) = this->find_word(token);  

        if(ret && !( 0 == token.compare("and") && !number_found ) ){
            current = current * scale + increment;
            if(scale > 100 ){
                result += current;
                current = 0;
            }  
            last_number_delimiter = delimiter;
            number_found = true;   
        } else {
            if(number_found) {                
                sresult += to_string(result+current); 
                sresult += last_number_delimiter;
                result = 0;
                current = 0;   
            }
            sresult += token;            
            sresult += delimiter;            
            number_found = false; 
        }
    }
    if(number_found) {                
        sresult += to_string(result+current); 
        sresult += last_number_delimiter;
    }
    return sresult;
}

string do_filtering(string s){
    string r;
    Filtering *f = new Filtering();
    r = f->filter(s);
    delete f;
    return r;
}

