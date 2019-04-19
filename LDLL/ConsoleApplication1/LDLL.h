#ifndef LDLL_H
#define LDLL_H
#include "node.h"
template<typename T>
class LDLL
{
	DNode<T> * head;
public:
	LDLL();
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeBefore(T key);
	void removeAfter(T key);
	void remove(T key);
	void removeAtHead();
	void removeAtTail();
	LDLL(const LDLL<T> & ref);
	~LDLL();
	void display();
	LDLL<T> & operator = (LDLL<T> & ref);
};
template<typename T>
LDLL<T>::LDLL()
{
	head = 0;
}
template<typename T>
void  LDLL<T>::display()
{
	DNode<T>* q = head;
	while (q != 0)
	{
		cout << q->info << "	";
		q = q->next;
	}
	cout << endl;
}
template<typename T>
void  LDLL<T>::insertAtHead(T val)
{
	if (head == 0)
	{
		head = new DNode <T>(val);
		return;
	}
	DNode<T> * p = new DNode <T>(val);
	p->next = head;
	head->prev = p;
	head = p;
}
template<typename T>
void  LDLL<T>::insertAtTail(T val)
{
	if (head == 0)
	{
		head = new DNode<T>(val);
		return;
	}
	DNode<T> * q = head;
	while (q->next != 0)
		q = q->next;
	DNode<T>*p = new DNode<T>(val);
	q->next = p;
	p->prev = q->next;
}
template<typename T>
void  LDLL<T>::insertAfter(T key, T val)
{
	DNode<T>* q = head;
	while (q->next != 0 && q->info != key)
	{
		q = q->next;
	}
	if (q->next == 0 && q->info != key)
		return;
	if (q->next == 0 && q->info == key)
	{
		DNode<T>* aft = new DNode<T>(val);
		q->next = aft;
		aft->prev = q;
		return;
	}
	DNode<T>* aft = new DNode<T>(val);
	q->next->prev = aft;
	aft->next = q->next;
	aft->prev = q;
	q->next = aft;
}
template<typename T>
void  LDLL<T>::insertBefore(T key, T val)
{
	if (head->info == key)
	{
		insertAtHead(val);
		return;
	}
	DNode<T>* p = head;
	DNode<T>* q = head->next;
	while (q->next != 0 && q->info != key)
	{
		p = q;
		q = q->next;
	}
	DNode<int>* temp = new DNode<T>(val);
	q->prev = temp;
	p->next = temp;
	temp->prev = p;
	temp->next = q;
}
template<typename T>
void  LDLL<T>::removeBefore(T key)
{
	if (head->info == key)
		return;
	if (head->next->info == key)
	{
		DNode<T>*p = head->next;
		p->prev = 0;
		delete head;
		head = p;
		return;
	}
	DNode<T>* q = head;
	DNode<T>* p = head->next->next;
	while (p!= 0 && p->info != key)
	{
		q = q->next;
		p = p->next;
	}
	if (!p)
		return;
	p->prev = q;
	delete q->next;
	q->next = p;
}
template<typename T>
void  LDLL<T>::removeAfter(T key)
{
	DNode<T>* a = head;
	DNode<T>* aft = head->next;
	while (a->next != 0 && a->info != key)
	{
		aft = aft->next;
		a = a->next;
	}
	if (a->next == 0 && a->info == key)
		return;
	if (aft->next == 0)
	{
		a->next = 0;
		delete aft;
		return;
	}
	if (!a)
		return;
	aft->next->prev = a;
	a->next = aft->next;
	delete aft;
	
}
template<typename T>
void  LDLL<T>::remove(T key)
{
	if (head->info == key)
	{
		DNode<T>* p = head->next;
		delete head;
		head = p;
		return;
	}
	DNode<T>* p = head;
	DNode<T> * q = head->next;
	while (q->next != 0 && q->info != key)
	{
		p = q;
		q = q->next;
	}
	if (q->next == 0 && q->info == key)
	{
		p->next = 0;
		delete q;
		return;
	}
	if (!q)
		return;
	p->next = q->next;
	q->next->prev = p;
	delete q;
}
template<typename T>
void  LDLL<T>::removeAtHead()
{
	DNode<T> * q = head->next;
	delete head;
	head = q;
}
template<typename T>
void LDLL<T>::removeAtTail()
{
	if (!head)
		return;
	DNode<T> * p = head;
	DNode<T>*q = head->next;
	while (q->next!= 0)
	{
		p = q;
		q = q->next;
	}
	p->next = 0;
	delete q;
}
template<typename T>
LDLL<T>::LDLL(const LDLL<T> & ref)
{
	if (ref.head == 0)
	{
		head = 0;
		return;
	}
	DNode<T>* q = ref.head;
	head = 0;
	while (q != 0)
	{
		insertAtTail(q->info);
		q = q->next;
	}
}
template<typename T>
LDLL<T>::~LDLL()
{
	DNode<T> *q = head;
	while (q != 0)
	{
		head = head->next;
		delete q;
		q = head;
	}
}
template<typename T>
LDLL<T> & LDLL<T>::operator = (LDLL<T> & ref)
{
	if (this == &ref)
		return *this;
	this->~LDLL();
	if (ref.head == 0)
	{
		head = 0;
		return;
	}
	DNode<T>* q = ref.head;
	head = 0;
	while (q != 0)
	{
		insertAtTail(q->info);
		q = q->next;
	}
	return *this;
}
#endif