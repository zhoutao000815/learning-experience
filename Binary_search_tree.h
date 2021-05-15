#pragma once
#include<iostream>
#include<string>

template<class K,class V>
struct bs_tree_node
{
	bs_tree_node(const K& key, V& value)
	{
		_key = key;
		_val = value;
		_left = nullptr;
		_right = nullptr;
	}

	K _key;
	V _val;
	bs_tree_node<K,V>* _left;
	bs_tree_node<K,V>* _right;
}; 

template<class K, class V>
class bs_tree 
{
	typedef bs_tree_node<K,V> node;

public:
	bs_tree(){}

	~bs_tree()
	{
		bstree_destory(_root);
	}

	void bstree_destory(node* pnode)
	{
		if (pnode == nullptr)
		{
			return;
		}
		bstree_destory(pnode->_left);
		bstree_destory(pnode->_right);
		delete(pnode);
	}


	bool insert(const K& in, V inv)
	{
		if (_root == nullptr)
		{
			_root = new node(in,inv);
			return true;
		}
		node* parents = nullptr;
		node* cur = _root;
		while (cur)
		{
			if (in == cur->_key)
			{
				return false;
			}
			else
			{
				parents = cur;
				if (in < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					cur = cur->_right;
				}
			}
		}
		node* newnode = new node(in,inv);
		if (in < parents->_key)
		{
			parents->_left = newnode;
		}
		else
		{
			parents->_right = newnode;
		}
		return true;
	}

	bool erase(const K& target)
	{
		//1.Ҷ�ӽڵ�
		//2.��Ϊ�ա�����Ϊ�ա�
		//3.���Ҷ���Ϊ��
		node* parents = nullptr;
		node*cur = _root;
		while (cur)
		{
			if (cur->_key < target)
			{
				parents = cur;
				cur = cur->_right;
			}
			else if (cur->_key>target)
			{
				parents = cur;
				cur = cur->_left;
			}
			else
			{
				//Ҷ�ӽڵ���Կ�������һ��Ϊ�գ�
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (cur == parents->_left)
						{
							parents->_left = cur->_right;
						}
						else
						{
							parents->_right = cur->_right;
						}
					}
					delete cur;
					return true;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parents->_left)
						{
							parents->_left = cur->_left;
						}
						else
						{
							parents->_right = cur->_left;
						}
					}
					delete cur;
					return true;
				}
				else  //���Ҷ��к���
				{
					//�����ɾ��:ֱ��ɾ���ƻ��������Ľṹ
					//�������������ڵ㣬���ߣ�����������С�ڵ㣬ȥ���ɾ����
					//��Σ�ɾ���ڵ����������������ĸ���Ҫ�ж�

					//�������������ڵ����
					node* smparents = cur;
					node* left_sub_max = cur->_left;
					while (left_sub_max->_right)
					{
						smparents = left_sub_max;
						left_sub_max = left_sub_max->_right;
					}
					if (left_sub_max == smparents->_left)
					{
						smparents->_left = left_sub_max->_left;
					}
					else
					{
						smparents->_right = left_sub_max->_left;
					}
					cur->_key = left_sub_max->k;
					delete left_sub_max;
					return true;
				}
			}
		}
		return false;
	}

	node* find(const K& target)
	{
		node* cur = _root;
		while (cur)
		{
			if (cur->_key == target)
			{
				return cur;
			}
			else
			{
				if (target < cur->_key)
				{
					cur = cur->_left;
				}
				else
				{
					cur = cur->_right;
				}
			}
		}
		return nullptr;
	}

	 static void inorder_printf(node* pnode)
	{
		if (pnode == nullptr)
		{
			return;
		}
		inorder_printf(pnode->_left);
		std::cout << pnode->_key << " " << pnode->_val << std:: endl;
		inorder_printf(pnode->_right);
	}
	
	void inorder()
	{
		inorder_printf(_root);
		std::cout << endl;
	}


private:
	node * _root = nullptr;
};

