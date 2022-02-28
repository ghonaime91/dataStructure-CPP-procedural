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
    Node* next;

};

//-----------------------------------------

void display(Node* head)
{
    if (head == NULL)
    {
        cout << "Empty List!\n";
        return;
    }

    Node* temp = new Node();
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }

}

//-----------------------------------------

void push(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    *head = newNode;
    return;
}

//-----------------------------------------

void append(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;

}

//-----------------------------------------

void insertAfter(Node* prev, int d)
{
    if (prev == NULL)
    {
        cout << "the previous node can't be null\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = d;
    newNode->next = prev->next;
    prev->next = newNode;
}

//-----------------------------------------

void sortedInsert(Node** head, int newData)
{
    Node* newNode = new Node();
    newNode->data = newData;

    if (*head == NULL || (*head)->data >= newNode->data)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL && current->next->data < newNode->data)
        current = current->next;

    newNode->next = current->next;
    current->next = newNode;
    return;

}

//-----------------------------------------

void deleteNode(Node** head, int value)
{
    Node* temp = (*head);
    if (temp != NULL)
    {
        if (temp->data == value)
        {
            *head = temp->next;
            delete temp;
            return;
        }

        while (temp->next != NULL)
        {
            if (temp->next->data == value)
            {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
                return;
            }

            temp = temp->next;
        }

        if (temp->data != value)
        {
            cout << "\nThe node that you want to delete is not found !\n";
            return;
        }
    }


}
//-----------------------------------------
//-----------------------------------------

int main()
{

    Node* head = new Node();
    Node** headPtr = &head;
    head->data = 15;
    //append(&head, 20);
    //append(&head, 30);
    //append(&head, 40);
    //append(&head, 50);
    //push(&head, 5);
    //insertAfter(head->next->next,45);

    sortedInsert(headPtr, 50);
    sortedInsert(headPtr, 45);
    sortedInsert(headPtr, 40);
    sortedInsert(headPtr, 55);
    sortedInsert(headPtr, 10);
    sortedInsert(headPtr, 60);
    display(head);
    //-----------------------------------------
    cout << endl << endl;
    deleteNode(headPtr, 50);
    display(head);
    //-----------------------------------------
    cout << endl << endl;
    deleteNode(headPtr, 55);
    display(head);
    //-----------------------------------------
    //-- try to delete an item not lisetd;
    deleteNode(headPtr, 90);

    system("pause>0");
}


