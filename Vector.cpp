/**********************************************************************
Title:		Vector.cpp
Author:		Jose Luis Rojas-Salazar
Date Created:	2/12/2017
Class:		Spring 2017, CSCI 25303, Mon & Wed 5:35pm-6:50pm
Professor:	Aarsh Vora
Purpose:	Assigment #1
Description:	Implementation of the public functions for class Vector
***********************************************************************/


#include <stdlib.h>
#include <string.h>
#include "Vector.h"


//Implementing default constructor
//Preconditions:The program just compile and start run and no memory space 
//was separated to start to fill the array that will contain the vector
//of integers.
//Postcondition:A space of memory was separated to storage the array that will
//contain the vector of integers.
 
Vector::Vector(unsigned int capacity){
	arr_ 	= new int[capacity];	//allocate array
	size_	= 0;			//array is empty
	capacity_ = capacity;	        //set capacity
};


//Implementing the Vector destroyer that will return the memory separated to
//storage the integer vector to PCs memory for reuse.
//Preconditions:There is a space separated of the memory to storage a dynamic
//array of integers.
//Postconditions:After call this function the memory separated is returned to
//the computers memory and the elements in the array are erased.

Vector::~Vector(){
	delete [] arr_;	//free memory used returning to the PC memory
};


//Implementing the first part or the first function needed to Overload operator=
//Copy Assigment operator.
//Preconditions: The dynamic array contains integers so if we need to copy the
//entire array as a new vector object first we need to allocate new space for 
//the copy and then use memcpy to copy the elements of the array.
//Postconditions: The new space in memory and information of the dynamic array 
//are ready to be transfer once the new Vector object is created.

Vector::Vector(const Vector& rhs){
	arr_ = new int[rhs.capacity_];	//allocate array
	memcpy(arr_, rhs.arr_, sizeof(int)*rhs.size_);	//copy array data
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;
};


//Implementing the second part or the secondd function needed to Overload operator=
//Copy Assigment operator.
//Preconditions: The new space in memory to allocate the copy and the information 
//of the dymanic array are ready to be transfer to the new created vector object.
//Postconditions: The new Vector object was created and the information of the dynamic
//array was copy to this new object returning the new Vector object as reference.

Vector& Vector::operator=(const Vector& rhs){
	static Vector v;	//make a new vector object

	v.resize(rhs.capacity_);
	memcpy(arr_, rhs.arr_, sizeof(int)*rhs.size_);	//copy array data
	size_ = rhs.size_;
	capacity_ = rhs.capacity_;

	return v;			//return it as reference
};


//Implementing the function to get the Vector object capacity
//Preconditions: There is a space separated in memory once a Vector object
//is created.
//Postconditions:Get the capacity or size of the space in the computer memory 
//currently allocated for the vector.

unsigned int Vector::capacity() const{
	return capacity_;
};


//Implementing the function to know the number of elements in the Vector object
//Preconditions:There are 0 or more elements in the Vector.
//Postconditions:Get the number of integers or elements in the dynamic array.

unsigned int Vector::size() const{
	return size_;
};


//Implementing the function to know if the vector contains 0 elements.
//Preconditions:The Vector object was created but I dont know if contain integers.
//Postconditions:Get if there is at least one integer in the vector, if there is
//no elements return true.

bool Vector::empty() const{
	return (size_ == 0);
};


//Implementing the function to add values integer or data to the end of the vector
//doubling the size of the underlying dynamic array if necessary.
//Preconditions:The space memory for the vector is allocated and start to input
//integer values,if the next value reach the limit of capacity increase it.
//Postconditions:The new integer values were added to the dynamic array and its size 
//was increased if necessary.

void Vector::push_back(const int& data){
	if((size_+1) > capacity_){	//if we don't have capacity for one more integer
		capacity_ += 10;	//testing increase with 10 to reallocate on next insert
		arr_ = (int*)realloc(arr_, sizeof(int)*(capacity_));	//change arr_ size
	}
	arr_[size_++] = data;	//save data
};


//Implementing the remove vector function to remove the first instance of data (integer 
//value enterted to the dynamic array) if it was already in the array and return true
//otherwise return false.
//Preconditions:The vector contains elements (integer numbers) not equal (concept of set)
//and they must be evaluated one by one, thats the reason to use a loop for, to avoid a
//repeated element in the array.
//Postconditions:If data is equal to an element in the vector this one is removed and the
//rest of elements in the array shift one position to the left.

bool Vector::remove(const int& data){
	int found = false;

	for(unsigned int i=0; i < size_; i++){	//for each element
		if(arr_[i] == data){		//if its our data
			//shift elements left with 1
			for(unsigned int j=i+1; j < size_; j++){
				arr_[j-1] = arr_[j];
			}
			--size_;
			found = true;	//we found the data
			break;			//stop searching
		}
	}
	return found;
};


//Implementing the void clear() function to empty the vector from its elements and
//resets the capacity to 3.
//Preconditions:The vector have diferent integer elements and its size can be bigger to 3.
//Postconditions:The elements in the vector are erased and its capacity is for 3 after
//call de function.

void Vector::clear(){
	resize(3);       //Call resize function but to the default start capacity
	bzero(arr_, sizeof(int)*size_);    //bzero() shall place zero-valued bytes in arr_
	size_ = 0;       //The quantity of elements in the array is now 0 
};


//Implementing the overload operator [] that returns the element (integer in the array)
//in pos (position inside the array) requested. We can assume that the given position
//is valid.
//Preconditions:There are elements in the array (arr_) and the integer pos (position in 
//the array) is less than the value of the actual capacity.
//Postconditions:Return the element in the position pos, assuming pos is less the value 
//of current capacity.

int& Vector::operator[](unsigned int pos){
	return arr_[pos];        //Return position pos in the array.
};


//Implementing the bool at() function that verify first if the position pos is valid in
//the array (pos>=0 and pos<size_) and then set the value of data in that position. 
//Preconditions:There are elements in the array and data is integer value.
//Postconditions:If position pos is valid set the value of data to the element in the
//vector at position pos, if not return false.

bool Vector::at(unsigned int pos, int& data) const{
	if((pos >= 0) && (pos < size_)){	//pos is valid index in arr_
		data = arr_[pos];              
		return true;
	}else{	                       //pos is invalid so return false
		return false;
	}
};


//Implementing resize(capacity) function to modify the capacity of number of elements 
//that can have the array,if number of elements is bigger than capacity (size_>capacity) 
//the capacity of the array is increased. 
//Preconditions:Size of elements are bigger than capacity.
//Postconditions:Capacity of the array that holds the integer values is modified and 
//content of the memory block is preserved using realloc function to move the memory block
//to the new location. 

void Vector::resize(unsigned int capacity){
	if(size_ > capacity){
		size_ = capacity;
	}
	capacity_ = capacity;
	arr_ = (int*)realloc(arr_, sizeof(int) * capacity_);
};
