// tests-main.cpp
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "exercise.hpp"

TEST_CASE( "Filtering", "[filtering]" ) {
    REQUIRE( do_filtering("one hundred and one") == "101");
    REQUIRE( do_filtering("I have one hundred apples") == "I have 100 apples");    
    REQUIRE( do_filtering("I have one hundred apples and two oranges") == "I have 100 apples and 2 oranges");
    REQUIRE( do_filtering("I have one hundred apples and two oranges\ndo you want twenty apples?") == 
            "I have 100 apples and 2 oranges\ndo you want 20 apples?");
    REQUIRE( do_filtering("I have one hundred apples      and two oranges") == "I have 100 apples      and 2 oranges");
    REQUIRE( do_filtering("I have one hundred    apples and two oranges") == "I have 100    apples and 2 oranges");    
    REQUIRE( do_filtering("I have one hundred,.,.apples and two oranges") == "I have 100,.,.apples and 2 oranges");        
    REQUIRE( do_filtering("one hundred and one.........") == "101........."); 
    REQUIRE( do_filtering("one hundred and one.") == "101.");              
    REQUIRE( do_filtering("one hundred and one ") == "101 ");              
    REQUIRE( do_filtering("one hundred and one   ") == "101   ");      
    REQUIRE( do_filtering("I have one hundred apples.") == "I have 100 apples.");        
    REQUIRE( do_filtering("I have one hundred apples and two oranges.") == "I have 100 apples and 2 oranges.");    
    REQUIRE( do_filtering("one hundred and one   ") == "101   ");  
    REQUIRE( do_filtering("three billion") == "3000000000");   
    REQUIRE( do_filtering("two million three thousand nine hundred and eighty four") == "2003984"); 
    REQUIRE( do_filtering("nineteen") == "19");
    REQUIRE( do_filtering("two thousand and nineteen") == "2019");
    REQUIRE( do_filtering("two million three thousand and nineteen") == "2003019");    
    REQUIRE( do_filtering("three billion") == "3000000000");
    REQUIRE( do_filtering("three million") == "3000000"); 
    REQUIRE( do_filtering("one hundred twenty three million four hundred fifty six thousand seven hundred and eighty nine") == "123456789");
    REQUIRE( do_filtering("eleven") == "11");
    REQUIRE( do_filtering("nineteen billion and nineteen") == "19000000019");
    REQUIRE( do_filtering("one hundred and forty two") == "142");
    REQUIRE( do_filtering("112") == "112");
    REQUIRE( do_filtering("11211234") == "11211234");
    REQUIRE( do_filtering("five") == "5");
    REQUIRE( do_filtering("two million twenty three thousand and forty nine") == "2023049");    
    REQUIRE( do_filtering("do you want one hundred?") == "do you want 100?");    
    //REQUIRE( do_filtering("one hundred\n and one") == "101\n");        
    // REQUIRE( do_filtering("hundred") == "100");
    // REQUIRE( do_filtering("thousand") ==  "1000");
    // REQUIRE( do_filtering("million") == "1000000");
    // REQUIRE( do_filtering("billion") == "1000000000");
    //REQUIRE( do_filtering("one hundred thirty-five") == "135");
}

TEST_CASE( "Internal: find words", "[filtering]" ){
    Filtering *f = new Filtering();
    bool ret;
    long scale;
    int increment;

    string str = "hundred";
    tie(ret, scale, increment) =f->find_word(str);
    REQUIRE( ret == true );
    REQUIRE(scale == 100);
    REQUIRE(increment == 0);


    str = "hundredX";
    tie(ret, scale, increment) =f->find_word(str);
    REQUIRE( ret == false );
    REQUIRE(scale == -1);
    REQUIRE(increment == -1);

    delete f;
}


TEST_CASE( "Internal: split", "[filtering]" ){
    Filtering *f = new Filtering();
    bool ret;
    long scale;
    int increment;
    string token;
    string delimiter;
    string str = "One,Two.Three?Four!Five";
    
    vector<tuple<string,string>> v = f->split(str, "\n\t ,.?!:;");
 
    REQUIRE( v.size() == 5 );
    std::tie(token, delimiter) = v.at(0);
    REQUIRE( token == "One");
    REQUIRE( delimiter == ",");

    std::tie(token, delimiter) = v.at(1);
    REQUIRE( token == "Two");
    REQUIRE( delimiter == ".");

    std::tie(token, delimiter) = v.at(2);
    REQUIRE( token == "Three");
    REQUIRE( delimiter == "?");

    std::tie(token, delimiter) = v.at(3);
    REQUIRE( token == "Four");
    REQUIRE( delimiter == "!");

    std::tie(token, delimiter) = v.at(4);
    REQUIRE( token == "Five");
    REQUIRE( delimiter == "");


    delete f;
}