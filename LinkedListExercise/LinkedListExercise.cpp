// LinkedListExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListBlock {
	int data;
	ListBlock* next = nullptr;
};

class LinkedList {
public:
	void addItem(int data) 
	{
		ListBlock* listBlock = new ListBlock();

		listBlock->data = data;

		if (_length == 0) {
			_head = listBlock;
			_tail = _head;
		}
		else {
			_tail->next = listBlock;
			_tail = listBlock;
		}

		_length++;
	};
	void addItem(int data, int position) 
	{
		ListBlock* listBlock = new ListBlock();
		ListBlock* listBlockToEdit = _head;

		listBlock->data = data;

		if (position == 0) {
			listBlock->next = _head;
			_head = listBlock;
		}
		else {
			for (int i = 0; i < position - 1; i++) {
				listBlockToEdit = listBlockToEdit->next;
			}

			listBlock->next = listBlockToEdit->next;
			listBlockToEdit->next = listBlock;
		}

		_length++;
	};
	void removeItem(int position) 
	{
		ListBlock* blockToEdit = _head;
		ListBlock* blockToDelete = _head;

		if (position == 0) {
			_head = _head->next;
			delete blockToDelete;
		} 
		else {
			for (int i = 0; i < position - 1; i++) {
				blockToEdit = blockToEdit->next;
			}

			blockToDelete = blockToEdit->next;
			blockToEdit->next = blockToDelete->next;
			delete blockToDelete;
		}

		_length--;
	};
	int getItem(int position) 
	{
		ListBlock* block = _head;

		for (int i = 0; i < position; i++) {
			block = block->next;
		}

		return block->data;
	}
	int getLength() 
	{
		return _length;
	};
	void print()
	{
		ListBlock* block = _head;

		while (block != nullptr) {
			cout << block->data << endl;
			block = block->next;
		}
	};
private:
	ListBlock* _head = nullptr;
	ListBlock* _tail = nullptr;
	int _length = 0;
};

int main()
{
	LinkedList list = LinkedList();

	list.addItem(0);
	list.addItem(1);
	list.addItem(2);
	list.addItem(3);
	list.addItem(4, 0);
	list.addItem(5, 1);
	list.addItem(6, 2);
	list.addItem(4, 6);

	list.print();

	cout << list.getLength() << ' ' << list.getItem(7) << endl;

	list.removeItem(6);
	list.removeItem(0);

	list.print();

    return getchar();
}

