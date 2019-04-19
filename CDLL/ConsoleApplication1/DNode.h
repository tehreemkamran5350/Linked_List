#ifndef DNODE_H
#define DNODE_H
template <typename T>
class DNode
{
public:
	T info;
	DNode<T> * next;
	DNode<T> * prev;
	DNode()
	{
		next = 0;
	}
	DNode(T val)
	{
		info = val;
		next = 0;
	}
};
#endif