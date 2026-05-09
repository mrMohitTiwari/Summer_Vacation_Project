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
            cout<<temp->data<<"->";
            temp = temp->next;

        }
        cout<<"null"<<endl;

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
// deleting the tail
// first we have to reach the seonc last element of the linked list and should exist
Node* deleteLast(Node *&head){
    if(!head) return nullptr;
    if(!(head->next)){
        free(head);
        head = nullptr;
        return head;
    }
        Node *temp= head;
        while(temp->next->next){
            temp = temp->next;
        }
        free(temp->next);
          temp->next = nullptr;
        return head;
}


int main() {
    // static variable 
    // Node n1(2);
    // dynamic from array
    vector<int> arr = {1,3,4,5,6,7,3,2,1};
    Node *head = createLLFromArray(arr);
         PrintLL(head);
            // head = deleteHead(head);
            // cout<<"printing LL again"<<endl;

            // PrintLL(head);

            cout<<"printing LL again"<<endl;
            deleteLast(head);
          
            PrintLL(head);



    return 0;
}