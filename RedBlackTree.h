#pragma once
#include "Cell.h"
#include <set>

enum class NODE_COLOR
{
	BLACK = 0,
	RED
};

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

class RedBlackTree
{
public:
	RedBlackTree();
	virtual ~RedBlackTree();

	bool Insert(int Data);

	bool Delete(int Data);

	bool Find(int Data);

	void Print();

	int GetMaxDepth() const;

private:
	void DeleteDestructor(Node* node);

	// Red-Black Tree 를 위한 것
	void InsertBalance(Node* node);
	void DeleteBalance(Node* node);
	void LineToParent(Node* node);

	void RightDirectionRotate(Node* node);
	void LeftDirectionRotate(Node* node);

	// 출력을 위한 것
	RowList GetRowList(int maxDepth) const;
	vector<string> FormatRow(const RowList& rowList) const;
	void TrimRow(vector<string>& rows);

private:
	Node* _Nil;
	Node* _Root;

#ifdef _DEBUG
public:
	void ReliableTest(const set<int>& ReliableList);
	bool Test(Node* node);
	set<int> _ReliableSet;
	set<int>::iterator _Iter;
	int _Index;
#endif
};