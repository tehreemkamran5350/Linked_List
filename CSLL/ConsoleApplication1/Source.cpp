#include<iostream>
#include "CSLL.h"
using namespace std;
int main()
{
	LCLL <int> l;
	l.insertAtTail(1);
	l.insertAtTail(2);
	l.insertAtTail(3);
	l.insertAtTail(4);
	l.insertAtTail(5);
	l.insertAtTail(6);
	l.display();

	l.insertAfter(2,7);
	l.display();
	return 1;
}