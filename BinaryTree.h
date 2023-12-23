#pragma once
#include "Cell.h"
#include <list>

class BinaryTree {
	struct Node {
		int Data;
		Node* Left;
		Node* Right;

		Node()
		{
			Data = 0;
			Left = nullptr;
			Right = nullptr;
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
	BinaryTree();
	virtual ~BinaryTree();

	bool Insert(int Data);

	bool Delete(int Data);

	bool Find(int Data);

	void Print();

private:
	bool Delete(Node* node, Node* Parent, int Data);
	bool Find(Node* node, int Data);

	void DeleteDestructor(Node* node);

	int GetMaxDepth() const;

	RowList GetRowList(int maxDepth) const;
	vector<string> FormatRow(const RowList& rowList) const;
	void TrimRow(vector<string>& rows);

	Node* _Root;

#ifdef _DEBUG
public:
	void ReliableTest(const list<int>& ReliableList);
	bool Test(Node* node);
	list<int> _ReliableList;
	list<int>::iterator _Iter;
	int _Index;
#endif
};