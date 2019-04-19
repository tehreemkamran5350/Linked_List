#ifndef CSLL_H
#define CSLL_H
#include "node.h"
template<typename T>
class LCLL
{
	node<T> * head;

public:
	LCLL();
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeBefore(T key);
	void removeAfter(T key);
	void remove(T key);
	void removeAtHead();
	void removeAtTail();
	LCLL(const LCLL<T> & ref);
	LCLL<T> & operator = (LCLL<T> & ref);
	void display();
	~LCLL();
};
template<typename T>
LCLL<T>::LCLL()
{
	head = 0;
}
template<typename T>
void  LCLL<T>::display()
{
	node<T>* q = head;
	do
	{
		cout << q->info << "	";
		q = q->next;
	}
	while (q != head);
	cout << endl;
}
template<typename T>
void  LCLL<T>::insertAtHead(T val)
{
	node<T> * q = new node <T>(val);
	node<T> * p = head;
	node<T> * tail = head;
	q->next = head;
	if (head != 0)
	{
		while (tail->next != head)
			tail = tail->next;
		tail->next = q;
	}
	else
		q->next = q;
	head = q;
}
template<typename T>
void  LCLL<T>::insertAtTail(T val)
{
	node<T> * p = new node<T>(val);
	node<T> * q = head;
	if (head != 0)
	{
		while (q->next != head)
			q = q->next;
		q->next = p;
	}
	else
		head = p;
	p->next = head;
}
template<typename T>
void  LCLL<T>::insertAfter(T key, T val)
{
	node<T>* p=new node<T>(val);
	node<T>* q = head;
	node<T>* aft = head->next;
	while (q->next != 0 && q->info != key)
	{
		q = aft;
		aft = aft->next;
	}
	if (q->next == head && q->info != key)
		return;
	if (q->next == head && q->info == key)
	{
		q->next = p;
		p->next = head;
		return;
	}
	q->next = p;
	p->next = aft;
}
template<typename T>
void  LCLL<T>::insertBefore(T key, T val)
{
	if (head->info == key)
	{
		node<T>* p = new node<T>(val);
		p->next = head;
		if (head->next != head)
		{
			node<T>* tail = head;
			while (tail->next != head)
				tail = tail->next;
			tail->next = p;
		}
		head = p;
		return;
	}
	node<T>* prev = head;
	node<T>* q = head->next;
	while (q->next != head && q->info != key)
	{
		prev = q;
		q = q->next;
	}
	if (q->next == head && q->info != key)
		return;
	if (q->next == head && q->info==key)
	{
		prev->next = new node<T>(val);
		prev->next->next = q;
		return;
	}
	prev->next = new node<T>(val);
	prev->next->next = q;
}
template<typename T>
void  LCLL<T>::removeBefore(T key)
{
	if (head->info == key)
	{
		node<T>* p = head;
		node<T>* q = head;
		while (p->next != head)
			p = p->next;
		while (q->next->next != head)
			q = q->next;
		delete p;
		q->next = head;
		return;
	}
	if (head->next->info == key)
	{
		node<T>*p = head->next;
		node<T>* q = head;
		while (q->next != head)
			q = q->next;
		delete head;
		head = p;
		q->next = head;
		return;
	}
	node<T>* prev = head;
	node<T>* p = head->next->next;
	while (p != head && p->info != key)
	{
		prev = prev->next;
		p = p->next;
	}
	if (p==head && p->info!=key)
		return;
	delete prev->next;
	prev->next = p;
}
template<typename T>
void  LCLL<T>::removeAfter(T key)
{
	node<T>* a = head;
	node<T>* aft = head->next;
	while (a->next != head && a->info != key)
	{
		aft = aft->next;
		a = a->next;
	}
	if (a->next == head && a->info != key)
		return;
	if (a->next == head && a->info == key)
	{
		node<T>* p = aft->next;
		delete aft;
		head = p;
		a->next = head;
		return;
	}
	a->next = aft->next;
	delete aft;

}
template<typename T>
void  LCLL<T>::remove(T key)
{
	if (head->info == key)
	{
		node<T>* p = head->next;
		node<T>* q = head;
		while (q->next != head)
			q = q->next;
		delete head;
		head = p;
		q->next = head;
		return;
	}
	node<T>* prev = head;
	node<T> * q = head->next;
	while (q != head && q->info != key)
	{
		prev = q;
		q = q->next;
	}
	if (q==head && q->info!=key)
		return;
	if (prev->next->next==head && prev->next->info==key)
	{
		delete q;
		prev->next = head;
		return;
	}
	prev->next = q->next;
	delete q;
}
template<typename T>
void  LCLL<T>::removeAtHead()
{
	node<T> * q = head->next;
	node<T> * p = head;
	while (p->next != head)
		p = p->next;
	delete head;
	head = q;
	p->next = head;
}
template<typename T>
void LCLL<T>::removeAtTail()
{
	if (head == 0)
		return;
	node<T> * p = head;
	node<T>*q = head->next;
	while (q->next != head)
	{
		p = q;
		q = q->next;
	}
	p->next = head;
	delete q;
}
template<typename T>
LCLL<T>::LCLL(const LCLL<T> & ref)
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
	while (q != ref.head)
	{
		p->next = new node<T>(q->info);
		p = p->next;
		q = q->next;
	}
	p->next = head;
}
template<typename T>
LCLL<T>::~LCLL()
{
	node<T> * q = head->next;
	node<T> * p = head->next;
	while (q!= head)
	{
		p = p->next;
		delete q;
		q = p;
	}
	delete head;
}
template<typename T>
LCLL<T> & LCLL<T>::operator = (LCLL<T> & ref)
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
	while (q != ref.head)
	{
		p->next = new node<T>(q->info);
		p = p->next;
		q = q->next;
	}
	p = head;
	return *this;
}
#endif