/*
 * Filename:      String.cpp
 * Author:        zah
 * Last Modified: 1/10/2016 
 *
 * Copyright © 2016 zah
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "String.h"
#include <cstring>
using std::strlen;
using std::strcpy;
using std::strncpy;
using std::strcmp;
using std::ws;



String::String() throw (bad_alloc){
    strSize = 0;
    bufferSize = 10;
    buffer = new char[bufferSize];
    *(buffer+strSize) = '\0';
}


String::~String() throw(){
    delete [] buffer;
    buffer = 0; // We set it to zero so that even if deleted space is accessed
    // by mistake we do not cause any segmentation fault by
    // giving access to wrong sections of the memory
}


String::String(const char* inputCstring) throw (bad_alloc){
    if (inputCstring == NULL){ inputCstring = "";}
    strSize = strlen(inputCstring);
    bufferSize = ((strSize+1)*1.50);
    buffer = new char[bufferSize];
    strcpy(buffer, inputCstring);
}


String::String(const char* inputCString, size_t inputSize) throw (bad_alloc){
    if (inputCString == NULL){ inputCString = "";}

    strSize = inputSize;
    bufferSize = ((strSize+1)*1.50);
    buffer = new char[bufferSize];

    // strncpy doesn't put a null terminating character
    // at the end of copied string
    strncpy(buffer, inputCString, inputSize); 

    // If inputSize is bigger than input c-style string,
    // we fill the remaining characters of our buffer
    // with space
    if (inputSize > strlen(inputCString)){
        for (size_t i = strlen(inputCString); i < strSize; ++i) {
            *(buffer+i) = ' ';
        }
    }

    *(buffer+strSize) = '\0';
}


String::String(char filler, size_t inputSize) throw (bad_alloc){
    strSize = inputSize;
    bufferSize = (strSize+1)*1.50;
    buffer = new char[bufferSize];

    for (size_t i = 0; i < strSize; ++i) {
        *(buffer+i) = filler;
    }

    *(buffer+strSize) = '\0';
}


String::String(const String& inputString) throw (bad_alloc){
    strSize = inputString.length();
    bufferSize = (strSize+1)*1.50;
    buffer = new char[bufferSize];
    strcpy(buffer, inputString.buffer);
}


String& String::operator=(const String& rhs) throw (bad_alloc){
    if (this != &rhs){
        strSize = rhs.length();

        if (strSize >= bufferSize){ // We need to reallocate
            bufferSize = ((strSize+1)*1.50);
            delete [] buffer;
            buffer = new char[bufferSize];
        }

        strcpy(buffer, rhs.buffer);
    }

    return *this;
}


void String::clear() throw(){
    strSize = 0;
    *(buffer+strSize) = '\0';
}


void String::resize(size_t newSize, char filler) throw (bad_alloc){
    if (newSize > strSize){
        if (newSize >= bufferSize){
            bufferSize = ((newSize+1)*1.5);
            char* newBuffer = new char[bufferSize];
            strcpy(newBuffer, buffer);
            delete [] buffer;
            buffer = newBuffer;
        }

        for (size_t i = strSize; i < newSize; ++i) {
            *(buffer+i) = filler;
        }
    }

    strSize = newSize;

    *(buffer+strSize) = '\0';
}



const char& String::operator[](size_t position) const throw (out_of_range) {
    if ( position >= strSize){
        throw out_of_range("String index out of range");
    }
    return *(buffer+position);
}


char& String::operator[](size_t position) throw (out_of_range){
    if ( position >= strSize){
        throw out_of_range("String index out of range");
    }
    return *(buffer+position);
}


String& String::operator+=(const String& rhs) throw (bad_alloc){
    if (this == &rhs){
        String copyString(rhs);
        return *this += copyString;
    }

    // Keeping track of original strSize
    size_t oldSize = strSize;
    strSize = rhs.length() + strSize;

    // We need to reallocate new memory
    if((strSize+1) > bufferSize){
        // Keeping track of old buffer
        char* oldBuffer = buffer;
        bufferSize = (strSize+1)*1.5;
        buffer = new char[bufferSize];
        strcpy(buffer, oldBuffer);
        delete [] oldBuffer;
    }	

    // Custom loop to populate concatenated string onto existing buffer
    for (size_t i=0; i < rhs.length(); i++){
        *(buffer+i+oldSize) = *(rhs.buffer+i);	
    }

    *(buffer+strSize) = '\0';

    return *this;
}


const char* String::c_str() const throw(){
    return buffer;
}


bool operator==(const String& lhs, const String& rhs) throw(){
    return (strcmp(lhs.c_str(),rhs.c_str()) == 0);
}


bool operator!=(const String & lhs, const String & rhs) throw(){
    return (!(lhs == rhs)); 
}


bool operator<(const String & lhs, const String & rhs) throw(){
    return (strcmp(lhs.c_str(),rhs.c_str()) < 0);
}


bool operator<=(const String & lhs, const String & rhs) throw(){
    return ((lhs < rhs) || (lhs == rhs));
}


bool operator>(const String & lhs, const String & rhs) throw(){
    return (!(lhs <= rhs));
}


bool operator>=(const String & lhs, const String & rhs) throw(){
    return (!(lhs < rhs));
}


String operator+(const String & lhs, const String & rhs) throw (bad_alloc){
    String newString = lhs;
    return newString += rhs;
}


ostream& operator<<(ostream & outStream, const String & inputString){
    return outStream << inputString.c_str();
}


istream& operator>>(istream & in, String & str) throw (bad_alloc){  
    char c;
    str = ""; // Set str to be an empty String
    in >> ws; // Taking out initial whitespace

    while (in.get(c)){
        if (str.strSize == str.bufferSize){
            char* oldBuffer = str.buffer;
            str.bufferSize = (str.bufferSize+1)*1.5;
            str.buffer = new char[str.bufferSize];
            strcpy(str.buffer, oldBuffer);
            delete [] oldBuffer;
        }

        if (isspace(c)){
            in.putback(c);
            str.buffer[str.strSize] = '\0';
            return in;
        }

        str.buffer[str.strSize] = c;
        ++str.strSize;
    }
    return in;
}


istream& String::getline(istream& inStream, char delim) throw (bad_alloc){
    char x;
    clear();

    inStream.get(x);

    do{
        if (strSize == bufferSize){
            char* oldBuffer = buffer;
            bufferSize = (bufferSize+1)*1.5;
            buffer = new char[bufferSize];
            strcpy(buffer, oldBuffer);
            delete [] oldBuffer;
        }	

        if (x == delim){
            break;
        }

        *(buffer+strSize) = x;
        ++strSize;

    }while (inStream.get(x));

    *(buffer+strSize) = '\0';

    return inStream;
}
