#pragma once
#include "Cell.h"

enum class NODE_COLOR
{
	BLACK = 0,
	RED
};

class RedBlackTree
{
	struct Node {
		Node* Parent;
		Node* Left;
		Node* Right;

		NODE_COLOR Color;

		int Data;

		Node()
		{
			Data = 0;
			Parent = nullptr;
			Left = nullptr;
			Right = nullptr;
			Color = NODE_COLOR::RED;
		}

		int GetMaxDepth() const
		{
			int maxDepth;
			int leftDepth = 0;
			int rightDepth = 0;

			if (Left != nullptr)
				leftDepth = Left->GetMaxDepth();

			if (Right != nullptr)
				rightDepth = Right->GetMaxDepth();

			if (leftDepth > rightDepth)
			{
				maxDepth = leftDepth + 1;
			}
			else
			{
				maxDepth = rightDepth + 1;
			}

			return maxDepth;
		}
	};

public:
	RedBlackTree();
	virtual ~RedBlackTree();

	bool Insert(int Data);

	bool Delete(int Data);

	bool Find(int Data);

	void Print();

private:
	bool Delete(Node* node, Node* Parent, int Data);
	bool Find(Node* node, int Data);

	// Red-Black Tree �� ���� ��
	void BalanceTree(Node* node, bool Left);
	void RightDirectionRotate(Node* node);
	void LeftDirectionRotate(Node* node);

	int GetMaxDepth() const;
	RowList GetRowList(int maxDepth) const;
	vector<string> FormatRow(const RowList& rowList) const;
	void TrimRow(vector<string>& rows);

private:
	Node* _Nil;
	Node* _Root;
};