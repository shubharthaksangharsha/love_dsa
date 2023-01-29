// Author: Shubharthak Sangharasha
/*  Date: 2023-01-12 22:45:56
         Description: Removing Duplicates from unsorted list ;=
*/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(NULL){};
    Node(int val) : data(val), next(NULL){};
};

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int data)
{
    Node *new_node = new Node(data);
    if (head)
    {
        new_node->next = head;
        head = new_node;
        return;
    }
    head = new_node;
}
Node *deleteDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    while (temp && temp->next)
    {
        if (temp->data == temp->next->data)
        {
            Node *delete_node = temp->next;
            temp->next = temp->next->next;
            delete delete_node;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

Node
int main()
{
    Node *head = new Node(10);
    cout << "Deleting Sorted List :-" << endl;
    insertAtHead(head, 10);
    insertAtHead(head, 5);
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 2);
    print(head);
    head = deleteDuplicates(head);
    print(head);

    cout << "Delete UnSorted List :-" << endl;
    insertAtHead(head, 10);
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    print(head);
}