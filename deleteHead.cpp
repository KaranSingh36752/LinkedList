#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1 = nullptr)
    {

        data = data1;
        next = next1;
    }
};

Node *convertArrtoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node *DeleteHead(Node *head)
{
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 7, 8, 9, 12};
    Node *head = convertArrtoLL(arr);
    cout << "Before deletion: \n";
    print(head);
    cout << "After deletion: \n";
    head = DeleteHead(head);
    print(head);
}