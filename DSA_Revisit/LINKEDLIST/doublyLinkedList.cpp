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
int main()
{
    vector<int> arr = {1, 3, 4, 5, 6, 7, 3, 2, 1};
    node *head = createDDLLArr(arr);
    print(head);
    return 0;
}