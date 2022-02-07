//Simple Binary Search Tree CPP Implementation

#pragma once
#include<iostream>
#include<initializer_list>
#include<queue>
using namespace std;

// struct BST node
struct TreeNode
{
	TreeNode() : left(nullptr), right(nullptr), val(0) {}
	TreeNode(int  x) : left(nullptr), right(nullptr), val(x) {}

	TreeNode* left;
	TreeNode* right;
	int val;

	//重载 << 以输出节点值
	friend ostream& operator << (ostream& out, TreeNode& node)	
	{
		cout << node.val;	
		return out;
	}
};

// To specify traversal rules
enum class TraverseFlag
{
	PRE_ORDER = 0,  
	IN_ORDER,		
	POST_ORDER,     
	LEVEL_ORDER,    
};

// Class BST Implementation
class BinaryTree final
{
public:
	BinaryTree() : root(nullptr) {}
	BinaryTree(initializer_list<int> list)
	{
		for (int val : list)
			insert(val);
	}

	void insert(int val)
	{
		if (!root)
		{
			root = new TreeNode(val);
			return;
		}

		TreeNode* current = root;
		TreeNode* newNode = new TreeNode(val);

		while (true)
		{
			if (newNode->val <= current->val)	
			{
				if (current->left == nullptr)
				{
					current->left = newNode;
					break;
				}
				else				
					current = current->left;

			}
			if (newNode->val > current->val)
			{
				if (current->right == nullptr)
				{
					current->right = newNode;
					break;
				}
				else				
					current = current->right;

			}
		}
	}

	void erase(int val)//TODO
	{

	}

	int minValue()	
	{
		if (!root)
			return -1;

		TreeNode* cur = root;
		while (cur && cur->left)
			cur = cur->left;

		return cur->val;		
	}

	int maxValue()
	{
		if (!root)
			return -1;

		TreeNode* cur = root;
		while (cur && cur->right)
			cur = cur->right;

		return cur->val;
	}

	friend ostream& operator << (ostream& out, BinaryTree& tree) 
	{
		tree.inOrder(tree.root);
		return out;
	}

	void print(TraverseFlag flag = TraverseFlag::IN_ORDER) const
	{
		switch (flag)
		{
		case TraverseFlag::PRE_ORDER:
		{
			preOrder(root);
			break;
		}
		case TraverseFlag::IN_ORDER:
		{
			inOrder(root);
			break;
		}
		case TraverseFlag::POST_ORDER:
		{
			postOrder(root);
			break;
		}
		case TraverseFlag::LEVEL_ORDER:
		{
			levelOrder(root);
			break;
		}
		}
	}

private:
	void preOrder(TreeNode* root) const
	{
		if (root)
		{
			cout << *root << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void inOrder(TreeNode* root) const
	{
		if (root)
		{
			inOrder(root->left);
			cout << *root << " ";
			inOrder(root->right);
		}
	}

	void postOrder(TreeNode* root) const
	{
		if (root)
		{
			cout << *root << " ";
			postOrder(root->left);
			postOrder(root->right);
		}
	}

	void levelOrder(TreeNode* root) const
	{
		if (!root)
			return;

		queue<TreeNode*>q;
		q.push(root);

		while (!q.empty())
		{
			for (int i = 0; i < q.size(); ++i)
			{
				TreeNode* node = q.front();
				q.pop();
				cout << *node << " ";

				if (node->left)
					q.push(node->left);

				if (node->right)
					q.push(node->right);
			}
		}
	}

private:
	TreeNode* root;
};