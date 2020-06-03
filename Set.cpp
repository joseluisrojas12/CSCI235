/**********************************************************************
Title:		Set.cpp
Author:		Jose Luis Rojas-Salazar
Date Created:	2/12/2017
Class:		Spring 2017, CSCI 25303, Mon & Wed 5:35pm-6:50pm
Professor:	Aarsh Vora
Purpose:	Assigment #1
Description:	Implementation of the public functions for class Set
***********************************************************************/


#include "Set.h"


//Implementation of size() function that returns the currente number of elements
//in the set.
//Preconditions:There are 0 or more elements in the vector.
//Postconditions:Get the size of the vector that hold the set of integer values.

unsigned int Set::size() const{
	return vector_.size();	//return vector size using vector_ object so we can
};                              //call and use ther function size() from Vector class


//Implementation of empty() function 
//
//
//
//

bool Set::empty() const{
	return vector_.empty();	//check if vector is empty
};




bool Set::contains(const int& data) const{
	int v_data;	//used as reference in at()
	for(unsigned int i=0; i < vector_.size(); i++){
		vector_.at(i, v_data);	//get value i at vector
		if(v_data == data)		//check if its our data
			return true;		//data is inside vector
	}
	return false;
};




bool Set::insert(const int& data){
	if(!contains(data)){			//if set doesn't have the data
		vector_.push_back(data);	//insert it
		return true;				//inserted successfully
	}
	return false;
};




bool Set::remove(const int& data){
	return vector_.remove(data);	//remove data from vector
};




void Set::clear(){
	vector_.clear();			//clear vector
};
