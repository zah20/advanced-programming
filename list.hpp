/*
 * Filename:      list.hpp
 * Version:       2.0
 * Author:        zah
 * Last Modified: Thu Nov 17, 2016 (01:31 PM)
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
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef LIST_HPP
#define LIST_HPP 

#include <cstddef>
using std::size_t;
using std::ptrdiff_t;

#include <iterator>
using std::bidirectional_iterator_tag;


namespace zh{

    class IteratorMisMatch{};
    class IteratorUninitialized{};
    class IteratorOutofRange{};

    template <typename T>
        class List {

            //============================================||
            //					          ||
            // 		       Prototype 	          ||
            //					          ||
            //============================================||
            /*                                            || 
             *   ======================================   ||
             *   |   Essential services: Class List   |   ||
             *   ======================================   ||
             *                                            ||
             *    List();                                 ||
             *    ~List();                                ||
             *    List(const List<T>&);                   ||
             *    List& operator=(const List<T>&);        ||
             *    size_type size() const;                 ||
             *    bool empty() const;                     ||
             *    void clear();                           ||
             *    reference front();                      ||
             *    const_reference front() const;          ||
             *    reference back();                       ||
             *    const_reference back() const;           ||
             *    void push_front(const T&);              ||
             *    void push_back(const T&);               ||
             *    void pop_front();                       ||
             *    void pop_back();                        ||
             *    iterator insert(iterator, const T&);    ||
             *    iterator erase(iterator);               ||
             *    iterator erase(iterator, iterator);     ||
             *    iterator begin();                       ||
             *    const_iterator const_begin() const;     ||
             *    iterator end();                         ||
             *    const_iterator const_end() const;       ||
             *                                            ||
             *    template <typename SQITR>               ||
             *        List(SQITR from, SQITR to);         ||
             *                                            ||
             *   template <typename SQITR>                ||
             *       void insert(iterator pos,            ||
             *               SQITR from, SQITR to);       ||
             *                                            ||
             *   size_type remove(const T& value);        ||
             *                                            ||
             *   template <typename UPRED>                ||
             *       size_type remove_if(UPRED condition);||
             *                                            ||
             *   void swap(List<T>& otherList);           ||
             *                                            ||
             *--------------------------------------------*/


            public:
                class RWIterator;
                class ROIterator;
                friend class RWIterator;
                friend class ROIterator;

                typedef RWIterator    iterator;
                typedef ROIterator    const_iterator;
                typedef T             value_type;
                typedef T*            pointer;
                typedef const T*      const_pointer;
                typedef T&            reference;
                typedef const T&      const_reference;
                typedef size_t        size_type;
                typedef ptrdiff_t     difference_type;
                typedef 
                    bidirectional_iterator_tag iterator_category;

                List();
                /*
                 *  Description: Create and initialize an empty
                 *               List object 
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Pre-condition:  1) Sufficient memory is available
                 *                  2) The object type T needs to provide 
                 *                     default constructor
                 *
                 *  Post-condition: 1) An empty List of size
                 *                     zero is created
                 *
                 *  Exception: 1) If insufficient memory is not 
                 *                available bad_alloc() exception will 
                 *                be thrown
                 *
                 *  Remark: Worst & Best case: O(1), as we can do our 
                 *          job in constant time
                 */


                ~List();
                /*
                 *  Description: Destroy and clean up objects in the List 
                 *               to make sure there is no memory leak
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Pre-condition:  1) It is assumed that the object of type 
                 *                     T in the List supports destructor to 
                 *                     clean itself
                 *
                 *  Post-condition: 1) We will make sure objects are removed 
                 *                     from the List object and cleaned up 
                 *                     properly so that resources that are no
                 *                     longer in use are released 
                 *
                 *  Exception: None
                 *
                 *  Remark: Worst case: O(n)
                 *          Best  case: O(1)
                 */


                List(const List<T>&);
                /*
                 *  Description: Create and initialize a new List object to 
                 *               match the state and arrangement of objects 
                 *               provided by the input List
                 *
                 *  Input: List object that we want to replicate
                 *
                 *  Output: None
                 *
                 *  Pre-condition:  1) It is assumed that sufficient memory 
                 *                     is available
                 *
                 *  Post-condition: 1) We will create and initialize a new 
                 *                     List object having the same arrangement 
                 *                     of objects and state as that of the input 
                 *                     list
                 *
                 *  Exception: 1) bad_alloc exception will be thrown if we fail 
                 *                to get sufficient memory
                 *
                 *  Remark: Worst case: O(n)
                 *          Best  case: O(1)
                 */


                List& operator=(const List<T>&);
                /*
                 *  Description: Change the state of our existing List object 
                 *               to match the state and arrangement of objects 
                 *               in the input List
                 *
                 *  Input: List object that we want to replicate
                 *
                 *  Output: Returns the list object whose state we modified
                 *
                 *  Pre-condition:  1) It is assumed that sufficient memory 
                 *                     is available
                 *                  2) It is assumed objects of type T supports
                 *                     constructor
                 *
                 *  Post-condition: 1) We will change the state of our List 
                 *                     object so that it has the same arrangement 
                 *                     of objects and state as that of the input 
                 *                     list
                 *
                 *  Exception: 1) bad_alloc exception will be thrown if we fail 
                 *                to get sufficient memory
                 *
                 *  Remark: Worst case: O(n)
                 *          Best  case: O(1)
                 */


                size_type size() const;
                /*
                 *  Description: Return the current size of our 
                 *               List object
                 *
                 *  Input: None
                 *
                 *  Output: 1) The current size of our List object
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: None
                 *
                 *  Exception: None
                 *
                 *  Remark: Best and Worst case: O(1)
                 */


                bool empty() const;
                /*
                 *  Description: Return a boolean value indicating 
                 *               whether the List object is empty 
                 *
                 *  Input: None
                 *
                 *  Output: 1) Returns true if List is empty
                 *          2) Returns false if List is not empty
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: None
                 *
                 *  Exception: None
                 *
                 *  Remark: Best and Worst case: O(1)
                 */


                void clear();
                /*
                 *  Description: Removes objects from our List and 
                 *               change its state to represent an 
                 *               empty List
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) The object type supports their 
                 *                    own destructor to clean themselves 
                 *                    up properly
                 *
                 *  Post-condition: 1) We will change the internal state 
                 *                     of our list object to represent an 
                 *                     empty list and clean up resources 
                 *                     that are no longer in use
                 *
                 *  Exception: None
                 *
                 *  Remark: Best case: O(1)
                 *          Worst case: O(n)
                 */


                reference front();
                /*
                 *  Description: Returns the first object in the List
                 *
                 *  Input: None
                 *
                 *  Output: 1) Returns the object that is the first item
                 *             on the List
                 *
                 *  Pre-condition: 1) The list is not empty
                 *
                 *  Post-condition: 1) We will allow both read and write 
                 *                     access to the object that has been 
                 *                     returned
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                const_reference front() const;
                /*
                 *  Description: Returns the first object in the List
                 *
                 *  Input: None
                 *
                 *  Output: 1) Returns the object that is the first item
                 *             on the List
                 *
                 *  Pre-condition: 1) The list is not empty
                 *
                 *  Post-condition: 1) We will allow only read access to 
                 *                     the object that has been returned
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                reference back();
                /*
                 *  Description: Returns the last object in the List
                 *
                 *  Input: None
                 *
                 *  Output: 1) Returns the object that is the last item
                 *             on the List
                 *
                 *  Pre-condition: 1) The list is not empty
                 *
                 *  Post-condition: 1) We will allow both read & write access 
                 *                     to the object that has been returned
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                const_reference back() const;
                /*
                 *  Description: Returns the last object in the List
                 *
                 *  Input: None
                 *
                 *  Output: 1) Returns the object that is the last item
                 *             on the List
                 *
                 *  Pre-condition: 1) The list is not empty
                 *
                 *  Post-condition: 1) We will allow read only access 
                 *                     to the object that has been 
                 *                     returned
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                void push_front(const T&);
                /*
                 *  Description: Insert the input object to the front 
                 *               of the list
                 *
                 *  Input: 1) Object that we want to insert into the list
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) It is assumed sufficient memory is 
                 *                    available
                 *                 2) Size of the list will be increased 
                 *                    by 1
                 *
                 *  Post-condition: 1) We will insert the input object at 
                 *                     the front of the list
                 *
                 *  Exception: 1) bad_alloc exception will be throw if we 
                 *                fail to secure sufficient memory
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                void push_back(const T&);
                /*
                 *  Description: Insert the input object to the end 
                 *               of the list
                 *
                 *  Input: 1) Object that we want to insert into the end
                 *            of the list
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) It is assumed sufficient memory is 
                 *                    available
                 *
                 *  Post-condition: 1) We will insert the input object at 
                 *                     the end of the list
                 *                  2) Size of the list will be increased 
                 *                     by 1
                 *
                 *  Exception: 1) bad_alloc exception will be throw if we 
                 *                fail to secure sufficient memory
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                void pop_front();
                /*
                 *  Description: Remove first object in the list
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) It is assumed that the object type 
                 *                    supports destructor
                 *
                 *  Post-condition: 1) We will remove the first object in 
                 *                     the list 
                 *                  2) Size of the list will be reduced by 1
                 *                     
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                void pop_back();
                /*
                 *  Description: Remove last object in the list
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) It is assumed that the object type 
                 *                    supports destructor
                 *
                 *  Post-condition: 1) We will remove the first object in 
                 *                     the list 
                 *                  2) Size of the list will be reduced by 1
                 *                     
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                iterator insert(iterator, const T&);
                /*
                 *  Description: Insert the supplied object specified by 
                 *               the 2nd parameter in front of the given 
                 *               position specified by the first parameter
                 *
                 *  Input: 1) Iterator object specifying the position to insert
                 *         2) Object that we wish to insert
                 *
                 *  Output: 1) Iterator pointing to the newly inserted object 
                 *             on the List
                 *
                 *  Pre-condition: 1) It is assumed sufficient memory will be 
                 *                    available
                 *                 2) We assume the iterator specified has been
                 *                    initialized
                 *                 3) It is assumed that the iterator specified 
                 *                    by the first parameter is pointing to the 
                 *                    same list where we want to insert
                 *
                 *  Post-condition: 1) We will insert the given object into the 
                 *                     specified position
                 *                  2) Size of the list will be increased by 1
                 *                  3) Iterator object that will be returned will 
                 *                     point to the newly inserted object
                 *  
                 *  Exception: 1) bad_alloc exception will be thrown when sufficient 
                 *                memory is not available
                 *             2) IteratorUninitialized exception will be throw if
                 *                the iterator is not pointing to any list object
                 *             3) IteratorMisMatch exception will be thrown if the
                 *                specified iterator is not part of the list where we
                 *                want to insert
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                iterator erase(iterator);
                /*
                 *  Description: Remove the object specified by the input iterator
                 *
                 *  Input: 1) Iterator object specifying the position of the object
                 *            we want to remove
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) We assume the iterator specified has been
                 *                    initialized
                 *                 2) We assume the list is not empty
                 *                 3) It is assumed that the iterator specified 
                 *                    by the first parameter is pointing to the 
                 *                    same list where we want to insert
                 *
                 *  Post-condition: 1) We will remove the object specified by the 
                 *                     iterator
                 *                  2) The size of the list will be decremented by 1
                 *  
                 *  Exception: 1) IteratorUninitialized exception will be throw if
                 *                the iterator is not pointing to any list object
                 *             2) IteratorOutofRange exception will be thrown if
                 *                the list is empty
                 *             3) IteratorMisMatch exception will be thrown if the
                 *                specified iterator is not part of the list where we
                 *                want to insert
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                iterator erase(iterator, iterator);
                /*
                 *  Description: Remove specific objects that fall with in the range 
                 *               starting from the position specified by the first 
                 *               parameter upto the position specified by the second 
                 *               parameter
                 *
                 *  Input: 1) Iterator object specifying the position of the first 
                 *            object in the range that is to be removed
                 *         2) Iterator object specifying the position of the last 
                 *            object in the range that is to be removed
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) We assume the iterators specified have been
                 *                    initialized
                 *                 2) We assume the list is not empty
                 *                 3) It is assumed that the iterators specified 
                 *                    are pointing to the same list 
                 *                 4) It is assumed that the first parameter is less
                 *                    than the second parameter
                 *
                 *  Post-condition: 1) We will remove the objects that fall with in
                 *                     the specified iterator range from the list
                 *                  2) The size of the list will be decremented by 
                 *                     the amount of objects that fall with in the
                 *                     specified iterator range
                 *  
                 *  Exception: 1) IteratorUninitialized exception will be throw if
                 *                the iterator is not pointing to any list object
                 *             2) IteratorOutofRange exception will be thrown if
                 *                the list is empty
                 *             3) IteratorMisMatch exception will be thrown if the
                 *                specified iterator is not part of the list where we
                 *                want to insert
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                iterator begin();
                /*
                 *  Description: Returns an iterator to the first object in the list
                 *
                 *  Input: None
                 *
                 *  Output: 1) Returns an iterator object pointing to the first item 
                 *             on the list
                 *
                 *  Pre-condition: 1) It is assumed that the list object is not empty
                 *
                 *  Post-condition: 1) An iterator pointing to the first object in the 
                 *                     list is returned allowing both read and write 
                 *                     access
                 *  
                 *  Exception: IteratorOutofRange exception will be thrown if the 
                 *             list is empty
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                const_iterator const_begin() const;
                /*
                 *  Description: Returns a constant_iterator object that points to 
                 *               the first object in the list
                 *
                 *  Input: None
                 *
                 *  Output: 1) Returns an const_iterator object pointing to the 
                 *             first item on the list
                 *
                 *  Pre-condition: 1) It is assumed that the list object is not empty
                 *
                 *  Post-condition: 1) An iterator pointing to the first object in the 
                 *                     list is returned allowing read only access
                 *  
                 *  Exception: IteratorOutofRange exception will be thrown if the 
                 *             list is empty
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                iterator end();
                /*
                 *  Description: Returns an iterator object that points to 
                 *               the last object in the list
                 *
                 *  Input: None
                 *
                 *  Output: 1) Returns an iterator object pointing to the 
                 *             last item on the list
                 *
                 *  Pre-condition: 1) It is assumed that the list object is not empty
                 *
                 *  Post-condition: 1) An iterator pointing to the last object in the 
                 *                     list is returned allowing both read and write 
                 *                     access
                 *  
                 *  Exception: IteratorOutofRange exception will be thrown if the 
                 *             list is empty
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                const_iterator const_end() const;
                /*
                 *  Description: Returns an const_iterator object that points to 
                 *               the last object in the list
                 *
                 *  Input: None
                 *
                 *  Output: 1) Returns an const_iterator object pointing to the 
                 *             last item on the list
                 *
                 *  Pre-condition: 1) It is assumed that the list object is not empty
                 *
                 *  Post-condition: 1) An iterator pointing to the last object in the 
                 *                     list is returned allowing read only access
                 *  
                 *  Exception: IteratorOutofRange exception will be thrown if the 
                 *             list is empty
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


                template <typename SQITR>
                    List(SQITR from, SQITR to);
                /*
                 *  Description: Creates and initialized a new List object 
                 *               on any generic container using starting 
                 *               from the position specified by the iterator 
                 *               'from' upto the ending position of the 
                 *               iterator 'to'
                 *
                 *  Input: 1) Iterator specifying the starting position in 
                 *            the container
                 *         2) Iterator specifying the ending position in 
                 *            the container
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) It is assumed that the iterators passed as 
                 *                    arguments work like
                 *                    standard iterator
                 *                    objects having support
                 *                    for ++ and * operator
                 *                 2) First argument has to be less than the second
                 *                    argument
                 *
                 *  Post-condition: 1) A new list object is created and initialized 
                 *                     to have the same arrangement of objects contained
                 *                     in the container whose iterators have been called 
                 *                  2) The size of the list is equal to the number of objects
                 *                  that are in between the 2 specified input iterators
                 *  
                 *  Exception: 1) bad_alloc exception will be thrown if we fail to secure 
                 *                enough memory 
                 *
                 *  Remark: Best case : O(1)
                 *          Worst case: O(n)
                 */


                template <typename SQITR>
                    void insert(iterator pos, 
                            SQITR from, SQITR to);
                /*
                 *  Description: Insert the supplied number of objects into 
                 *               the given position specified by the first 
                 *               parameter and starting from the position 
                 *               specified by the second parameter upto the 
                 *               end marked by the 3 parameter (iterator)
                 *
                 *  Input: 1) Iterator specifying the starting position in 
                 *            the container on which to insert
                 *         2) Iterator specifying the starting position on
                 *            a container from which we will be reading
                 *         3) Iterator specifying the ending position on the 
                 *            container from which we are reading
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) It is assumed that the iterators passed as 
                 *                    arguments in the second and third parameters 
                 *                    work like standard iterator objects having 
                 *                    support for ++ and * operator
                 *                 2) Second argument has to be less than the third
                 *                    argument
                 *                 3) It is assumed that the iterators that will be
                 *                 passed as arguments have been initialized properly
                 *                 4) It is also assumed that the container itself
                 *                 has atleast one element inside it and is not empty
                 *                
                 *  Post-condition: 1) The existing list object is populated starting 
                 *                     from the position indicated by the first parameter 
                 *                     and will contain objects that are with in the 
                 *                     range specified by the second and third parameters
                 *                  2) The size of the list is increased by the number of 
                 *                     objects that are in between the 2 specified input 
                 *                     iterators
                 *  
                 *  Exception: 1) bad_alloc exception will be thrown if we fail to secure 
                 *                enough memory 
                 *
                 *  Remark: Best & Worst case : O(1)
                 */


                size_type remove(const T& value);
                /*
                 *  Description: Remove objects from the list that have the 
                 *               same value as the specified input value
                 *
                 *  Input: Value of the object that we want to remove 
                 *
                 *  Output: Count indicating the number of objects having the 
                 *          same value that have been removed from the list
                 *
                 *  Pre-condition: 1) It is assumed that the list object is not empty
                 *                 2) The object type needs to support equality 
                 *                    comparison operator
                 *                 3) The object type needs to support destructor 
                 *                
                 *  Post-condition: 1) All the objects having the same input value are removed
                 *                     from the list and a count of the number of objects 
                 *                     are returned 
                 *  
                 *  Exception: 1) IteratorOutofRange exception will be thrown if
                 *                the list is empty
                 *
                 *  Remark: Best & Worst case : O(1)
                 */


                template <typename UPRED>
                    size_type remove_if(UPRED condition);
                /*
                 *  Description: Remove objects from the list that meet the same
                 *               input condition
                 *
                 *  Input: Generic function via a functor or a function pointer 
                 *         indicating what to do with the value of specific object
                 *
                 *  Output: Count indicating the number of objects meeting the 
                 *          same condition that have been removed from the list
                 *
                 *  Pre-condition: 1) It is assumed that the list object is not empty
                 *                 2) The object type needs to support destructor 
                 *                
                 *  Post-condition: 1) All the objects having the same input value are removed
                 *                     from the list and a count of the number of objects 
                 *                     are returned 
                 *  
                 *  Exception: 1) IteratorOutofRange exception will be thrown if
                 *                the list is empty
                 *
                 *  Remark: Best case : O(1)
                 *          Worst case: O(n)
                 */


                void swap(List<T>& otherList);
                /*
                 *  Description: Swap our list with the specified otherList
                 *
                 *  Input: List object of the same type as our existing list object
                 *
                 *  Output: None
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: 1) We make sure that the internal state remains 
                 *                     unchanged as both list objects are swapped
                 *  
                 *  Exception: None
                 *
                 *  Remark: Best & Worst case: O(1)
                 */


            private:
                class LNode;
                LNode* header;
                size_t counter;
        };

    template <typename T>
        class List<T>::LNode{
            public:
                LNode();
                LNode( const T&);
                T item;
                LNode* next;
                LNode* prev;
        };


    template <typename T>
        class List<T>::RWIterator{
            public:
                friend class List;
                typedef typename List<T>::value_type value_type;
                typedef typename List<T>::pointer pointer;
                typedef typename List<T>::reference reference;
                typedef typename List<T>::difference_type
                    difference_type; 
                typedef bidirectional_iterator_tag
                    iterator_category;


                RWIterator();
                T& operator*() const;
                T* operator->() const;
                RWIterator& operator++();
                RWIterator operator++(int);
                RWIterator& operator--();
                RWIterator operator--(int);
                bool operator==(const RWIterator&) const;
                bool operator!=(const RWIterator&) const;

            private:
                typename List<T>::LNode* ptr;
                typename List<T>::LNode* listHead;
                RWIterator(List<T>::LNode*, List<T>::LNode*);
                void assertInitialized() const;
                void assertWithinRange() const;
                void assertCanAdvance() const;
                void assertCanRetreat() const;
        };


    template <typename T>
        class List<T>::ROIterator{
            friend bool operator==(List<T>::const_iterator lhs, 
                    List<T>::const_iterator rhs){
                return (lhs.ptr == rhs.ptr);
            }
            friend bool operator!=(List<T>::const_iterator lhs,
                    List<T>::const_iterator rhs){
                return (lhs.ptr != rhs.ptr);
            }

            public:
            friend class List;
            typedef typename List<T>::value_type value_type;
            typedef typename List<T>::pointer pointer;
            typedef typename List<T>::reference reference;
            typedef typename List<T>::difference_type
                difference_type;
            typedef bidirectional_iterator_tag iterator_category;

            ROIterator();

            // Convert RWIterator to ROIterator
            // useful when we want to take advantage 
            // of implicit conversions
            ROIterator(const List<T>::RWIterator&); 

            const T& operator*() const;
            const T* operator->() const;
            ROIterator& operator++();
            ROIterator operator++(int);
            ROIterator& operator--();
            ROIterator operator--(int);

            private:
            const typename List<T>::LNode* ptr;
            const typename List<T>::LNode* listHead;
            ROIterator(const List<T>::LNode*, 
                    const List<T>::LNode*);
            void assertInitialized() const;
            void assertWithinRange() const;
            void assertCanAdvance() const;
            void assertCanRetreat() const;
        };




    //--------------------------------------------||
    //						  ||
    // 	                Class LNode               ||
    //					          ||
    //--------------------------------------------||

    template <typename T>
        List<T>::LNode::LNode(): item(){
            next = prev = NULL;
        }


    template <typename T>
        List<T>::LNode::LNode(const T& data){
            next = prev = NULL;
            item = data;
        }




    //--------------------------------------------||
    //						  ||
    // 	                Class List                ||
    //					          ||
    //--------------------------------------------||

    template <typename T>
        List<T>::List(){
            counter = 0;
            header = new LNode;
            header->next = header;
            header->prev = header;
        }


    template <typename t>
        List<t>::~List(){
            clear();
            delete header;
        }


    template <typename T>
        List<T>::List(const List& inputList){
            counter = 0;
            header = new LNode;
            header->next = header;
            header->prev = header;
            *this = inputList;
        }


    template <typename T>
        List<T>& List<T>::operator=(const List<T>& rhs){
            if (this != &rhs){
                clear();
                auto itr(rhs.const_begin());

                for (; itr != rhs.const_end(); ++itr){
                    push_back(*itr);
                }
            }
            return *this;
        }


    template <typename T>
        typename List<T>::size_type List<T>::size() const{
            return counter; 
        }


    template <typename T>
        bool List<T>::empty() const{
            if (counter == 0){
                return true;
            }else{
                return false;
            }
        }


    template <typename T>
        void List<T>::clear(){
            while (!empty()){
                pop_front();
            }
        }


    template <typename T>
        inline typename List<T>::reference
        List<T>::front(){
            return *begin();    
        }


    template <typename T>
        inline typename List<T>::const_reference
        List<T>::front() const{
            return *begin();    
        }


    template <typename T>
        inline typename List<T>::reference
        List<T>::back(){
            return *(--end());
        }


    template <typename T>
        inline typename List<T>::const_reference
        List<T>::back() const{
            return *(--end());
        }


    template <typename T>
        void List<T>::push_front (const T& item){
            insert(begin(), item);
        }


    template <typename T>
        void List<T>::push_back (const T& item){
            insert(end(), item);
        }


    template <typename T>
        void List<T>::pop_front (){
            if (!empty()){
                erase(begin());
            }
        }


    template <typename T>
        void List<T>::pop_back (){
            if (!empty()){
                erase(--(end()));
            }
        }


    template <typename T>
        typename List<T>::iterator List<T>::insert(
                iterator inputIter, const T& inputObj ){

            inputIter.assertInitialized();

            if (inputIter.listHead != header){
                throw IteratorMisMatch();
            }

            List<T>::LNode* LNodeOnHeap = new LNode(inputObj);

            LNodeOnHeap->next = inputIter.ptr;
            LNodeOnHeap->prev = inputIter.ptr->prev;
            (inputIter.ptr->prev)->next = LNodeOnHeap;
            inputIter.ptr->prev = LNodeOnHeap;

            ++counter;

            return typename List<T>::iterator(header, LNodeOnHeap);
        }


    template <typename T>
        typename List<T>::iterator List<T>::erase(
                List<T>::iterator inputIter){

            inputIter.assertInitialized();
            inputIter.assertWithinRange();

            if (inputIter.listHead != header){
                throw IteratorMisMatch();
            }

            auto currentNode = inputIter.ptr;

            // The code below would have been preferable
            // to improve readability
            //auto prevNode = currentNode->prev;
            //auto nextNode = currentNode->next;
            //prevNode->next = nextNode;
            //nextNode->prev = prevNode;
            ((inputIter.ptr)->prev)->next = (inputIter.ptr)->next;
            ((inputIter.ptr)->next)->prev = (inputIter.ptr)->prev;

            ++inputIter;
            delete currentNode;
            --counter;

            return inputIter;
        }


    template <typename T>
        typename List<T>::iterator List<T>::erase(
                iterator frontIter, iterator endIter){
            iterator currentIter = frontIter;

            while (currentIter != endIter){
                currentIter = erase(currentIter);
            }

            return currentIter;
        }


    template <typename T>
        typename List<T>::iterator List<T>::begin(){
            iterator currentIter(header, header->next);
            return currentIter;
        }


    template <typename T>
        typename List<T>::const_iterator 
        List<T>::const_begin() const{
            const_iterator currentIter(header, header->next);
            return currentIter;
        }


    template <typename T>
        typename List<T>::iterator List<T>::end(){
            return List<T>::iterator(header, header);
        }


    template <typename T>
        typename List<T>::const_iterator 
        List<T>::const_end() const{
            return List<T>::const_iterator(header, header);
        }


    template <typename T>
        template <typename SQITR>
        List<T>::List(SQITR from, SQITR to){
            SQITR current = from;
            counter = 0;
            header = new LNode;
            header->next = header;
            header->prev = header;

            while (current != to){
                push_back(*(current));
                ++current;
            }
        }


    template <typename T>
        template <typename SQITR>
        void List<T>::insert(iterator pos,
                SQITR from, SQITR to){

            SQITR current = from;
            iterator copyIter = pos;

            while (current != to){
                insert(copyIter, (*current)); 
                ++current;
            }
        }


    template <typename T>
        typename List<T>::size_type 
        List<T>::remove(const T& value){
            auto currentIter = begin();    
            size_type counter = 0;

            while (currentIter != end()){
                if ( (*currentIter) == value){
                    // erase() automatically 
                    // increments iterator 
                    // so we don't need to 
                    // increment currentIter
                    erase(currentIter);
                    ++counter;
                } else{
                    ++currentIter;
                }
            }

            return counter;
        }


    template <typename T>
        template <typename UPRED>
        typename List<T>::size_type
        List<T>::remove_if(UPRED condition){
            size_type counter = 0;
            iterator currentIter = begin();

            while (currentIter != end()){
                if(condition(*currentIter)){
                    erase(currentIter); 
                    ++counter;
                } else{
                    ++currentIter;
                }

            }
            return counter;
        }


    template <typename T>
        void List<T>::swap( List<T>& otherList){
            if (this == &otherList){
                return; 
            }

            auto tempHeader = this->header;
            size_t tempCounter = this->counter;

            this->header = otherList.header;
            this->counter = otherList.counter;

            otherList.header = tempHeader;
            otherList.counter = tempCounter;

        }




    //--------------------------------------------||
    //						  ||
    // 	             Class RWIterator             ||
    //					          ||
    //--------------------------------------------||

    template <typename T>
        List<T>::RWIterator::RWIterator(): 
            ptr(nullptr), listHead(nullptr){}


    template <typename T>
        T& List<T>::RWIterator::operator*() const{
            assertInitialized();
            assertWithinRange();
            return ptr->item;
        }


    template <typename T>
        T* List<T>::RWIterator::operator->() const{
            assertInitialized();
            assertWithinRange();
            return &(ptr->item);
        }


    template <typename T>
        typename List<T>::RWIterator& 
        List<T>::RWIterator::operator++(){
            assertInitialized();
            assertCanAdvance();
            ptr = ptr->next;
            return *this;
        }


    template <typename T>
        typename List<T>::RWIterator 
        List<T>::RWIterator::operator++(int){
            assertInitialized();
            assertCanAdvance();
            auto oldValue = *this;
            ++(*this);
            return oldValue;
        }

    template <typename T>
        typename List<T>::RWIterator&
        List<T>::RWIterator::operator--(){
            assertInitialized();
            assertCanRetreat();
            ptr = ptr->prev;
            return *this;
        }


    template <typename T>
        typename List<T>::RWIterator
        List<T>::RWIterator::operator--(int){
            assertInitialized();
            assertCanRetreat();
            auto oldValue = *this;
            --(*this);
            return oldValue;
        }


    template <typename T>
        bool List<T>::RWIterator::operator==
        (const RWIterator& rhs) const{
            if (this->ptr == rhs.ptr){
                return true;
            }else{
                return false;
            }
        }


    template <typename T>
        bool List<T>::RWIterator::operator!=
        (const RWIterator& rhs) const {
            if (this->ptr != rhs.ptr){
                return true;
            }else{
                return false;
            }
        }


    template <typename T>
        List<T>::RWIterator::RWIterator(
                List<T>::LNode* ptrToDummy,
                typename List<T>::LNode* ptrToElement):
            listHead(ptrToDummy), ptr(ptrToElement){}


    template <typename T>
        void List<T>::RWIterator::assertInitialized() const{
            if (ptr == nullptr){
                throw IteratorUninitialized();
            }
        }


    template <typename T>
        void List<T>::RWIterator::assertWithinRange() const{
            if (ptr == listHead){
                throw IteratorOutofRange();
            }
        }


    template <typename T>
        void List<T>::RWIterator::assertCanAdvance() const{
            if (ptr == listHead){
                throw IteratorOutofRange();
            }
        }


    template <typename T>
        void List<T>::RWIterator::assertCanRetreat() const{
            if (ptr->prev == listHead){
                throw IteratorOutofRange();
            }
        }




    //--------------------------------------------||
    //						  ||
    // 	             Class ROIterator             ||
    //					          ||
    //--------------------------------------------||

    template <typename T>
        List<T>::ROIterator::ROIterator(): 
            ptr(nullptr), listHead(nullptr){};


    template <typename T>
        List<T>::ROIterator::ROIterator(
                const List<T>::RWIterator& inputIter){
            this->ptr = inputIter.ptr;
            this->listHead = inputIter.listHead;
        }


    template <typename T>
        const T& List<T>::ROIterator::operator*() const{
            assertInitialized();
            assertWithinRange();
            return ptr->item;
        }


    template <typename T>
        const T* List<T>::ROIterator::operator->() const{
            assertInitialized();
            assertWithinRange();
            return &(ptr->item);
        }


    template <typename T>
        typename List<T>::ROIterator& 
        List<T>::ROIterator::operator++(){
            assertInitialized();
            assertCanAdvance();
            this->ptr = ptr->next;
            return *this;
        }


    template <typename T>
        typename List<T>::ROIterator 
        List<T>::ROIterator::operator++(int){
            assertInitialized();
            assertCanAdvance();
            auto oldValue = *this;
            ++(*this);
            return oldValue;
        }


    template <typename T>
        typename List<T>::ROIterator& 
        List<T>::ROIterator::operator--(){
            assertInitialized();
            assertCanRetreat();
            this->ptr = this->ptr->prev;
            return this;
        }


    template <typename T>
        typename List<T>::ROIterator 
        List<T>::ROIterator::operator--(int){
            assertInitialized();
            assertCanRetreat();
            auto oldValue = *this;
            --(*this);
            return oldValue;
        }


    template <typename T>
        List<T>::ROIterator::ROIterator(
                const typename List<T>::LNode* ptrToDummy,
                const List<T>::LNode* ptrToElement):
            listHead(ptrToDummy), ptr(ptrToElement){}


    template <typename T>
        void List<T>::ROIterator::assertInitialized() const{
            if (ptr == nullptr){
                throw IteratorUninitialized();
            }
        }


    template <typename T>
        void List<T>::ROIterator::assertWithinRange() const{
            if (ptr == listHead){
                throw IteratorOutofRange();
            }
        }


    template <typename T>
        void List<T>::ROIterator::assertCanAdvance() const{
            if (ptr == listHead){
                throw IteratorOutofRange();
            }
        }


    template <typename T>
        void List<T>::ROIterator::assertCanRetreat() const{
            if (ptr->prev == listHead){
                throw IteratorOutofRange();
            }
        }


}
#endif /* ifndef LIST_HPP */

