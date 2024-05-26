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
class Table {
protected:
	typedef _Vector_iterator<_Vector_val<_Simple_types<pair<KeyData, Data>>>> it; //type of vector iterator 
	vector<pair<KeyData, Data>> arr; // dictionary

public:
	virtual it insert(KeyData key, Data value) { //insert cacheline 
		auto iter = arr.begin();
		while (iter != arr.end()) {
			if (iter->first == key) {
				iter->second = value;
				return iter;
			}
			++iter;
		}
		arr.push_back(make_pair(key, value));
		iter = arr.end() - 1;
		return iter;
	}

	virtual bool remove(KeyData key) { // remove ...
		auto iter = arr.begin();
		while (iter != arr.end()) {
			if (iter->first == key) {
				arr.erase(iter);
				return true;
			}
			++iter;
		}
		return false;
	}

	it operator[](KeyData key) { // access to line`s data
		auto iter = arr.begin();
		while (iter != arr.end()) {
			if (iter->first == key)
				return iter;
			iter++;
		}
		Data t;
		return insert(key, t);
	}
	
	virtual it search(KeyData key) { // search for line with it`s key
		auto iter = arr.begin();
		while (iter != arr.end()) {
			if (key == iter->first) {

				return iter;
			}
			++iter;
		}
		return arr.end();
	}

	//constructor
	Table() {}

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
class Sorted_Table :protected Table<KeyData, Data> {
protected:
	bool comp_given;
	typedef _CoreCrtNonSecureSearchSortCompareFunction  comp;
	comp temp;

public:
	Sorted_Table() {
		comp_given = 0;
	}

	Sorted_Table(comp t) {
		comp_given = true;
		temp = t;
	}

	void sort_table() {
		if (comp_given == false) {
			std::qsort(arr.begin(), arr.size(), sizeof(make_pair(KeyData t, Data y)));
		}
		else {
			std::qsort(arr.begin(), arr.size(), sizeof(make_pair(KeyData t, Data y)), temp);
		}
	}

	it f_binar(KeyData key) {
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

	it insert(KeyData key, Data value) override {
		auto l_iter = arr.begin();
		auto r_iter = arr.end();
		if (arr.size() == 0) {
			arr.push_back(make_pair(key, value));
			return arr.begin();
		}

		auto finded = f_binar(key);
		if (finded != arr.end()) {
			if ((finded)->first == key) {
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

	bool remove(KeyData key) override {
		if (arr.size() == 0) 
			return false;
		auto iter = f_binar(key);
		if (iter->first == key) {
			arr.erase(iter);
			return true;
		}
		return false;
	}

	it operator[](KeyData key) {
		auto iter = f_binar(key);
		if (iter == arr.end()) {
			Data t;
			return insert(key, t);
		}
		else
			return iter;
	}

	it search(KeyData key) override {
		return f_binar(key);
	}

};


template<class KeyData, class Data>
class Hash_Table :protected Table<KeyData, Data> {
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

	int get_hash(vector<int> key, int razmer_table) {
		int ans = 0;
		for (int i = 0; i < key.size(); i++) {
			ans += key[i] * pow(simple_base, i);
		}
		return ans % razmer_table;
	} // get ahash

	int get_hash(string key, int razmer_table) {
		int ans = 0;
		for (int i = 0; i < key.size(); i++)
			ans += (int)(key[i]) * pow(simple_base, i);
		return ans % razmer_table;
	}

	int get_hash(int key, int razmer_table) {
		int ans = key;
		ans >> 13;
		ans << 4;
		ans >> 58;
		ans>>27;
		ans = ~ans;
		return abs(ans % razmer_table);
	}
	
	int get_hash(double key, int razmer_table) {
		int ans = 0;
		string temp = to_string(key);/*  to_string(key);*/
		string temp2 = "";
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] != '.')
				temp2.push_back(temp[i]);
		}
		ans = get_hash(temp2, razmer_table);
		ans = get_hash(ans, razmer_table);
		return get_hash(ans, razmer_table) % razmer_table;
	}

public:
	Hash_Table(int n) {
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
	

	it insert_hash(KeyData key, Data val) {
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
		while (iter != arr[hash].end()) {
			if (iter->first == key) {
				iter->second = val;
				return iter;
			}
			iter++;
		}

		if (flag_for_iter==true) {
			auto sav1 = gen_iter->first;
			arr[hash].push_back(make_pair(key, val));
			if (hash == b_iter) {
				flag_for_iter = false;
				operator++();
			}
				
			while (gen_iter->first != sav1)
				operator++();
		}
		else arr[hash].push_back(make_pair(key, val));		
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

	bool remove_hash(KeyData key) { // removes ... a part of cacheline
		auto hash = get_hash(key, table_size);
		auto iter = arr[hash].begin();
		while (iter != arr[hash].end()) {
			if (iter->first == key) {
				arr[hash].erase(iter);
				return true;
			}
			iter++;
		}
		return false;
	}

	it operator[](KeyData key) { // access to line`s data returns vector -> iterate with in: sfkjghsfjkg
		auto hash = get_hash(key, table_size);
		auto iter = arr[hash].begin();

		while (iter != arr[hash].end()) {
			if (iter->first == key)
				return iter;
			iter++;
		}
		Data t;
		return insert_hash(key, t);
	}

	it search_hash(KeyData key) { // search for line with it`s key
		auto hash = get_hash(key, table_size);
		auto iter = arr[hash].begin();
		while (iter != arr[hash].end()) {
			if (iter->first == key) 
				return iter;
			iter++;
		}
		if (iter == arr[hash].end())
			throw 123;
	}

	it operator++() {
		auto prev = gen_iter;
		auto gen_iter_inner = gen_iter;
		bool flag_for_skip = false;
		while (b_iter != table_size) {
			gen_iter_inner = arr[b_iter].begin();
			while (gen_iter_inner != arr[b_iter].end()) {
				if (!flag_for_iter) {
					gen_iter = gen_iter_inner;
					flag_for_iter = true;
					return gen_iter_inner;
				}

				while ((gen_iter_inner->second != prev->second || gen_iter_inner->first != prev->first)&& !flag_for_skip)
					gen_iter_inner++;
				flag_for_skip = true;
				
				if (gen_iter_inner->second != prev->second || gen_iter_inner->first != prev->first) {
					gen_iter = gen_iter_inner;
					return gen_iter_inner;
				}
				gen_iter_inner++;
			}
			b_iter++;
		}
		b_iter = 0;
		flag_for_iter = false;
		while (b_iter != table_size) {
			gen_iter_inner = arr[b_iter].begin();
			while (gen_iter_inner != arr[b_iter].end()) {
				if (!flag_for_iter) {
					gen_iter = gen_iter_inner;
					flag_for_iter = true;
					return gen_iter_inner;
				}

				if (gen_iter_inner->second != prev->second || gen_iter_inner->first != prev->first) {
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
	enum colors { red, black };
	struct TreeNode
	{
		Data value;
		KeyData key;

		TreeNode* left;
		TreeNode* right;
		TreeNode* top;
		colors color;

		int Height;
		bool visited = false;
		TreeNode() :value(NULL),key(NULL), left(NULL), right(NULL), top(NULL), visited(false),color(black) {}

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
	virtual it back_to_root(it temp, it ans)
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
				pos.X = pos.X - 5;
				pos.Y = pos.Y + 1;
				print_inner(root->left, pos);
				

			}
			pos = position;
			if (root->right != NULL)
			{
				
				pos.X = pos.X + 5;
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
	void link_nodes(TreeNode* u, TreeNode* v) {
		if (u->top == NULL) {
			start_root = v;
		}
		else if (u == u->top->left) {
			u->top->left = v;
		}
		else {
			u->top->right = v;
		}
		v->top = u->top;
	}
public:
	Binary_Tree() {
		start_root = new TreeNode();
	}

	Binary_Tree(Data val, KeyData key) {
		start_root = new TreeNode(val, key);
	}

	Binary_Tree(const Binary_Tree& tree) {
		if (tree.start_root != NULL) {
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

	bool remove(KeyData key) {
		//TreeNode* temp = search(key);
		//if (!(temp==NULL) ) {
		//	for (int i = 0; i < stack.size(); i++) {
		//		if (stack[i] == temp) {
		//			stack.erase(stack.begin() + i);
		//			break;
		//		}
		//	}
		//	//left net right da
		//	if (temp->left == NULL && temp->right != NULL) {
		//		if (temp != start_root) {
		//			TreeNode* save = temp;
		//			temp = temp->top;
		//			if (save == temp->left) {
		//				save = save->right;
		//				temp->left = save;
		//				//temp = temp->left;
		//			}
		//			else {
		//				save = save->right;
		//				temp->right = save;
		//				//temp = temp->right;
		//			}
		//			save->top = temp;
		//			temp = back_to_root(temp, start_root);
		//			start_root = temp;
		//		}
		//		else
		//			start_root = temp->right;
		//	}
		//	//left da right net
		//	else if (temp->left != NULL && temp->right == NULL) {
		//		if (start_root != temp) {
		//			TreeNode* save = temp;
		//			temp = temp->top;
		//			if (save == temp->left) {
		//				save = save->left;
		//				temp->left = save;
		//				//temp = temp->left;
		//			}
		//			else {
		//				save = save->left;
		//				temp->right = save;
		//				//temp=temp->right;
		//			}
		//			save->top = temp;
		//			temp = back_to_root(temp, start_root);
		//			start_root = temp;
		//		}
		//		else start_root = temp->left;
		//	}
		//	//tout est la
		//	else if (temp->left != NULL && temp->right != NULL) {
		//		auto save = temp;
		//		auto s_left = temp->left;
		//		auto s_right = temp->right;
		//		temp = temp->right;
		//		bool flag = false;
		//		while (!flag) {
		//			if (temp->left == NULL)
		//				flag++;
		//			else
		//				temp = temp->left;
		//		}
		//		//temp = min sprava ->set this branch
		//		auto min_r_branch = temp;
		//		//create brand new node to build evrth
		//		TreeNode* blank = new TreeNode(min_r_branch->key,min_r_branch->value);
		//		blank->visited = min_r_branch->visited;
		//		//join right branch
		//		if (min_r_branch != s_right) {
		//			if (min_r_branch->right != NULL) {
		//				blank->right = min_r_branch->right;
		//				min_r_branch->right->top = blank;
		//			}
		//			auto skipper = s_right;
		//			while (skipper->left != min_r_branch)
		//				skipper = skipper->left;
		//			skipper->left = NULL;
		//			skipper = back_to_root(skipper, s_right);
		//			s_right = skipper;
		//			temp = blank;
		//			while (temp->right != NULL)
		//				temp = temp->right;
		//			temp->right = s_right;
		//			s_right->top = temp;
		//			temp = back_to_root(temp, blank);
		//			blank = temp;
		//		}
		//		else {
		//			if (s_right->right != NULL) {
		//				blank->right = s_right->right;
		//				s_right->right->top = blank;
		//			}
		//		}
		//		//join left branch
		//		blank->left = s_left;
		//		s_left->top = blank;
		//		//join main tree
		//		if (save != start_root) {
		//			auto s_top = save->top;
		//			if (s_top->left == save) {
		//				s_top->left = blank;
		//				blank->top = s_top;
		//			}
		//			else {
		//				s_top->right = blank;
		//				blank->top = s_top;
		//			}
		//			s_top = back_to_root(s_top, start_root);
		//			start_root = s_top;
		//		}
		//		else start_root = blank;
		//		//if it dont work properly than try 2 var
		//	}
		//	//leaf
		//	else if (temp->left == NULL && temp->right == NULL) {
		//		if (temp != start_root) {
		//			auto save = temp->top;
		//			if (save->left == temp) {
		//				save->left = NULL;
		//				temp->top = NULL;
		//			}
		//			else {
		//				save->right = NULL;
		//				temp->top = NULL;
		//			}
		//			save = back_to_root(save, start_root);
		//			start_root = save;
		//		}
		//		else {
		//			start_root = NULL;
		//			flag_not_null++;
		//		}
		//	}
		//	stack.clear();
		//	stack.shrink_to_fit();
		//	remaster_stack(start_root);
		//	return true;
		/*}
		return false;*/

		TreeNode* z = Binary_Tree::search(key);

		/*if (!(z == NULL)) {
			for (int i = 0; i < stack.size(); i++) {
				if (stack[i] == z) {
					stack.erase(stack.begin() + i);
					break;
				}
			}
		}*/
		if (!(z == NULL)) //enter the alg
		{

			TreeNode* x;
			auto y = z;
			int y_original_color = y->color;

			if (z->left == NULL) { //leaf && left net right da
				if (z == start_root && z->left == NULL && z->right == NULL)
				{
					start_root = new TreeNode();
					flag_not_null = false;
					return true;
				}
				else
				{
					auto save = z->top;
					TreeNode* temp1 = NULL;
					if (z->right == NULL)
					{
						z->right = new TreeNode();
						z->right->top = z;
						temp1 = z->right;
					}
					x = z->right;
					link_nodes(z, z->right);
					delete z;

					if (temp1 != NULL)
					{
						if (temp1->top->left == temp1)
							temp1->top->left = NULL;
						else
							temp1->top->right = NULL;
						temp1 = NULL;
					}
				}

			}
			else if (z->right == NULL) // left da right net
			{
				TreeNode* temp3 = NULL;
				if (z->left == NULL)
				{
					z->left = new TreeNode();
					z->left->top = z;
					temp3 = z->left;
				}
				x = z->left;
				link_nodes(z, z->left);

				delete z;
				
				if (temp3 != NULL)
				{
					if (temp3->top->left == temp3)
						temp3->top->left = NULL;
					else
						temp3->top->right = NULL;
					temp3 = NULL;
				}

			}
			else {
				auto min_r_branch = y->right;
				bool flag = false;

				while (!flag) {
					if (min_r_branch->left == NULL)
						flag++;
					else
						min_r_branch = min_r_branch->left;
				}
				y = min_r_branch;

				TreeNode* temp2 = NULL;
				if (y->right == NULL)
				{
					y->right = new TreeNode();
					y->right->top = y;
					temp2 = y->right;
				}
				x = y->right;
				if (y->top == z) {
					x->top = y;
				}
				else {
					link_nodes(y, y->right);
					y->right = z->right;
					y->right->top = y;
				}

				link_nodes(z, y);

				y->left = z->left;
				y->left->top = y;

				delete z;

				if (temp2 != NULL)
				{
					if (temp2->top->left == temp2)
						temp2->top->left = NULL;
					else
						temp2->top->right = NULL;
					temp2 = NULL;
				}
			}
			return true;
		}
		return false;
		
	}

	int get_size() {
		return stack.size();
	}

	it insert(KeyData key,Data val) {
		TreeNode* temp = start_root;
		if (flag_not_null) {
			while (1) {
				if (temp->key >= key) {
					if (temp->left != nullptr)
						temp = temp->left;
					else {
						TreeNode* ans = new TreeNode(key,val);
						ans->top = temp;
						temp->left = ans;
						
						/*start_root = temp;*/
						/*stack.clear();
						stack.shrink_to_fit();
						remaster_stack(start_root);*/
						return ans;
					}
				}

				if (temp->key < key) {
					if (temp->right != nullptr)
						temp = temp->right;
					else {
						TreeNode* ans = new TreeNode(key,val);
						ans->top = temp;
						temp->right = ans;
						/*temp = back_to_root(temp, start_root);*/
						/*start_root = temp;*/
						/*stack.clear();
						stack.shrink_to_fit();
						remaster_stack(start_root);*/
						return ans;
					}
				}
			}
		}
		else {
			start_root->value = val;
			start_root->key = key;
			flag_not_null = true;
			/*stack.clear();
			stack.shrink_to_fit();
			remaster_stack(start_root);*/
			return temp;
		}
	}

	it search(KeyData key) {
		TreeNode* temp = start_root;
		if (temp != NULL) {
			while (1) {
				if (temp->key == key)
					return temp;

				if (temp->key > key)
					if (temp->left != NULL)
						temp = temp->left;
					else return NULL;

				if (temp->key < key) 
					if (temp->right != NULL)
						temp = temp->right;
					else return NULL;
			}
		}
	}

	it operator++() {
		if (stack.size() == 0)
			return new TreeNode();

		if (check()) {
			int min = INT_MAX;
			int pos = 0;
			for (int i = 0; i < stack.size(); i++) 
				if (stack[i]->visited == false && stack[i]->key < min) {
					min = stack[i]->key;
					pos = i;
				}

			stack[pos]->visited = true;
			iter_pos = stack[pos];
			return iter_pos;
		}
		else {
			for (auto i : stack)
				i->visited = false;
			auto t = this->operator++();
			return t;
		}
	}

	void print() {
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

	int size_of_tree() {
		return stack.size();
	}
};


template<class KeyData,class Data>
class AVL_Tree : public Binary_Tree<KeyData,Data> {
	
	it minValueNode(it node) {
		it current = node;
		while (current && current->left != nullptr) {
			current = current->left;
		}
		return current;
	}
	it maxValueNode(it node) {
		NodeAVL<KeyType, ValueType>* current = node;
		while (current && current->right != nullptr) {
			current = current->right;
		}
		return current;
	}
	void print_inner(TreeNode* root, COORD position) {
		if (root != NULL) {
			SetConsoleCursorPosition(hConsole, position);
			cout << root->key;
			auto pos = position;
			if (root->left != NULL) {
				int temp =  (root->Height*2);
				pos.X = pos.X - temp;
				pos.Y = pos.Y + 1;
				print_inner(root->left, pos);
			}
			pos = position;

			if (root->right != NULL) {
				int temp = (root ->Height*2);
				pos.X = pos.X +temp;
				pos.Y = pos.Y + 1;
				print_inner(root->right, pos);
			}
		}
	}
	it balance(it node) {
		int balance = getBalance(node);
		if (balance > 1) {
			if (node->right == nullptr) {
				node = rightRotate(node);
			}
			else {
				if (getBalance(node->left) < 0) {
					node = leftRotate(node);
				}
				return bigRightRotate(node);
			}
		}
		else if (balance < -1) {
			if (node->left == nullptr) {
				node = leftRotate(node);
			}
			else {
				if (getBalance(node->right) > 0) {
					node = rightRotate(node);
				}
				return bigLeftRotate(node);
			}
		}
		return node;
	}

	int getHeight(it node) {
		if (node == nullptr) {
			return 0;
		}
		return node->Height;
	}

	it insertNode(it node, KeyData key, Data value) {
		if (node == nullptr) {
			return new TreeNode(key, value);
		}

		if (key < node->key) {
			node->left = insertNode(node->left, key, value);
		}
		else if (key > node->key) {
			node->right = insertNode(node->right, key, value);
		}
		else {
			return node;
		}

		node->Height = 1 + max(getHeight(node->left), getHeight(node->right));

		int balance = getBalance(node);

		if (balance > 1 && key < node->left->key) {
			return rightRotate(node);
		}

		if (balance < -1 && key > node->right->key) {
			return leftRotate(node);
		}

		if (balance > 1 && key > node->left->key) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		if (balance < -1 && key < node->right->key) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}
	it removeNode(it root, KeyData key) {
		if (root == NULL) {
			
			return root;
		}
		if (root == start_root && root->left == NULL && root->right == NULL)
		{
			start_root = NULL;
			return start_root;
		}

		if (key < root->key) {
			root->left = removeNode(root->left, key);
		}
		else if (key > root->key) {
			root->right = removeNode(root->right, key);
		}
		else {
			if ((root->left == NULL) || (root->right == NULL)) {
				it temp = root->left ? root->left : root->right;

				if (temp == NULL) {
					temp = root;
					root = NULL;
				}
				else {
					*root = *temp;
				}

				delete temp;
			}
			else {
				it temp = minValueNode(root->right);
				root->key = temp->key;
				root->right = removeNode(root->right, temp->key);
			}
		}

		if (root == NULL) {
			return root;
		}

		root->Height = 1 + max(getHeight(root->left), getHeight(root->right));

		int balance = getBalance(root);

		if (balance > 1 && getBalance(root->left) >= 0) {
			return rightRotate(root);
		}

		if (balance > 1 && getBalance(root->left) < 0) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}

		if (balance < -1 && getBalance(root->right) <= 0) {
			return leftRotate(root);
		}

		if (balance < -1 && getBalance(root->right) > 0) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}

		return root;
	}

	it rightRotate(it y) {
		it x = y->left;
		if (x->right != nullptr) {
			x->right->top = y;
		}
		it T2 = x->right;
		y->left = T2;
		x->right = y;
		y->top = x;
		x->top = y->top;
		y->Height = 1 + max(getHeight(y->left), getHeight(y->right));
		x->Height = 1 + max(getHeight(x->left), getHeight(x->right));

		return x;
	}

	int getBalance(it node) {
		if (node == nullptr) {
			return 0;
		}
		return getHeight(node->left) - getHeight(node->right);
	}

	it leftRotate(it x) {
		it y = x->right;
		it T2 = y->left;
		x->right = T2;
		if (y->left != nullptr) {
			y->left->top = x;
		}
		y->left = x;
		x->top = y;
		y->top = x->top;
		x->Height = 1 + max(getHeight(x->left), getHeight(x->right));
		y->Height = 1 + max(getHeight(y->left), getHeight(y->right));

		return y;
	}

	it bigRightRotate(it node) {
		it x = node;
		node = rightRotate(x);
		return leftRotate(node);
	}

	it bigLeftRotate(it node) {
		it y = node;
		node = leftRotate(y);
		return rightRotate(node);
	}

	
public:
	AVL_Tree() {
		start_root = NULL;
	}

	AVL_Tree(KeyData key,Data val) {
		start_root = new TreeNode(key, val);
		flag_not_null = true;
	}
	
	void insert(KeyData key, Data val) {
		insertNode(start_root, key, val);

	}
	

	void remove(KeyData key) {
		removeNode(start_root, key);
	}
	
	void print() {
		system("cls");
		position.X = 50;
		position.Y = 0;
		print_inner(start_root, position);
	}
};

template<class KeyData, class Data>
class RB_Tree : protected Binary_Tree<KeyData, Data> {
private:
	
	int blacks;

	it SmallRotateRight(TreeNode* p) { // правый поворот вокруг p
		auto save =p;
		bool flag_start_root = save == start_root ? true: false;
		
		auto q = p->left;

		if (flag_start_root == false)
		{
			if (save->top->left == save)
			{
				p->left = q->right;
				if (p->left != NULL)
					p->left->top = p;
				q->right = p;
				q->top = p->top;
				p->top->left = q;
				p->top = q;
			}
			else
			{
				p->left = q->right;
				if (p->left != NULL)
					p->left->top = p;
				q->right = p;
				q->top = p->top;
				p->top->right = q;
				p->top = q;
			}
		}
		else
		{
			p->left = q->right;
			if (p->left != NULL)
				p->left->top = p;
			q->right = p;
			q->top = p->top;
			p->top = q;
			start_root = q;
		}
			
		return q;
	}
	
	it SmallRotateLeft(TreeNode* q) { // левый поворот вокруг q
		auto save =q;
		bool flag_start_root = save == start_root ? true : false;
		auto p = q->right;
		
		
		if (!flag_start_root)
		{
			if (save->top->left == save)
			{
				q->right = p->left;
				if (q->right != NULL)
					q->right->top = q;
				p->left = q;
				p->top = q->top;
				q->top->left = p;
				q->top = p;

				
			}
			else
			{
				q->right = p->left;
				if (q->right != NULL)
					q->right->top = q;
				p->left = q;
				p->top = q->top;
				q->top->right = p;
				q->top = p;
			}
				
		}
		else
		{
			q->right = p->left;
			if (q->right != NULL)
				q->right->top = q;
			p->left = q;
			p->top = q->top;
			q->top = p;
			start_root = p;
		}
			
		
		
		
		return p;
	}
	

	it grandparent(TreeNode* node)
	{
		if ((node != NULL) && (node->top != NULL))
			return node->top->top;
		else
			return NULL;
	}

	it Uncle(TreeNode* node) {
	    it g = grandparent(node);
		if (g == NULL)
			return NULL;
		if (node->top == g->left)
			return g->right;
		else
			return g->left;
	}

	void print_inner(TreeNode* root, COORD position)
	{
		if (root != NULL)
		{
			SetConsoleCursorPosition(hConsole, position);
			if (root->color == red)
				SetConsoleTextAttribute(hConsole, 12);
			else
				SetConsoleTextAttribute(hConsole, 15);
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

	

	bool check_out_ins(it node)
	{
		if (node == start_root)
		{
			node->color = colors::black;
			return true;
		}
		while (node->top != NULL)
		{
			if (node->top->color == red)
			{
				auto un = Uncle(node);
					
				if (node->top == node->top->top->left)
				{
						
					if (un != NULL)
					{
						if (un->color == colors::red)
						{
							node->top->color = black;
							un->color = black;
							node->top->top->color = red;
							node = node->top->top;

						}
						else
						{
							if (node == node->top->right)
							{
								node = node->top;
								SmallRotateLeft(node);
							}
							node->top->color = black;
							node->top->top->color = red;
							SmallRotateRight(node->top->top);
						}
					}
					else
					{
						if (node == node->top->right)
						{
							node = node->top;
							SmallRotateLeft(node);
						}
						node->top->color = black;
						node->top->top->color = red;
						SmallRotateRight(node->top->top);
					}

				}
				else
				{
					
					if (un != NULL)
					{
						if (un->color == red)
						{
							node->top->color = black;
							un->color = black;
							node->top->top->color = red;
							node = node->top->top;
						}
						else
						{
							if (node == node->top->left)
							{
								node = node->top;
								SmallRotateRight(node);

							}
							node->top->color = black;
							node->top->top->color = red;
							SmallRotateLeft(node->top->top);

						}
					}
					else
					{
						if (node == node->top->left)
						{
							node = node->top;
							SmallRotateRight(node);
						}
						node->top->color = black;
						node->top->top->color = red;
						SmallRotateLeft(node->top->top);
					}



				}
				
			}
			else
				break;
		}
		start_root->color = black;
		return true;
	}
public:


	RB_Tree()
	{

		start_root = new TreeNode();
	}
	RB_Tree(KeyData key, Data val)
	{
		start_root = new TreeNode(key, val);
		flag_not_null = true;
	}
	
	void skolko_negrov(int& blacks, int& mx_blacks, bool& rez) {
		height_black(start_root, blacks, mx_blacks, rez);
	}

	void height_black(TreeNode* node, int& blacks, int& mx_blacks, bool& rez) {
		if (node->color == 1) {
			blacks++;
		}
		int loc_black = blacks;
		if (node->left != NULL)
			if (node->right != NULL) {
				loc_black = blacks;
				height_black(node->right, loc_black, mx_blacks, rez);
				loc_black = blacks;
				height_black(node->left, loc_black, mx_blacks, rez);
			}
			else {
				loc_black = blacks;
				height_black(node->left, loc_black, mx_blacks, rez);
			}
		else
			if (node->right != NULL) {
				loc_black = blacks;
				height_black(node->right, loc_black, mx_blacks, rez);
			}
			else
				if (mx_blacks == -1)
					mx_blacks = blacks;
				else
					if (mx_blacks != blacks)
						rez = false;
					else rez = true;
	}
	
	void print() {
		system("cls");
		position.X = 50;
		position.Y = 0;
		print_inner(start_root, position);
		position.X = 0;
		position.Y = 30;
		SetConsoleCursorPosition(hConsole, position);
	}

	it insert(KeyData key, Data val)
	{
		auto tmp = Binary_Tree::insert(key, val);
		tmp->color = red;
		if (check_out_ins(tmp))
			return tmp;
		return NULL;
	}

	void check_out_delete(TreeNode* p)
	{

		while (p->color == black && p->top != NULL)
		{
			auto  papa = p->top;
			if (papa->left == p)
			{
				if (papa->right != NULL)
				{
					auto brat = papa->right;
					if (brat->color == red)
					{
						brat->color = black;
						papa->color = red;
						SmallRotateLeft(papa);

						brat = p->top->right;
					}
					bool flag_cr_left=false;
					bool flag_cr_right=false;
					if (brat->left == NULL)
					{
						brat->left = new TreeNode();
						brat->left->top = brat;
						brat->left->color = black;
						flag_cr_left = true;
					}
					if (brat->right == NULL)
					{
						brat->right = new TreeNode();
						brat->right->top = brat;
						brat->right->color = black;
						flag_cr_right = true;
					}
					if (brat->left->color == black && brat->right->color == black)
					{
						brat->color = red;
						p = papa;
						if (flag_cr_left)
						{
							brat->left->top = NULL; brat->left = NULL;
						}
						if (flag_cr_right)
						{
							brat->right->top = NULL; brat->right = NULL;
						}
					}
					else
					{
						if (brat->right->color == black)
						{
							brat->color = red;
							brat->left->color = black;
							SmallRotateRight(brat);
							if (flag_cr_right)
							{

								brat->right->top = NULL; brat->right = NULL;
							}
							brat = p->top->right;
						}
						brat->color = papa->color;
						papa->color = black;
						brat->right->color = black;

						if (flag_cr_left)
						{
							brat->left->top = NULL; brat->left = NULL;
						}
						
						SmallRotateLeft(papa);

						
						p = start_root;
					}


					
				}
			}
			else if (papa->right = p)
			{
				if (papa->left != NULL)
				{
					auto brat = papa->left;
					if (brat->color == red)
					{
						brat->color = black;
						papa->color = red;
						SmallRotateRight(papa);
						brat = p->top->left;
					}

					bool flag_cr_left = false;
					bool flag_cr_right = false;
					if (brat->left == NULL)
					{
						brat->left = new TreeNode();
						brat->left->top = brat;
						brat->left->color = black;
						flag_cr_left = true;
					}
					if (brat->right == NULL)
					{
						brat->right = new TreeNode();
						brat->right->top = brat;
						brat->right->color = black;
						flag_cr_right = true;
					} /// continue made brats gotta check out
					
					if (brat->right->color == black && brat->left->color == black)
					{
						brat->color = red;
						p = papa;
						if (flag_cr_left)
						{
							brat->left->top = NULL; brat->left = NULL;
						}
						if (flag_cr_right)
						{
							brat->right->top = NULL; brat->right = NULL;
						}
					}
					else
					{
						if (brat->left->color == black)
						{
							brat->right->color = black;
							brat->color = red;
							SmallRotateLeft(brat);
							if (flag_cr_left)
							{
								brat->left->top = NULL; brat->left = NULL;
							}
							brat = p->top->left;
						}
						brat->color = papa->color;
						papa->color = black;
						brat->left->color = black;

						if (flag_cr_right)
						{
							brat->right->top = NULL; brat->right = NULL;
						}
						SmallRotateRight(papa);

						p = start_root;
					}
				}
			}
		}
		p->color = black;

	};

	void link_nodes(TreeNode* u, TreeNode* v) {
		if (u->top == NULL) {
			start_root = v;
		}
		else if (u == u->top->left) {
			u->top->left = v;
		}
		else {
			u->top->right = v;
		}
		v->top = u->top;
	}
	bool remove_inner(KeyData key, Data val)
	{
		TreeNode* z = Binary_Tree::search(key);

		/*if (!(z == NULL)) {
			for (int i = 0; i < stack.size(); i++) {
				if (stack[i] == z) {
					stack.erase(stack.begin() + i);
					break;
				}
			}
		}*/
		if (!(z == NULL)) //enter the alg
		{

			TreeNode* x;
			auto y = z;
			int y_original_color = y->color;
			
			if (z->left == NULL) { //leaf && left net right da
				if (z == start_root && z->left ==NULL && z->right ==NULL)
				{
					start_root = new TreeNode();
					flag_not_null=false;
					return true;
				}
				else
				{
					TreeNode* temp1 = NULL;
					if (z->right == NULL)
					{
						z->right = new TreeNode();
						z->right->top = z;
						temp1 = z->right;
					}
					x = z->right;
					link_nodes(z, z->right);
					delete z;

					if (y_original_color == black) {
						check_out_delete(x);
					}
					if (temp1 != NULL)
					{
						if (temp1->top->left == temp1)
							temp1->top->left = NULL;
						else
							temp1->top->right = NULL;
						temp1 = NULL;
					}
				}
				
			}
			else if (z->right == NULL) // left da right net
			{
				TreeNode* temp3 = NULL;
				if (z->left == NULL)
				{
					z->left = new TreeNode();
					z->left->top = z;
					temp3 = z->left;
				}
				x = z->left;
				link_nodes(z, z->left);

				delete z;
				if (y_original_color == black) {
					check_out_delete(x);
				}
				if (temp3 != NULL)
				{
					if (temp3->top->left == temp3)
						temp3->top->left = NULL;
					else
						temp3->top->right = NULL;
					temp3 = NULL;
				}
				
			}
			else {
				auto min_r_branch = y->right;
				bool flag = false;

				while (!flag) {
					if (min_r_branch->left == NULL)
						flag++;
					else
						min_r_branch = min_r_branch->left;
				}
				y = min_r_branch;
				y_original_color = y->color;

				TreeNode* temp2=NULL;
				if (y->right == NULL)
				{
					y->right = new TreeNode(); 
					y->right->top = y; 
					temp2 = y->right;
				}
				x = y->right;
				if (y->top == z) {
					x->top = y;
				}
				else {
					link_nodes(y, y->right);
					y->right = z->right;
					y->right->top = y;
				}

				link_nodes(z, y);
				
				y->left = z->left;
				y->left->top = y;
				y->color = z->color;
				
				delete z;
				if (y_original_color == black) {
					check_out_delete(x);
				}
				if (temp2 != NULL)
				{
					if (temp2->top->left == temp2)
						temp2->top->left = NULL;
					else
						temp2->top->right = NULL;
					temp2 = NULL;
				}
			}
			return true;
		}
		return false;
	}

	bool remove(KeyData key, Data val)
	{
		return (remove_inner(key, val));
	}

	it search(KeyData key)
	{
		return Binary_Tree::search(key);
	}
	
};