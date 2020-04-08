/*
 * Filename:      TestDriver.cpp
 * Version:       2.0
 * Author:        zah
 * Last Modified: 23/10/2016 
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


#include <iostream>
using std::cout;
using std::endl;
#include "dynarray.hpp"
using namespace zh;

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


int main(void)
{
    DArray<int> testArray1;
    DArray<int> testArray2(10);
    DArray<int> testArray3(5, 5);

    CTest1(testArray1.size() == 0, "testArray1, default constructor"
            " with size() check");


    CTest1(testArray1.isEmpty() == true, "testArray1, default"
            "constructor with isEmpty() check");

    testArray1.resize(5);
    CTest1(testArray1[0] == 0, "testArray2 with value check");

    CTest1(testArray1.size() == 5, "testArray1, default constructor"
            " with size() check after resize()");

    CTest1(testArray1.isEmpty() == false, "testArray1," 
            "default constructor with isEmpty() check"
            " after resize()");


    CTest1(testArray2.size() == 10, "testArray2, "
            "default constructor with size() check");

    CTest1(testArray2.isEmpty() == false, "testArray2, default "
            "constructor with isEmpty() check");

    CTest1(testArray2[0] == 0, "testArray2 with value check");

    testArray2[0] = 10;
    testArray2[1] = 20;
    testArray2[2] = 30;

    CTest1((testArray2[0] == 10 && testArray2[1] == 20 &&
                testArray2[2] == 30), "testArray2 with custom"
            " value check");

    CTest1(testArray3.size() == 5, "testArray3, default constructor"
            " with size() check");

    CTest1(testArray3.isEmpty() == false, "testArray3, default"
            "constructor with isEmpty() check");

    CTest1(testArray3[0] == 5, "testArray3 with value check");

    testArray3[4] = 40;
    testArray3[3] = 50;
    testArray3[2] = 60;

    CTest1((testArray3[4] == 40 && 
                testArray3[3] == 50 &&
                testArray3[2] == 60), 
            "testArray3 with custom value check");

    testArray3.resize(10, 7);
    CTest1(testArray3[5] == 7, "testArray3 with value check"
            " after resize()");

    CTest1(testArray3[4] == 40, "testArray3 with second value check"
            " after resize()");
    CTest1(testArray3.size() == 10, "testArray3, default constructor"
            " with size() check");

    testArray3[9] = 4;
    testArray3[8] = 5;
    testArray3[7] = 6;

    CTest1((testArray3[9] == 4 && 
                testArray3[8] == 5 &&
                testArray3[7] == 6), 
            "testArray3 with custom value check");

    testArray3 = testArray1;

    CTest1(testArray3.size() == 5, "testArray3, "
            "with size() check after assignment");

    CTest1(testArray3[0] == 0, "testArray3 with value check"
            " after assignment"); 

    testArray1 = testArray2;

    CTest1(testArray1.size() == 10, "testArray1, "
            "with size() check after assignment");

    CTest1((testArray1[0] == 10 && 
                testArray1[1] == 20 &&
                testArray1[2] == 30), 
            "testArray1 with custom value check"
            " after assignment");

    testArray1.clear();
    CTest1(testArray1.size() == 0, "testArray1, "
            "with size() check after clear()");

    CTest1(testArray1.isEmpty() == true, "testArray1,"
            " with isEmpty() check after clear()");

    testArray1.append(13);
    CTest1(testArray1.size() == 1, "testArray1, "
            "with size() check after append()");

    CTest1(testArray1.isEmpty() == false, "testArray1,"
            " with isEmpty() check after append()");

    CTest1(testArray1[0] == 13, "testArray1, "
            "with value check after append()");

    testArray1.remove_last();

    CTest1(testArray1.size() == 0, "testArray1, "
            "with size() check after remove_last()");

    CTest1(testArray1.isEmpty() == true, "testArray1,"
            " with isEmpty() check after remove_last()");

    testArray1.add(6,0);

    CTest1(testArray1.size() == 1, "testArray1, "
            "with size() check after add()");

    CTest1(testArray1.isEmpty() == false, "testArray1,"
            " with isEmpty() check after add()");

    CTest1(testArray1[0] == 6, "testArray1, "
            "with value check after add(6,0)");

    testArray1.append(6);

    CTest1(testArray1.size() == 2, "testArray1, "
            "with size() == 2 check after add() and append()");

    testArray1.add(13,1);

    CTest1(testArray1.size() == 3, "testArray1, "
            "with size() == 3 check after add(13,1)");

    CTest1(testArray1[0] == 6, "testArray1, "
            "with value check after add(13,1)");

    CTest1(testArray1[1] == 13, "testArray1, "
            "with second value check after add(13,1)");

    CTest1(testArray1[2] == 6, "testArray1, "
            "with third value check after add(13,1)");

    DArray<int> testArray4 = testArray1;

    CTest1(testArray4.size() == 3, "testArray4, "
            "with size() == 3 check testing copy constructor");

    CTest1(testArray4[0] == 6, "testArray4, "
            "with value check testing copy constructor");

    CTest1(testArray4[1] == 13, "testArray4, "
            "with second value check testing copy constructor");

    CTest1(testArray4[2] == 6, "testArray4, "
            "with third value check testing copy constructor");

    testArray4.remove(1);

    CTest1(testArray4.size() == 2, "testArray4, "
            "with size() == 2 check testing remove(1)");

    CTest1(testArray4[0] == 6, "testArray4, "
            "with value check testing remove(1)");

    CTest1(testArray4[1] == 6, "testArray4, "
            "with value check testing remove(1)");

    testArray4.reserve(15);

    CTest1(testArray4.capacity() == 15, "testArray4, "
            "with reserve(15) and capacity() check");

    testArray4.reserve(10);

    CTest1(testArray4.capacity() == 15, "testArray4, "
            "with second reserve(10) and capacity() check");


    DArray<int> testArray5;
    testArray5.append(10);
    testArray5.append(5);

    DArray<long> testArray6 = testArray5;

    CTest1(testArray5.size() == 2, "testArray5, "
            "with size() == 2 check testing");

    CTest1(testArray6.size() == 2, "testArray6, "
            "with size() == 0 check testing");

    CTest1(testArray6[0] == 10, "testArray6, "
            "with value check testing index 0");

    CTest1(testArray6[1] == 5, "testArray6, "
            "with value check testing index 1");

    cout << "[+] Total tests passed: (" << nPass 
        << "/" << (nPass+nFail) << ")" << endl;

    return 0;

    /*
     * Version2/ (master✗) $ which Cm                           
     * Cm: aliased to g++ -std=c++14 -ggdb *.cpp -o  
     * Version2/ (master✗) $ Cm bin/TestDriver                  
     * Version2/ (master✗) $ echo $?                            
     * 0 
     * Version2/ (master✗) $ ./bin/TestDriver                   
     * [+] Total tests passed: (49/49) 
     * Version2/ (master✗) $ echo $?                            
     * 0 
     * Version2/ (master✗) $
     */
}

