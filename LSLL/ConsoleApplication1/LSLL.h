#ifndef LSLL_H
#define LSLL_H
#include "node.h"
template<typename T>
class LSLL
{
	node<T> * head;
	bool isPresent(T key)
	{
		node<T>* p = head;
		while (p != 0)
		{
			if (p->info == key)
				return true;
			p = p->next;
		}
		return false;
	}
public:
	LSLL();
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeBefore(T key);
	void removeAfter(T key);
	void remove(T key);
	void removeAtHead();
	void removeAtTail();
	LSLL<T> doUnion(LSLL<T>& list2);
	int isEqual(LSLL<T>& list2);
	LSLL<T> createClone();
	LSLL(const LSLL<T> & ref);
	~LSLL();
	void removeDuplicates();
	void delAlternate();
	void display();
	LSLL<T> & operator = (LSLL<T> & ref);
	void splitList(LSLL<T> & list1, LSLL<T> & list2);
	void foldList();
	void reverseList();
	T findMiddlePoint();
	T findMajorityColor();
};
template<typename T>
LSLL<T>::LSLL()
{
	head = 0;
}
template<typename T>
void  LSLL<T>::display()
{
	node<T>* q = head;
	while (q != 0)
	{
		cout << q->info << "	";
		q = q->next;
	}
	cout << endl;
}
template<typename T>
void  LSLL<T>::insertAtHead(T val)
{
	node<T> * q = new node <T>(val);
	q->next = head;
	head = q;
}
template<typename T>
void  LSLL<T>::insertAtTail(T val)
{
	if (head == 0)
	{
		head = new node<T>(val);
		return;
	}
	node<T> * q = head;
	while (q->next != 0)
		q = q->next;
	q->next = new node<T>(val);
}
template<typename T>
void  LSLL<T>::insertAfter(T key, T val)
{
	node<T>* q = head;
	node<T>* aft = head->next;
	while (q->next != 0 && q->info != key)
	{
		q = aft;
		aft = aft->next;
	}
	if (q->next == 0 && q->info != key)
		return;
	q->next = new node<T>(val);
	q->next->next = aft;
}
template<typename T>
void  LSLL<T>::insertBefore(T key, T val)
{
	if (head->info == key)
	{
		node<T>* p = new node<T>(val);
		p->next = head;
		head = p;
		return;
	}
	node<T>* prev = head;
	node<T>* q = head->next;
	while (q->next != 0 && q->info != key)
	{
		prev = q;
		q = q->next;
	}
	if (q->next == 0 && q->info==key)
	{
		prev->next = new node<T>(val);
		prev->next->next = q;
		q->next = 0;
		return;
	}
	prev->next = new node<T>(val);
	prev->next->next = q;
}
template<typename T>
void  LSLL<T>::removeBefore(T key)
{
	if (head->info == key)
		return;
	if (head->next->info == key)
	{
		node<T>*p = head->next;
		delete head;
		head = p;
		return;
	}
	node<T>* prev = head;
	node<T>* p = head->next->next;
	while (p != 0 && p->info != key)
	{
		prev = prev->next;
		p = p->next;
	}
	if (!p)
		return;
	delete prev->next;
	prev->next = p;
}
template<typename T>
void  LSLL<T>::removeAfter(T key)
{
	node<T>* a = head;
	node<T>* aft = head->next;
	while (a->next != 0 && a->info != key)
	{
		aft = aft->next;
		a = a->next;
	}
	if (a->next == 0 && a->info != key)
		return;
	if (a->next == 0 && a->info == key)
		return;
	if (!a)
		return;
	a->next = aft->next;
	delete aft;

}
template<typename T>
void  LSLL<T>::remove(T key)
{
	if (head->info == key)
	{
		node<T>* p = head->next;
		delete head;
		head = p;
		return;
	}
	node<T>* prev = head;
	node<T> * q = head->next;
	while (q != 0 && q->info != key)
	{
		prev = q;
		q = q->next;
	}
	if (!q)
		return;
	prev->next = q->next;
	delete q;
}
template<typename T>
void  LSLL<T>::removeAtHead()
{
	node<T> * q = head->next;
	delete head;
	head = q;
}
template<typename T>
void LSLL<T>::removeAtTail()
{
	if (head == 0)
		return;
	node<T> * p = head;
	node<T>*q = head->next;
	while (q->next != 0)
	{
		p = q;
		q = q->next;
	}
	p->next = 0;
	delete q;
}
template<typename T>
LSLL<T> LSLL<T>::doUnion(LSLL<T> & list2)
{
	node<T>* p = list2.head;
	LSLL<T> un = *this;
	while (p != 0)
	{
		if (!un.isPresent(p->info))
			un.insertAtTail(p->info);
		p = p->next;
	}
	return un;
}
template<typename T>
int LSLL<T>::isEqual(LSLL<T>& list2)
{
	node<T>* p = list2.head;
	while (p != 0)
	{
		if (isPresent(p->info))
		{
			p = p->next;
		}
		else
			return 0;
	}
	return 1;
}
template<typename T>
LSLL<T> LSLL<T>::createClone()
{
	LSLL<T> clone(*this);
	return clone;
}
template<typename T>
LSLL<T>::LSLL(const LSLL<T> & ref)
{
	if (ref.head == 0)
	{
		head = 0;
		return;
	}
	node<T>* q = ref.head;
	node<T>*p = new node<T>(q->info);
	q = q->next;
	head = p;
	while (q != 0)
	{
		p->next = new node<T>(q->info);
		p = p->next;
		q = q->next;
	}

}
template<typename T>
LSLL<T>::~LSLL()
{
	node<T> *q = head;
	while (q != 0)
	{
		head = head->next;
		delete q;
		q = head;
	}
}
template<typename T>
void LSLL<T>::removeDuplicates()
{
	node<T>* q = head;
	while (q->next != 0)
	{
		node<T>* p = q->next;
		int key = q->info;
		while (p->next != 0 && p->info != key)
		{
			p = p->next;
		}
		if (p->info == q->info)
		{
			q = q->next;
			remove(key);
		}
		else
			q = q->next;
	}
}
template<typename T>
void LSLL<T>::delAlternate()
{
	if (!head)
		return;
	node<T>* p = head;
	while (p != 0)
	{
		removeAfter(p->info);
		p = p->next;
	}
}
template<typename T>
LSLL<T> & LSLL<T>::operator = (LSLL<T> & ref)
{
	if (this == &ref)
		return *this;
	if (head)
	this->~LSLL();
	if (ref.head == 0)
	{
		head = 0;
		return;
	}
	node<T>* q = ref.head;
	node<T>*p = new node<T>(q->info);
	q = q->next;
	head = p;
	while (q != 0)
	{
		p->next = new node<T>(q->info);
		p = p->next;
		q = q->next;
	}
	return *this;
}
template<typename T>
void LSLL<T>::foldList()
{
	node<int>* q = head;
	node<int>* p = head;
	while (p->next != 0)
		p = p->next;
	while (q->next != 0 && q->next->next != 0)
	{
		insertAfter(q->info, p->info);
		removeAtTail();
		q = q->next->next;
		p = q;
		while (p->next != 0)
			p = p->next;
	}
}
template<typename T>
void LSLL<T>::splitList(LSLL<T> & list1, LSLL<T> & list2)
{
	int count = 1;
	node<T>*p = head;
	while (p->next != 0)
	{
		p = p->next;
		count++;
	}
	int h = count / 2;
	int l = count - h;
	for (int i = 0; i < l; i++)
	{
		list1.insertAtTail(head->info);
		head = head->next;
	}
	for (int j = 0; j < h; j++)
	{
		list2.insertAtTail(head->info);
		head = head->next;
 	}
}
template<typename T>
void LSLL<T>::reverseList()
{
	if (!head)
		return;
	node<T>* p = NULL;
	node<T>*curr= head;
	while (curr != 0)
	{
		node<T>*q = curr->next;
		curr->next = p;
		p = curr;
		curr = q;
	}
	head = p;
}
template<typename T>
T LSLL<T>::findMiddlePoint()
{
	node<T>* p = head;
	node<T>* q = head;
	int count = 0;
	while (p->next != 0 && p != 0)
	{
		p = p->next->next;
		if (p == 0)
			return q->info;
		q = q->next;
	}
	
	return q->info;
}
template<typename T>
T LSLL<T>::findMajorityColor()
{
	node<T>* p = head;
	int white = 0;
	int black = 0;
	while (p != 0)
	{
		if (p->info == 'w')
			white++;
		if (p->info == 'b')
			black++;
		p = p->next;
	}
	if (white > black)
		return 'w';
	else
		return 'b';
}
#endif