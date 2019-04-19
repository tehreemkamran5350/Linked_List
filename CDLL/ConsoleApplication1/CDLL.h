#ifndef CDLL_H
#define CDLL_H
#include "DNode.h"
template<typename T>
class CDLL
{
	DNode<T> * head;
public:
	CDLL();
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertAfter(T key, T val);
	void insertBefore(T key, T val);
	void removeBefore(T key);
	void removeAfter(T key);
	void remove(T key);
	void removeAtHead();
	void removeAtTail();
	CDLL(const CDLL<T> & ref);
	~CDLL();
	void display();
	CDLL<T> & operator = (CDLL<T> & ref);
};
template<typename T>
CDLL<T>::CDLL()
{
	head = 0;
}
template<typename T>
void  CDLL<T>::display()
{
	DNode<T>* q = head;
	do
	{
		cout << q->info << "	";
		q = q->next;
	} 
	while (q != head);
	cout << endl;
}
template<typename T>
void  CDLL<T>::insertAtHead(T val)
{
	if (head == 0)
	{
		head = new DNode <T>(val);
		head->prev = head;
		return;
	}
	DNode<T> * p = new DNode <T>(val);
	p->next = head;
	head->prev->next = p;
	p->prev = head->prev;
	head->prev = p;
	head = p;
}
template<typename T>
void  CDLL<T>::insertAtTail(T val)
{
	if (head == 0)
	{
		head = new DNode<T>(val);
		head->prev = head;
		return;
	}
	DNode<T>*p = new DNode<T>(val);
	head->prev->next = p;
	p->prev = head->prev;
	p->next = head;
	head->prev = p;
}
template<typename T>
void  CDLL<T>::insertAfter(T key, T val)
{
	DNode<T>* q = head;
	while (q->next != head && q->info != key)
	{
		q = q->next;
	}
	if (q->next == head && q->info != key)
		return;
	if (q->next == head && q->info == key)
	{
		DNode<T>* aft = new DNode<T>(val);
		q->next = aft;
		aft->prev = q;
		aft->next = head;
		head->prev = aft;
		return;
	}
	DNode<T>* aft = new DNode<T>(val);
	q->next->prev = aft;
	aft->next = q->next;
	aft->prev = q;
	q->next = aft;
}
template<typename T>
void  CDLL<T>::insertBefore(T key, T val)
{
	if (head->info == key)
	{
		DNode<T> * temp = new DNode <T>(val);
		temp->next = head;
		head->prev->next = temp;
		temp->prev = head->prev;
		head->prev = temp;
		head = temp;
		return;
	}
	DNode<T>* p = head;
	DNode<T>* q = head->next;
	while (q->next != head && q->info != key)
	{
		p = q;
		q = q->next;
	}
	if (q->next == head && q->info != key)
		return;
	DNode<int>* temp = new DNode<T>(val);
	q->prev = temp;
	p->next = temp;
	temp->prev = p;
	temp->next = q;
}
template<typename T>
void  CDLL<T>::removeBefore(T key)
{
	if (head->info == key)
	{
		DNode<T>* t = head->prev->prev;
		delete t->next;
		t->next = head;
		head->prev = t;
		return;
	}
	if (head->next->info == key)
	{
		DNode<T>*p = head->next;
		p->prev = head->prev;
		head->prev->next = p;
		delete head;
		head = p;
		return;
	}
	DNode<T>* q = head;
	DNode<T>* p = head->next->next;
	while (p != head && p->info != key)
	{
		q = q->next;
		p = p->next;
	}
	if (p==head && p->info!=key)
		return;
	p->prev = q;
	delete q->next;
	q->next = p;
}
template<typename T>
void  CDLL<T>::removeAfter(T key)
{
	DNode<T>* a = head;
	DNode<T>* aft = head->next;
	while (a->next != head && a->info != key)
	{
		aft = aft->next;
		a = a->next;
	}
	if (a->next == head && a->info != key)
		return;
	if (aft->next == head)
	{
		a->next = head;
		head->prev = a;
		delete aft;
		return;
	}
	if (a->next == head && a->info == key)
	{
		a->next = head->next;
		head->next->prev = a;
		delete head;
		head = a->next;
		return;
	}
	aft->next->prev = a;
	a->next = aft->next;
	delete aft;

}
template<typename T>
void  CDLL<T>::remove(T key)
{
	if (head->info == key)
	{
		DNode<T>* p = head->next;
		p->prev = head->prev;
		head->prev->next = p;
		delete head;
		head = p;
		return;
	}
	DNode<T>* p = head;
	DNode<T> * q = head->next;
	while (q->next != head && q->info != key)
	{
		p = q;
		q = q->next;
	}
	if (q->next == head && q->info == key)
	{
		p->next = head;
		head->prev = p;
		delete q;
		return;
	}
	if (q->next==head && q->info!=key)
		return;
	p->next = q->next;
	q->next->prev = p;
	delete q;
}
template<typename T>
void  CDLL<T>::removeAtHead()
{
	if (!head)
		return;
	DNode<T> * q = head->next;
	q->prev = head->prev;
	head->prev->next = q;
	delete head;
	head = q;
}
template<typename T>
void CDLL<T>::removeAtTail()
{
	if (!head)
		return;
	DNode<T> * p = head->prev->prev;
	p->next = head;
	delete head->prev;
	head->prev = p;
}
//template<typename T>
//CDLL<T>::CDLL(const CDLL<T> & ref)
//{
//	if (ref.head == 0)
//	{
//		head = 0;
//		return;
//	}
//	node<T>* q = ref.head;
//	node<T>*p = new node<T>(q->info);
//	q = q->next;
//	head = p;
//	while (q != ref.head)
//	{
//		p->next = new node<T>(q->info);
//		p = p->next;
//		q = q->next;
//	}
//	p->next = head;
//}
template<typename T>
CDLL<T>::~CDLL()
{
	DNode<T> * q = head->next;
	DNode<T> * p = head->next;
	while (q != head)
	{
		p = p->next;
		delete q;
		q = p;
	}
	delete head;
}
//template<typename T>
//CDLL<T> & CDLL<T>::operator = (CDLL<T> & ref)
//{
//	if (this == &ref)
//		return *this;
//	this->~LDLL();
//	if (ref.head == 0)
//	{
//		head = 0;
//		return;
//	}
//	DNode<T>* q = ref.head;
//	head = 0;
//	while (q != 0)
//	{
//		insertAtTail(q->info);
//		q = q->next;
//	}
//	return *this;
//}
#endif