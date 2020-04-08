/*
 * Filename:      TestDriver.cpp
 * Author:        zah
 * Last Modified: 15/09/2016 
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
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstring>
using std::strcmp;

unsigned int nPass = 0;
unsigned int nFail = 0;

void CTest1(bool cond, const char* msg){
    if (cond)
        ++nPass;
    else{
        cout << "Test Failed: " << msg << endl;
        ++nFail;
    }
}


// Test using strcmp, which returns 0 if strings are equal
void CTest2(int val, const char* msg){
    if (val == 0)
        ++nPass;
    else{
        cout << "Test Failed: " << msg << endl;
        ++nFail;
    }
}


int main(void)
{
    String s1;
    CTest1(s1.length() == 0, "Default Constructor and length check (s1)");
    s1 = "abcd";
    CTest1(s1 == "abcd", "Equality operator for String s1");
    String s2("string s2");
    CTest1(s2.length() == 9, "Constructor accepting c-string and length check (s2) ");
    CTest1(s2 != s1, "Not equals operator (s2 != s1)");

    String s3 = "abc";
    String s4 = "abcd";

    CTest1(s4 > s3, "Greater than operator (s4 > s3)");
    CTest1(s3 < s4, "Less than operator (s3 < s4)");
    String s5 = "efg";
    s4 += s5;
    CTest1(s4 == "abcdefg", "Operator += (s4 == 'abcdefg')");
    CTest1(s4 >= s3,"Operator >= (s4 >= s3)");
    CTest1(s3 <= s4,"Operator <= (s3 <= s4)");
    CTest2(strcmp(s5.c_str(), "efg"),"c_str() function (s5 == 'efg')");
    String s6(s5);
    CTest2(strcmp(s6.c_str(), "efg"), "Copy constructor");

    String s7("this is a test", 14);
    CTest1(s7.length() == 14, "Constructor accepting c-string and string length (s7.length() == 14)");
    CTest1(s7[6] == 's', "Operator [] test, (s7[6] == 's')");

    s7.clear();
    CTest2(strcmp(s7.c_str(), ""), "clear() function with c_str() check, s7.clear()");
    CTest1(s7.length() == 0, "clear() function with length() check, s7.clear()");

    s7 = "testing";
    s7.resize(12, '*');
    CTest1(s7.length() == 12, "resize() function with length() check, s8.length()");
    CTest2(strcmp(s7.c_str(), "testing*****"), "resize() function with c_str() check, s8.resize(12,'*')");
    s7.resize(4, '*');
    CTest1(s7.length() == 4, "resize() function with length() check, s8.resize(4,'*')");
    CTest2(strcmp(s7.c_str(), "test"), "resize() function with c_str() check, s8.resize(4,'*')");

    cout << "[+] Total tests passed: (" << nPass << "/" << (nPass+nFail) << ")" << endl;

    return 0;
}


/*
 *
 * String_Library/ $ g++ *.cpp -o bin/TestDriver
 * String_Library/ $ ./bin/TestDriver                       
 * [+] Total tests passed: (19/19)
 *
 */

