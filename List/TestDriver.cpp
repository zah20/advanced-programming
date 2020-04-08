/*
 * Filename:      TestDriver.cpp
 * Version:       2.0
 * Author:        zah
 * Last Modified: Thu Nov 17, 2016 (10:40 PM)
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
#include "list.hpp"
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

template <typename T>
void CTest2(const T inputArray[], size_t arrayLength,
        const List<T>& inputList, const char* msg){

    auto iter = inputList.const_begin();

    for (size_t i=0; i < arrayLength; ++i, ++iter){
        if (inputArray[i] != *iter){
            cout << "Test Failed: " << msg << endl;
            ++nFail;
            break;
        }
    }
    ++nPass;
}


int main(void)
{
    List<int> testArray1;

    CTest1(testArray1.size() == 0, "testArray1, default constructor"
            " with size() check");

    CTest1(testArray1.empty() == true, "testArray1, default"
            "constructor with empty() check");

    testArray1.push_back(5);

    auto currentIter = testArray1.begin();

    CTest1(testArray1.size() == 1, "testArray1, after push_back(5)"
            " with size() check");

    CTest1(*currentIter == 5, "testArray1, after push_back(5)"
            " with *currentIter value check");

    testArray1.push_front(3);

    CTest1(testArray1.size() == 2, "testArray1, after push_front(3)"
            " with size() check");

    --currentIter;

    CTest1(*currentIter == 3, "testArray1, after push_front(3)"
            " with --currentIter & *currentIter value check");

    testArray1.pop_back();
    testArray1.pop_front();

    CTest1(testArray1.size() == 0, "testArray1, after 2 pop_back()"
            " with size() check");

    CTest1(testArray1.empty() == true, "testArray1, after 2 pop_back()"
            " with empty() check");

    testArray1.push_back(4);
    testArray1.push_back(7);
    testArray1.push_front(3);

    CTest1(testArray1.size() == 3, "testArray1, after 2 pop_back()"
            " with size() check");

    currentIter = testArray1.begin();

    CTest1(*currentIter == 3, "testArray1,"
            " with *currentIter value check == 3");

    ++currentIter;

    CTest1(*currentIter == 4, "testArray1,"
            " with *currentIter value check == 4");

    ++currentIter;

    CTest1(*currentIter == 7, "testArray1,"
            " with *currentIter value check == 7");

    *currentIter = 8;

    currentIter = testArray1.begin();

    *currentIter = 0;

    testArray1.push_front(2);

    int arrayCorrect[] = {2,0,4,8};
    size_t arraySize = sizeof(arrayCorrect)/(sizeof(int));

    CTest2(arrayCorrect, arraySize, testArray1, "testArray1, "
            "with CTest2 comparing with arrayCorrect");


    List<int> testArray2 = testArray1;

    CTest2(arrayCorrect, arraySize, testArray2, "testArray2, "
            "with CTest2 comparing with arrayCorrect "
            "after assigntment");

    testArray1.clear();

    CTest1(testArray1.size() == 0, "testArray1,"
            " with size() check after clear()");

    CTest1(testArray1.empty() == true, "testArray1,"
            " with empty() check after clear()");

    auto itr2 = testArray1.begin();
    testArray1.insert(itr2, 7);
    --itr2;

    CTest1(*itr2 == 7, "testArray1,"
            " with *itr2 value check == 7 after insert");

    CTest1(testArray1.front() == 7, "testArray1,"
            " with *itr2 value check == 7 after insert");

    testArray1.erase(itr2);

    CTest1(testArray1.size() == 0, "testArray1,"
            " with size() check after erase(itr2)");

    CTest1(testArray1.empty() == true, "testArray1,"
            " with empty() check after erase(itr2)");


    DArray<char> dynArray;
    dynArray.append('a');
    dynArray.append('b');
    dynArray.append('c');
    dynArray.append('d');

    List<char> charList(dynArray.begin(), dynArray.end());
    char alphabet[] = {'a','b','c','d'};

    CTest1(dynArray.size() == 4, "dynArray,"
            " with size() check after passing dynamic array");

    CTest2(alphabet, 4, charList, "dynArray with CTest2"
            " and alphabet");

    List<char> customList;

    customList.push_front('k');

    customList.insert(customList.begin(),
            dynArray.begin(), dynArray.end());

    char correctList[] = {'a','b','c','d','k'};

    CTest2(correctList, 5, customList, "customList with CTest2 check");

    CTest1(customList.size() == 5, "customList,"
            " with size() check after passing dynamic array");

    customList.remove('k');

    char correctList2[] = {'a','b','c','d'};

    CTest2(correctList, 4, customList, "correctList with CTest2 check");

    cout << "[+] Total tests passed: (" << nPass 
        << "/" << (nPass+nFail) << ")" << endl;




    return 0;

}

