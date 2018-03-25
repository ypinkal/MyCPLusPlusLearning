// LinkedListExercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MyDataStuctures.h"

using namespace std;

int main(int argc, char** argv)
{
	mydatastructures::LinkedList list = mydatastructures::LinkedList();

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

