#include<iostream>
#include "CDLL.h"
using namespace std;
int main()
{
	/*CDLL <int> l;
	l.insertAtTail(1);
	l.insertAtTail(2);
	l.insertAtTail(3);
	l.insertAtTail(4);
	l.insertAtTail(5);
	l.insertAtTail(6);
	l.display();

	l.removeAtTail();
	l.display();*/
	CDLL<int> l;
	l.insertAtTail(1);
	l.insertAtTail(2);
	l.insertAtTail(3);
	l.insertAtTail(3);
	l.insertAtTail(3);
	l.display();

	l.removeAtTail();
	l.display();
	return 1;
}