#include "dictionary_head.h"
using namespace std;



template<typename KeyData, typename Data>
bool Table<KeyData, Data>::Remove(KeyData key)
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
template<typename KeyData, typename Data>
typename Table <KeyData,Data>:: it& Table<KeyData, Data>::insert(KeyData key, Data value)
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
	return iter;
}
template<typename KeyData, typename Data>
typename Table <KeyData, Data>::it Table<KeyData, Data>::search(KeyData key)
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
template<typename KeyData, typename Data>
typename Table <KeyData, Data>::it& Table<KeyData, Data>::operator[](KeyData key)
{
	auto iter = arr.begin();
	while (iter != arr.end())
	{
		if (iter->first == key)
			return iter;
		return iter;
		iter++;
	}
	//return iter;
}

	Table <int, string> a;
	a.insert(0, "e");
	
	cout << a.search(0)->second;
	a[2];
}
