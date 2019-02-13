//
//  cencept2.cpp
//  concept2
//
//  Created by Bryan Wong on 1/25/19.
//  Copyright © 2019 Bryan Wong. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isValidRowerString(string rowerString);
bool validTime(string rowerString, int position);
bool validStrokeRate(string rowerString, int position);
bool validDistance(string rowerString, int position);
bool validHeartRate(string rowerString, int position);

int totalDistance(string rowerString);
int heartRate(string rowerString);
int strokesPerMinute(string rowerString);
int elapsedMinutes(string rowerString);
int elapsedSeconds(string rowerString);

/*----------------------------------------------*/

int main() {
    
    // Provided Test Cases
    assert(isValidRowerString(":14    28 s/m     42 m    110"));
    assert(isValidRowerString("          :14         28 s/m         42 m      110"));
    assert(isValidRowerString("1:14    28 s/m     42 m    110"));
    assert(isValidRowerString("59:14     28 s/m     42 m    110"));
    assert(isValidRowerString("59:59    28 s/m     42 m    110"));
    assert(isValidRowerString("59:59    999 s/m     42 m    110"));
    assert(isValidRowerString("59:59    999 s/m     42 m    999"));
    assert( ! isValidRowerString("asdf:14    28 s/m     42 m    110"));
    assert( ! isValidRowerString(":14    28 s/m     42 m    110 asdf"));
    assert( ! isValidRowerString(":14     28       s/m    42 m    110"));
    assert( ! isValidRowerString("0:14    28 s/m     42 m    110"));
    assert( ! isValidRowerString("0000:14    00028 s/m     00042 m   000110"));
    assert( ! isValidRowerString(":-14    -28 s/m     -42 m   -110"));
    assert( ! isValidRowerString("555:14    28 s/m    42 m   110"));
    assert( ! isValidRowerString(":555      28 s/m      42 m  110"));
    assert( ! isValidRowerString(":14    99123 s/m    42 m   110"));
    assert( ! isValidRowerString(":14    0 s/m            42 m   110"));
    assert( ! isValidRowerString(":14    28 s/m         42 m   99123"));
    assert( ! isValidRowerString(":14    28 s/m         42 m   0"));
    
    // Self Test Cases
    assert(isValidRowerString(" 11:11 1 s/m 1 m 1"));
    assert(isValidRowerString("11:11    1 s/m 1 m 1"));
    assert(isValidRowerString("11:11 1 s/m  1 m 1"));
    assert(isValidRowerString("11:11 1 s/m 1 m  1"));
    assert(isValidRowerString(" 11:11       1 s/m   1 m     1"));
    assert(isValidRowerString(":11 1 s/m 1 m 1"));
    assert(isValidRowerString("1:11 1 s/m 1 m 1"));
    assert(isValidRowerString(":00 1 s/m 1 m 1"));
    assert(isValidRowerString(":00 1 s/m 111 m 1"));
    assert(isValidRowerString(":00 1 s/m 9999 m 1"));
    assert(isValidRowerString(":00 1 s/m 9999999 m 1"));
    assert(isValidRowerString(":00 1 s/m 999 m 999"));
    assert(isValidRowerString("59:59 999 s/m 999999 m 999"));
    assert(isValidRowerString(":59 999 s/m 999999 m 999"));
    assert( ! isValidRowerString("11:11 1 s/m 0 m 1"));
    assert( ! isValidRowerString(":11 1 s/m 1 m 1 "));
    assert( ! isValidRowerString(":59 9999 s/m 999999 m 999"));
    assert( ! isValidRowerString(":59 999 s/m 999999 m 9999"));
    assert( ! isValidRowerString("11:11 1 s /m 0 m 1"));
    assert( ! isValidRowerString("11:   11 1 s/m 0 m 1"));
    assert( ! isValidRowerString("1 s/m 1 m 1"));
    assert( ! isValidRowerString("11:11 1 s/m 1"));
    assert( ! isValidRowerString("11:11 1 m 1"));
    assert( ! isValidRowerString("11:11 1 s/m 1 m"));
    assert( ! isValidRowerString("11:11 1 s/m 1 1"));
    assert( ! isValidRowerString("11:11 1 s/m 1 m -1"));
    assert( ! isValidRowerString("11:11 1 s/m 1 m 0"));
    assert( ! isValidRowerString("11:11 1 s/m 09 m 1"));
    assert( ! isValidRowerString("11:11 1 s/m -1 m 1"));
    assert( ! isValidRowerString("11:11 -1 s/m 1 m 1"));
    assert( ! isValidRowerString("11:11 1 m 1 m 1 "));
    assert( ! isValidRowerString("11:11 01 s/m 1 m 1"));
    assert( ! isValidRowerString("11:11 1000 s/m 1 m 1"));
    assert( ! isValidRowerString("11:11 1 s m 1 m 1"));
    assert( ! isValidRowerString("11:11 1 s/ 1 m 1"));
    assert( ! isValidRowerString("11:11 0 s/m 1 m 1"));
    assert( ! isValidRowerString("11:11 1s/m 1 m 1"));
    assert( ! isValidRowerString(":: 1 s/m 1 m 1"));
    assert( ! isValidRowerString(":111 1 s/m 1 m 1"));
    assert( ! isValidRowerString("111:12 1 s/m 1 m 1"));
    assert( ! isValidRowerString("1 s/m 1 m 1"));
    assert( ! isValidRowerString(": 1 s/m 1 m 1"));
    assert( ! isValidRowerString(":60 1 s/m 1 m 1"));
    assert( ! isValidRowerString("60:00 1 s/m 1 m 1"));
    assert( ! isValidRowerString("00:00 1 s/m 1 m 1"));
    assert( ! isValidRowerString("0:00 1 s/m 1 m 1"));
    assert( ! isValidRowerString("9:0a    56 s/m   42 m   110"));
    assert( ! isValidRowerString("9:00    5a6 s/m   42 m   110"));
    assert( ! isValidRowerString("9:00    56 s/m   4a2 m   110"));
    assert( ! isValidRowerString("9:00    56 s/m   42 m   1a0"));
    assert( ! isValidRowerString("0000:14    28 s/m     42 m   110"));
    assert( ! isValidRowerString("00:14    00028 s/m     42 m   110"));
    assert( ! isValidRowerString("00:14    28 s/m     00042 m   110"));
    assert( ! isValidRowerString("00:14    28 s/m     42 m   00110"));
    assert( ! isValidRowerString("11:1 1 s/m 1 m 1"));
    assert( ! isValidRowerString("11:11 1  s/m 1 m 1"));
    assert( ! isValidRowerString("11:11 1 s/m 1  m 1"));
    assert( ! isValidRowerString("14    28 s/m     42 m    110"));
    assert( ! isValidRowerString("10:14    28     42 m    110"));
    assert( ! isValidRowerString("10:14    28 s/m     42    110"));
    assert( ! isValidRowerString("28 s/m   10:14    42 m    110"));
    assert( ! isValidRowerString(""));
    assert( ! isValidRowerString(""));
    assert( ! isValidRowerString(" "));
    assert( ! isValidRowerString(""));

    
    cerr << "All tests succeeded" << endl;
    
    while(true){
        string input;
        
        cout << "Input a valid time: ";
        getline(cin, input);
        
        if(isValidRowerString(input))
            cout << "Rower String is Valid" << endl;
        else cout << "Rower String is Invalid" << endl << endl;
        
        cout << endl << "Minutes: " << elapsedMinutes(input) << endl;
        cout << "Seconds: " << elapsedSeconds(input) << endl;
        cout << "Stroke Rate: " << strokesPerMinute(input) << endl;
        cout << "Total Distance: " << totalDistance(input) << endl;
        cout << "Heart Rate: " << heartRate(input) << endl << endl;
    }
    return 0;
}

/*----------------------------------------------*/

// This function returns true if its parameter is a well-formed rower string as described above, or  false otherwise.
// Spaces MUST be present between each parameter
bool isValidRowerString(string rowerString) {
    
    int i = 0;
    bool firstConditionFulfilled = false;
    int j = 0;
    bool secondConditionFulfilled = false;
    int k = 0;
    bool thirdConditionFulfilled = false;
    int l = 0;
    
    while(i < rowerString.length() && !firstConditionFulfilled) { // First Condition Checked - Time Elapsed
    
        // if character is not space, continue
        if(rowerString[i] != ' '){
            //return validTime(rowerString, i);
            if(validTime(rowerString, i)) { //if first test is passed, locate the next space
                while(rowerString[i] != ' ' && i < rowerString.length()) {
                    i++;
                }
                
                while(rowerString[i] == ' ' && i < rowerString.length()) { //locate the next nonspace character
                    i++;
                }
                
                if(i >= rowerString.size()) // if index does not exist in string, return false
                    return false;
                
                j = i; // location of next parameter is found and its index is stored in j
                firstConditionFulfilled = true;

            } else return false;
        }
        else i++;
        
    }

    while(j < rowerString.length() && !secondConditionFulfilled) { // Second Condition Checked - Stroke Rate
  
        if(validStrokeRate(rowerString, j)) { //if second test is passed, locate the index of the 'm' at the end of the stroke rate
            while(rowerString[j] != 'm' && j < rowerString.length()) {
                j++;
            }
            
            if(j == rowerString.size() - 1) // check that we are not at last character
                return false;
            
            j++; // increment once to hit the spaces
            
            while(rowerString[j] == ' ' && j < rowerString.length()) { //locate the next nonspace character
                j++;
            }
            
            if(j >= rowerString.size()) // if index does not exist in string, return false
                return false;
            
            k = j; // location of next parameter is found and its index is stored in k
            secondConditionFulfilled = true;
            
        } else return false;
     
    }
    
    while(k < rowerString.length() && !thirdConditionFulfilled) { // Third Condition Checked - Distance
        
        if(validDistance(rowerString, k)) { // if third test passed, locate the index of the next parameter
            
            while(rowerString[k] != 'm' && k < rowerString.size()) { // skip to the 'm' in the distance
                k++;
            }
            
            if(k >= rowerString.size() - 1) { // check that we are not at last character
                return false;
            }
            
            k++; // increment once to hit the spaces
            
            while(rowerString[k] == ' ' && k < rowerString.size()) {
                k++;
            }
            
            if(k >= rowerString.size()) // if index does not exist in string, return false
                return false;
            
            l = k; // location of next parameter is found and its index is stored in l
            thirdConditionFulfilled = true;
            
        } else return false;
    }
    
    if(validHeartRate(rowerString, l)) { // Fourth Condition Checked - Heart Rate
        
        //    cerr << endl << "Time Spent Rowing: " << rowerString.substr(0,i) << endl;
        //    cerr << "Stroke Rate: " << rowerString.substr(i,j-i) << endl;
        //    cerr << "Distance Traveled: " << rowerString.substr(j,k-j) << endl;
        //    cerr << "Heart Rate: " << rowerString.substr(l,rowerString.size() - l) << endl;
        return true;
        
    } else return false;
    
    return false;
}

/*----------------------------------------------*/

// This function receives a string and the index of its first nonspace character. Returns true if the first part of the string is a valid time, otherwise return false
bool validTime(string rowerString, int position) {
    if(rowerString[position] >= 49 && rowerString[position] <= 58) {  // if ASCII value corresponds to digit 1-9 or :, continue
       
        if ( rowerString[position] == 58 ) {   // first character is a :
            
            if(rowerString.size() < (position + 3)) // if string isn't long enough to contain :XX, test failed
                return false;
            
            if(rowerString.size() >= (position + 4) && rowerString[position + 3] != ' ') // if string is longer than :XX, check that next char
                return false;                                                            // is a space
            
            if(rowerString[position + 1] >= 48 && rowerString[position + 1] <= 53 && rowerString[position + 2] >= 48
               && rowerString[position + 2] <= 57) // digit after : must be 0-5, digit 2 after : must be 0-9
                return true;
            
            return false; // if last condition isn't met, return false
            
        }
        
        else { // first character is not a :
            if(rowerString[position] >= 54 ) { // if first digit is 6-9,
                
                if(rowerString.size() < (position + 4)) // if string isn't long enough to contain X:XX, test failed
                    return false;
                
                if(rowerString[position + 1] != ':') // if the character after is not a ':', test is failed
                    return false;
                
                if(rowerString.size() >= (position + 5) && rowerString[position + 4] != ' ') // if string is longer than X:XX, check that next char
                    return false;                                                            // is a space
                
                if(rowerString[position + 2] >= 48 && rowerString[position + 2] <= 53 && rowerString[position + 3] >= 48
                   && rowerString[position + 3] <= 57) // digit after : must be 0-5, digit 2 after : must be 0-9
                    return true;
                
                return false; // if last condition isn't met return false
            }
            
            else { // we know first digit is 1-5, we check if next characters are valid
                
                if(rowerString.size() <= position + 1) // if the string ends at the first digit, test is failed
                    return false;
                
                if(rowerString[position + 1] == ':') {// time should be in the form X:XX
                   
                    if(rowerString.size() < (position + 4)) // if string isn't long enough to contain X:XX, test failed
                        return false;
                    
                    if(rowerString.size() >= (position + 5) && rowerString[position + 4] != ' ') // if string is longer than X:XX, check that next
                        return false;                                                            // char is a space
                    
                    if(rowerString[position + 2] >= 48 && rowerString[position + 2] <= 53 && rowerString[position + 3] >= 48
                       && rowerString[position + 3] <= 57) // digit after : must be 0-5, digit 2 after : must be 0-9
                        return true;
                    
                    return false; // if last condition isn't met return false
                }
                else // time should be in the form XX:XX
                {
                    if(!(rowerString[position + 1] >= 48 && rowerString[position + 1] <= 57)) // digit after X must be 0-9
                        return false;
                    
                    if(rowerString.size() < (position + 5)) // if string isn't long enough to contain XX:XX, test failed
                        return false;
                
                    if(rowerString[position + 2] != ':') // if the character after is not a ':', test is failed
                        return false;
                    
                    if(rowerString.size() >= (position + 6) && rowerString[position + 5] != ' ') // if string is longer than XX:XX, check that next
                        return false;                                                            // char is a space
                    
                    if(rowerString[position + 3] >= 48 && rowerString[position + 3] <= 53 && rowerString[position + 4] >= 48
                       && rowerString[position + 4] <= 57) // digit after : must be 0-5, digit 2 after : must be 0-9
                        return true;
                    
                    return false; // if last condition isn't met return false
                }
                
            }
        }

    }
    return false; // any other exceptions will be returned false
}

/*----------------------------------------------*/

// This function receives a string and the index of its first character for rowing rate. Returns true if the rowing time is valid, otherwise return false
bool validStrokeRate(string rowerString, int position) {
    
    if(rowerString[position] >= 49 && rowerString[position] <= 57 && rowerString.size() >= (position + 5)) { // check that first digit is 1-9, and that there is at least enough space in the string to include X s/m
        
        if(rowerString[position + 1] == ' ') { // recognized that stroke rate should be in format X s/m
            
            if(rowerString[position + 2] == 's' && rowerString[position + 3] == '/' && rowerString[position + 4] == 'm') {
                
                if(rowerString.size() >= position + 6 && rowerString[position + 5] != ' ') { // if there is an extra nonspace character, return false
                    return false;
                    
                } else return true; // test passed
                
            } else return false;
            
        }
        
        if(rowerString[position + 1] >= 48 && rowerString[position + 1] <= 57 && rowerString.size() >= (position + 6)) { //check that second digit is 0-9, and there is enough space in the string to include XX s/m
            
            if(rowerString[position + 2] == ' ') { // recognized that stroke rate should be in format XX s/m
                
                if(rowerString[position + 3] == 's' && rowerString[position + 4] == '/' && rowerString[position + 5] == 'm') {
                    
                    if(rowerString.size() >= position + 7 && rowerString[position + 6] != ' ') { // if there is an extra nonspace character, return false
                        return false;
                        
                    } else return true; // test passed
                    
                } else return false;
                
            } // recognized that stroke rate should be in format XXX s/m
                
            if(rowerString[position + 2] >= 48 && rowerString[position + 2] <= 57 && rowerString.size() >= (position + 7))  {// check that third digit is 0-9, and there is enough space for XXX s/m
            
                if(rowerString[position + 3] == ' ' && rowerString[position + 4] == 's' && rowerString[position + 5] == '/' && rowerString[position + 6] == 'm') {
                    
                    if(rowerString.size() >= position + 8 && rowerString[position + 7] != ' ') { // if there is an extra nonspace character, return false
                        return false;
                        
                    } else return true; // test passed
                    
                } else return false;
                
            } else return false;
            
        } else return false;
        
    } else return false;
    
    return false;
}

/*----------------------------------------------*/

// returns true if string starting at index position is a valid distance traveled
bool validDistance(string rowerString, int position) {
    
    if(rowerString[position] >= 49 && rowerString[position] <= 57 && rowerString.size() >= (position + 3)) { // check that first digit is from 1-9
        
        if(rowerString[position + 1] == ' ' && rowerString[position + 2] == 'm') {// single digit distance
            
            if(rowerString.size() >= position + 4 && rowerString[position + 3] != ' ') { // if there is a nonspace digit after the 'm', then return false;
                return false;
            
            } else return true;
            
        }

        int i = position + 1; // i begins at the second digit
        while(rowerString[i] != ' ' && i < rowerString.size()) {
            
            if(!(rowerString[i] >= 48 && rowerString[i] <= 57)){ // if any of the digits is NOT 0-9, return false
                return false;
            }
            
            i++;
        }
        
        // i should now be index of the space
        if(rowerString[i] == ' ' && rowerString[i+1] == 'm' && rowerString.size() >= i+2) {
            
            if(rowerString.size() >= i+3 && rowerString[i+2] != ' ') { // if the digit after 'm' is nonspace, return false
                return false;
            }
            
            return true; // test passed
            
        } else return false;
           
    } else return false;
    
    return false;
}

/*----------------------------------------------*/


// returns true if string starting at given index "position" is a valid three-digit heart rate. No additional characters, including spaces, allowed after the heart rate
bool validHeartRate(string rowerString, int position) {
    
    if(rowerString.size() == position + 1) { // heart rate is in single digits
        
        if(rowerString[position] >= 49 && rowerString[position] <= 57) { // if heart rate is between 1-9, return true
            return true;
            
        } else return false;
    }
    
    if(rowerString.size() == position + 2) { // heart rate is in two digits
        
        if(rowerString[position] >= 49 && rowerString[position] <= 57 && rowerString[position + 1] >= 48 && rowerString[position + 1] <= 57) { // first digit must be 1-9, second digit must be 0-9
            return true;
            
        } else return false;
    }
    
    if(rowerString.size() == position + 3) { // heart rate is in three digits
        
        if(rowerString[position] >= 49 && rowerString[position] <= 57 && rowerString[position+1] >= 48 && rowerString[position+1] <= 57 && rowerString[position+2] >= 48 && rowerString[position+2] <= 57) {
            return true;
            
        } else return false;
        
    }
    
    return false; // if heart rate exceeds 3 digits, or there are any extra characters after heart rate, return false
}

/*----------------------------------------------*/

//If the parameter is a well-formed rower string, this function should return the total meters rowed so far.  If the parameter is not a valid rower string, return -1.
int totalDistance(string rowerString) {
    
    int totalDistance = 0;
    int i = 0;
    
    if(isValidRowerString(rowerString)) {
        
        while(rowerString[i] != 'm') { // skip to first 'm'
            i++;
        }
        
        i++; // increment once more to skip to next space
        
        while(rowerString[i] == ' ') { // skip to next nonspace character, the start of the distance
            i++;
        }
        
        while(rowerString[i] != ' ') { // read through all nonspace characters, counting them into the total distance traveled
            totalDistance = totalDistance * 10;
            totalDistance += (rowerString[i] - 48);
            i++;
        }
        
        return totalDistance;
        
    } else return -1;
    
    return -1;
}

/*----------------------------------------------*/

//If the parameter is a well-formed rower string, this function should return the heart rate in beats per minute.  If the parameter is not a valid rower string, return -1.
int heartRate(string rowerString) {
    
    int heartRate = 0;
    int i = 0;
    
    if(isValidRowerString(rowerString)) {
        
        while(rowerString[i] != 'm') { // skip to first 'm'
            i++;
        }
        
        i++; // increment once more to skip to next space
        
        while(rowerString[i] != 'm') { // skip to second 'm'
            i++;
        }
        
        i++; // increment once more to skip to space after second 'm'
        
        while(rowerString[i] == ' ') { // skip to next nonspace digit
            i++;
        }
        
        // i will now be at first digit of heart rate
        
        if(rowerString.size() == i + 1) { // heart rate is in single digits
            heartRate += (rowerString[i] - 48);
            return heartRate;
        }
        
        if(rowerString.size() == i + 2) { // heart rate is in two digits
            heartRate += (rowerString[i] - 48) * 10;
            heartRate += (rowerString[i+1] - 48);
            return heartRate;
        }
        
        if(rowerString.size() == i + 3) { //heart rate is in three digits
            heartRate += (rowerString[i] - 48) * 100;
            heartRate += (rowerString[i+1] - 48) * 10;
            heartRate += (rowerString[i+2] - 48);
            return heartRate;
        }
        
        // if somehow rowerString size isn't any of the above, return -1;
        return -1;
        
    } else return -1;
    
    return -1;
}

/*----------------------------------------------*/

//If the parameter is a well-formed rower string, this function should return the stroke rate in strokers per minute.  If the parameter is not a valid rower string, return -1.
int strokesPerMinute(string rowerString) {
    int strokesPerMinute = 0;
    int i = 0;
    
    if(isValidRowerString(rowerString)) {
        
        // this below section skips to first digit of stroke rate
        while(rowerString[i] != ':'){
            i++;
        }
        
        while(rowerString[i] != ' '){
            i++;
        }
        
        while(rowerString[i] == ' '){
            i++;
        }
        
        if(rowerString[i+1] == ' '){ // if single digit value, return that value
            strokesPerMinute += rowerString[i] - 48;
            return strokesPerMinute;
        }
        
        if(rowerString[i+2] == ' '){ // if 2-digit value, return the 2 digit value
            strokesPerMinute += (rowerString[i] - 48) * 10;
            strokesPerMinute += (rowerString[i+1] - 48);
            return strokesPerMinute;
        }
        
        if(rowerString[i+3] == ' '){ // if 3-digit value, return the 3 digit value
            strokesPerMinute += (rowerString[i] - 48) * 100;
            strokesPerMinute += (rowerString[i+1] - 48) * 10;
            strokesPerMinute += (rowerString[i+2] - 48);
            return strokesPerMinute;
        }
        
    } else return -1;
    
    return -1;
}

/*----------------------------------------------*/

// If the parameter is a well-formed rower string, this function should return the elapsed number of minutes rowing.  If the parameter is not a valid rower string, return -1.
int elapsedMinutes(string rowerString) {
    
    int minutes = 0;
    int i = 0;
    
    if(isValidRowerString(rowerString)){
        
        while(i < rowerString.size()) {
            if(rowerString[i] != ' ') {
                
                if(rowerString[i] == ':') { // there is no minutes digit, return 0
                    minutes = 0;
                    return minutes;
                }
                
                if(rowerString[i+1] == ':') { // if there is only one minutes digit, return it
                    minutes += (rowerString[i] - 48);
                    return minutes;
                    
                } else { // there are two minutes digits
                    minutes += (rowerString[i] - 48) * 10;
                    minutes += (rowerString[i+1] - 48);
                    return minutes;
                }
                
            } else i++;
        }
        
    } else return -1;
    
    return -1;
}

/*----------------------------------------------*/

// If the parameter is a well-formed rower string, this function should return the elapsed number of seconds rowing.  If the parameter is not a valid rower string, return -1.
int elapsedSeconds(string rowerString) {

    int seconds = 0;
    int i = 0;
    
    if(isValidRowerString(rowerString)){
        
        while(i < rowerString.size()) {
            
            if(rowerString[i] == ':') { // ':' is located, and the seconds are added and returned
                
                seconds += (rowerString[i+1] - 48) * 10;
                seconds += (rowerString[i+2] - 48);
                return seconds;
                
            } else i++;
        }
        
    }
    return -1;
}
