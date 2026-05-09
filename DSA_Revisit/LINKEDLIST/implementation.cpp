#include <iostream>
using namespace std;
class Node{
    public:

    int data;
    Node *next;
    // consturctor
    Node(int data){
        this->data = data;
        this->next=nullptr;
    }


};
// creating a Linked List with array
Node *createLLFromArray(vector<int> &arr)
{
        Node *head = new Node(arr[0]);
        Node *tail = head;
        // creating the other Link 
        for(int i =1;i<arr.size();i++){
            // create a node 
            Node *temp = new Node(arr[i]);
            tail->next = temp;
            tail = temp;;
        }
        return head;

}
// print Linked List
void PrintLL(Node *&head)
{
        Node *temp = head;
        while(temp){
            cout<<temp->data<<" ";
            temp = temp->next;

        }
        cout<<endl;

}
// delete head of the Linked List
Node* deleteHead(Node *&head){
    if(!head) {
        return nullptr;
    }
    // store the next node 
    Node *temp = head;
    head = head->next;
    delete(temp);
    return head;
}


int main() {
    // static variable 
    // Node n1(2);
    // dynamic from array
    vector<int> arr = {1,2,3,4,5,6};
    Node *head = createLLFromArray(arr);
         PrintLL(head);
    return 0;
}