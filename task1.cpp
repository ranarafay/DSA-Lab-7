// Will be implementing Singly Circular Linked List as Doubly haven't discussed yet in lectures

#include <iostream>
using namespace std;

class Node
{

    int Data;
    Node *Next;

public:
    // default constructor
    Node();
    // setters
    void setData(int);
    void setNext(Node *);
    // getters
    int getData();
    Node *getNext();
};
// Function Implementattion for class Node
// default constructor
Node ::Node()
{
    Data = 0;
    Next = NULL;
}
// setters
void Node ::setData(int x)
{
    Data = x;
}
void Node ::setNext(Node *next)
{
    Next = next;
}
// getters
int Node ::getData()
{
    return Data;
}
Node *Node ::getNext()
{
    return Next;
}
class CircularLinkedList
{
    // private:
    Node *Head;

public:
    // default constructor
    CircularLinkedList();
    // parameterized constructor
    CircularLinkedList(int);
};
// Function Implementattion for class CircularLinkedList
// default constructor
CircularLinkedList ::CircularLinkedList()
{
    Head = NULL;
}
// parameterized constructor
CircularLinkedList ::CircularLinkedList(int x)
{
    Head = NULL;

    Node *newnode = new Node;
    newnode->setData(x);
    // for making circular linked list

    if (Head == NULL)
    {
        Head = newnode;
        newnode->setNext(Head);
    }
    else
    {
        Node *temp = Head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        temp->setNext(newnode);
        temp->setNext(Head);
    }
}

int main()
{
    CircularLinkedList l1(4);

    return 0;
}