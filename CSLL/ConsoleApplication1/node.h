#ifndef NODE_H
#define NODE_H
template <typename T>
class node
{
public:
	T info;
	node<T> * next;
	node()
	{
		next = 0;
	}
	node(T val)
	{
		info = val;
		next = 0;
	}
};
#endif