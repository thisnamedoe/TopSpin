#pragma once
#include <iostream>
using namespace std;
template <class Item> //templated class Item
class CDLL { //class declaration for Circular Doubly Linked List (CDLL)
private:
	class Node //class Node inside of class CDLL
	{ 
	public:
		Node(Item v, Node *n = NULL, Node *p = NULL) : value(v), next(n), prev(p) {}  //Node initalization
		Item value; //value of Node
		Node * prev; //previous Node
		Node * next; //next Node
	};
	Node * m_head; //head Node
	Node * m_tail; //tail Node
	unsigned int m_size; //size of CDLL 

public:
	CDLL <Item>::CDLL() : m_head (NULL), m_tail (NULL), m_size (0) //constructor
	{
	}

	CDLL <Item>::~CDLL() 
	{ //destructor
		Node * here = m_head; //initalize pointer here to be equal to head node
		Node * nextNode = NULL; //nextNode is equal pointing to NULL
		while (here != NULL) //while head node is not equal to null
		{
			nextNode = here->next; //the next node is equal to the the next node of the head node
			delete[] here; //delete current node
			here = nextNode; //current node is equal to next node (new head node)
		}
	}

	void CDLL <Item>::addData(Item d) //add new Node to tail of CDLL with value d
	{ 
		Node *temp = new Node(d, NULL, NULL); //initalize new Node equalling value d 
		if (m_size == 0) //if the CDLL is empty
		{ 
			m_head = m_tail = temp; //head and tail are equal as there is only one element in the CDLL
			m_head->next = m_tail->next = NULL; //since they are equal and there is only one element, there is no next element
			m_head->prev = m_tail->prev = NULL; //no previous elements as there is only one element
		}
		else
		{
			m_tail->next = temp; //tail now points to the temp
			temp->prev = m_tail; //temp points from previous tail
			m_tail = temp; //tail is now tmep
			m_head->prev = m_tail; //head points from tail
			m_tail->next = m_head; //tail now points to head
		}
		m_size++; //size of CDLL is incremented by 1

	}

	void CDLL <Item>::incrementHead() { //increment head 
		if (m_head == NULL || m_size == 1) {
			return; //if there is no CDLL or only one element, then nothing happens
		}
		else
		{
			Node *temp = m_head; //temp now is equal to head
			m_head = m_head->next; //head is now the next element 
			m_tail = temp; //old tail is now the new head
		}
	}

	void CDLL <Item>::decrementHead() {
		if (m_head == NULL || m_size == 1)
		{
			return; //if there is no CDLL or only one element, nothing happens
		}
		else
		{
			Node *m_temp = m_tail; //temp is now equal to tail
			m_tail = m_tail->prev; //tail is equal to what was pointing to tail 
			m_head = m_temp; //new head is equal to the old tail
		}
	}
	void CDLL <Item>::swap(unsigned int src, unsigned int dst)  //swaps the values in two Nodes
	{ 
		Node * temp1 = m_head; //temp1 is equal to the head
		Node * temp2 = m_head; //temp2 is equal to the head 
		Item tempValue; //temporary value of type item

		for (unsigned int k = 1; k < src; k++) {
			temp1 = temp1->next; //finds the src-Node and sets temp1 equal to it
		}
		for (unsigned int i = 1; i < dst; i++) {
			temp2 = temp2->next; //finds the dst-Node and sets temp2 equal to it
		}

		tempValue = temp1->value; //temporary value is equal to the value at src-Node
		temp1->value = temp2->value; //value at Node temp1 is now equal to the value at Node temp2
		temp2->value = tempValue; //Node temp2 value is now equal to the temp value (old temp1 value)
	}

	Item CDLL <Item>::getData(unsigned int i) const {
		Node * here = m_head; //Node here is equal to Node m_head
		if (i == 1) {
			return m_head->value; //asking to return value of first Node, so it is equal to the value at head
		}
		else if (i == m_size) {
			return m_tail->value; //asking to return value of last Node, so it is equal to the value at tail
		}
		for (unsigned int k = 1; k < i; k++) {
			here = here->next; //Node here is equal to the Node that it is pointing to
		}
		return here->value; //return the i-th Node value in the CDLL
	}
};