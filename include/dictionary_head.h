#pragma once
#include<iostream>
#include<vector>
#include <string>
#include <iosfwd>
using namespace std;

struct EmptyException {
	int lost_key;
};

template<class KeyData, class Data>
class Table
{
protected:
	typedef _Vector_iterator<_Vector_val<_Simple_types<pair<KeyData, Data>>>> it; //type of vector iterator 

	vector<pair<KeyData, Data>> arr; // dictionary
public:
	it insert(KeyData key, Data value) //insert cacheline 
	{
		auto iter = arr.begin();
		while (iter != arr.end())
		{

			if (iter->first == key)
			{
				iter->second = value;
				return iter;
			}
			++iter;
		}
		arr.push_back(make_pair(key, value));
		iter = arr.end() - 1;
		return iter;
	}

	bool Remove(KeyData key) // remove ...
	{
		auto iter = arr.begin();
		while (iter != arr.end())
		{
			if (iter->first == key)
			{
				arr.erase(iter);
				return true;
			}
			++iter;
		}
		return false;
	}

	it operator[](KeyData key)// access to line`s data
	{
		auto iter = arr.begin();
		while (iter != arr.end())
		{
			if (iter->first == key)
				return iter;
			iter++;
		}
		Data t;
		return insert(key, t);
	}

	it search(KeyData key) // search for line with it`s key
	{
		auto iter = arr.begin();
		while (iter != arr.end())
		{
			if (key == iter->first)
			{

				return iter;
			}
			++iter;
		}
	}

	//constructor
	Table() {
	
	}

	//copy constructor
	Table(const Table& d) {
		auto iter = d.arr.begin();
		while (iter != d.arr.end()) {
			arr.push_back(make_pair(iter->first, iter->second));
			iter++;
		}
	}

	//destructor
	~Table() {
		arr.clear();
		arr.shrink_to_fit();
	}
};


template<class KeyData, class Data>
class Sorted_Table :protected Table<KeyData, Data> 
{
	 it search(KeyData key, KeyData searchkey) override //binary search for a cachelne
	{
		 auto l_iter = arr.begin() - 1;
		 auto r_iter = arr.end();
		 while (l_iter < r_iter - 1) {
			 auto m_iter = (l_iter + r_iter) / 2;
			 if (m_iter->first < searchkey) l_iter = m_iter;
			 else r_iter = m_iter;
		 }
		 return r_iter;
	}

	 
};