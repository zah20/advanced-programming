/*
 * Filename:      darray.hpp
 * Version:       1.0
 * Author:        zah
 * Last Modified: 21/10/2016 
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


//====================================================||
//					              ||
// 		       Prototype 		      ||
//					              ||
//====================================================||

namespace zh{

    class ArrayFull{};
    class ArrayEmpty{};
    class InvalidIndexException{};

    template <typename T>
        class DArray{


            /*  // Summary of available services
             *
             *  DArray();
             *
             *  explicit DArray(size_t=0, const T& = T());
             *
             *  ~DArray() throw();
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
             *  void add();
             *  
             *  void append(const T&);
             *
             *  void remove(size_t index);
             *
             *  void remove_last();
             *
             *  template <typename Y>
             *      DArray(const DArray<Y>&);
             */


            public:
                DArray();
                /*
                 *  Description: Create and initialize an empty 
                 *               Dynamic Array object
                 *
                 *  Input:  None 
                 *
                 *  Output: None
                 *
                 *  Plan: 
                 *
                 *  Pre-condition:  1) Sufficient memory is available
                 *
                 *  Post-condition: 1) An array of type <T> with 
                 *                     logical size of zero is created 
                 *                     and initialized
                 *                  2) Preallocation of memory is done 
                 *                     in advance to reduce the 
                 *                     frequency of reallocation
                 *
                 *  Exception: 1) If insufficient memory is available 
                 *                ArrayFull() exception will be thrown
                 *
                 *  Remark: Best & Worse case: O(1), as it is the 
                 *          default constructor we preallocate buffer 
                 *          to a fixed size depending on the object 
                 *          type. Which is why we canalways does the 
                 *          job in constant time
                 */


                explicit DArray(size_t);
                /*
                 *  Description: Create and initialize a Dynamic 
                 *               Array object of the specified size
                 *
                 *  Input:  None 
                 *
                 *  Output: None
                 *
                 *  Plan: 
                 *
                 *  Pre-condition:  1) Sufficient memory is available
                 *
                 *  Post-condition: 1) An array of type <T> with the 
                 *                     specified logical size is 
                 *                     created and initialized by 
                 *                     calling default constructor 
                 *                     of T
                 *                  2) Preallocation of memory is done 
                 *                     in advance to reduce the 
                 *                     frequency of reallocation
                 *
                 *  Exception: 1) If insufficient memory is available 
                 *                ArrayFull() exception will be thrown
                 *
                 *  Remark: Worst case: O(n), as we have to create and 
                 *          initialize n number of objects
                 *
                 *          Best case: O(1), as we preallocate buffer 
                 *          to a fixed size depending on the object 
                 *          type. Which is why we can always do the 
                 *          job in constant time
                 *
                 *
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
                 *  Plan: 
                 *
                 *  Pre-condition:  1) Sufficient memory is available
                 *                  2) It is assumed that an appropriate
                 *                     value is specified as the second
                 *                     parameter depending on the type 
                 *                     of object
                 *
                 *  Post-condition: 1) If only the size is given and no
                 *                     default values are specified then
                 *                     the object types default
                 *                     constructor will be called to
                 *                     initialize it
                 *                  2) If both arguments are present
                 *                     then the array will be created 
                 *                     to be of the specified size and 
                 *                     it's objects initialized to 
                 *                     the specified value
                 *                  3) Preallocation of memory is done
                 *                     in all cases to reduce the
                 *                     frequency of reallocation
                 *
                 *  Exception: 1) If insufficient memory is available 
                 *                ArrayFull() exception will be thrown
                 *
                 *  Remark: 
                 *          Worst case: O(n), as we have to create an
                 *          array of n number of objects and initialize
                 *          the values to the specified value or call 
                 *          its constructor if value is not present
                 *          we are not do our job in constant time
                 *          
                 *          Best case: O(1), as the size is not
                 *          specified we preallocate buffer to a fixed
                 *          size depending on the object type. 
                 *          Which is why it always does the job 
                 *          in constant time
                 */


                ~DArray() throw();
                /*
                 *  Description: Delete the array object and cleanup
                 *               properly to ensure there are no memory
                 *               leaks
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Plan: 
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: Array objects will be cleaned up
                 *                  properly by calling the types
                 *                  appropriate destructor
                 *
                 *  Exception: None
                 *
                 *  Remark: Worst case: O(n), we need to clean up array
                 *          which has n number of objects
                 *
                 *          Best case: O(1), that is when the default
                 *          constructor has been called, therfore we
                 *          only cleanup a fixed number of objects which
                 *          can be done in constant time
                 */


                DArray(const DArray<T>&);
                /*
                 *  Description: Initialize our Dynamic array to
                 *               represent the same state as the input
                 *               Dynamic array object
                 *
                 *  Input: Dynamic array object of type <T> whose state
                 *         we wish to replicate
                 *
                 *  Output: None
                 *
                 *  Plan: 
                 *
                 *  Pre-condition: 1) Sufficient memory is available
                 *                 2) We assume that the Dynamic array
                 *                    whose state we want to replicate 
                 *                    is of the same type as the dynamic
                 *                    array we will be creating
                 *
                 *  Post-condition: 1) We will create a new dynamic
                 *                     array on the heap whose type
                 *                     will be the same as that of
                 *                     input dynamic array object
                 *                  2) The state of our new dynamic
                 *                     array will be the same as that of
                 *                     the input object on a logical
                 *                     level and will have the same
                 *                     arrangment of internal objects
                 *                     as well as the same value
                 *                     depending on the type
                 *
                 *  Exception: 1) ArrayFull() exception will be thrown
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
                 *  Output: None
                 *
                 *  Plan: 
                 *
                 *  Pre-condition: 1) Sufficient memory is available
                 *                 2) Input dynamic array object has to
                 *                    be of the same type as the dynamic
                 *                    array that is being modified
                 *
                 *  Post-condition: 1) We modify the state of our
                 *                     dynamic array object to represent
                 *                     the same state as that of the
                 *                     passed input object on a logical
                 *                     level
                 *
                 *  Exception: 1) An exception of ArrayFull() is thrown
                 *                if we fail to get sufficient memory to
                 *                do our job properly
                 *
                 *  Remark: Worst case: O(n), as we may have to change 
                 *          our state and initialize n number of objects
                 *
                 *          Best case: O(1), as the passed in input
                 *          object is the same object that we are
                 *          modifying
                 */


                const T& operator[](size_t) const;
                /*
                 *  Description: Provide read only access to a
                 *               particular object at the specified
                 *               index
                 *
                 *  Input: 1) Index of the object in the array
                 *
                 *  Output: None
                 *
                 *  Plan: 
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
                 *  Remark: Worst case: O(1), as we can provide access
                 *                      in constant time
                 *          Best case:  O(1), as we can provide access 
                 *                      in constant time
                 *
                 */


                T& operator[](size_t);
                /*
                 *  Description: Provide read and write only access to a
                 *               particular object at the specified
                 *               index
                 *
                 *  Input: 1) Index of the object in the array
                 *
                 *  Output: None
                 *
                 *  Plan: 
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
                 *  Remark: Worst case: O(1), as we can provide access
                 *                      in constant time
                 *          Best case:  O(1), as we can provide access 
                 *                      in constant time
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
                 *  Plan: 
                 *
                 *  Pre-condition:
                 *
                 *  Post-condition: 1) If the specified size is higher 
                 *                  than the curret size, then the
                 *                  array is resized to the bigger
                 *                  size and the new objects in the 
                 *                  array are initialized with the 
                 *                  values specified in the second
                 *                  parameter. If no parameter is
                 *                  present then the default
                 *                  constructor of the object type
                 *                  is called.
                 *
                 *                  2) If specified size is smaller
                 *                  than the existing size of the
                 *                  array, the array is shrunk to
                 *                  match the specified size
                 *
                 *  Exception: 1) ArrayFull() exception is thrown
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


                size_t size() const throw();
                /*
                 *  Description: Return the size of our array
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Plan: 
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


                bool isEmpty() const throw();
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
                 *  Plan: 
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
                 *  Plan: 
                 *
                 *  Pre-condition: None
                 *
                 *  Post-condition: 1) We will change state of our
                 *                  array to represent an empty array
                 *
                 *  Exception: None
                 *
                 *  Remark: Best and Worst case: O(1) as we can do
                 *          our job in constant time
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
                 *               is not over written 
                 *
                 *  Input: 1) Value that we want the index to be set
                 *         2) Index at which we want to add the
                 *            element
                 *
                 *  Output: None
                 *
                 *  Plan: 
                 *
                 *  Pre-condition: 1) We assume sufficient memory is
                 *                    available
                 *                 2) Index has to be with in valid
                 *                    range which is zero to size-1
                 *                    or equal to size if we want 
                 *                    to append to the end of the 
                 *                    array.
                 *
                 *  Post-condition: 1) We will add the specified
                 *                     value to the element at the
                 *                     specified index and make sure
                 *                     that the previous value is
                 *                     not overwritten by shifting
                 *                     them appropriately to the
                 *                     right to make space for the
                 *                     new value
                 *                  2) If specified index is equal
                 *                     to the size of the array,
                 *                     then the size of the array is
                 *                     expanded by one and new value
                 *                     is appended at the end
                 *
                 *  Exception: 1) Throws ArrayFull() if insufficient
                 *                memory is available
                 *             2) Throws InvalidIndexException()
                 *                when the index is greater than 
                 *                the valid range (zero to size)
                 *                
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
                 *  Input: Value that the object will be set to
                 *
                 *  Output: None
                 *
                 *  Plan: 
                 *
                 *  Pre-condition: 1) It is assumed that sufficient
                 *                    memory is available
                 *                 2) It is assumed that the input
                 *                    object type is the same as the
                 *                    type of the array
                 *
                 *  Post-condition: 1) The specified value will be
                 *                     appended to the end of array
                 *
                 *  Exception: 1) ArrayFull() exception will be
                 *                thrown if we fail to get
                 *                sufficient memory 
                 *
                 *  Remark: Worst Case: O(n), as we have to end up
                 *          reallocating the buffer and copying upto
                 *          n number of objects onto the new buffer
                 *          from old buffer
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
                 *  Plan: 
                 *
                 *  Pre-condition: 1) Index has to be with in valid
                 *                    range
                 *                 2) Array can not be empty
                 *
                 *  Post-condition: 1) The object at the specified
                 *                     index will be removed and the
                 *                     objects following it (if any)
                 *                     will be shifted accordingly
                 *                     to the left
                 *
                 *  Exception: 1) InvalidIndexException will be
                 *                thrown if the index is not with in
                 *                the valid range
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
                 *               array
                 *
                 *  Input: None
                 *
                 *  Output: None
                 *
                 *  Plan: 
                 *
                 *  Pre-condition: 1) We assume the array is not
                 *                    empty
                 *
                 *  Post-condition: 1) We remove the last object in
                 *                     the array
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
                 *  Description:
                 *
                 *  Input:
                 *
                 *  Output:
                 *
                 *  Plan: 
                 *
                 *  Pre-condition:
                 *
                 *  Post-condition:
                 *
                 *  Exception:
                 *
                 *  Remark: 
                 */

            private:
                T* buffer;
                size_t physicalSize; // Physical size
                size_t logicalSize; // Logical size
                static const size_t SIZE_DEFAULT = 5; 
                static constexpr float PREALLOC_PERCENT = 1.50;
        };




    //================================================||
    //						      ||
    // 	                 Definition 		      ||
    //					              ||
    //================================================||


    template <typename T>
        DArray<T>::DArray(): logicalSize(0), physicalSize(SIZE_DEFAULT){
            try{
                buffer = new T[physicalSize]; 
            }catch (bad_alloc){
                throw ArrayFull();
            }
        }

    template <typename T>
        DArray<T>::DArray(size_t inputSize): logicalSize(inputSize){
            if (inputSize == 0){
                physicalSize =  SIZE_DEFAULT;
            }else{
                physicalSize = inputSize*PREALLOC_PERCENT;
            }

            try{
                buffer = new T[physicalSize]; 
            }catch (bad_alloc){
                throw ArrayFull();
            }
        }


    template <typename T>
        DArray<T>::DArray(size_t inputSize, const T& input){
            if (inputSize == 0){
                physicalSize =  SIZE_DEFAULT;
            }else{
                physicalSize = inputSize*PREALLOC_PERCENT;
            }

            logicalSize = inputSize;

            try{
                buffer = new T[physicalSize]();
            }catch (bad_alloc){
                throw ArrayFull();   
            }

            if (inputSize > 0 && input != T()){
                for (size_t i=0; i < logicalSize; ++i){
                    *(buffer+i) = input;
                }
            }
        }


    template <typename T>
        DArray<T>::~DArray() throw(){
            physicalSize = logicalSize = 0;
            delete [] buffer;
            buffer = nullptr;
        }


    template <typename T>
        DArray<T>::DArray(const DArray<T>& copy): buffer(NULL), 
        logicalSize(0), physicalSize(0){
            *this = copy;
        }


    template <typename T>
        DArray<T>& DArray<T>::operator=(const DArray<T>& rhs) {
            if (this != &rhs){

                logicalSize = rhs.size();

                // Check if our buffer size is sufficient
                if (rhs.size() > physicalSize){
                    T* oldBuffer = buffer;

                    physicalSize = logicalSize * PREALLOC_PERCENT;

                    try{
                        buffer = new T[physicalSize]();
                    } catch (bad_alloc){
                        throw ArrayFull();
                    }

                    delete [] oldBuffer;
                }

                for (size_t i=0; i < logicalSize; i++){
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

                // We need to reallocate and copy objects from 
                // old buffer to new buffer to maintain state and
                // also we need to make sure we delete old buffer
                if (inputSize > physicalSize){
                    physicalSize = inputSize*PREALLOC_PERCENT;
                    T* oldBuffer = buffer;

                    try{
                        buffer = new T[physicalSize]();
                    } catch (bad_alloc){
                        throw ArrayFull(); 
                    }

                    for (size_t i=0; i <logicalSize; i++){
                        *(buffer+i) = *(oldBuffer+i);
                    } 

                    delete [] oldBuffer;
                }

                // Initializing new objects on buffer 
                // with input value
                for (size_t i=logicalSize; i<inputSize; i++){
                    *(buffer+i) = value;
                }
            } 

            logicalSize = inputSize;
        }


    template <typename T>
        inline size_t DArray<T>::size() const throw(){
            return logicalSize;
        }


    template <typename T>
        inline bool DArray<T>::isEmpty() const throw(){
            if (logicalSize == 0){
                return true;
            }else{
                return false;
            }
        }


    template <typename T>
        void DArray<T>::clear(){
            resize(0, T());
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
            resize(size()+1, T());
            *(buffer+(size()-1)) = value;
        }


    template <typename T>
        void DArray<T>::remove(size_t index){
            if (index >= size()){
                throw InvalidIndexException();
            }else{

                for (size_t i=index; i < size()-1; i++){
                    *(buffer+i) = *(buffer+i+1);
                }

                resize(size()-1, T());
            }
        }


    template <typename T>
        void DArray<T>::remove_last(){
            if (isEmpty()){
                throw ArrayEmpty();
            }else {
                resize(size()-1, T());
            }
        }

} // namespace zh
#endif /* ifndef DARRAY */


