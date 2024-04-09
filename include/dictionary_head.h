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
		return arr.end();
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
	/*typedef std::_Vector_iterator<std::_Vector_val<_Simple_types<vector<pair<KeyData, Data>>>>> big_it;*/


	bool Key_str = false; // check if keydata is ...
	bool Key_vec = false;
	bool Key_int = false;
	bool Key_double = false;
	
	bool flag_for_iter = false; // flag for it

	const int simple_base = 7; // for hash
	int table_size = 0;

	vector<vector<pair<KeyData,Data>>> arr;


	it gen_iter;
	
	int b_iter = 0;
	const int mx_inserted = 2;

	int get_hash(vector<int> key, int razmer_table)
	{

		int ans = 0;


		for (int i = 0; i < key.size(); i++)
		{
			ans += key[i] * pow(simple_base, i);
		}

		return ans % razmer_table;


	} // get ahash

	int get_hash(string key, int razmer_table)
	{
		int ans = 0;

			for (int i = 0; i < key.size(); i++)
			{
				ans += (int)(key[i]) * pow(simple_base, i);
			}
		return ans % razmer_table;
	}

	int get_hash(int key, int razmer_table)
	{
		int ans = key;
		ans >> 13;
		ans << 4;
		ans >> 58;
		ans>>27;
		ans = ~ans;
		return abs(ans % razmer_table);
	}
	
	int get_hash(double key, int razmer_table)
	{
		int ans = 0;
	
		string temp = to_string(key);/*  to_string(key);*/
		string temp2 = "";
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] != '.')
				temp2.push_back(temp[i]);

		}
			
		ans = get_hash(temp2, razmer_table);

		ans = get_hash(ans, razmer_table);
		return get_hash(ans, razmer_table) % razmer_table;
	}

public:
	


	Hash_Table(int n)
	{
		n = std::max(1, n);
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
		gen_iter = arr[0].begin();
	}
	

	it insert_hash(KeyData key, Data val)
	{
		int hash = get_hash(key, table_size);
		if (arr[hash].size() >= mx_inserted) {
			vector<vector<pair<KeyData, Data>>> temp((table_size+1)*2);
			it tmp = operator++();
			KeyData sav1 = tmp->first;
			Data sav2 = tmp->second;
			int new_tabsize = (table_size+1) * 2;
			hash = get_hash(tmp->first, new_tabsize);
			temp[hash].push_back(make_pair(sav1, sav2));
			tmp=operator++();
			while (sav1 != tmp->first && sav2 != tmp->second) {
				hash = get_hash(tmp->first, new_tabsize);
				temp[hash].push_back(make_pair(tmp->first, tmp->second));
				tmp=operator++();
			}
			sav1 = gen_iter->first;
			arr = temp;
			table_size = (table_size+1)*2;
			this->flag_for_iter = false;
			operator++();
			while (gen_iter->first != sav1)
				operator++();
		}
		hash = get_hash(key, table_size);
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
		if (flag_for_iter==true){
			auto sav1 = gen_iter->first;
			arr[hash].push_back(make_pair(key, val));
			if (hash == b_iter)
			{
				flag_for_iter = false;
				operator++();
			}
				
			
			while (gen_iter->first != sav1)
			{
				operator++();
			}
		}
		else
		{
			arr[hash].push_back(make_pair(key, val));
		}
		
		iter = arr[hash].end();
		iter--;
		return iter;
	}

	long long size() {
		return table_size;
	}

	long long number_elem() {
		long long sum = 0;
		for (int i = 0; i < table_size; i++) {
			sum += arr[i].size();
		}
		return sum
	}

	bool remove_hash(KeyData key) // removes ... a part of cacheline
	{
		
		auto hash = get_hash(key, table_size);
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
		
		auto hash = get_hash(key, table_size);
		auto iter = arr[hash].begin();

		while (iter != arr[hash].end())
		{
			if (iter->first == key)
			{
				return iter;
			}

			iter++;
		}

		Data t;
		return insert_hash(key, t);
	}

	it search_hash(KeyData key) // search for line with it`s key
	{
		auto hash = get_hash(key, table_size);
		auto iter = arr[hash].begin();
		while (iter != arr[hash].end())
		{
			if (iter->first == key)
			{
				return iter;
			}

			iter++;
		}
		if (iter == arr[hash].end())
		{
			throw 123;
		}

	}

	it operator++()
	{
		auto prev = gen_iter;
		auto gen_iter_inner = gen_iter;
		bool flag_for_skip = false;
		while (b_iter != table_size)
		{
			gen_iter_inner = arr[b_iter].begin();
			while (gen_iter_inner != arr[b_iter].end())
			{
				if (!flag_for_iter)
				{
					gen_iter = gen_iter_inner;
					flag_for_iter = true;
					return gen_iter_inner;
				}
				while ((gen_iter_inner->second != prev->second || gen_iter_inner->first != prev->first)&& !flag_for_skip)
				{
					gen_iter_inner++;
					
				}
				flag_for_skip = true;
				if (gen_iter_inner->second != prev->second || gen_iter_inner->first != prev->first)
				{
					gen_iter = gen_iter_inner;
					return gen_iter_inner;
				}
				gen_iter_inner++;
			}
			b_iter++;
		}
		b_iter = 0;
		flag_for_iter = false;
		while (b_iter != table_size)
		{
			gen_iter_inner = arr[b_iter].begin();
			while (gen_iter_inner != arr[b_iter].end())
			{
				if (!flag_for_iter)
				{
					gen_iter = gen_iter_inner;
					flag_for_iter = true;
					return gen_iter_inner;
				}
				if (gen_iter_inner->second != prev->second || gen_iter_inner->first != prev->first)
				{
					gen_iter = gen_iter_inner;
					return gen_iter_inner;
				}
				gen_iter_inner++;
			}
			b_iter++;
		}
	}
};

template<class KeyData,class Data>
class binary_tree:public  Table<KeyData,Data>
{
	class TreeNode
	{
	protected:
		Data value;

		TreeNode* left;
		TreeNode* right;
		TreeNode* top;

		TreeNode() :value(NULL) {}
		
		TreeNode(Data value) : value(value), left(NULL), right(NULL), top(NULL) {}

	};

	typedef TreeNode* it;
	TreeNode* start_root;

	binary_tree()
	{
		start_root->TreeNode();
	}
	binary_tree(Data val)
	{
		start_root->TreeNode(val);
	}
	binary_tree(binary_tree* tree)
	{
		this->start_root = tree->start_root;
	}


	bool remove(Data val) override
	{
		TreeNode* temp = search(val);
		if (temp->value != NULL)
		{
			//left net right da
			if (temp->left == NULL && temp->right != NULL)
			{
				TreeNode* save = temp;
				temp = temp->top;
				save = save->right;
				save->top = temp;
				if (save == temp->left)
				{
					temp->left = save;
				}
				else
				{
					temp->right = save;
				}


			}
			//left da right net
			else if (temp->left != NULL && temp->right == NULL)
			{
				TreeNode* save = temp;
				temp = temp->top;
				save = save->left;
				save->top = temp;
				if (save == temp->left)
				{
					temp->left = save;
				}
				else
				{
					temp->right = save;
				}
			}
			// tout est la
			else if (temp->left != NULL && temp->right != NULL)
			{
				auto save = temp;
				auto s_left = temp->left;
				auto s_right = temp->right;
				temp = temp->right;
				bool flag = false;
				while (!flag)
				{
					if (temp->left == NULL)
						flag++;
					else
						temp = temp->left;
				}
				//temp = min sprava ->set this branch
				auto min_r_branch = temp;

				//create brand new node to build evrth
				TreeNode blank = TreeNode(min_r_branch->value);
				blank->right = min_r_branch->right;
				delete temp;
				// join left branch
				blank->left = s_left;
				s_left->top = blank;
				//join right branch
				min_r_branch = min_r_brach->top;
				min_r_branch->left = NULL;

				auto temp = blank;
				while (temp->right != NULL)
					temp = temp->right;

				temp->right = s_right;
				s_right->top = temp;
				// join main tree
				auto s_top = save->top;
				if (s_top->left == save)
				{
					s_top->left = blank;
					blank->top = s_top;
				}
				else
				{
					s_top->right = blank;
					blank->top = s_top;

				}
				// if it dont work properly than try 2 var

				
			}
			// leaf
			else if (temp->left == NULL && temp->right == NULL)
			{
				auto save = temp->top;
				if (save->left == save)
				{
					save->left = NULL;
					temp->top = NULL;
				}
				else
				{
					save->right = NULL;
					temp->top = NULL;

				}
				
			}
			return true;

		}
		return false;
	}

	it search(Data val) override
	{
		TreeNode* temp = start_root;
		if (temp != NULL)
		{
			bool flag_for_rem = true;
			while (1)
			{
				if (temp->value == val)
					return temp;

				if (temp->value > val)
				{
					if (temp->left != NULL)
					{
						temp = temp->left;
					}
					else
					{
						TreeNode ans = TreeNode();
						ans->top = temp;
						return ans;
					}
						
				}

				if (temp->value < val)
				{
					if (temp->right != NULL)
					{
						temp = temp->right;
					}
					else
					{
						TreeNode ans = TreeNode();
						ans->top = temp;
						return ans;
					}
				}
			}
		}
	}
};