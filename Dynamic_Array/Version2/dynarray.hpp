/*
 * Filename:      darray.hpp
 * Version:       2.0
 * Author:        zah
 * Last Modified: Thu Nov 10, 2016 (09:17 AM)
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


#ifndef DARRAY
#define DARRAY 
#include <cstddef>
using std::size_t;
#include <new>
using std::bad_alloc;


namespace zh{


    //============================================||
    //					          ||
    // 		       Prototype 	          ||
    //					          ||
    //============================================||


    class OutOfMemory{};
    class ArrayEmpty{};
    class InvalidIndexException{};

    template <typename T>
        class DArray{

            /*  // Summary of available services
             *
             *  DArray();
             *
             *  explicit DArray(size_t);
             *
             *  DArray(size_t, const T&);
             *
             *  ~DArray() noexcept;
             *  
             *  DArray(const DArray<T>&);
             *
             *  DArray<T>& operator=(const DArray<T>&);
             *
             *  const T& operator[](size_t) const;
             *
             *  T& operator[](size_t);
             *
             *  void resize(size_t, const T& = T());
             *
             *  size_t size() const;
             *
             *  bool isEmpty() const;
             *
             *  void clear();
             *
             *  void add(const T&, size_t);
             *  
             *  void append(const T&);
             *
             *  void remove(size_t index);
             *
             *  void remove_last();
             *
             *  template <typename Y>
             *      DArray(const DArray<Y>&);
             *      
             *  size_t capacity() const;
             *
             *  void reserve(size_t);
             */


            public:
                typedef T* iterator;
                typedef const T* const_iterator;

                iterator begin(){ return &buffer[0];};
                iterator end(){return &buffer[size()];};
                const_iterator begin() const{ return &buffer[0];};
                const_iterator end() const{return &buffer[size()];};

                DArray();
                /*
                 *  Description: Create and initialize an empty 
                 *               Dynamic Array object
                 *
                 *  Input:  None 
                 *
                 *  Output: None
                 *
                 *  Pre-condition:  1) Sufficient memory is available
                 *
                 *  Post-condition: 1) An array of type <T> with 
                 *                     logical size of zero is created 
                 *                  2) Preallocation of memory is done 
                 *                     in advance to reduce the 
                 *                     frequency of reallocation
                 *
                 *  Exception: 1) If sufficient memory is not available 
                 *                OutOfMemory() exception will be thrown
                 *                
                 *
                 *  Remark: Best & Worse case: O(1), as it is the 
                 *          default constructor we preallocate fixed
                 *          amount of memory on the heap and since
                 *          the logical size is zero we do not 
                 *          create or initiatialize any objects 
                 *          which means we can do our job in 
                 *          constant time 
                 *
                 */


                explicit DArray(size_t);
                /*
                 *  Description: Create and initialize a Dynamic 
                 *               Array object of the specified size
                 *
                 *  Input: Initial size of the dynamic array 
                 *
                 *  Output: None
                 *
                 *  Pre-condition:  1) Sufficient memory is available
                 *                  2) The object type T needs to provide 
                 *                     default constructor
                 *
                 *  Post-condition: 1) An array of type <T> with the 
                 *                     specified logical size is 
                 *                     created and initialized by 
                 *                     calling default constructor 
                 *                     of each object of type T
                 *                  2) Preallocation of memory is done 
                 *                     in advance to reduce the 
                 *                     frequency of reallocation
                 *
                 *  Exception: 1) If insufficient memory is not 
                 *                available OutOfMemory() exception will 
                 *                be thrown
                 *
                 *  Remark: Worst case: O(n), as we have to create and 
                 *          initialize n number of objects
                 *
                 *          Best case: O(1), as we preallocate buffer 
                 *          to a fixed size is the specified input size 
                 *          is less than or equal to 5. Which is why we 
                 *          can always do the job in constant time
                 */


                DArray(size_t, const T&);
                /*
                 *  Description: Create and initialize Dynamic Array
                 *               object according to given size and
                 *               initial value.
                 *
                 *  Input: 1) Initial size of the array 
                 *         2) Value the objects in the array will be
                 *            initialized to
                 *
                 *  Output: None
                 *
                 *  Pre-condition:  1) Sufficient memory is available
                 *                  2) It is assumed that an appropriate
                 *                     value is specified as the second
                 *                     parameter depending on the type 
                 *                     of object
                 *
                 *  Post-condition: 1) Dynamic array will be created 
                 *                     to be of the specified size 
                 *                     indicated by the first
                 *                     parameter and it's objects 
                 *                     initialized to the specified 
                 *                     value (2nd parameter)
                 *                  2) Preallocation of memory is done
                 *                     in order to reduce the
                 *                     frequency of reallocation
                 *
                 *  Exception: 1) If insufficient memory is available 
                 *                OutOfMemory() exception will be thrown
                 *
                 *  Remark: 
                 *          Worst case: O(n), as we have to create an
                 *          array of n number of objects and initialize
                 *          the values to the specified value or call 
                 *          its constructor if value is not present
                 *          we are not do our job in constant time
                 *          
                 *          Best case: O(1), when the specified size 
                 *          is less than or equal to 5, we preallocate
                 *          buffer to a fixed size depending on the 
                 *          object type.  Which is why it always does 
                 *          the job in constant time
                 */


                ~DArray() noexcept;
                /*
                 *  Description: Delete the array object and cleanup
                 *               properly to ensure there are no memory
                 *               leaks
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: Array object will be cleaned up
                 *                  properly by calling the object types
                 *                  own destructor
                 *
                 *  Exception: None
                 *
                 *  Remark: Worst case: O(n), we need to clean up array
                 *          which has n number of objects
                 *
                 *          Best case: O(1), when the logical size is zero 
                 *          indicating there are no objects that need
                 *          to be cleaned up. Therfore we can release the 
                 *          memory on the heap which can be done in 
                 *          constant time
                 */


                DArray(const DArray<T>&);
                /*
                 *  Description: Create & initialize our Dynamic array to
                 *               represent the same state as the input
                 *               Dynamic array object on a logical level
                 *
                 *  Input: Dynamic array object of type <T> whose state
                 *         we wish to replicate
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) Sufficient memory is available
                 *                 2) We assume that the Dynamic array
                 *                    whose state we want to replicate 
                 *                    is of the same type as the dynamic
                 *                    array we will be creating
                 *
                 *  Post-condition: 1) The state of our new dynamic
                 *                     array will be the same as that of
                 *                     the input object on a logical
                 *                     level and will have the same
                 *                     arrangment of internal objects
                 *                     as well as the same value
                 *                     depending on the type
                 *                  2) Preallocation of memory is done 
                 *                     to reduce the frequency of 
                 *                     reallocation
                 *
                 *  Exception: 1) OutOfMemory() exception will be thrown
                 *                when there is insufficient memory
                 *
                 *  Remark: Worst case: O(n) as we need to create a new
                 *          dynamic array of size n and initialize each
                 *          object with given value or by calling
                 *          default constructor
                 *
                 *          Best case: O(1), if the input dynamic array
                 *          object is of size zero we can do our job in
                 *          constant time
                 *               
                 */


                DArray<T>& operator=(const DArray<T>&);
                /*
                 *  Description: Change existing state of our dynamic
                 *               array to represent the state of the
                 *               input dynamic array object
                 *
                 *  Input: 1) Dynamic array object whose state we 
                 *            wish to replicate
                 *
                 *  Output: 1) Modified dynamic array object
                 *             is returned
                 *
                 *  Pre-condition: 1) Sufficient memory is available
                 *                 2) Input dynamic array object has to
                 *                    be of the same type as the dynamic
                 *                    array that is being modified
                 *                 3) The object type needs to support 
                 *                    assignment function
                 *
                 *  Post-condition: 1) We modify the state of our
                 *                     dynamic array object to represent
                 *                     the same state as that of the
                 *                     passed input object on a logical
                 *                     level
                 *
                 *  Exception: 1) An exception of OutOfMemory() is thrown
                 *                if we fail to get sufficient memory to
                 *                do our job properly
                 *
                 *  Remark: Worst case: O(n), as we may have to change 
                 *          our state and initialize n number of objects
                 *          including allocating the buffer to a bigger 
                 *          size and copying the new objects
                 *
                 *          Best case: O(1), as the passed in input
                 *          object is the same object that we are
                 *          modifying therefore we just return it and 
                 *          we can do that in constant time
                 *
                 */


                const T& operator[](size_t) const;
                /*
                 *  Description: Provide read only access to a
                 *               particular object at the specified
                 *               index
                 *
                 *  Input: 1) Index of the requested object in the array
                 *
                 *  Output: 1) The object at the specified index
                 *
                 *  Pre-condition: 1) The specified index has to be with
                 *                    in the valid range of the array 
                 *                    (size()-1)
                 *
                 *  Post-condition: 1) We will not make any modification
                 *                     to the state of our array object
                 *
                 *  Exception: 1) Throws InvalidIndexException() if the
                 *                input index is equal to or greater
                 *                than the size of the array
                 *
                 *  Remark: Best & Worst case: O(1), as we can provide 
                 *          access in constant time
                 *
                 */


                T& operator[](size_t);
                /*
                 *  Description: Provide read and write access to a
                 *               particular object at the specified
                 *               index
                 *
                 *  Input: 1) Index of the requested object in the array
                 *
                 *  Output: 1) The object at the specified index
                 *
                 *  Pre-condition: 1) The specified index has to be with
                 *                    in the valid range of the array 
                 *                    (size()-1)
                 *
                 *  Post-condition: 1) We will not make any modification
                 *                     to the state of our array object
                 *
                 *  Exception: 1) Throws InvalidIndexException() if the
                 *                input index is equal to or greater
                 *                than the size of the array
                 *
                 *  Remark: Best & Worst case: O(1), as we can provide 
                 *          access in constant time
                 *
                 */


                void resize(size_t, const T& = T());
                /*
                 *  Description: Change the size of our dynamic
                 *               array to the specified size.  
                 *
                 *  Input: 1) Size which we want our array to have
                 *         2) Value which our object will be
                 *         initialized to if our existing array size
                 *         is increased and we have to initialize
                 *         the new objects
                 *
                 *  Output: None
                 *
                 *  Pre-condition:  1) We assume sufficient memory is 
                 *                     available
                 *                  2) We assumed that the input type T 
                 *                  has a default constructor
                 *                  3) We assume the object of type T 
                 *                  has a destructor
                 *
                 *  Post-condition: 1) If the specified size is higher 
                 *                  than the curret size, then the
                 *                  array is resized to the bigger
                 *                  size and the new objects in the 
                 *                  array are initialized with the 
                 *                  values specified in the second
                 *                  parameter. If no parameter is
                 *                  present then the default constructor 
                 *                  of the object type is called.
                 *
                 *                  2) If specified size is smaller
                 *                  than the existing size of the
                 *                  array, the logical size of the 
                 *                  array is shrunk to match the 
                 *                  specified size and the
                 *                  objects are properly
                 *                  destroyed by calling
                 *                  their respective
                 *                  destructor
                 *
                 *  Exception: 1) OutOfMemory() exception is thrown
                 *                when insufficient memory is
                 *                available
                 *
                 *  Remark: Worst case: O(n), as we have to
                 *          reallocate more memory since the
                 *          specified size is larger than our
                 *          existing buffer size
                 *
                 *          Best case: O(1), as the specified size
                 *          is less than or equal to the logical 
                 *          size of our existing array size
                 */


                size_t size() const noexcept;
                /*
                 *  Description: Return the logical size of 
                 *               our array
                 *
                 *  Input: None
                 *
                 *  Output: 1) The current size of the dynamic 
                 *             array object
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: None
                 *
                 *  Exception: None
                 *
                 *  Remark: Best and Worst case: O(1), as it just
                 *          returns the size of the array which 
                 *          can be done in constant time
                 */


                bool isEmpty() const noexcept;
                /*
                 *  Description: Returns true if our array is empty,
                 *               or false if array has atleast 1 
                 *               object in it
                 *
                 *  Input: None
                 *
                 *  Output: Boolean value indicating whether dynamic
                 *          array is empty or not
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: None
                 *
                 *  Exception: None
                 *
                 *  Remark: Best and Worst case: O(1), as it just
                 *          returns the size of the array
                 */


                void clear();
                /*
                 *  Description: Changes the state of our dynamic
                 *               array to represent an empty array
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: 1) We will change internal state 
                 *                     of our array to represent an 
                 *                     empty array and free up memory 
                 *                     by freeing up objects that are
                 *                     no longer in use
                 *
                 *  Exception: None
                 *
                 *  Remark: Worst Case: O(n), as we have to remove n 
                 *          number of objects from the array and call 
                 *          their destructor to free up the resources
                 *
                 *          Best Case: O(1), as we can do our job in 
                 *          constant time provided that there is only 
                 *          one object on the array 
                 *
                 */


                void add(const T&, size_t);
                /*
                 *  Description: Increase the size of our dynamic
                 *               array by 1 and adds one object
                 *               whose value is specified by the 
                 *               first parameter to the index 
                 *               specified by the second parameter 
                 *               aswell as making sure that the 
                 *               existing data in that position 
                 *               is not over written by shifting 
                 *               around the existing values
                 *               appropriately
                 *
                 *  Input: 1) Value that we want the index to be set
                 *         2) Index at which we want to add the
                 *            element
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) We assume sufficient memory is
                 *                    available
                 *                 2) Index has to be with in valid
                 *                    range which is zero to size
                 *                 3) It is assumed that the object 
                 *                    of type <T> is a first class object
                 *                    that supports assignment operator 
                 *                    function
                 *
                 *  Post-condition: 1) We will add the specified
                 *                     value to the element at the
                 *                     specified index by calling the 
                 *                     objects assignment operator 
                 *                     and make sure that the previous 
                 *                     value is not overwritten by 
                 *                     shifting them appropriately 
                 *                     to the right to make space 
                 *                     for the new value
                 *                  2) If specified index is equal
                 *                     to the size of the array,
                 *                     then the size of the array is
                 *                     expanded by one and new value
                 *                     is appended at the end
                 *
                 *  Exception: 1) Throws OutOfMemory() if insufficient
                 *                memory is available
                 *             2) Throws InvalidIndexException()
                 *                when the index is greater than 
                 *                the valid range (zero to size)
                 *
                 *  Remark: Worst Case: O(n), if adding one more
                 *          element would cause us to reallocate to
                 *          a new buffer which also means copying
                 *          previous elements
                 *
                 *          Best Case: O(1), if buffer size is
                 *          sufficient, and we have to append the
                 *          new element to the end we can do our job
                 *          in constant time
                 */


                void append(const T&);
                /*
                 *  Description: Append the specified object to 
                 *               the end of the array 
                 *
                 *  Input: Value that the object will be
                 *         assigned  to
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) It is assumed that sufficient
                 *                    memory is available
                 *                 2) It is assumed that the input
                 *                    object type is the same as the
                 *                    type of the array
                 *
                 *  Post-condition: 1) The specified value will be
                 *                     appended to the end of array
                 *                  2) Size of Dynamic Array will be 
                 *                     incremented by 1
                 *
                 *  Exception: 1) OutOfMemory() exception will be
                 *                thrown if we fail to get
                 *                sufficient memory 
                 *
                 *  Remark: Worst Case: O(n), as we have to end up
                 *          reallocating the buffer and copying upto
                 *          n number of objects onto the new buffer
                 *          from old buffer as well as append the new 
                 *          object into the array
                 *
                 *          Best Case: O(1), as the buffer size is
                 *          large enough so we can just append the
                 *          new object in constant time
                 *          
                 */


                void remove(size_t index);
                /*
                 *  Description: Remove an object from the specified
                 *               index
                 *
                 *  Input: 1) Index of the object that we want to
                 *            remove from the array
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) Index has to be with in valid
                 *                    range which is 0 to size-1
                 *
                 *  Post-condition: 1) The object at the specified
                 *                     index will be removed and the
                 *                     objects following it (if any)
                 *                     will be shifted accordingly
                 *                     to the left
                 *
                 *  Exception: 1) InvalidIndexException will be
                 *                thrown if the index is not with in
                 *                the valid range which is 0
                 *                to size-1
                 *
                 *  Remark: Worst Case: O(n), as we have to shift n
                 *          number of objects to the left to make
                 *          up for the object that has been removed
                 *          from the first index
                 *
                 *          Best Case: O(1), the object at the last
                 *          index is removed therefore we don't have
                 *          to do any shifting and can do it in
                 *          constant time
                 */


                void remove_last();
                /*
                 *  Description: Remove the last element in the
                 *               dynamic array
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) We assume the array is not
                 *                    empty
                 *
                 *  Post-condition: 1) We remove the last object in
                 *                     the array
                 *                  2) We free up the resource that 
                 *                     has been removed by calling 
                 *                     the objects destructor
                 *
                 *  Exception: 1) ArrayEmpty() exception is thrown
                 *                is size of array is zero
                 *
                 *  Remark: Worst & Best Case: O(1), as we can
                 *          always remove the last object in the 
                 *          array in constant time 
                 */


                template <typename Y>
                    DArray(const DArray<Y>&);
                /*
                 *  Description: Create and initialize a dynamic 
                 *               array object of type <T> to 
                 *               represent the same state as the 
                 *               given input dynamic array object 
                 *               of type <Y>
                 *
                 *  Input: Dynamic array object of a different type 
                 *         than our the dynamic object we will create
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) Sufficient memory is available
                 *                 2) We assume that the Dynamic array
                 *                    whose state we want to replicate 
                 *                    is of a different type as the 
                 *                    dynamic array we will be creating
                 *                 3) It is assumed that the type of 
                 *                 input Dynamic Array object that is
                 *                 passed is different from our own type
                 *
                 *  Post-condition: 1) We create and initialize dynamic 
                 *                     array object from the given input 
                 *                     dynamic array object and we assume 
                 *                     that both are of different types
                 *                  2) The newly created object has the 
                 *                  same state as the input object on a 
                 *                  logical level
                 *
                 *  Exception: OutOfMemory() exception will be thrown if we 
                 *             fail to get insufficient memory
                 *
                 *  Remark: Best and Worst case: O(n) as we need to create 
                 *          a new dynamic array of size n and initialize 
                 *          each object with value of the input dynamic 
                 *          object
                 */


                size_t capacity() const;
                /*
                 *  Description: Returns the current physical size 
                 *               of the dynamic array
                 *
                 *  Input: None
                 *
                 *  Output: Physical size of the array
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: None
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worst Case: O(1), as we can 
                 *          always do our job in constant time
                 */


                void reserve(size_t);
                /*
                 *  Description: Changes physical size of the array 
                 *               to be atleast equal to the specified 
                 *               size. If specified size is less than 
                 *               current physical size, then it is 
                 *               ignored 
                 *
                 *  Input: 1) Size that we want the arrays physical
                 *            size to be equal to
                 *
                 *  Output: None
                 *
                 *  Pre-condition: 1) Sufficient memory is available
                 *
                 *  Post-condition: 1) The physical size of the array 
                 *                     will be expanded to be of the 
                 *                     specified input size, if input 
                 *                     size is greater than physical 
                 *                     size
                 *                  2) No change to logical size and 
                 *                  structure of existing objects if
                 *                  input size is less than or equal 
                 *                  to the logical size
                 *
                 *
                 *  Exception: 1) OutOfMemory() exception will be thrown 
                 *                if there is insufficient memory 
                 *                available
                 *
                 *  Remark: Worst Case: O(n), considering current buffer 
                 *          has to be reallocated and the existing 
                 *          objects need to be copied onto new buffer
                 *
                 *          Best Case: O(1), as the specified size is 
                 *          smaller than the existing physical size
                 *          therefore no reallocation of memory is 
                 *          required and we can do our job in constant 
                 *          time
                 */


            private:
                T* buffer;
                size_t physicalSize; // Physical size
                size_t logicalSize; // Logical size
                unsigned char* myHeap;
                static const unsigned unitSize = sizeof(T);
                static const size_t SIZE_DEFAULT = 5; 
                static constexpr float PREALLOC_PERCENT = 1.50;


                bool initObject(size_t, size_t, T*, const T& = T());
                /*
                 *  Description: Initialize object of type T
                 *               onto the buffer specified by third
                 *               parameter, starting from index
                 *               indicated by first parameter and
                 *               ending at index (second parameter - 1).
                 *               The objects will be initialized to the
                 *               value specified by the fourth
                 *               parameter, if it is missing the default
                 *               constructor of the object type will be
                 *               called to initialize it
                 *
                 *  Input:  1) Starting index on the buffer 
                 *          2) Ending index + 1
                 *          3) Location of the buffer
                 *          4) Value the object(s) will be initialized to 
                 *
                 *  Output: 1) Returns True if creation and initialization 
                 *             of the object(s) were done successfully
                 *          2) Returns False if we run into errors 
                 *             especially when allocating memory on the 
                 *             heap
                 *
                 *  Pre-condition:  1) Sufficient memory is available
                 *                  2) First parameter is less than second
                 *                     parameter
                 *                  3) It is assumed that inputBuffer is 
                 *                  large enough to do our job
                 *
                 *  Post-condition: 1) Objects will be created and 
                 *                     initialized according to given 
                 *                     value on the specified buffer and
                 *                     the given range
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worse case: O(n), as we need to create 
                 *          and initialize n number of objects on the 
                 *          buffer
                 * 
                 *  
                 */


                void initPhysicalSize(size_t);
                /*
                 *  Description: Change physical size to the
                 *               specified size
                 *
                 *  Input:  1) Size that we want our physical 
                 *             size to have 
                 *
                 *  Output: None
                 *
                 *  Pre-condition:  None
                 *
                 *  Post-condition: 1) If size is less than or equal 
                 *                     to 5, physical size will be set 
                 *                     to SIZE_DEFAULT which currently 
                 *                     has value of 10
                 *
                 *                  2) If size is greatr
                 *                     than 5, physical size
                 *                     will be set to 1.5
                 *                     times input size
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worse case: O(1), as we can do our 
                 *          job in constant time 
                 */


                void cleanHeap();
                /*
                 *  Description: Delete and free myHeap and make sure 
                 *               the pointers myHeap and buffer are 
                 *               set to nullptr to prevent accidental 
                 *               usage
                 *
                 *  Input:  None 
                 *
                 *  Output: None
                 *
                 *  Pre-condition:  1) myHeap pointer has to be initialized 
                 *                     to point to memory location on the 
                 *                     heap
                 *
                 *  Post-condition: 1) myHeap is deleted and the pointers 
                 *                     myHeap and buffer are set to nullptr
                 *
                 *  Exception: None
                 *
                 *  Remark: Best & Worse case: O(1), as we can delete the 
                 *          buffer pointed to by myHeap in constant time
                 *
                 */

        };




    //============================================||
    //						  ||
    // 	               Definition 		  ||
    //					          ||
    //============================================||


    template <typename T>
        DArray<T>::DArray(): logicalSize(0), physicalSize(0), 
        buffer(nullptr), myHeap(nullptr){

            try{
                myHeap = new unsigned char[SIZE_DEFAULT*unitSize]; 
                buffer = reinterpret_cast<T*>(myHeap);
                physicalSize = SIZE_DEFAULT;
            }catch (bad_alloc){
                throw OutOfMemory();
            }
        }


    template <typename T>
        DArray<T>::DArray(size_t inputSize): 
            logicalSize(inputSize), buffer(nullptr), myHeap(nullptr){

                // Setting the correct physical size
                initPhysicalSize(inputSize);

                // We try to get the required memory on heap
                // and make buffer point to the same thing
                try{
                    myHeap = new unsigned char[physicalSize * unitSize]; 
                    buffer = reinterpret_cast<T*>(myHeap);
                }catch (bad_alloc){
                    physicalSize = logicalSize = 0;
                    throw OutOfMemory();
                }

                // Creating and initializing objects of
                // type <T> on our buffer
                bool status = initObject(0, logicalSize, buffer, T());

                if (status == false){
                    logicalSize = 0;
                    cleanHeap();
                    throw OutOfMemory();
                }
            }


    template <typename T>
        DArray<T>::DArray(size_t inputSize, const T& input):
            logicalSize(inputSize), buffer(nullptr), myHeap(nullptr){

                initPhysicalSize(inputSize);

                // Trying to get sufficient memory
                try{
                    myHeap = new unsigned char[physicalSize*unitSize];
                    buffer = reinterpret_cast<T*>(myHeap);
                }catch (bad_alloc){
                    physicalSize = logicalSize = 0;
                    throw OutOfMemory();   
                }

                // Creating and initializing objects on
                // logical size section of the memory
                bool status = initObject(0, logicalSize, buffer, input);

                if (status == false){
                    logicalSize = 0;
                    cleanHeap();
                    throw OutOfMemory();
                }
            }


    template <typename T>
        DArray<T>::~DArray() noexcept{
            clear();
            cleanHeap();
        }


    template <typename T>
        DArray<T>::DArray(const DArray<T>& copy): buffer(nullptr), 
        myHeap(nullptr), logicalSize(0), physicalSize(0){
            *this = copy;
        }


    template <typename T>
        DArray<T>& DArray<T>::operator=(const DArray<T>& rhs) {
            if (this != &rhs){

                resize(rhs.size(), T());

                for (size_t i=0; i < logicalSize; ++i){
                    *(buffer+i) = *(rhs.buffer+i);
                }
            }

            return *this;
        }


    template <typename T>
        const T& DArray<T>::operator[](size_t index) const{
            if (index < logicalSize){
                return *(buffer+index);
            }else{
                throw InvalidIndexException();
            }
        }


    template <typename T>
        T& DArray<T>::operator[](size_t index) {
            if (index < logicalSize){
                return *(buffer+index);
            }else{
                throw InvalidIndexException();
            }
        }


    template <typename T>
        void DArray<T>::resize(size_t inputSize, const T& value){
            if (inputSize > logicalSize){

                if (inputSize > physicalSize){
                    reserve((inputSize * PREALLOC_PERCENT));
                }

                // Initializing new objects on buffer 
                // with input value
                bool status = initObject(logicalSize, inputSize,
                        buffer, value);

                if (status == false){
                    logicalSize = 0;
                    cleanHeap();
                    throw OutOfMemory();
                }

                logicalSize = inputSize;

            }else{

                while (logicalSize != inputSize){
                    remove_last();
                }
            }
        }


    template <typename T>
        inline size_t DArray<T>::size() const noexcept{
            return logicalSize;
        }


    template <typename T>
        inline bool DArray<T>::isEmpty() const noexcept{
            if (logicalSize == 0){
                return true;
            }else{
                return false;
            }
        }


    template <typename T>
        void DArray<T>::clear(){
            for (size_t i=0; i < logicalSize; ++i){
                (&buffer[i])->~T();
            }

            logicalSize = 0;
        }


    template <typename T>
        void DArray<T>::add(const T& value, size_t index){
            if (index > size()){
                throw InvalidIndexException();
            }else{
                resize(size()+1, T());

                for (size_t i=size(); i>index; i--){
                    *(buffer+i) = *(buffer+i-1);
                }

                *(buffer+index) = value;
            }
        }


    template <typename T>
        void DArray<T>::append(const T& value){
            add(value, size());
        }


    template <typename T>
        void DArray<T>::remove(size_t index){
            if (index >= size()){
                throw InvalidIndexException();
            }else{

                for (size_t i=index; i < size()-1; i++){
                    *(buffer+i) = *(buffer+i+1);
                }

                remove_last();
            }
        }


    template <typename T>
        void DArray<T>::remove_last(){
            if (isEmpty()){
                throw ArrayEmpty();
            }else {
                // We decrement logical size before calling
                // the destructor of object, so we get the
                // exact index instead of using
                // logicalSize-1
                --logicalSize;
                (&buffer[logicalSize])->~T();
            }
        }


    template <typename T>
        bool DArray<T>::initObject(size_t startIndex,
                size_t endIndex, T* inputBuffer, 
                const T& inputValue){

            // We try to create and initialize
            // objects from startIndex to endIndex
            // on the inputBuffer with given value
            //
            // Note: We could have just called line below
            // buffer = new (myHeap) T[logicalSize]();
            //
            // But, we want to make the function exception
            // safe so that there are no objects left on the 
            // heap if we fail to get required memory when
            // creating an initializing object of type <T>.
            //
            // Therefore, I chose to manually call copy 
            // constructor so that in case there is 
            // insufficient memory we can clean up properly

            size_t i = startIndex;

            try{

                for(; i < endIndex; ++i){
                    new (inputBuffer + i) T(inputValue);
                }

            }catch (bad_alloc){
                // Cleanup phase
                for(; i > 0; --i){
                    (&inputBuffer[i])->~T();
                }
                return false;
            }

            return true;
        }


    template <typename T>
        void DArray<T>::initPhysicalSize(size_t inputSize){
            if (inputSize <= 5){
                physicalSize =  SIZE_DEFAULT;
            }else{
                physicalSize = inputSize*PREALLOC_PERCENT;
            }
        }


    template <typename T>
        void DArray<T>::cleanHeap(){
            delete [] myHeap;
            buffer = nullptr;
            myHeap = nullptr;
            physicalSize = 0;
        }


    template <typename T>
        size_t DArray<T>::capacity() const{
            return physicalSize;
        }


    template <typename T>
        void DArray<T>::reserve(size_t inputSize) {
            if (inputSize > physicalSize){
                size_t newSize = inputSize;
                T* oldBuffer = buffer;
                unsigned char* oldHeap = myHeap;

                try{
                    myHeap = new unsigned char[newSize * unitSize];
                    buffer = reinterpret_cast<T*>(myHeap);
                } catch (bad_alloc){
                    myHeap = oldHeap;
                    throw OutOfMemory();
                }

                size_t i = 0;

                try{
                    for(; i < logicalSize; ++i){
                        new (buffer + i) T(*(oldBuffer+i));
                    }

                } catch (bad_alloc){
                    // Cleanup phase
                    for(; i > 0; --i){
                        (&buffer[i])->~T();
                    }
                    delete [] myHeap;
                    myHeap = oldHeap;
                    buffer = oldBuffer;
                    throw;
                }

                // Cleaning up old buffer
                for (size_t j=0; j < logicalSize; ++j){
                    (&oldBuffer[j])->~T();
                }

                delete [] oldHeap;
                physicalSize = newSize;

            }
        }

    template <typename T>
        template <typename Y>
        DArray<T>::DArray(const DArray<Y>& input): 
            buffer(nullptr), myHeap(nullptr)    
    {
        logicalSize = input.size(); 
        initPhysicalSize(logicalSize); 

        try{
            myHeap = new unsigned char[physicalSize * unitSize]; 
            buffer = reinterpret_cast<T*>(myHeap);
        }catch (bad_alloc){
            physicalSize = logicalSize = 0;
            throw OutOfMemory();
        }

        // Creating and initializing objects of
        // type <T> on our buffer
        bool status = initObject(0, logicalSize, buffer, T());

        if (status == false){
            logicalSize = 0;
            cleanHeap();
            throw OutOfMemory();
        }

        // Copying exact values
        for (size_t i=0; i < logicalSize; ++i){
            *(buffer+i) = static_cast<T>(input[i]);
        }
    }

} // namespace zh

#endif /* ifndef DARRAY */


