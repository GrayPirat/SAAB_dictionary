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
	virtual it insert(KeyData key, Data value) //insert cacheline 
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

	virtual bool remove(KeyData key) // remove ...
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
	virtual it search(KeyData key) // search for line with it`s key
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
class Sorted_Table :protected Table<KeyData,Data>
{
protected:
	bool comp_given;
	typedef _CoreCrtNonSecureSearchSortCompareFunction  comp;
	comp temp;
	
public:
	Sorted_Table()
	{
		comp_given = 0;
	}

	Sorted_Table(comp t)
	{
		comp_given = true;
		temp = t;
	}

	void sort_table()
	{
		if (comp_given == false)
		{
			std::qsort(arr.begin(), arr.size(), sizeof(make_pair(KeyData t, Data y)));
		}
		else
		{
			std::qsort(arr.begin(), arr.size(), sizeof(make_pair(KeyData t, Data y)), temp);
		}
	}

	it f_binar(KeyData key)
	{
		auto beg = arr.begin();
		auto end = arr.end();
		auto mid = arr.begin() + (end - beg) / 2;
		while (mid != end && mid->first != key) {
			if (key < mid->first)
				end = mid;
			else
				beg = mid + 1;
			mid = beg + (end - beg) / 2;
		}
		return mid;
	}

	it insert(KeyData key, Data value) override
	{
		auto l_iter = arr.begin();
		auto r_iter = arr.end();
		if (arr.size() == 0)
		{
			arr.push_back(make_pair(key, value));
			return arr.begin();
		}

		auto finded = f_binar(key);
		if (finded != arr.end()) {
			if ((finded)->first == key)
			{
				(finded)->second = value;
				return finded;
			}
		}
		if (finded == arr.end()) {
			arr.push_back(make_pair(key, value));
			l_iter = arr.end() - 1;
			return l_iter;
		}
		else {
			arr.insert(finded, make_pair(key, value));
			return finded;
		}
	}

	bool remove(KeyData key) override
	{
		if (arr.size() == 0) 
			return false;
		auto iter = f_binar(key);
		if (iter->first == key)
		{
			arr.erase(iter);
			return true;
		}
		return false;
	}

	it operator[](KeyData key)
	{
		auto iter = f_binar(key);
		if (iter == arr.end()) {
			Data t;
			return insert(key, t);
		}
		else
			return iter;
	}

	it search(KeyData key) override
	{
		return f_binar(key);
	}
};


template<class KeyData, class Data>
class Hash_Table :protected Table<KeyData, Data>
{
private:

	typedef _Vector_iterator<_Vector_val<_Simple_types<pair<KeyData,Data>>>> it;

	bool Key_str = false;
	bool Key_vec = false;
	bool Key_int = false;
	bool Key_double = false;
	
	const int simple_base = 7;
	int table_size = 0;

	vector<vector<pair<KeyData,Data>>> arr;

	
	int get_hash(KeyData key)
	{
		int ans = 0;
		
		if (Key_vec)
		{

			for (int i = 0; i < key.size(); i++)
			{
				ans += key[i] * pow(simple_base, i);
			}
		}
		
		if (Key_str)
		{
			for (int i = 0; i < key.size(); i++)
			{
				ans += (int)(key[i]) * pow(simple_base, i);
			}
		}
		if (Key_int)
		{
			ans = clock();
		}
		if (Key_double)
		{
			string temp = "";/*  to_string(key);*/
			string temp2 = "";
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp[i] != '.')
					temp2.push_back(temp[i]);

			}
			ans = stoi(temp2);

		}
		return ans % table_size;
	}

public:
	Hash_Table(int n)
	{
		if (is_same_v<string,KeyData>)
			Key_str = true;
		if (is_same_v<KeyData, vector<int>>)
			Key_vec = true;
		if (is_same_v<KeyData, int>)
			Key_int = true;
		if (is_same_v<KeyData, double>)
			Key_double = true;

		this->arr = vector<vector<pair<KeyData, Data>>>(n);
		this->table_size = n;
	}
	
	it insert_hash(KeyData key, Data val)
	{
		
		int hash = get_hash(key);
		auto iter = arr[hash].begin();
		while (iter != arr[hash].end())
		{
			if (iter->first == key)
			{
				iter->second = val;
				return iter;
			}
			iter++;

		}
		arr[hash].push_back(make_pair(key, val));
		iter = arr[hash].end();
		iter--;
		return iter;
	}

	bool remove_hash(KeyData key) // remove ... casheline fully  idk if i should`ve make it more specific
	{
		
		auto hash = get_hash(key);
		auto iter = arr[hash].begin();
		while (iter != arr[hash].end())
		{
			if (iter->first == key)
			{
				arr[hash].erase(iter);
				return true;
			}
			iter++;

		}
		return false;
	}

	it operator[](KeyData key)// access to line`s data returns vector -> iterate with in: sfkjghsfjkg
	{
		
		auto hash = get_hash(key);
		auto iter = arr[hash].begin();
		while (iter != arr[hash].end())
		{
			if (iter->first == key)
			{
				return iter;
			}

			iter++;
		}
		Data t = NULL;
		return insert_hash(key, t);
	}

	it search_hash(KeyData key) // search for line with it`s key
	{
		auto hash = get_hash(key);
		auto iter = arr[hash].begin();
		while (iter != arr[hash].end())
		{
			if (iter->first == key)
			{
				return iter;
			}

			iter++;
		}
		return iter;
	}
};