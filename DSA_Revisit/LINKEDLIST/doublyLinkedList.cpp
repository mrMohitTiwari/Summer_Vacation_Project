#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev ;
    node* next;
    // constructor
    node(int data){
        this->data = data;
    }
    node(int data ,node *prev , node* next)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }

};
int main() {
     vector<int> arr = {1, 3, 4, 5, 6, 7, 3, 2, 1};
    return 0;
}