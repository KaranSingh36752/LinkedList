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

Node *DeleteKth(Node *head,int el)
{
    if(head == NULL) return head; 
    if(head->data == el){    // agar index diya hain k==1
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        if(temp->data == el){ //idr ik count hoga jo count kasre ga and cnt == k then
        prev->next = prev->next->next;
        free(temp);
        break; 
        }
        prev = temp;  //agar if faled then the before incremnting the temp the prev holds temp old value then temp moves to next
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {2, 5, 7, 8, 9, 12};
    Node *head = convertArrtoLL(arr);
    cout << "Before deletion: \n";
    print(head);
    cout << "After deletion: \n";
    head = DeleteKth(head,1);
    print(head);
}