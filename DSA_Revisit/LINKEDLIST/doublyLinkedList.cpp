#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    // constructor
    node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
    node(int data, node *prev, node *next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};
// creating doubly linked list from array
node *createDDLLArr(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *prev = head; // important step
    // looping for other values
    for (int i = 1; i < arr.size(); i++)
    {
        // create a new node
        node *newNode = new node(arr[i], prev, nullptr);
        prev->next = newNode;
        prev = newNode;
    }
    return head;
}
// print function
void print(node *head)
{
    node *temp = head;
    while (temp)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << endl;
}
// deletion at head
node *deleteHead(node *&head)
{
    if (!head)
        return head;
    if (!(head->next))
    {
        node *temp = head;
        delete temp;
        return nullptr;
    }
    node *temp = head;
    head = head->next;
    temp->next = nullptr;
    
    delete temp;
    return head;
}
// deleting the tail of DLL
node *removeTail(node *&head)
{
    if (!head)
        return nullptr;
    if (head->next == NULL)
    {
        node *temp = head;
        head = NULL;
        delete temp;
        return head;
    }
    node *temp = head;
    while (temp->next)
        temp = temp->next;
    node *prev = temp->prev;
    temp->prev = nullptr;
    prev->next = NULL;
    delete temp;
    return head;
}
// deleting the kth node
node *deleteKth(node *head, int k)
{
    if (!head)
        return head;
    node *knode = head;
    int cnt = 0;
    while (knode)
    {
        cnt++;
        if (cnt == k)
            break;
        knode = knode->next;
    }

    node *prev = knode->prev;
    node *front = knode->next;
    if (!(prev) && !(front))
    {
        delete knode;
        return nullptr;
    }
    // if head node to be deleted
    else if (prev == NULL)
      return  deleteHead(head);
    // tailElenment
    else if (front == NULL)
       return  removeTail(head);
    // middle element

    prev->next = front;
    front->prev = prev;
    free(knode);
    return head;
}
// implementing the  insert operations
int main()
{
    vector<int> arr = {1};
    node *head = createDDLLArr(arr);
    print(head);
    //    head =  deleteHead(head);
    //  head = removeTail(head);
    cout << "again printing DLL\n";
    head = deleteKth(head, 1);
    print(head);
    return 0;
}