//Simple Binary Search Tree CPP Implementation

#pragma once
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include<iostream>
#include<initializer_list>
#include<queue>
#include<memory>

// Struct BST node 
struct TreeNode
{
	TreeNode() : left(nullptr), right(nullptr), val(0) {}
	TreeNode(int  x) : left(nullptr), right(nullptr), val(x) {}
	TreeNode(TreeNode* left, TreeNode* right, int x) :left(left), right(right), val(x) {}

	~TreeNode() = default;

	std::shared_ptr<TreeNode> left = std::make_shared<TreeNode>();
	std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>();
	int val;

	// Overloading << to ouput value of this TreeNode
	friend std::ostream& operator << (std::ostream& out, TreeNode& node)
	{
		out << node.val;
		return out;
	}
};

// Enum Class to specify traversal rules
enum class TraverseFlag
{
	PRE_ORDER = 0,
	IN_ORDER = 1,
	POST_ORDER = 2,
	LEVEL_ORDER = 3,
};

// CLASS BST
class BinarySearchTree final
{
public:
	using BST = BinarySearchTree;

	BinarySearchTree() : root(nullptr) {}
	BinarySearchTree(std::initializer_list<int> list)
	{
		for (int val : list)
			insert(val);
	}

	BinarySearchTree(const BinarySearchTree& tree)
	{
		root = tree.root;
	}

	~BinarySearchTree() = default;

	void insert(int val)
	{
		if (!root)
		{
			root->val = val;
			return;
		}

		std::shared_ptr<TreeNode> current = root;		
		std::shared_ptr<TreeNode> newNode = std::make_shared<TreeNode>(val);

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
				{
					current = current->left;
				}
			}
			if (newNode->val > current->val)
			{
				if (current->right == nullptr)
				{
					current->right = newNode;
					break;
				}
				else
				{
					current = current->right;
				}
			}
		}
	}

	void erase(int val)
	{
		// TODO
	}

	int minValue()
	{
		if (!root)
			return -1;

		std::shared_ptr<TreeNode> cur = root;
		while (cur && cur->left)
			cur = cur->left;

		return cur->val;
	}

	int maxValue()
	{
		if (!root)
			return -1;

		std::shared_ptr<TreeNode> cur = root;
		while (cur && cur->right)
			cur = cur->right;

		return cur->val;
	}

	// Overloading operagtor << to output the whole BST
	friend std::ostream& operator << (std::ostream& out, BinarySearchTree& tree)
	{
		if (tree.root == nullptr)
			return out;

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
	void preOrder(std::shared_ptr<TreeNode> root) const
	{
		if (root)
		{
			std::cout << *root << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void inOrder(std::shared_ptr<TreeNode> root) const
	{
		if (root)
		{
			inOrder(root->left);
			std::cout << *root << " ";
			inOrder(root->right);
		}
	}

	void postOrder(std::shared_ptr<TreeNode> root) const
	{
		if (root)
		{
			postOrder(root->left);
			postOrder(root->right);
			std::cout << *root << " ";
		}
	}

	void levelOrder(std::shared_ptr<TreeNode> root) const
	{
		if (!root)
			return;

		std::queue<std::shared_ptr<TreeNode>>q;
		q.push(root);
		while (!q.empty())
		{
			int length = q.size();
			for (int i = 0; i < length; ++i)
			{
				auto node = q.front();
				q.pop();
				std::cout << *node << " ";

				if (node->left)
					q.push(node->left);

				if (node->right)
					q.push(node->right);
			}
		}
	}
private:
	std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>();
};

#endif BINARY_SEARCH_TREE_
