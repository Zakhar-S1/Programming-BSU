#include <iostream>

using namespace std;

struct node
{
	int key;
	node *left;
	node *right;
	int height;
	node *prev;
	node(int k)
	{
		left = NULL;
		right = NULL;
		key = k;
		prev = NULL;
		height = 1;
	}
};
class avl_tree
{
public:
	node *root_node;
	avl_tree(){
		root_node = NULL;
	}
private:
	int balance_factor(node* n){
		return height(n->left) - height(n->right);
	}

	int height(node* n){
		int h = 0;
		if (n != NULL){
			int height_left = height(n->left);
			int height_right = height(n->right);
			h = (height_left > height_right ? height_left : height_right) + 1;
		}
		return h;
	}

	node* rotateleft(node* q) {
		node* p = q->left;
		q->left = p->right;
		p->right = q;
		return p;
	}

	node* rotateright(node* q) {	
		node* p = q->right;
		q->right = p->left;
		p->left = q;
		return p;
	}

	node* left_right_rotate(node* q)
	{
		node* p = q->left;
		q->left = rotateright(p);
		return rotateleft(q);
	}

	node* right_left_rotate(node* q)
	{
		node* p = q->right;
		q->right = rotateleft(p);
		return rotateright(q);
	}

	node* balance(node* p) {
		if (balance_factor(p) > 1) {
			if (balance_factor(p->left) > 0)
				p = rotateleft(p);
			else
				p = left_right_rotate(p);
		}
		else if (balance_factor(p) < -1){
				if (balance_factor(p->right) > 0)
					p = right_left_rotate(p);
				else
					p = rotateright(p);
			}
		return p;
	}
public:
	void set_prev(node* begin)
	{
		if (begin == NULL)
			return;
		set_prev(begin->left);
		if (begin->left != NULL)
			begin->left->prev = begin;
		set_prev(begin->right);
		if (begin->right != NULL)
			begin->right->prev = begin;
	}

	node* insert(node* p, int k){
		if (p == NULL) return new node(k);
		if (p->key == k) return p;
		if (k < p->key) {
			p->left = insert(p->left, k);
			p->left->prev = p;
		}
		else {
			p->right = insert(p->right, k);
			p->right->prev = p;
		}
		p = balance(p);
		return p;
	}
	
	node* Find(node* begin, int k) {
		if (begin == NULL)
			return begin;
		node* answer = begin;
		if (begin->key > k)
			answer = Find(begin->left, k);
		if (begin->key < k)
			answer = Find(begin->right, k);
		if (begin->key == k)
			return begin;
		return answer;
	}

	void StraightBiet(node* begin) {
		if (begin == NULL)
			return;
		cout << begin->key << endl;
		StraightBiet(begin->left);
		StraightBiet(begin->right);
	}
	void BackBiet(node* begin) {
		if (begin == NULL)
			return;
		BackBiet(begin->left);
		BackBiet(begin->right);
		cout << begin->key << endl;
	}
	void ZentreBiet(node* begin) {
		if (begin == NULL)
			return;
		ZentreBiet(begin->left);
		cout << begin->key << endl;
		ZentreBiet(begin->right);
	}
private:
	node* find_minimum_key_in_p(node* p) {
		if (p->left != NULL)
			return find_minimum_key_in_p(p->left);
		else
			return p;
	}

	node* removemin(node* p){
		if (p->left == 0)
			return p->right;
		p->left = removemin(p->left);
		return balance(p);
	}
public:
	node* remove(node* p, int k) 	{
		if (p == 0) return NULL;
		if (k < p->key)
			p->left = remove(p->left, k);
		else if (k > p->key)
				p->right = remove(p->right, k);
			else
			{
				node* q = p->left;
				node* r = p->right;
				delete p;
				if (!r) return q;
				node* min = find_minimum_key_in_p(r);
				min->right = removemin(r);
				min->left = q;
				return balance(min);
			}
			return balance(p);
	}

	node* move_forward(node* p)
	{
		node* answer = p;
		if (p->right != NULL)
		{
			answer = answer->right;
			while (answer->left != NULL)
			{
				answer = answer->left;
			}
		}
		else
		{
			if (p->prev != NULL)
			{
				answer = p->prev;
				while (answer->key < p->key)
				{
					answer = answer->prev;
					if (answer == NULL)
						return NULL;
				}
			}
			else
				return NULL;
		}
		return answer;
	}

	node* move_back(node* p)
	{
		node* answer = p;
		if (p->left != NULL)
		{
			answer = answer->left;
			while (answer->right != NULL)
			{
				answer = answer->right;
			}
		}
		else
		{
			if (p->prev != NULL)
			{
				answer = p->prev;
				while (answer->key > p->key)
				{
					answer = answer->prev;
					if (answer == NULL)
						return NULL;
				}
			}
			else
				return NULL;
		}
		return answer;
	}
};



int main()
{
	avl_tree *my_tree = new avl_tree();
	node* head = my_tree->root_node;
	while (true)
	{
		int n;
		cout << "Select an action" << endl;
		cout << "1.Add new key" << endl;
		cout << "2.Find key" << endl;
		cout << "3.Delete key" << endl;
		cout << "4.Biets" << endl;
		cout << "5.Iterations" << endl;
		cout << "6.Exit" << endl;
		try
		{
			cin >> n;
			bool chek = false;
			for (int i = 1; i <= 6; i++)
			{
				if (n == i)
				{
					chek = true;
					break;
				}
			}
			if (chek == false)
				throw 999;
		}
		catch (int thr)
		{

			return 0;
		}
		node* finded_cell;
		node* this_node;
		node* test_node;
		bool movable;
		switch (n)
		{
		case 1:
			cout << "Enter the key" << endl;
			int key;
			cin >> key;
			my_tree->root_node = my_tree->insert(my_tree->root_node, key);
			my_tree->set_prev(my_tree->root_node);
			my_tree->root_node->prev = NULL;
			break;
		case 2:
			cout << "Enter the key" << endl;
			int key2;
			cin >> key2;
			finded_cell = my_tree->Find(my_tree->root_node, key2);
			if (finded_cell == NULL)
				cout << "Don`t find";
			else
				cout << "Find!";
//			system("pause");
			break;
		case 3:
			cout << "Enter the key" << endl;
			int key3;
			cin >> key3;
			my_tree->root_node = my_tree->remove(my_tree->root_node, key3);
			break;
		case 4:
			cout << "Select Biet\n1.Straight\n2.Centre\n3.Back\n";
			int key4;
			cin >> key4;
			switch (key4)
			{
			case 1:
				my_tree->StraightBiet(my_tree->root_node);
				break;
			case 2:
				my_tree->ZentreBiet(my_tree->root_node);
				break;
			case 3:
				my_tree->BackBiet(my_tree->root_node);
				break;
			default:
				break;
			}
//			system("pause");
			break;
		case 5:
			if (my_tree->root_node == NULL)
			{
				cout << "Tree is empty" << endl;
				break;
			}
			this_node = my_tree->root_node;
			cout << "You are in node " << this_node->key << endl;
			movable = true;
			while (movable == true)
			{
				int k;
				cout << "If you want to go forward, enter 1. \nIf you want to go back, enter 2. \nTo exit, press 0\n";
				cin >> k;
				switch (k)
				{
				case 0:
					movable = false;
					break;
				case 1:
					test_node = my_tree->move_forward(this_node);
					if (test_node == NULL)
					{
						cout << "You can`t move forward" << endl;
					}
					else
					{
						this_node = test_node;
					}
					cout << "You are in node " << this_node->key << endl;
					break;
				case 2:
					test_node = my_tree->move_back(this_node);
					if (test_node == NULL)
					{
						cout << "You can`t move back" << endl;
					}
					else
					{
						this_node = test_node;
					}
					cout << "You are in node " << this_node->key << endl;
					break;
				default:
					break;
				}
			}
			break;
		case 6:
			return 0;
		default:
			break;
		}
//		system("cls");
	}
	return 0;
}