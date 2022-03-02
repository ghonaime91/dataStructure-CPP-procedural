#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
using std::cout;
using std::cin;
using std::endl;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

};

//-----------------------------------------

void push(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = (*head);

    if ((*head) != NULL)
        (*head)->prev = newNode;

    (*head) = newNode;
    return;
}

//-----------------------------------------

void display(Node* head)
{
    Node* last = new Node(),*temp = new Node();
    temp = head;

    cout << "Display items in forward direction\n";
    while (temp != NULL)
    {
        cout << temp->data << endl;
        last = temp;
        temp = temp->next;
    }
    cout << "\n-----------------------------\n";

    cout << "Display items in reverse direction\n";
    while (last != NULL)
    {
        cout << last->data << endl;
        last = last->prev;
    }
}

//-----------------------------------------

void deleteNode(Node** head, Node* del)
{
    if ((*head) == NULL || del == NULL)
        return;
    
    if ((*head) == del)
        (*head) = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    delete del;
    return;
   

}

int main()
{
 
    Node* head = new Node(),**hPtr = &head;
    head = NULL;

    push(hPtr,10);
    push(hPtr, 20);
    push(hPtr, 30);
    push(hPtr, 35);
    push(hPtr, 40);
    push(hPtr, 50);

    deleteNode(hPtr,head->next->next);

    display(head);


    system("pause>0");
}

