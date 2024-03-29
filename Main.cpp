#include "RedBlackTree.h"
#include "Test.h"
#include <iostream>
using namespace std;

Test test;

void TestCase001()
{
	RedBlackTree redblackTree;
	for(int i=0 ; i< 10; i++)
		redblackTree.Insert(i);


	for (int i = 0; i < 5; i++)
		redblackTree.Delete(i);

	redblackTree.Insert(10);
	redblackTree.Insert(3);
	redblackTree.Insert(11);
	redblackTree.Insert(0);
	redblackTree.Insert(15);
	redblackTree.Insert(4);
	redblackTree.Insert(17);

	for (int i = 6; i < 11; i++)
	{
		redblackTree.Delete(i);
		redblackTree.Print();
	}
}

void TestCase002()
{
	test.MakeTestCase();
	test.TestTree001();
}

void TestAutoTree()
{
	test.CalculateTime();
}

// 의사 난수 만들어 테스트
void TestRandomNumberTree()
{
	test.MakeTestCase();
	test.TestRedBlackTree();
	test.TestBinaryTree();
}

void TestManualTree()
{
	RedBlackTree tree;
	int Data;
	int Menu;

	cout << "[메뉴] 1. 삽입 2. 찾기 3. 삭제 4. 종료\n";

	while (1)
	{
		cout << ">> ";
		cin >> Menu;

		switch (Menu)
		{
		case 1:
			cout << ">> ";
			cin >> Data;
			if (true == tree.Insert(Data))
			{
				tree.Print();
			}
			else
			{
				cout << "이미 데이터가 존재합니다.\n";
			}
			break;
		case 2:
			cout << ">> ";
			cin >> Data;
			if (true == tree.Find(Data))
			{
				cout << "데이터가 존재합니다.\n";
			}
			else
			{
				cout << "데이터가 존재하지 않습니다.\n";
			}
			break;
		case 3:
			cout << ">> ";
			cin >> Data;
			if (true == tree.Delete(Data))
			{
				tree.Print();
			}
			else
			{
				cout << "트리 내 존재하지 않는 데이터 입니다.\n";
			}
			break;
		case 4:
			return;
		default:
			cout << "잘못된 메뉴입니다. \n";
			break;
		}
	}
}

int main()
{
	// Test 때 확인할 것.
	TestManualTree();

	// 삽입, 삭제 신뢰성 테스트
	//TestRandomNumberTree();

	// 삽입, 삭제 시간 테스트
	//TestAutoTree();

	// 테스트 케이스
	//TestCase001();
	//TestCase002();
}