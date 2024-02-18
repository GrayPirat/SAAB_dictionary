#pragma once
#include<iostream>
#include<vector>
#include <string>
#include <iosfwd>
using namespace std;

template<typename KeyData, typename Data>
class Table
{
	protected:
	typedef _Vector_iterator<_Vector_val<_Simple_types<pair<KeyData, Data>>>> it; //type of vector iterator 

	vector<pair<KeyData, Data>> arr; // dictionary
public:
	it& insert(KeyData key, Data value); //insert cacheline 
	bool Remove(KeyData key); // remove ...
	it& operator[](KeyData key);// access to line`s data
	it search(KeyData key);// search for line with it`s key
	//Table();//init constructor
	//Table(const Table& d);//copy constructor
	//~Table();//destructor
};