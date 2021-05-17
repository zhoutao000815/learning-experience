//剑指 Offer 36. 二叉搜索树与双向链表
//输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
//
//
//为了让您更好地理解问题，以下面的二叉搜索树为例：
//
//
//我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
//
//下图展示了上面的二叉搜索树转化成的链表。“head” 表示指向链表中有最小元素的节点。
//
//
//特别地，我们希望可以就地完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中的第一个节点的指针。
//
//
//
//注意：本题与主站 426 题相同：https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
//
//注意：此题对比原题有改动。

/*
// Definition for a Node.
class Node {
public:
int val;
Node* left;
Node* right;

Node() {}

Node(int _val) {
val = _val;
left = NULL;
right = NULL;
}

Node(int _val, Node* _left, Node* _right) {
val = _val;
left = _left;
right = _right;
}
};
*/

//二叉搜索树的中序遍历就是有序的，虽然不知道cur->right指向谁，
//但是用一个prev指针记录上一个节点，cur->left=prev;prev->right=cur;
class Solution {
public:
	void convert(Node* cur, Node* &prev)  //想一想为什么传引用?
	{
		if (cur == NULL)
		{
			return;
		}
		convert(cur->left, prev); //由于只要一个prev指针，并且函数内改变prev指向，函数外还要拿到这个改变，所以prev传引用

		cur->left = prev;
		if (prev != NULL)
		{
			prev->right = cur;
		}
		prev = cur;

		convert(cur->right, prev);
	}

	Node* treeToDoublyList(Node* root) {
		if (root == NULL)
		{
			return NULL;
		}
		Node* prev = NULL;
		convert(root, prev);

		//找到头
		Node* head = root;
		while (head->left)
		{
			head = head->left;
		}
		//找到尾
		Node* tail = prev; //传引用，此时的prev指向的就是尾。
		//头尾相连
		head->left = tail;
		tail->right = head;

		return head;
	}
};