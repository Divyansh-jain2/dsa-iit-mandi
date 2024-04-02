#include <cstdlib> 
#include <iostream> 
#include <time.h>
using namespace std;

class Node{
public:
    int val;
    Node* down;
    Node* next;
    Node(){
        this->next = NULL;
        this->down = NULL;
    }
};
class Skiplist
{
public:
    Node* l1head;
    Node* l2head;
    Node* l3head;
    Node* t1;
    Node* t2;
    Node* t3;
    Skiplist(){
        l1head = new Node;
        l1head->val = INT32_MIN;
        l2head = new Node;
        l2head->val = INT32_MIN;
        l2head->down = l1head;
        this->t1 = l1head;
        this->t2 = l2head;
        l3head = new Node;
        l3head->val = INT32_MIN;
        l3head->down = l2head;
        this->t3= l3head;
    }
    void insert(int key){
        
        int prob = rand()%2;
        // inserting into l1 list either way
        Node* newNode1 = new Node;
        newNode1->val = key;
        t1->next = newNode1;
        t1 = newNode1;
        if(prob == 1){
            // inserting into level 1 with half probability
            Node* newNode2 = new Node;
            newNode2->val = key;
            newNode2->down = newNode1;
            t2->next = newNode2;
            t2 = newNode2;
            int prob1 = rand()%2;
            if(prob1 == 1){
                Node* newNode3 = new Node;
                newNode3->val = key;
                newNode3->down = newNode2;
                t3->next = newNode3;
                t3 = newNode3;
            }
        }
    }
    void displayLL(Node* head){
        Node* temp = head->next;
        while(temp){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    Node* search(int key){
        //first we seacrh in l3
        Node* temp0 = l3head;
        while(temp0->next && temp0->next->val < key){
            temp0 = temp0->next;
        }
        //then we search in l2 till we find element greater than key

        Node* temp1 = temp0->down;
        while(temp1->next && temp1->next->val < key){
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->down;
        while(temp2 && temp2->val < key){
            temp2 = temp2->next;
        }
        if(temp2 && temp2->val == key){
            cout<<"Searched"<<endl;
            return temp2;
        }
        else{
            cout<<"cant find"<<endl;
            return NULL;
        }

    }
    Node* searchINLVL(Node* lvlhead){
        Node* temp = lvlhead;
        

    }
};

int main(){
    srand(time(0));
    Skiplist s;
    s.insert(5);
    s.insert(10);
    s.insert(14);
    s.insert(17);
    s.insert(21);
    s.insert(100);
    s.insert(104);
    s.insert(109);
    s.displayLL(s.l3head);
    s.displayLL(s.l2head);
    s.displayLL(s.l1head);
    s.search(104);
}