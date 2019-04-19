#include<iostream>
#include "LDLL.h"
using namespace std;
int main()
{
	LDLL <int>l;
	l.insertAtTail(1);
	l.insertAtTail(2);
	l.insertAtTail(3);
	l.insertAtTail(4);
	l.insertAtTail(5);
	l.insertAtTail(6);
	l.display();

	//l.remove(6);
	//l.removeAtHead();
	//l.removeAtTail();
	l.removeAfter(5);
	//l.removeBefore(5);

	//l.insertAtTail(8);
	//l.insertAtHead(0);
	//l.insertAfter(6, 7);
	//l.insertBefore(6, 7);
	l.display();
	return 1;
}