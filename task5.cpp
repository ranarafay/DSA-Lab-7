// Will be implementing Singly Circular Linked List as Doubly haven't discussed yet in lectures

#include <iostream>
using namespace std;

class Node
{
    // private:
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
public:
    Node *Head;

    // default constructor
    CircularLinkedList();
    // fucntions
    void InsertAtFirst(int);
    void InsertAtLast(int);
    void MakeCircular();
    void Display();
};
// Function Implementattion for class CircularLinkedList
// default constructor
CircularLinkedList ::CircularLinkedList()
{
    Head = NULL;
}
void CircularLinkedList ::InsertAtLast(int x)
{
    Node *newnode = new Node;
    newnode->setData(x);

    if (Head == NULL)
    {
        Head = newnode;
    }
    else
    {
        Node *temp = Head;
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }
        temp->setNext(newnode);
    }
}
void CircularLinkedList ::MakeCircular()
{
    // for making circular linked list
    Node *temp = Head;
    while (temp->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    temp->setNext(Head);
}
void CircularLinkedList ::Display()
{
    Node *temp = Head;

    cout << "Linked List: ";
    while (temp->getNext() != Head)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << temp->getData() << " ";
}
// function for returning value of middle node
int MiddleVal(Node *head)
{
    Node *temp = head;

    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->getNext();
        cnt++;
    }

    // middle node for odd number of nodes
    cnt = cnt / 2 + 1;

    Node *temp1 = head;
    for (int i = 1; i < cnt; i++)
    {
        temp1 = temp1->getNext();
    }
    return temp1->getData();
}

int main()
{
    CircularLinkedList l1;
    l1.InsertAtLast(1);
    l1.InsertAtLast(2);
    l1.InsertAtLast(3);
    l1.InsertAtLast(4);
    l1.InsertAtLast(5);

    cout << MiddleVal(l1.Head);

    return 0;
}