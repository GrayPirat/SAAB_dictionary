#pragma once
#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<limits>
#include<string>
#include<iosfwd>
#include<windows.h>
#include<cstdio>
using namespace std;



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
		n = max(1, n);
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



template<class KeyData, class Data>
class Binary_Tree
{
protected:
	struct TreeNode
	{
		Data value;
		KeyData key;

		TreeNode* left;
		TreeNode* right;
		TreeNode* top;


		int Height;
		bool visited = false;
		TreeNode() :value(NULL),key(NULL), left(NULL), right(NULL), top(NULL), visited(false) {}

		TreeNode(KeyData key,Data value) : value(value),key(key), left(NULL), right(NULL), top(NULL), visited(false),Height(0) {}
	};

	
	bool  flag_not_null = false;

	typedef TreeNode* it;

	TreeNode* start_root;
	//iterator prop
	it iter_pos;

	vector<TreeNode*> stack;

	int size;

	bool flag_not_started = true;

	bool check()
	{
		for (auto v : stack)
		{
			if (v->visited == false)
				return true;
		}
		return false;
	}
	//end of prop
	it back_to_root(it temp, it ans)
	{
		while (temp != ans)
			temp = temp->top;
		return temp;
	}

	void print_inner(TreeNode* root, COORD position)
	{
		if (root != NULL)
		{
			SetConsoleCursorPosition(hConsole, position);

			cout << root->key;
			auto pos = position;
			if (root->left != NULL)
			{

				/*pos.X = position.X - rashod/2;
				pos.Y = position.Y + 1;
				SetConsoleCursorPosition(hConsole, pos);
				cout << '/';*/
				pos.X = pos.X - 4;
				pos.Y = pos.Y + 1;
				print_inner(root->left, pos);
				

			}
			pos = position;
			if (root->right != NULL)
			{
				/*pos.X = position.X + rashod/2;
				pos.Y = position.Y + 1;
				SetConsoleCursorPosition(hConsole, pos);
				cout << '\\';*/
				pos.X = pos.X + 4;
				pos.Y = pos.Y + 1;
				print_inner(root->right, pos);
			}
		}
	}

	void remaster_stack(TreeNode* root)
	{
		if (root != NULL)
		{
			stack.push_back(root);

			if (root->left != NULL)
			{
				remaster_stack(root->left);
			}
			if (root->right != NULL)
				remaster_stack(root->right);
		}
		
	}
public:
	Binary_Tree()
	{
		start_root = new TreeNode();
	}
	Binary_Tree(Data val,KeyData key)
	{
		start_root =new TreeNode(val,key);
	}
	Binary_Tree(const Binary_Tree& tree)
	{
		if (tree.start_root != NULL)
		{
			this->start_root = new TreeNode();

			cop_tree(this, tree.start_root);
		}
	}

	void cop_tree(Binary_Tree* tree,TreeNode* root) {
		tree->insert(root->key,root->value);

		if (root->left != NULL)
			cop_tree(tree, root->left);
		if (root->right != NULL)
			cop_tree(tree, root->right);
	}


	bool remove(KeyData key)
	{
		TreeNode* temp = search(key);


		if (!(temp==NULL) )
		{
			for (int i = 0; i < stack.size(); i++)
			{
				if (stack[i] == temp)
				{
					stack.erase(stack.begin() + i);
					break;
				}
			}

			//left net right da
			if (temp->left == NULL && temp->right != NULL)
			{
				if (temp != start_root)
				{


					TreeNode* save = temp;
					temp = temp->top;

					if (save == temp->left)
					{
						save = save->right;
						temp->left = save;
					}
					else
					{
						save = save->right;

						temp->right = save;

					}
					save->top = temp;
					temp = back_to_root(temp, start_root);
					start_root = temp;
				}
				else
				{
					start_root = temp->right;
				}
			}
			//left da right net
			else if (temp->left != NULL && temp->right == NULL)
			{
				if (start_root != temp)
				{
					TreeNode* save = temp;
					temp = temp->top;

					if (save == temp->left)
					{
						save = save->left;
						temp->left = save;
					}
					else
					{
						save = save->left;

						temp->right = save;

					}
					save->top = temp;
					temp = back_to_root(temp, start_root);
					start_root = temp;
				}
				else
				{
					start_root = temp->left;
				}
			}

			//tout est la
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
				TreeNode* blank = new TreeNode(min_r_branch->key,min_r_branch->value);
				blank->visited = min_r_branch->visited;

				//join right branch
				if (min_r_branch != s_right)
				{
					if (min_r_branch->right != NULL)
					{
						blank->right = min_r_branch->right;
						min_r_branch->right->top = blank;
					}

					

					auto skipper = s_right;
					while (skipper->left != min_r_branch)
						skipper = skipper->left;
					skipper->left = NULL;
					skipper = back_to_root(skipper, s_right);
					s_right = skipper;
					

					temp = blank;
					while (temp->right != NULL)
						temp = temp->right;

					temp->right = s_right;
					s_right->top = temp;
					temp = back_to_root(temp, blank);
					blank = temp;
				}
				else
				{
					if (s_right->right != NULL)
					{
						blank->right = s_right->right;
						s_right->right->top = blank;
					}

				}


				//join left branch
				blank->left = s_left;
				s_left->top = blank;


				//join main tree
				if (save != start_root)
				{
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
					s_top = back_to_root(s_top, start_root);
					start_root = s_top;
				}
				else
				{
					start_root = blank;
				}
				//if it dont work properly than try 2 var


			}

			//leaf
			else if (temp->left == NULL && temp->right == NULL)
			{
				if (temp != start_root)
				{
					auto save = temp->top;
					if (save->left == temp)
					{
						save->left = NULL;
						temp->top = NULL;

					}
					else
					{
						save->right = NULL;
						temp->top = NULL;

					}
					save = back_to_root(save, start_root);
					start_root = save;
				}
				else
				{
					start_root = NULL;
					flag_not_null++;
				}
				

			}

			stack.clear();
			stack.shrink_to_fit();
			remaster_stack(start_root);

			return true;

		}

		return false;
	}

	int get_size() {
		return stack.size();
	}

	it insert(KeyData key,Data val)
	{
		TreeNode* temp = start_root;
		
		if (flag_not_null)
		{
			while (1)
			{

				if (temp->key >= key)
				{
					if (temp->left != nullptr)
					{
						temp = temp->left;
					}
					else
					{
						TreeNode* ans = new TreeNode(key,val);

						ans->top = temp;
						temp->left = ans;
						temp = back_to_root(temp, start_root);
						start_root = temp;
						stack.clear();
						stack.shrink_to_fit();
						remaster_stack(start_root);
						return ans;
					}

				}

				if (temp->key < key)
				{
					if (temp->right != nullptr)
					{
						temp = temp->right;
					}
					else
					{
						TreeNode* ans = new TreeNode(key,val);
						ans->top = temp;
						temp->right = ans;
						temp = back_to_root(temp, start_root);
						start_root = temp;
						stack.clear();
						stack.shrink_to_fit();
						remaster_stack(start_root);
						return ans;
					}
				}
			}

		}
		else
		{
			start_root->value = val;
			start_root->key = key;
			flag_not_null = true;
			stack.clear();
			stack.shrink_to_fit();
			remaster_stack(start_root);
			return temp;

		}

	}

	it search(KeyData key)
	{
		TreeNode* temp = start_root;
		if (temp != NULL)
		{
			while (1)
			{
				if (temp->key == key)
					return temp;

				if (temp->key > key)
				{
					if (temp->left != NULL)
					{
						temp = temp->left;
					}
					else
					{
						
						return NULL;
					}

				}

				if (temp->key < key)
				{
					if (temp->right != NULL)
					{
						temp = temp->right;
					}
					else
					{
						
						return NULL;
					}
				}
			}
		}
	}

	it operator++()
	{

		if (stack.size() == 0)
			return new TreeNode();

		if (check())
		{
			int min = INT_MAX;
			int pos = 0;
			for (int i = 0; i < stack.size(); i++)
			{
				if (stack[i]->visited == false && stack[i]->key < min)
				{
					min = stack[i]->key;
					pos = i;

				}
			}
			stack[pos]->visited = true;
			iter_pos = stack[pos];

			return iter_pos;
		}
		else
		{
			for (auto i : stack)
				i->visited = false;
			auto t = this->operator++();
			return t;
		}

	}

	void print()
	{
		system("cls");
		position.X = 50;
		position.Y = 0;

		print_inner(start_root, position);

		position.X = 0;
		position.Y = 30;
		SetConsoleCursorPosition(hConsole, position);
	}

	int tree_height() {
		return height_start_root(start_root);
	}

	int height_start_root(TreeNode* root) {
		if (root == NULL)
			return 0;
		else {
			auto left_height = height_start_root(root->left);
			auto right_height = height_start_root(root->right);

			return max(left_height, right_height) + 1;
		}
	}

	int size_of_tree()
	{
		return stack.size();
	}
};


template<class KeyData,class Data>
class AVL_Tree : public Binary_Tree<KeyData,Data>
{
	int set_height(TreeNode* root)
	{
		int t1 = 0;
		int t2 = 0;
		if (root->left != NULL)
			t1=set_height(root->left);
		if (root->right != NULL)
			t2 = set_height(root->right);
		if (root->left == NULL && root->right == NULL)
		{
			root->Height = 0;
			return 0;
		}
		else
		{
			root->Height = max(t1, t2) + 1;
			return root->Height;
		}
		
	}
	int bfactor(TreeNode* p)
	{
		auto h_l = 0;
		auto h_r = 0;
		if (p->left != NULL)
			h_l = p->left->Height;
		if (p->right != NULL)
			h_r = p->right->Height;
		return h_r - h_l;
	}

	it SmallRotateRight(TreeNode* p) // правый поворот вокруг p
	{
		auto q = p->left;
		p->left = q->right;
		q->right = p;
		q->top = p->top;
		p->top = q;
		
		return q;
	}
	it SmallRotateLeft(TreeNode* q) // левый поворот вокруг q
	{
		auto p = q->right;
		q->right = p->left;
		p->left = q;
		p->top = q->top;
		q->top = p;

		
		return p;
	}
	void balance(TreeNode* p) // балансировка узла p
	{
		
		if (bfactor(p) == 2)
		{
			
			if (bfactor(p->right) < 0)
				p->right = SmallRotateRight(p->right);
			auto temp = SmallRotateLeft(p);
			start_root = temp;
		}
		if (bfactor(p) == -2)
		{
			if (bfactor(p->left) > 0)
				p->left = SmallRotateLeft(p->left);
			auto temp = SmallRotateRight(p);
			start_root = temp;
		}
	}

	void print_inner(TreeNode* root, COORD position)
	{
		if (root != NULL)
		{
			SetConsoleCursorPosition(hConsole, position);

			cout << root->key;
			auto pos = position;
			if (root->left != NULL)
			{
				int temp =  (root->Height*2);
				
				pos.X = pos.X - temp;
				pos.Y = pos.Y + 1;
				print_inner(root->left, pos);


			}
			pos = position;
			if (root->right != NULL)
			{
				int temp = (root ->Height*2);
				pos.X = pos.X +temp;
				pos.Y = pos.Y + 1;
				print_inner(root->right, pos);
			}
		}
	}
public:
	AVL_Tree()
	{
		
		start_root = new  TreeNode();
	}
	AVL_Tree(KeyData key,Data val)
	{
		start_root = new TreeNode(key, val);
		flag_not_null = true;
	}
	
	
	it insert(KeyData key, Data val) 
	{
		auto ans = Binary_Tree::insert(key, val);
		set_height(start_root);
		print();
		balance(start_root);
		print();
		return ans;
	}
	bool remove(KeyData key)
	{
		auto ans = Binary_Tree::remove(key);
		set_height(start_root);
		balance(start_root);
		return ans;
	}
	
	void print()
		{
		system("cls");
		position.X = 50;
		position.Y = 0;

		print_inner(start_root, position);
	}
	
};

template<class KeyData, class Data>
class RB_Tree : public Binary_Tree<KeyData, Data> {
private:
	enum colors {red, black};

	struct RBNode {
		RBNode* parent, * left, * right;
		enum colors color;
		KeyData key;
		Data value;
	};

	RBNode *grandparent(RBNode* node)
	{
		if ((node != NULL) && (node->parent != NULL))
			return node->parent->parent;
		else
			return NULL;
	}

	RBNode* Uncle(RBNode* node) {
		Node* g = grandparent(node);
		if (g == NULL)
			return NULL;
		if (node->parent == g->left)
			return g->right;
		else
			return g->left;
	}


public:
	void rotate_left(RBNode* node)//left RB turn
	{
		RBNode* temp = node->right;

		temp->parent = node->parent;
		if (node->parent != NULL) {
			if (node->parent->left == node)
				node->parent->left = temp;
			else
				node->parent->right = temp;
		}

		node->right = temp->left;
		if (temp->left != NULL)
			temp->left->parent = n;

		node->parent = temp;
		temp->left = node;
	}

	void rotate_right(RBNode* node)
	{
		RBNode* temp = node->left;

		temp->parent = node->parent; /* при этом, возможно, temp становится корнем дерева */
		if (node->parent != NULL) {
			if (node->parent->left == node)
				node->parent->left = temp;
			else
				node->parent->right = temp;
		}

		node->left = temp->right;
		if (temp->right != NULL)
			temp->right->parent = node;

		node->parent = temp;
		temp->right = node;
	}

	void replace(RBNode* node, RBNode* child) {
		child->parent = node->parent;
		if (node == node->parent->left) {
			node->parent->left = child;
		}
		else {
			node->parent->right = child;
		}
	}

	void remove(KeyData key, Data val) {

	}

	void insert(KeyData key, Data val) {
		
	}
};