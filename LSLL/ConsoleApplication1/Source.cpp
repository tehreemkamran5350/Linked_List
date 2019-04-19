#include<iostream>
#include "LSLL.h"
using namespace std;
int main()
{
	/*LSLL <int>l;
	l.insertAtTail(1);
	l.insertAtTail(2);
	l.insertAtTail(3);
	l.insertAtTail(4);
	l.insertAtTail(5);
	l.insertAtTail(6);
	l.insertAtTail(7);*/
	LSLL<char> l;
	l.insertAtTail('w');
	l.insertAtTail('b');
	l.insertAtTail('w');
	l.insertAtTail('b');
	l.insertAtTail('b'); 
	l.insertAtTail('w');
	l.insertAtTail('b');
	l.insertAtTail('b');
	l.insertAtTail('b');
	l.insertAtTail('w');
	l.insertAtTail('b');
	l.insertAtTail('w');
	l.display();
	
	cout << l.findMajorityColor() << endl;
	return 1;
}