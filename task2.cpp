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
    // private:
    Node *Head;

public:
    // default constructor
    CircularLinkedList();
    // fucntions
    void InsertAtFirst(int);
    void InsertAtLast(int);
    void InsertAt(int, int);
    void DeleteAtFirst();
    void DeleteAtLast();
    void DeleteAt(int);
    void MakeCircular();
    void Display();
};
// Function Implementattion for class CircularLinkedList
// default constructor
CircularLinkedList ::CircularLinkedList()
{
    Head = NULL;
}
void CircularLinkedList ::InsertAtFirst(int x)
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
        Head = newnode;
        newnode->setNext(temp);
    }
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
void CircularLinkedList ::InsertAt(int pos, int x)
{
    Node* newnode = new Node;
    newnode->setData(x);

    if (Head == NULL)
    {
        cout << "List is Empty! " << endl;
    }

    Node *temp = Head;

    if (pos == 0)
    {
        InsertAtFirst(x);
    }

    else
    {
        // 1 -> 2 -> 3 -> 4 -> 5 -> *
        for (int i = 1; i < pos; i++)
        {
            temp = temp->getNext();
        }
        Node * next = temp->getNext();
        temp->setNext(newnode);
        newnode->setNext(next);
        
    }
}
void CircularLinkedList ::DeleteAtFirst()
{
    if (Head == NULL)
    {
        cout << "List is Empty Already!" << endl;
    }

    else
    {
        Node *temp;
        temp = Head;

        Head = temp->getNext();

        delete temp;
    }
}
void CircularLinkedList ::DeleteAtLast()
{
    if (Head == NULL)
    {
        cout << "List is Empty Already!" << endl;
    }

    else
    {
        Node *temp = Head;
        Node *prev = Head;
        while ((prev->getNext())->getNext() != NULL)
        {
            prev = prev->getNext();
        }

        delete (prev->getNext());
        prev->setNext(NULL);
    }
}
void CircularLinkedList ::DeleteAt(int pos)
{
    if (Head == NULL)
    {
        cout << "List is Empty! " << endl;
    }

    Node *temp = Head;

    if (pos == 0)
    {
        Head = temp->getNext();
        delete (temp);
    }

    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->getNext();
        }
        Node *next = temp->getNext();
        temp->setNext(next->getNext());
        delete next;
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
int main()
{
    CircularLinkedList l1;
    l1.InsertAtLast(1);
    l1.InsertAtLast(2);
    l1.InsertAtLast(3);
    l1.InsertAtLast(4);
    l1.InsertAtLast(5);


    l1.InsertAtFirst(0);
    l1.Display();

    l1.InsertAt(2, 10);
    l1.Display();

    l1.DeleteAtFirst();
    l1.Display();
    
    l1.DeleteAtLast();
    l1.Display();
    
    l1.DeleteAt(2);
    l1.Display();

    l1.MakeCircular();
    return 0;
}