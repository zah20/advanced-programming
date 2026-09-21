/*
 * Filename:      queue.hpp
 * Version:       2.0
 * Author:        zah
 * Last Modified: 29/09/2016 
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

#ifndef QUEUE_V2
#define QUEUE_V2

#include <cstddef>
#include <new>
using std::bad_alloc;



//====================================================//
//					              //
// 		       Prototype 		      //
//					              //
//====================================================//

class QueueEmpty{};
class QueueFull{};

template <typename T>
class Queue{

    public:
        Queue(); 
        /*                                   
         * Description: Create and initialize an empty Queue object
         *
         * Input:  None
         *
         * Output: None
         *
         * Plan: 1) Initialize data to it's default value
         *       2) Make next point to NULL
         *
         * Pre-Conditions: None
         *
         * Post-Conditions: None
         *
         * Exception: None
         */


        ~Queue() throw();
        /*                                   
         * Description: Delete the Queue object properly
         *
         * Input:  None
         *
         * Output: None
         *
         * Plan: While Queue is not empty, keep on calling
         *       dequeue()
         *
         * Pre-Conditions: None
         *
         * Post-Conditions: None
         *
         * Exception: None
         */


        Queue(const Queue<T>&);
        /*                                   
         * Description: Initialize our Queue object
         *              to represent the same state
         *              as the input Queue object
         *
         * Input:  1) Queue object of type <T> whose state we 
         *            wish to replicate
         *
         * Output: None
         *
         * Plan:   Use of the assignment operator and 
         *         derefence this pointer to hold the 
         *         value of the returned object 
         *
         * Pre-Conditions:  1) Sufficient memory is available
         *
         * Post-Conditions: 1) We do not modify input Queue object
         *
         * Exception: 1) Throws QueueFull when allocating new 
         *               memory on the heap fails
         */


        Queue<T>& operator=(const Queue<T>&);
        /*                                   
         * Description: Modifies and returns an existing Queue 
         *              object to represent the same state as the 
         *              input Queue object and return it
         *
         * Input: 1) Queue object of type <T> whose state we 
         *           wish to replicate
         *
         * Output: Returns Queue object with modified state
         *
         * Plan:  1) If this pointer does not point to the same
         *           location the input (rhs) object:
         *
         *              i) While queue is not empty, keep on 
         *                 calling dequeue()
         *
         *              ii) Create a QNode pointer (rhsPtr) and
         *                  make it point to rhs.front
         *
         *              iii) While rhsPtr is not NULL,
         *                   a) Create a QNode pointer called temp
         *                   b) Allocate memory on the heap by
         *                      passing (rhsPtr->data) to the 
         *                      constructor
         *                   c) Make temp point to the allocated
         *                      memory (b)
         *                   d) If our queue is empty, make front 
         *                      point to temp and back point to
         *                      front
         *                   e) Otherwise, make back->next point
         *                      to temp and set back to temp
         *                   f) Set rhsPtr point to rhs->next
         *
         *              iv) Set value of counter to rhs.counter
         *        
         *        2) Return *this pointer which points to our
         *           queue object
         *
         * Pre-Conditions:  1) The input Queue object has to be 
         *                     of the same type as that of the 
         *                     Queue object we are modifying
         *                  2) Sufficient memory is available
         *
         * Post-Conditions: 1) We do not modify the state of
         *                     input Queue object
         *
         * Exception: 1) Throws QueueFull when allocating new
         *               memory on the heap fails
         */


        inline bool isEmpty() const throw();
        /*                                   
         * Description: Returns boolean value indicating
         *              whether Queue is empty or not 
         *
         * Input:  None
         *
         * Output: 1) True if queue is empty
         *         2) False is queue is not empty
         *
         * Plan: Return true if front == NULL or 
         *       else return false
         *
         * Pre-Conditions: None
         *
         * Post-Conditions: 1) We do not make any modification
         *                     to the state of the current object
         * Exception: None
         */


        inline size_t size() const throw();
        /*                                   
         * Description: Indicates the size of the current Queue
         *
         * Output: Number of items inside the Queue object
         *
         * Pre-Conditions: None
         *
         * Plan: Return the value of counter
         *
         * Post-Conditions: 1) We do not make any modification
         *                     to the state of the current object
         *
         * Exception: None
         */


        void enqueue(const T&);
        /*                                   
         * Description: Push an item of type <T> onto the Queue
         *
         * Input:  1) Item of type <T> that we wish to insert into 
         *            the Queue
         *
         * Output: None
         *
         * Plan:   1) Create a pointer newPtr of type QNode
         *         2) Create new memory on the heap of type QNode by 
         *            passing the input Queue object of type <T> to 
         *            the constructor
         *         3) Catch bad_alloc if sufficient memory is not
         *            available and throw an exception of QueueFull
         *         4) Make newPtr point to the newly allocated memory
         *            we have from (2)
         *         5) Check if Queue is empty and if it is:
         *                i) Make front point to newPtr
         *                ii) Make back point to front
         *         6) Otherwise,
         *                i) Make next pointer of back point to newPtr
         *                ii) Set back point to newPtr;
         *
         * Pre-Conditions:  1) The input parameter has to be the same
         *                    type <T> as the Queue that it is being
         *                    inserted into
         *                  2) Sufficient memory is available
         *
         * Post-Conditions: 1) We do not make any modification
         *                     to the state of input object
         *
         * Exception: 1) Throws QueueFull when sufficient memory
         *               is not available 
         */


        T dequeue();
        /*                                   
         * Description: Remove the first item from the Queue
         *              and return the value of that item
         *
         * Input:   None
         *
         * Output:  Value of the item that is being removed 
         *          from the Queue
         *
         * Plan:    1) If queue is empty, throw QueueEmpty()
         *          2) Create a QNode pointer tmp and make it
         *             point to front
         *          3) Create a variable 'val' of type <T> and set
         *             its value to be the data of front
         *          4) Make front point to the next pointer 
         *             of front
         *          5) Delete the pointer tmp
         *          6) Decrement counter by 1
         *          7) Return the value of val we calculated
         *             in (3)
         *
         * Pre-Conditions: 1) Queue is not empty
         *
         * Post-Conditions: None
         *
         * Exception: 1) Throws QueueEmpty() when an attempt
         *               is made to remove item from an empty
         *               Queue object
         */


        T& getFirst();
        /*                                   
         * Description: Return the first item in the Queue with
         *              no restrictions on modification
         *
         * Input: None
         *
         * Output: Return the first item in the Queue 
         *
         * Pre-Conditions: None
         *
         * Plan: 1) If Queue is empty, throw QueueEmpty()
         *       2) Otherwise return the data value of front
         *
         * Post-Conditions: 1) We allow modification of the returned
         *                     object
         *                  2) We assume the Queue is not empty
         *
         * Exception: 1) Throws QueueEmpty() when the queue is
         *               empty
         */


        const T& getFirst() const;
        /*                                   
         * Description: Return the first item on the Queue with 
         *              read only access
         *
         * Output: Return the first item on the Queue
         *
         * Plan:   1) If Queue is empty, throw QueueEmpty()
         *         2) Otherwise return the data value of front
         *
         * Pre-Conditions:  1) Queue is not empty
         *
         * Post-Conditions: 1) We do not make any modification
         *                     to the state of the current object
         *                  2) We do not allow any modification
         *                     to the state of returned object
         *                  3) We assume Queue is not empty
         *
         * Exception: 1) Throws QueueEmpty() when the queue is
         *               empty
         */


        template <typename T2>
            Queue<T>(const Queue<T2>& input);
        /*                                   
         * Description: Initialize our Queue object to represent 
         *              the same state as that of the input Queue 
         *              object. Also this member template allows 
         *              us to copy Queue objects of different 
         *              types 
         *
         * Input: Queue object of a type that is different
         *        than the type of our existing queue object
         *
         * Output: None
         *
         * Plan: 1) While queue is not empty, keep on 
         *          calling dequeue()
         *
         *       2) Create a QNode pointer (inputPtr) and
         *           make it point to input.front
         *
         *       3) While inputPtr is not NULL,
         *            a) Create a QNode pointer called temp
         *            b) Allocate memory on the heap by
         *               passing (input->data) to the 
         *               constructor
         *            c) Make temp point to the allocated
         *               memory (b)
         *            d) If our queue is empty, make front 
         *               point to temp and back point to
         *               front
         *            e) Otherwise, make back->next point
         *               to temp and set back to temp
         *            f) Set inputPtr point to inputPtr->next
         *
         *       4) Set value of counter to rhs.counter
         *
         * Pre-Conditions:  1) Sufficient memory is available
         *
         * Post-Conditions: 1) We do not modify input Queue object
         *
         * Exception: 1) Throws QueueFull when allocating new 
         *               memory on the heap fails
         */


    private:
        class QNode;
        // front pointer points to the first item that
        // got inserted in the Queue
        QNode* front;

        // back pointer points to the last item that got
        // inserted in the Queue
        QNode* back;


        /* (Condition)
         * front == back, only when 
         * (1) Queue object is empty
         * (2) Queue object has 1 item inserted
         */

        // Counter is a count of the number of items
        // inside our Queue object
        size_t counter;
};


template <typename T>
class Queue<T>::QNode{
    public:
        T data;
        QNode* next;
        QNode(); 
        QNode(const T &item);

};




//====================================================//
//						      //
// 	             Definition 		      //
//					              //
//====================================================//


template <typename T>
Queue<T>::QNode::QNode(): data(), next(NULL){}


template <typename T>
Queue<T>::QNode::QNode(const T& item): data(item), next(NULL){}

template <typename T>
Queue<T>::Queue(): front(NULL), back(NULL), counter(0){}


template <typename T>
Queue<T>::~Queue() throw(){
    if (!isEmpty()){
        dequeue();
    }
}



template <typename T>
Queue<T>::Queue(const Queue<T>& node): front(NULL), back(NULL), counter(0){
    *this = node;
}


template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs){
    if (this != &rhs){
        while (!isEmpty()){ dequeue();}

        // Pointer to iterate input queue object
        QNode* rhsPtr = rhs.front;

        while (rhsPtr != NULL) {
            QNode* temp;
            try{
                // Pointer to store as current object
                temp = new QNode(rhsPtr->data);
            }catch (bad_alloc){ throw QueueFull();}
            // Assuming our first insertion
            if (isEmpty()){
                front = temp;
                back = front;
            }else{
                back->next = temp;
                back = temp;
            }
            rhsPtr = rhsPtr->next;
        }
        counter = rhs.counter;
    }
    return *this;
}

template <typename T>
inline bool Queue<T>::isEmpty() const throw() {
    return (this->front == NULL?true:false);
}


template <typename T>
size_t Queue<T>::size() const throw(){
    return counter;
}


template <typename T>
void Queue<T>::enqueue(const T& item){
    QNode* newPtr; 
    try{
        newPtr = new QNode(item);
    }catch (bad_alloc){
        throw QueueFull();
    }

    if (isEmpty()){ 
        front = newPtr;
        back = front;
    }else{
        back->next = newPtr;
        back = newPtr;
    }

    counter++;
}


template <typename T>
T Queue<T>::dequeue(){
    if (isEmpty()){ 
        throw QueueEmpty();
    }

    QNode* tmp = front;
    T val = front->data;

    if (size() == 1){
        front = NULL;
        back = NULL;
    }else{
        front = front->next;
    }

    delete tmp;
    counter--;
    return val;
}


template <typename T>
T& Queue<T>::getFirst() {
    if (isEmpty()){ 
        throw QueueEmpty();
    }else{
        return front->data;
    }
}


template <typename T>
const T& Queue<T>::getFirst() const{ 
    if (isEmpty()){ 
        throw QueueEmpty();
    }else{
        return front->data;
    }
}


template <typename T1>
template <typename T2>
Queue<T1>::Queue(const Queue<T2>& input): front(NULL), back(NULL), counter(0){
    // The purpose of this class is basically to allow
    // us to copy a Queue object of type <T2> onto a
    // Queue object of type <T1> and allow the Queue
    // copy constructor to be compatible with different
    // Queue types.
    //
    // We make use of the higher level functions like 
    // enqueue() and dequeue()
    //
    //   1) The reason we need to make a copy is because
    //      the original input Queue object is constant,
    //      which means that we will not be able to modify
    //      it's state. 
    //
    //   2) Higher level functions like enqueue() and dequeue() 
    //      will modify objects internal state so calling such 
    //      functions on a constant input Queue object is not 
    //      possible without breaking the constant guarantee. 
    //      Which is why we need to make a copy of it.
    //
    //   3) Also by calling enqueue() and dequeue() we are doing
    //      code reuse :)

    // We use typename keyword because, the compiler doesn't know
    // or can not distinguish between a class and a member variable
    // so typename specifically tells the compiler that what we are 
    // declaring is a nested class and not a member variable
    typename Queue<T2>::Queue copy = input;

    while (!copy.isEmpty()) {
        enqueue(copy.getFirst());
        copy.dequeue();
    }
}

#endif //QUEUE_V2
