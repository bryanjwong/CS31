//
//  array.cpp
//  array
//
//  Created by Bryan Wong on 2/4/19.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <string>
using namespace std;

bool hasDuplicates( const std::string array[ ],  int size );
int  countAllDigits( const std::string array[ ] , int size );
bool isInDecreasingOrder( const std::string array[ ], int size );
int  shiftRight( std::string array[ ], int size, int amount, std::string placeholder );
int  find( const std::string array[ ], int size, std::string match );
int  replaceAllCharacters( std::string array[ ], int size, char findLetter, char replaceLetter );

int main() {
    
    string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
    
    string folks[8] = {
        "samwell", "jon", "margaery", "daenerys",
        "tyrion", "sansa", "howard123", "jon"
    };
    
    string folks2[8] = {
        "samwell", "jon", "margaery", "daenerys",
        "tyrion", "sansa", "howard123", "jon"
    };
    
    string morefolks[8] = {
        "samwell", "jon", "margaery", "daenerys",
        "tyrion", "sansa", "howard123", "jon"
    };
    
    string nums[5] = { "1", "24", "eat12", "ligma", "11"};
    
    string letters[5] = { "z", "y", "x", "w"};
    
    assert(hasDuplicates(a, -1 ) == false);
    assert(hasDuplicates(a, 0 ) == false);
    assert(hasDuplicates(a, 1 ) == false);
    assert(hasDuplicates(a, 2 ) == false);
    assert(hasDuplicates(a, 3 ) == false);
    assert(hasDuplicates(a, 4 ) == true);
    assert(hasDuplicates(a, 5 ) == true);
    assert(hasDuplicates(a, 6 ) == true);
    assert(hasDuplicates(folks, 8 ) == true);
    assert(hasDuplicates(folks, 1 ) == false);
    
    assert(countAllDigits( folks, 8 ) == 3);
    assert(countAllDigits( folks, -10 ) == -1);
    assert(countAllDigits( folks, 0 ) == -1);
    assert(countAllDigits( folks, 3 ) == 0);
    
    assert(countAllDigits( nums, 1 ) == 1);
    assert(countAllDigits( nums, 2 ) == 3);
    assert(countAllDigits( nums, 3 ) == 5);
    assert(countAllDigits( nums, 4 ) == 5);
    assert(countAllDigits( nums, 5 ) == 7);
    
    assert(isInDecreasingOrder( folks, -1) == false);
    assert(isInDecreasingOrder( folks, 0) == true);
    assert(isInDecreasingOrder( folks, 1) == true);
    assert(isInDecreasingOrder( folks, 2) == true);
    assert(isInDecreasingOrder( folks, 3) == false);
    assert(isInDecreasingOrder( folks, 8) == false);
    assert(isInDecreasingOrder( a, 3) == false);
    assert(isInDecreasingOrder( a, 4) == false);
    assert(isInDecreasingOrder( letters, 4) == true);
    
    assert(find( folks, 5, "foo" ) == -1);
    assert(find( folks, 5, "jon" ) == 1);
    assert(find( folks, 8, "jon" ) == 1);
    assert(find( folks, -1, "jon" ) == -1);
    assert(find( folks, 0, "jon" ) == -1);
    assert(find( folks, 5, "daenerys" ) == 3);
    assert(find( folks, 5, "daene" ) == -1);
    assert(find( folks, 8, "" ) == -1);
    assert(find( folks, 8, "ligma" ) == -1);
    
    assert(shiftRight(folks, 8, 100, "yo gabba gabba") == 8);
    assert(shiftRight(folks, 8, -1, "yo gabba gabba") == -1);
    assert(shiftRight(folks, -1, 5, "yo gabba gabba") == -1);
    assert(shiftRight(folks, 0, 5, "yo gabba gabba") == 0);
    assert(shiftRight(folks, 8, 0, "yo gabba gabba") == 0);
    assert(shiftRight(folks, 0, 0, "yo gabba gabba") == 0);
    assert(shiftRight(folks, 8, 1, "yo gabba gabba") == 1);
    assert(shiftRight(folks, 8, 2, "yo gabba gabba") == 2);
    assert(shiftRight(folks, 8, 3, "yo gabba gabba") == 3);
    assert(shiftRight(folks, 8, 4, "yo gabba gabba") == 4);
    assert(shiftRight(folks, 8, 8, "yo gabba gabba") == 8);
    assert(shiftRight(folks, 8, 2, "") == 2);
    
    assert(replaceAllCharacters(folks2, 8, ':', 'A') == 0);
    assert(replaceAllCharacters(folks2, -1, 'a', '_') == -1);
    assert(replaceAllCharacters(folks2, -5, 'a', '_') == -1);
    assert(replaceAllCharacters(folks2, 0, 'a', '_') == -1);
    assert(replaceAllCharacters(folks2, 1, 'a', '_') == 1);
    assert(replaceAllCharacters(folks2, 8, 'e', '_') == 4);
    assert(replaceAllCharacters(folks2, 8, '&', '_') == 0);
    

    cout << "All tests succeeded" << endl;
    
    int n = shiftRight(morefolks, 8, 3, "placeholder");
    cout << "# of placeholders used: " << n << endl;
//
//    int m = replaceAllCharacters(morefolks, 8, 'a', '_');
//    cout << "# of char replacements made: " << m << endl;
//
    for(int i = 0; i < 8; i++){
        cout << "index " << i << " has: " << morefolks[i] << endl;
    }
    

    int i = hasDuplicates( folks, 5 );  // should return 0
    cout << "i is: " << i << endl;
    
    return 0;
}

/*----------------------------------------------*/

//Returns true when an element in the array is found more than once; false otherwise or if there are no elements because size is less than or equal to zero.  For example, for the array folks[ 8 ] show above, hasDuplicates( folks, 5 ) should return false.  hasDuplicates( folks, -1 ) should also return false.  hasDuplicates( folks, 8 ) should return true.
bool hasDuplicates( const std::string array[ ],  int size ) {
    if(size <= 0) // returns false if size is less than or equal to 0
        return false;
    
    bool dupeFound = false; // boolean flag for duplicates found is set to false by default
    
    for(int i = 0; i < size; i++) { // first for loop runs through each value of the array at the specified size once
        
        for(int j = 0; j < size; j++) { // second loop compares all values in array to the value at index i, searching for duplicates
            
            if(i != j) { // if i and j are at the same index, the values inside the array will obviously be the same. We must exclude this case.
                
                if(array[j] == array[i]) // duplicate value is found
                    dupeFound = true;
                
            }

        }
        
    }
    
    return dupeFound;
    
}

/*----------------------------------------------*/

//Returns the total number of digit characters (that is, the characters '0' - '9') found in all the elements of the passed array argument.  Return -1 if there are no elements because size is less than or equal to zero.  For example, for the array people[ 5 ] show above, countAllDigits( folks, 8 ) should return 3.    countAllDigits( folks, -108 ) should return -1.
int  countAllDigits( const std::string array[ ] , int size ) {
    if(size <= 0) // returns -1 if size is less than or equal to 0
        return -1;
    
    int numDigits = 0; // counter for total number of digits inside strings in the array
    
    for(int i = 0; i < size; i++) {
        string currentString = array[i]; // sets current string to whatever string is in index i of the array
        
        for(int j = 0; j < currentString.length(); j++) { // run through each character in the string we are looking at
            if(currentString[j] >= '0' && currentString[j] <= '9') // if the character in the string at index j is a digit, increment the counter
                numDigits++;
        }
    }
    
    return numDigits;
}

/*----------------------------------------------*/

//If every value in the array is smaller than the one that precedes it, return true; otherwise return false or if size is less than zero return false .  For example, for the array people[ 5 ] shown above, isInDecreasingOrder( people, 5 )  should return false.  When passed an array of size 0 or 1, isInIncreasingOrder( ... ) will return true, since the function will not find a pair of values that fail to meet its ordering criteria.
bool isInDecreasingOrder( const std::string array[ ], int size ) {
    if(size < 0) // if size is negative, return false
        return false;
    
    if(size == 0 || size == 1) // if size is 0 or 1, return true because the program can't find a pair of values to fail its criteria
        return true;
    
    bool followsCondition = true; // boolean flag for the values being in decreasing order is set to true by default
    
    for(int i = 1; i < size; i++) { // we start at index 1, because the array must be at least size 2 to make it to this point
    
        if(array[i] > array[i-1]) // we know i-1 will always be in bounds, because i starts at 1
            followsCondition = false;
        
    }
    return followsCondition;
}

/*----------------------------------------------*/

//Adjust the items found in the array, shifting each value to the right by amount parameter, filling the resulting first amount elements of the array with the placeholder parameter and returning the number of times the placeholder value was used after all the shifting has been performed or -1 if the size or amount is less than zero.  For example,  for the array people[ 5 ]  shown above,  shiftRight( people, 5, 3, "foo" )  should return 3 and adjust the array to have the values { "foo", "foo", "foo", "samwell", "jon" };    shiftRight( people, -5, 3, "foo" )   should return -1.  shiftRight( people, 5, 25, "foo" ) should return 5 and adjust the array to have the values  { "foo", "foo", "foo", "foo", "foo" };

// Following code broke on g31 due to using variable size array

//int  shiftRight( std::string array[ ], int size, int amount, std::string placeholder ) {
//    if(size < 0 || amount < 0) // if size or amount is negative, return -1
//        return -1;
//
//    int placeholderUseCount = 0; // counter for how many times placeholder is used
//    string temp[size];
//
//    for(int i = 0; i < size; i++) { // copy values in array[ ] to a new array
//        temp[i] = array[i];
//    }
//
//    int index = 0; // index marker for original array
//
//    while(index < size && index < amount) { // original array's first [amount] digits are replaced with the placeholder. This continues
//                                            // until all placeholders are placed or we reach the end of the array, whichever comes first.
//        array[index] = placeholder;
//        placeholderUseCount++; // counter is incremented
//        index++;
//
//    }
//
//    int index2 = 0; // index marker for copied array
//
//    while(index < size) { // remaining spots in the original array are filled with original values, until it is full
//
//        array[index] = temp[index2]; // values in temp array copy are copied back into the original array, but shifted
//        index++;
//        index2++;
//
//    }
//
//    return placeholderUseCount;
//}

int  shiftRight( std::string array[ ], int size, int amount, std::string placeholder ) {
    if(size < 0 || amount < 0) // if size or amount is negative, return -1
        return -1;
    
    for(int i = 0; i < amount && i < size; i++) { // we will need to shift the values over [amount] times
                                                  // if amount requested is larger than size, this measure ensures that the shifting algorithm isnt used too many times
        
        for(int j = size - 1; j > i; j--) { // value at j is changed into the value at j-1, until j reaches index i
            array[j] = array[j-1];
        }
        
    }
    
     int placeholderUseCount = 0; // how many times placeholder is used
    
    for(int k = 0; k < amount && k < size; k++) { // replace first [amount] indexes with the placeholder, or until all indexes are full, whichever comes first
        array[k] = placeholder;
        placeholderUseCount++;
    }

    return placeholderUseCount;
}

/*----------------------------------------------*/

//Return the smallest index of the element whose value equals the match parameter in the array.  Return -1 if the item was not found or there are no elements because size is less than zero.  For example, for the array folks[ 8 ] shown above, find( folks, 5, "foo" ) should return the value -1, since "foo" was not found.  find( folks, -500, "foo" ) should also return -1.  find( folks, 8, "jon" ) should return 1.
int  find( const std::string array[ ], int size, std::string match ) {
    if(size <= 0) // if size is zero or negative, return false. If the size is zero, it's impossible to find the match.
        return -1;
    
    for(int i = 0; i < size; i++) {
       
        if(array[i] == match) // if the string in array[ ] at index i is the same as the target match, return that index. Since we go from smallest to largest
            return i;         // index, the first occurence index will be returned.
        
    }
    
    return -1; // if no match is found, return -1
}


/*----------------------------------------------*/

//This function should replace every occurrence of the findLetter value with the replaceLetter value found in all the array elements of the passed array argument.  Return the number of letters that were replaced or -1 if the array has no elements because size is less than or equal to zero.  For example, for the array  people[ 5 ]  shown above,  replaceAllCharacters( people, 5, 'z', 'a' )  should return 0 and the array elements should all be unchanged.   replaceAllCharacters( people, -5, 'z', 'a' )  should return -1.  replaceAllCharacaters( people, 5, 'a', '_' ) should return 4 and the array parameter should be changed to:   { "s_mwell", "jon", "m_rg_ery", "d_enerys", "tyrion" };
int  replaceAllCharacters( std::string array[ ], int size, char findLetter, char replaceLetter ) {
    if(size <= 0) // if size is zero or negative, return -1.
        return -1;
    
    int replaceCount = 0;
    
    for(int i = 0; i < size; i++) { // run through each string in the array
        
        for(int j = 0; j < array[i].length(); j++) { // run through each character in the string
           
            if(array[i].at(j) == findLetter) { // if any charaacter in the string matches findLetter, replace it with replaceLetter and increment the counter
                array[i].at(j) = replaceLetter;
                replaceCount++;
            }
        }
        
    }
    
    return replaceCount;
}

