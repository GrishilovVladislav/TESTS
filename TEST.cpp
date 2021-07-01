#include <iostream>
#include <queue>

using namespace std;

class List
{
	struct ListItem
	{
		ListItem* pNext;
		ListItem* pPrev;
		int data;
		ListItem(int data) : data(data), pNext(nullptr), pPrev(nullptr) {}
	};
	ListItem* Head;
	ListItem* Tail;
	int Size=0;
public:
	bool IsEmpty() 
	{
		if (Size == 0) return 1;
		else return 0;
	}
	void PushBack(int val)
	{
		ListItem* NewItem = new ListItem(val);
		if (Tail == nullptr)
		{
			Head = Tail = NewItem;
			return;
		}
		NewItem->pPrev = Tail;
		Tail->pNext = NewItem;
		Tail = NewItem;
		Size++;
	}
	void PushFront(int val)
	{
		ListItem* NewItem = new ListItem(val);
		if (Head == nullptr)
		{
			Head = Tail = NewItem;
			return;
		}
		NewItem->pNext = Head;
		Head->pPrev = NewItem;
		Head = NewItem;
		Size++;
	}
	void Delete()
	{
		Head = nullptr;
		Tail = nullptr;
		Size = 0;
	}
	void Print()
	{
		ListItem* pCurrent = Head;
		for (int i = 0; i < Size + 1; i++)
		{
			cout << pCurrent->data;
			pCurrent = pCurrent->pNext;
		}
	}
};

class Tree
{
	struct Node
	{
		Node* Left = nullptr;
		Node* Right = nullptr;
		Node* Parent = nullptr;
		int data;
		Node(int data) : data(data) {};
	};
	Node* Main = nullptr;

	int Size = 0;
public:

	void Insert(int val)
	{
		Node* NewNode = new Node(val);
		if (Main == nullptr)
		{
			Main = NewNode;
			return;
		}
		Node* Current = Main;
		while (true)
		{
			if (Current->data < val)
			{
				if (Current->Right == nullptr)
				{
					Current->Right = NewNode;
					NewNode->Parent = Current;
					Size++;
					return;			
				}
				else
				{
					Current = Current->Right;
				}
			}
			if (Current->data > val)
			{
				if (Current->Left == nullptr)
				{
					Current->Left = NewNode;
					NewNode->Parent = Current;
					Size++;
					return;
				}
				else
				{
					Current = Current->Left;
				}
			}
		}
	}

	void Show1(Node* Current) {
		if (Current) {
			cout << Current->data << " ";
			Show1(Current->Left);
			Show1(Current->Right);
		}
	}

	void Show2(Node* Current) {
		if (Current) {
			Show2(Current->Left);
			cout << Current->data << " ";
			Show2(Current->Right);
		}
	}
	void Show3(Node* Current) {
		if (Current) {
			Show3(Current->Left);
			Show3(Current->Right);
			cout << Current->data << " ";
		}
	}
	void Print()
	{
		Show1(Main);
		cout << endl;
		Show2(Main);
		cout << endl;
		Show3(Main);
	}
	Node* Search(int data, Node* Current = nullptr)
	{
		if (Current == nullptr) Current = Main;
		if (Current->data == data) 
		{
			return Current;
		}
		if (Current->data < data)
		{
			Current = Current->Right;
			Search(data, Current);
		}
		if (Current->data > data)
		{
			Current = Current->Left;
			Search(data, Current);
		}
	}
	void Delete(int data)
	{
		Node* Current = Search(data);

	}

};





int main()
{
	Tree T1;
	T1.Insert(10);
	T1.Insert(20);
	T1.Insert(5);
	T1.Insert(30);
	T1.Insert(40);
	T1.Insert(35);
	T1.Insert(75);
	T1.Insert(-100);
	T1.Insert(-335);
	T1.Insert(-15);
	T1.Insert(8);
	T1.Print();
	T1.Search(20);
}

