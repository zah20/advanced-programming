/*
 * Filename:      TestDriver.cpp
 * Version:       1.0
 * Author:        zah
 * Last Modified: Thu Dec 01, 2016 (06:52 PM)
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
#include "pqueue.hpp"
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
    PQueue<int> pq1;

    CTest1((pq1.empty() == true), "PQueue with default constructor "
            "and empty() check");

    pq1.enQueue(10);

    CTest1((pq1.empty() == false), "PQueue with enQueue(10)"
            "and empty() check");
    CTest1((pq1.getTop() == 10), "PQueue with getTop() == 10 ");

    pq1.enQueue(5);
    CTest1((pq1.getTop() == 5), "PQueue with getTop() == 5");

    pq1.enQueue(13);
    CTest1((pq1.getTop() == 5), "PQueue with getTop() == 5");
    pq1.enQueue(3);
    CTest1((pq1.getTop() == 3), "PQueue with getTop() == 5");

    CTest1((pq1.size() == 4), "PQueue with pq1.size() == 4");
    CTest1((pq1.getTop() == 3), "PQueue with pq1.getTop() == 5");

    pq1.deQueue();
    CTest1((pq1.size() == 3), "PQueue with pq1.size() == 3");
    pq1.deQueue();
    pq1.deQueue();
    CTest1((pq1.getTop() == 13), "PQueue with pq1.getTop() == 13");


    cout << "[+] Total tests passed: (" << nPass 
        << "/" << (nPass+nFail) << ")" << endl;




    return 0;

}

