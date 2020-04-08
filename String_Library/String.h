
/*
 * Filename:      String.h
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

#ifndef STRING_H
#define STRING_H

#include <iostream>
using std::ostream;
using std::istream;
using std::cin;

#include <cstddef> 
using std::size_t;


#include <new> 
using std::bad_alloc;

#include <stdexcept> 
using std::out_of_range;


class String {

    friend ostream & operator<<(ostream & outStream, const String & inputString);
    /*
     * Responsibility: To take an input String object, modify ostream object to reflect
     *                 the contents stored in that string and return it.
     * Inputs: 1) String object that we will read from
     * 2) ostream object that we will modify
     * Outputs: 1) Reference to an ostream object
     * Plan: 1) If length() of inputString is 0, return outStream with an empty String
     * 2) Otherwise just return outStream with value of inputString.c_str()
     * Pre-Conditions: 1) Second parameter has to be a valid String object
     * Post-Conditions: 1) We will not modify state of input String object
     * 2) We will modify and return the state of ostream object
     * to reflect the value stored in the input String object
     * Exception: N/A
     */

    friend istream & operator>>(istream & inStream, String & outputString) throw (bad_alloc);
    /*
     * Responsibility: Take values from istream object and initialize a String object 
     * with the same value(s) and return istream object
     * Inputs: 1) istream object that we will read from
     * 2) String object that we will modify
     * Outputs: Reference to an istream object
     * Plan: 1) Discard empty whitespace at the beginning
     * 2) Loop as long as there are character remaining
     * 3) Check is strSize is equal to buffersize, if it is then allocate
     * more memory as necessary and deleting previous buffer
     * 4) Check if the character is a space, if it is then put char '\0'
     * in buffer and return reference to the existing istream object
     * 5) Place character onto the buffer at specified strSize of input
     * String object
     * 6) Increment strSize by 1
     * 7) Return the reference to istream object after out the loop
     * Pre-Conditions: 1) Second parameter has to be a valid String object
     * Post-Conditions: 1) We will modify and return the state of istream 
     * object.
     * 2) We will modify reference to input String object 
     * as necessary
     * 3) We will allow returned istream object reference to
     * be modified
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     * indicating that we have failed to instantiate the object.
     */

    friend String operator+(const String & lhs, const String & rhs) throw (bad_alloc);
    /*
     * Responsibility: We take two input String objects, and return a String object 
     *                 which is the concatenated output of the two
     * Inputs: Two constant String objects
     * Outputs: We return the modified String object
     * Plan:
     * Pre-Conditions: 1) We assume we have sufficient memory
     * 2) We assume input is valid String object
     * Post-Conditions: 1) We guarantee that we will not modify the 
     * input String objects passed in as reference
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     * indicating that we have failed to instantiate the object.
     * */

    public:
    String() throw (bad_alloc);
    /*
     * Responsibility: Create an empty String object
     * Inputs: None
     * Outputs: None
     * Plan: 1) Allocate memory on the heap of a fixed size
     * 2) Set the first character to be '\0'
     * Pre-Conditions: 1) We assume sufficient memory is available
     * Post-Conditions: 1) We will create an empty String object
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     * indicating that we have failed to create and instantiate the object.
     **/

    String(const char * inputCString) throw (bad_alloc);
    /*
     * Responsibility: Create a String object and initialize 
     *                 it to have the same value as that of 
     *                 input c-style string
     * Inputs: Constant pointer to a c-style character array
     * Outputs: None
     * Plan: 1) If pointer is NULL, make pointer point to ""
     *       2) Set strSize = length of inputCString
     *       3) Calculate size of the buffer that we need to allocate. 
     *       Buffer size is 1.5 times that of (logical size+1) 
     *       calculated in (2)
     *       4) Allocate memory on the heap for character array based 
     *       on the size we calculated in (3)
     *       5) Copy values of input c-style character array to the 
     *       previously allocated buffer (4)
     * Pre-Conditions: 1) We assume that the character pointer is a 
     *                    null terminated c-style string
     *                 2) The pointer can not be NULL
     *                 3) We assume sufficient memory is available
     * Post-Conditions: 1) If inputCstring is NULL we create an empty String object
     *                  2) We will instantiate a String object with the give value
     *                  3) We will not modify the state of the input character array
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     *               indicating that we have failed to instantiate the object.
     * */

    String(const char * inputCString, size_t inputSize) throw (bad_alloc);
    /*
     * Responsibility: Create a String object of the given size (inputSize) and 
     *                 initialize it to have the same value as first parameter (inputCString)
     * Inputs: 1) Input c-style string from which we will read
     *         2) Length of the new String object we will create
     * Outputs: None
     * Plan: 1) Check if the inputSize is NULL we throw NULLPtrException()
     *       2) We set strSize equal to inputSize
     *       3) We calculate bufferSize which is 1.5 times inputSize+1 
     *       4) Allocate memory on the heap that is of the same size we calculated in (3)
     *       5) Copy values of input c-style character array on to our buffer 
     *       6) We set value at indexSize to be '\0'
     * Pre-Conditions: 1) We assume the size provided by inputSize is a valid c-style string
     *                 2) We assume sufficient memory is available
     * Post-Conditions: 1) We will instantiate a new String object and copy n amount of 
     *                     characters specified by inputSize from the c-style string onto 
     *                     our String object
     *                  2) We will not modify the state of input c-style string 
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     *               indicating that we have failed to instantiate the object.
     * */

    String(char filler, size_t inputSize = 1) throw (bad_alloc); 
    /*
     * Responsibility: Creates a new String object of the specified
     * inputSize and instantiates it's values with 
     * the supplied filler character 
     * Inputs: 1) First argument is a character that will be used to fill
     * 2) Second argument is the number of times that character will 
     * be repeated in the String object 
     * Outputs: None
     * Plan: 1) Set strSize to inputSize
     * 2) Set bufferSize = 1.5 times (inputSize+1)
     * 3) If filler is '\0' we set bufferSize=10, strSize=0
     * 4) We allocate new buffer on the heap of size bufferSize
     * 5) We loop across the character array (from 0 to strSize-1) and 
     * assign it's value to be the filler character 
     * 6) We set value of character array at (strSize) to be '\0'
     * Pre-Conditions: 1) We assume sufficient memory is available
     * Post-Conditions: 1) If filler is '\0' we will change the state of the 
     * String to be an empty String object
     * 2) We will instantiate a new String object of the 
     * specified size (inputSize) and filled 
     * with specified character (filler)
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     * indicating that we have failed to instantiate the object.
     * */

    String(const String& inputString) throw (bad_alloc);
    /*
     * Responsibility: Copy constructor of String object. Will modify state 
     * of an existing String object and change it's state 
     * to be the same as that of inputString object
     * Inputs: Reference to a String object
     * Outputs: None
     * Plan: 1) Set strSize = length of inputString
     * 2) Set bufferSize = bufferSize of inputString
     * 3) Allocate memory on heap of size bufferSize and make
     * buffer point to it
     * 4) Copy values from inputString buffer to our newly created
     * buffer
     * Pre-Conditions: 1) We assume input String is a valid String object
     * 2) We assume sufficient memory is available
     * Post-Conditions: 1) We guarantee that we will not modify the state 
     * of the input String object.
     * 2) We will instantiate our String object to have the 
     * same state as input String object.
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     * indicating that we have failed to instantiate the object.
     * */

    ~String() throw();
    /*
     * Responsibility: Destroy the string object and perform cleanup of memory allocated on the heap
     * Inputs: None
     * Outputs: None
     * Plan: 1) Delete buffer on the heap
     * 2) Make pointer 'buffer' point to NULL
     * Pre-Conditions: None
     * Post-Conditions: 1) We guarantee that the String object will be cleaned up properly 
     * with no chance of memory leak.
     * Exception: None
     * */

    String& operator=(const String & rhs) throw (bad_alloc);
    /*
     * Responsibility: Change the state of our exististing String object 
     * to be the same state as the constant String object 
     * passed as argument.
     * Inputs: Constant reference to a String object
     * Outputs: Reference to a String object
     * Plan: 1) Check to make sure that our current String object is not 
     * the same object that is passed as argument
     * a) We set our strSize to be the same as the length of 
     * input String object
     * b) We set our bufferSize equal to 1.5 times (strSize+1)
     * c) We allocate a new character buffer on the heap of size bufferSize
     * d) We copy the buffer from input String object to our buffer
     * 2) We return our new String object as reference
     * Pre-Conditions: 1) We asssume the argument passed as first parameter is a 
     * reference to a constant String object
     * 2) We assume sufficient memory is available
     * Post-Conditions: 1) We guarantee that we will create and return a new 
     * String object that will have the same state
     * as the input String object on a logical level.
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     * indicating that we have failed to instantiate the String object.
     * */

    String& operator+=(const String & rhs) throw (bad_alloc);
    /*
     * Responsibility: Create and return a new String object and change 
     * it's state so that the passed in String objects
     * value is appended to the existing String's value.
     * Inputs: Reference to a constant String object.
     * Outputs: Reference to a new String object.
     * Plan: 1) We create a size_t variable called oldSize to keep track 
     * of previous size
     * 2) We assign current strSize to be the length of rhs + current strSize
     * 3) We check if strSize+1 is greater than current bufferSize
     * a) We create another character pointer to keep track of original buffer
     * b) We store the value of buffer size to be strSize+1 times 1.5
     * c) We allocate character array on the heap of bufferSize found in (b) 
     * and set it to buffer
     * d) We copy values from original buffer onto new buffer
     * 4) We loop through from index zero to length of the input Strings buffer 
     * and copy the values onto
     * our buffer from where the null character starts
     * 5) We add null character to our buffer at index strSize
     * 6) We return reference to our String object
     * 
     * Pre-Conditions: 1) We assume sufficient memory is available
     * 2) We assume the object passed in the parameter should 
     * point to a valid String object
     * 
     * Post-Conditions: 1) We will return a new String object whose 
     * state has changed and it's value is the concatenation 
     * of itself and the String object passed as reference
     * 
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     * indicating that we have failed to instantiate the object.
     * */

    char& operator[](size_t position ) throw (out_of_range);
    /*
     * Responsibility: Returns the character value at the specified 
     * position with write access alongside read access
     * Inputs: Index of the character
     * Outputs: Reference to a character
     * Plan: 1) Checks if input index is greater or equal to strSize, 
     * if it is then it throws an out_of_range exception 
     * 2) Return the value of the character array at specified index
     * Pre-Conditions:  1) The value of input index can not be greater 
     * than or equal to strSize
     * Post-Conditions: 1) We will allow modification of the returned 
     * character value (write access) at that 
     * particular index
     * Exception: 1) Throws std::out_of_range when the specified index 
     * is >= strSize, indicating that the index is not 
     * valid / inaccessible
     * */

    const char& operator[] (size_t position ) const throw (out_of_range); 
    /*
     * Responsibility: Returns the value of a constant character at the 
     * specified position, with read only access
     * Inputs: Index of the character
     * Outputs: Reference to a constant character
     * Plan: Return the value of the character array at specified index
     * Pre-Conditions: 1) Checks if input index is greater or equal to strSize, 
     * if it is then it throws an out_of_range exception 
     * 2) The value of input index can not be greater than or 
     * equal to strSize
     * Post-Conditions: 1) We will not allow any modification to the constant
     * character reference that is returned
     * 2) We guarantee that we will not modify state of the
     * current String object
     * 
     * Exception: 1) Throws std::out_of_range when the specified index is 
     * >= strSize, indicating that the index is not valid / 
     * inaccessible
     * */

    const char *c_str() const throw();
    /*
     * Responsibility: Returns a constant pointer to a c-style string
     * Inputs: None
     * Outputs: Char pointer (buffer)
     * Plan: 1) Return buffer
     * Pre-Conditions: None
     * Post-Conditions: 1) We guarantee that we will not modify the state 
     * of our string object 
     * 2) We do not allow modification of the returned
     * pointer to a c-style character array
     * Exception: None
     * */

    size_t length() const throw();
    /*
     * Responsibility: Return the logcal size of the String object
     * Inputs: None
     * Outputs: Length of the String (size_t)
     * Plan: Return the value of strSize
     * Pre-Conditions: None
     * Post-Conditions: 1) We guarantee to not modify the state of 
     * the String object
     * Exception: None
     * */

    bool empty() const throw(); 
    /*
     * Responsibility: Return a boolean indicating whether a String 
     * is empty or not
     * Inputs: None
     * Outputs: Boolean value indicating if String is empty
     * Plan: Return the value of strSize == 0
     * Pre-Conditions: None
     * Post-Conditions: We guarantee to not modify state of the 
     * String object
     * Exception: None
     * */


    void clear() throw();
    /*
     * Responsibility: Make the String object empty
     * Inputs: None
     * Outputs: None
     * Plan: 1) Set strSize to 0
     * 2) Set first character in the buffer to be '\0'
     * Pre-Conditions: None
     * Post-Conditions: We guarantee that we will clear the values in String object
     * to represent the state of an empty String
     * Exception: None
     * */

    void resize(size_t newSize, char filler = ' ') throw (bad_alloc);
    /*
     * Responsibility: To resize the String object to the specified size (newSize) 
     * and fill the empty space of new String object with the 
     * specified character (filler) if newSize is larger than strSize
     * 
     * Inputs: 1) New size of the String object
     * 2) Character to be used to fill the String object
     * 
     * Outputs: None
     * 
     * Plan:   1) If newSize is less than or equal to strSize
     *               a) set strSize = newSize
     *               b) set buffer at location strSize = '\0'
     *         2) Otherwise, 
     *               a) Create and set variable oldSize = strSize
     *               b) Set strSize = newSize 
     *               c) Check if newSize is greater than or equal to
     *                  bufferSize, if it is then allocate new memory
     *                  of bufferSize >= 1.5(strSize+1), copy characters
     *                  from old buffer to our new buffer and delete
     *                  old buffer
     *               d) Loop, starting from oldSize to strSize-1, and
     *                  allocate every character with the input filler
     *                  character
     *               e) Set buffer at index strSize to be '\0'
     * 
     * Pre-Conditions:  1) We assume sufficient memory is available
     * 
     * Post-Conditions: 1) We guarantee that we will modify the String object so 
     *                     that it is atleast greater or equal to the specified size 
     *                     and that empty space will be initialized with the 
     *                     specified character
     * 2) If newSize=0 or filler is '\0' we will modify the state 
     *    of our String object to represent an empty String
     * 3) If the newSize is less than strSize, we will modify 
     *    strSize to be the value of newSize, signifying that 
     *    we have discarded certain character occupied in the 
     *    character array
     * 
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     * indicating that we have failed to resize our String object.
     * */

    istream & getline(istream & inStream  = cin, char delim = '\n') throw (bad_alloc);
    /*
     * Responsibility: Get the whole line passed as input and initialize
     * our String object also making sure whitespace
     * is not discarded depending on the delimiter
     * 
     * Inputs: 1) Reference to an istream object
     * 2) Delimiter character by which to parse the line. 
     * 
     * Outputs: Reference to an input Stream object
     * 
     * Plan: 1) Create a char variable (x)
     * 2) Set strSize to 0
     * 3) Get the first character from inStream to x
     * 4) Do: a) Check if strSize == bufferSize, if it 
     * reallocate more memory of size (bufferSize+1)*1.5,
     * copy old characters onto new buffer and making sure 
     * to delete old buffer
     * b) If input character (x) is delim, break out of the loop
     * c) Otherwise set index of buffer at strSize to be x
     * d) Increment strSize by 1
     * 5) While inStream still has input remaining, get the next
     * character and set it to x
     * 6) Set buffer at index strSize to be '\0'
     * 7) Return inStream object
     * 
     * Pre-Conditions: 1) We assume sufficient memory is available
     * 
     * Post-Conditions: We will guarantee that the input stream will be 
     * parsed according to the specified delimiter and 
     * the resultant value will be stored in a String 
     * object, aswell as making sure initial whitespace
     * is not discarded as long as delimiter character
     * is not whitespace.
     * 
     * Exception: 1) Throws std::bad_alloc when allocating memory on the heap fails,
     * indicating that we have failed to initialize our String object.
     * */


    private:
    size_t strSize;      // Stores the logical size of String object.
    size_t bufferSize;   // Stores physical size of String object.
    char *buffer;        // Pointer to a null terminated character array on heap.
};

bool operator==(const String & lhs, const String & rhs) throw();
/*
 * Responsibility: Check if two given strings have the same value
 * Inputs: 2 String objects
 * Outputs: Boolean value indicating if the value of 2 input String 
 * objects are equal lexicographically
 * Plan: Use std::strcmp function
 * Pre-Conditions: 1) Both input have to be valid String objects
 * Post-Conditions: 1) We will not modify state of the input String 
 * objects
 * Exception: None
 */

bool operator!=(const String & lhs, const String & rhs) throw();
/*
 * Responsibility: Check if two given strings are not equal to one another
 * Inputs: 2 String objects
 * Outputs: Boolean value indicating if the value of 2 input String objects are
 * not equal lexicographically
 * Plan: Use std::strcmp function
 * Pre-Conditions: 1) Both input have to be valid String objects
 * Post-Conditions: 1) We will not modify state of the input String objects
 * Exception: None
 */

bool operator<(const String & lhs, const String & rhs) throw();
/*
 * Responsibility: Check if the first string is less than the second string
 * Inputs: 2 String objects
 * Outputs: Boolean value indicating if the value of first String object is less
 * than the value of second String object lexicographically
 * Plan: Use std::strcmp function
 * Pre-Conditions: 1) Both input have to be valid String objects
 * Post-Conditions: 1) We will not modify state of the input String objects
 * Exception: None
 */

bool operator<=(const String & lhs, const String & rhs) throw();
/*
 * Responsibility: Check if two given strings are less than or equal to one another
 * Inputs: 2 String objects
 * Outputs: Boolean value indicating if the value of first String object is less than
 * or equal to the value of the second String object lexicographically
 * Plan: Use std::strcmp function
 * Pre-Conditions: 1) Both input have to be valid String objects
 * Post-Conditions: 1) We will not modify state of the input String objects
 * Exception: None
 */

bool operator>(const String & lhs, const String & rhs) throw();
/*
 * Responsibility: Check if two given strings are greater than one another
 * Inputs: 2 String objects
 * Outputs: Boolean value indicating if the value of first String object is greater than
 * the value of the second String object lexicographically
 * Plan: Use std::strcmp function
 * Pre-Conditions: 1) Both input have to be valid String objects
 * Post-Conditions: 1) We will not modify state of the input String objects
 * Exception: None
 */

bool operator>=(const String & lhs, const String & rhs) throw();
/*
 * Responsibility: Check if two given strings are greater than or equal to one another
 * Inputs: 2 String objects
 * Outputs: Boolean value indicating if the value of first String object is greater than
 * or equal to the value of the second String object lexicographically
 * Plan: Use std::strcmp function
 * Pre-Conditions: 1) Both input have to be valid String objects
 * Post-Conditions: 1) We will not modify state of the input String objects
 * Exception: None
 */

inline size_t String::length() const throw()
    /*
     * Responsibility: Return the logcal size of the String object
     * Inputs: None
     * Outputs: Length of the String (size_t)
     * Plan: Return the value of strSize
     * Pre-Conditions: None
     * Post-Conditions: We guarantee to not modify the state of the String object
     * Exception: None
     */
{ return strSize; }

inline bool String::empty() const throw()
    /*
     * Responsibility: Return a boolean indicating whether a String is empty or not
     * Inputs: None
     * Outputs: Boolean value indicating if String is empty
     * Plan: Return the value of strSize == 0
     * Pre-Conditions: None
     * Post-Conditions: We guarantee to not modify state of the String object
     * Exception: None
     */
{ return strSize == 0; }

#endif

