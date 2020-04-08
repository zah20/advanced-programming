/*
 * Filename:      TestDriver.cpp
 * Author:        zah
 * Last Modified: 26/09/2016 
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


#include "queue.hpp"
#include <iostream>
using std::cout;
using std::endl;
#include "String.h"
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


void CTest2(const char* input1, const char* input2, const char* msg){
    if (strcmp(input1,input2) == 0)
        ++nPass;
    else{
        cout << "Test Failed: " << msg << endl;
        ++nFail;
    }
}



void CTest3(const char input1, const char input2, const char* msg){
    if (input1 ==input2) 
        ++nPass;
    else{
        cout << "Test Failed: " << msg << endl;
        ++nFail;
    }
}


int main(void)
{
    Queue<int> num1;
    CTest1(num1.size() == 0, "Default constructor and size()");
    CTest1(num1.isEmpty() == true, "Default constructor and isEmpty()");
    num1.enqueue(7);
    CTest1(num1.size() == 1, "Default constructor, enqueue and size()");
    CTest1(num1.isEmpty() == false, "Default constructor and isEmpty()");
    num1.enqueue(9);
    num1.enqueue(5);
    CTest1(num1.getFirst() == 7, "Default constructor and getFirst()");
    int val1 = num1.dequeue();
    CTest1(val1 == 7, "Default constructor and dequeue()");
    CTest1(num1.size() == 2, "Default constructor, dequeue() and size()");

    Queue<int> num2;
    num2 = num1;
    CTest1(num2.size() == 2, "Assignment operator and size()");
    int val2 = num2.dequeue();
    CTest1(val2 == 9, "Assignment operator and dequeue()");
    CTest1(num2.size() == 1, "Assignment operator, dequeue() and size()");
    int val3 = num2.getFirst();
    CTest1(val3 == 5, "getFirst() and value comparison");
    CTest1(num2.size() == 1, "getFirst() and size check");

    Queue<int> num3(num2);
    CTest1(num3.size() == 1, "Copy constructor and size()");
    CTest1(num3.isEmpty() == false, "Copy constructor and isEmpty()");
    int val4 = num3.dequeue();
    CTest1(val4 == 5, "Copy constructor, dequeue() and value comparison");
    CTest1(num3.size() == 0, "Copy constructor and size()");
    CTest1(num3.isEmpty() == true, "Copy constructor and isEmpty()");

    Queue<String> strQue;
    CTest1(strQue.isEmpty() == true, "String object with isEmpty() check ");
    strQue.enqueue("Amigo");
    CTest1(strQue.isEmpty() == false, "String object with enqueue & isEmpty() check ");
    CTest1(strQue.size() == 1, "String object with size() check ");
    const char* cstr1 = strQue.getFirst().c_str();
    CTest2(cstr1, "Amigo", "String object with c_str() comparison");  
    strQue.dequeue();
    CTest1(strQue.isEmpty() == true, "String object with isEmpty() check ");
    CTest1(strQue.size() == 0, "String object with size() check ");

    Queue<String> colors;
    CTest1(colors.isEmpty() == true, "String colors with isEmpty() check ");
    colors.enqueue("White");
    colors.enqueue("Black");
    colors.enqueue("Purple");
    colors.enqueue("Yellow");
    colors.enqueue("Blue");
    CTest1(colors.isEmpty() == false, "String colors with isEmpty() check ");
    CTest1(colors.size() == 5, "String colors with size() check ");
    colors.dequeue();
    colors.dequeue();
    colors.dequeue();
    colors.dequeue();
    CTest2(colors.getFirst().c_str(), "Blue", "String colors with c_str() comparison");  

    Queue<char> letter;
    CTest1(letter.isEmpty() == true, "Char letter with isEmpty() check ");
    letter.enqueue('a');
    letter.enqueue('b');
    letter.enqueue('c');
    letter.enqueue('d');
    CTest1(letter.size() == 4, "Char letter with size() check ");
    letter.dequeue();
    letter.dequeue();
    char chr1 = letter.getFirst();
    CTest3(chr1, 'c', "Char letter comparison");  
    letter.dequeue();
    chr1 = letter.getFirst();
    CTest3(chr1, 'd', "Char letter comparison");  


    Queue<int> intVar;
    Queue<unsigned long> ulongVar;
    intVar.enqueue(4);
    intVar.enqueue(3);
    intVar.enqueue(2);
    intVar.enqueue(1);
    ulongVar = intVar;
    CTest1(intVar.size() == 4, "Implicit conversion test of intVar with size()");
    CTest1(intVar.isEmpty() == false, "Implicit conversion test of intVar with isEmpty()");
    CTest1(ulongVar.size() == 4, "Implicit conversion test of ulongVar with size()");
    CTest1(ulongVar.isEmpty() == false, "Implicit conversion test of ulongVar with isEmpty()");
    CTest1(ulongVar.getFirst() == 4, "Implicit conversion test of ulongVar with getFirst()");
    ulongVar.dequeue();
    CTest1(ulongVar.getFirst() == 3, "Implicit conversion test of ulongVar with getFirst()");
    CTest1(ulongVar.size() == 3, "Implicit conversion test of ulongVar with size()");


    cout << "[+] Total tests passed: (" << nPass << "/" << (nPass+nFail) << ")" << endl;
    return 0;
}
/*
 * Queue/ $ g++ *.cpp -o bin/TestDriver
 * Queue/ $ ./bin/TestDriver
 * [+] Total tests passed: (38/38)
 *
 **/
