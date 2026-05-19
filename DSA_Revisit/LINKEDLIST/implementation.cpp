#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // consturctor
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
// creating a Linked List with array
Node *createLLFromArray(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;
    // creating the other Link
    for (int i = 1; i < arr.size(); i++)
    {
        // create a node
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
        ;
    }
    return head;
}
// print Linked List
void PrintLL(Node *&head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "null" << endl;
}
// delete head of the Linked List
Node *deleteHead(Node *&head)
{
    if (!head)
    {
        return nullptr;
    }
    // store the next node
    Node *temp = head;
    head = head->next;
    delete (temp);
    return head;
}
// deleting the tail
// first we have to reach the seonc last element of the linked list and should exist
Node *deleteLast(Node *&head)
{
    if (!head)
        return nullptr;
    if (!(head->next))
    {
        free(head);
        head = nullptr;
        return head;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

// deleting the kth node from the list
Node *delteK(Node *head, int k)
{
    if (!head)
        return nullptr;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;

        return head;
    }
    // now we will search for kth element
    int cnt = 1;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {
        cnt++;
        prev = temp;
        temp = temp->next;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete (temp);
            break;
        }
    }
    return head;
}
// remove when data is given
Node *deltedata(Node *head, int val)
{
    if (!head)
        return nullptr;
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;

        return head;
    }
    // now we will search for kth element

    Node *temp = head;
    Node *prev = nullptr;
    while (temp)
    {

        prev = temp;
        temp = temp->next;
        if (temp->data == val)
        {
            prev->next = prev->next->next;
            delete (temp);
            break;
        }
    }
    return head;
}

// ************** Insertion ****************************************
Node *InsetAtHead(Node *head, int val)
{
    if (!head)
    {
        // head->data = val;
        // head->next = NULL;
        // return head;
        return new Node(val);
    }
    // create a node
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
    return head;
}
// inserting at k position
Node *insertK(Node *head, int k, int val)
{
    if ((!head) && k == 1)
        return new Node(val);
    if (k == 1)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        return head;
    }
    //    inseting at some other k place
    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        if (cnt == k - 1)
        {
            // create a node
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}
// insert at head
Node* insetAtTail(Node*head ,int val)
{
    if(!head) return new Node(val);
        Node *temp = head;
        while(temp) temp= temp->next;
            // create new node and add it 
temp->next = new Node(val);
return head;
 

}
// inseting before a given value
Node *insertingBeforVal(Node *head, int k, int val)
{
   if(!head) return NULL; //if head is null we do not have any value before which we can insert
    if (head->data == val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        return head;
    }
    //    inseting at some other k place

    Node *temp = head;
    while (temp->next)
    {
        
if(temp->next->data == val)
        {
            // create a node
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}
// revese a doubly Linked List
int main()
{
    // static variable
    // Node n1(2);
    // dynamic from array
    vector<int> arr = {1, 3, 4, 5, 6, 7, 3, 2, 1};
    Node *head = createLLFromArray(arr);
    PrintLL(head);
    // head = deleteHead(head);
    // cout<<"printing LL again"<<endl;

    // PrintLL(head);

    cout << "printing LL again" << endl;
    // deleteLast(head);
    // deleting the kth node
    // head = delteK(head, 9);
    // head = deltedata(head,3);
    // cout<<"inserting at head\n";
    // head= InsetAtHead(head,40);
        head =insertK(head,10,100);
    PrintLL(head);

    return 0;
}