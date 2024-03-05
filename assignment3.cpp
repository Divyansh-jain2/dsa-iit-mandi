//q1

// #include<iostream>
// using namespace std;

// class Stack{
//     private:
//     class node {
//     public:
//         int data;
//         node* next;
        
//         node(int data){
//             this->data=data;
//             this->next=NULL;
//         }
//     };

//     node* head = NULL;
//     public:
//     int popped_ele;
    
//     void push(int d){
//         node* temp=new node(d);
//         temp->next=head;
//         head=temp;
//     }
//     void print(){
//         node* temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
//     int pop(){
//         if (head == NULL) {
//         cout << "Stack is empty" << endl;
//         return -1;  // or throw an exception
//         }
//         popped_ele=head->data;
//         head=head->next;
//         return popped_ele;
//     }
// };

// void arrangement(Stack* source, Stack* helper, Stack* destination, int a,string source_name,string helper_name,string destination_name) {
//     if (a>0){
//         arrangement(source,  destination,helper, a - 1,source_name,destination_name,helper_name);
//             destination->push(source->pop());
//             cout<<"Move the "<<a<< " disc from "<<source_name<<" to "<<destination_name<<endl;
//         arrangement(helper, source, destination, a - 1,helper_name,source_name,destination_name);
//     }
    
// }
// int main (){
//     Stack* stack1 = new Stack(); 
//     Stack* stack2=new Stack();
//     Stack* stack3=new Stack();   
    
//     int a;
//     cout<<"enter the number of chakra you want ";
//     cin>>a;
//     for (int i=a;i>=1;i--){
//         stack1->push(i);
//     }
//     cout<<"this is the initial stack ";stack1->print();
//     arrangement(stack1,stack2,stack3,a,"stack1","stack2","stack3");
//     cout<<"this is the final destination stack ";stack3->print();
//     return 0;
// }



//q2


// #include<iostream>
// using namespace std;

// class Stack{
//     private:
//     class node {
//     public:
//         int data;
//         node* next;
        
//         node(int data){
//             this->data=data;
//             this->next=NULL;
//         }
//     };

//     node* head = NULL;
//     public:
//     int popped_ele;
//     void push(int d){
//         node* temp=new node(d);
//         temp->next=head;
//         head=temp;
//     }
//     void print(){
//         node* temp=head;
//         while(temp!=NULL){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }
//     int pop(){
//         if (head == NULL) {
//         return -1;  
//         }
//         popped_ele=head->data;
//         head=head->next;
//         return popped_ele;
//     }
// };

// int main(){
//     Stack* stack1=new Stack();
//     string a;
//     cout<<"enter the string ";cin>>a;
//     int x=0;
//     for (int i=0;i<a.size();i++){
//         if(a[i]=='('){
//             stack1->push(a[i]);
//         }
//         else if(a[i]==')'){
//             int b=stack1->pop();
//             if (b==-1){
//                     x=-1;
//                     break;
//             }
//         }
//     }
//     if(stack1->pop()==-1 && x!=-1){
//         cout<<"The paranthesis are balanced"<<endl;
//     }
//     else{
//         cout<<"The paranthesis are unbalanced"<<endl;
//     }
//     return 0;
// }


//q3


// #include<iostream>
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node *previous;
//     Node(int d)
//     {
//         data = d;
//         next = NULL;
//         previous = NULL;
//     }
// };

// class Doubly_linked_list
// {
// public:
//     Node *head;
//     Node *tail;
    

//     Doubly_linked_list()
//     {
//         head = NULL;
//         tail = NULL;
        
//     }
//     void print()
//     {
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             cout << temp->data << " ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
//     void insertathead(int val)
//     {
//         Node *node1 = new Node(val);
//         if (head == NULL)
//         {
//             head = node1;
//             tail = node1;
//             return;
//         }
//         else
//         {
//             node1->next = head;
//             head->previous = node1;
//             head = node1;
//         }
//     }
// };

// int main()
// {
//     Node *node1 = new Node(10);

//     Doubly_linked_list dil;
//     dil.head = node1;
//     dil.tail = node1;
//     dil.insertathead(13);   
//     dil.insertathead(12);
//     dil.insertathead(16);
//     dil.insertathead(6);
//     dil.insertathead(10);
//     dil.insertathead(12);
//     dil.insertathead(13);
//     dil.print();
//     Node* temp1=dil.head->next;
//     int count=0;
//     while(temp1!=NULL){
//         count++;
//         if(temp1->data<temp1->previous->data){
//             Node* temp2 = temp1;
//             int temp2_d=temp1->data;
//             Node*temp3=temp1->previous;
//             temp1=temp1->next;
//             while(temp3!=NULL && temp3->data>=temp2_d){
//                 temp3->next->data=temp3->data;
//                 temp3=temp3->previous;
//             }
//             if(temp3==NULL){
//                 dil.head->data=temp2_d;
//             }  
//             else{
//                 temp3->next->data=temp2_d;
//             }    
//     }
//     else{
//             temp1=temp1->next;
//         }     
//     }
//     dil.print();
//     return 0;
// }






//q4.1


// #include<iostream>
// using namespace std;

// int main() {
//     int A[5][6] = {
//         {0 , 0 , 0 , 0 , 9, 0 },
//         {0 , 8 , 0 , 0 , 0, 0 },
//         {4 , 0 , 0 , 2 , 0, 0 },
//         {0 , 0 , 0 , 0 , 0, 5 },
//         {0 , 0 , 2 , 0 , 0, 0 }
//     };

//     int B[5][6] = {
//         {0 , 0 , 0 , 0 , 1, 0 },
//         {0 , 5 , 0 , 2 , 0, 0 },
//         {0 , 0 , 1 , 0 , 0, 5 },
//         {2 , 8 , 0 , 0 , 1, 0 },
//         {0 , 0 , 4 , 0 , 0, 0 }
//     };

//     int C[5][6] = {0};

//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 6; j++) {
//             for (int k = 0; k < 5; k++) {
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }


//     for (int i = 0; i < 5; i++) {
//         for (int j = 0; j < 6; j++) {
//             cout << C[i][j] << " ";
//         }
//         cout << "\n";
//     }

//     return 0;
// }




// user input



// #include <iostream>
// using namespace std;
// int main (){
//     int m,n,p,q;
//     cout<<"enter the number of rows ";
//     cin>>m;
//     cout<<"enter the number of columns ";
//     cin>>n;
//     int A[m][n];
//     cout<<"enter the elements of the matrix ";
//     for (int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cin>>A[i][j];
//         }
//     }
//     cout<<"enter the number of rows of matrix 2 ";
//     cin>>p;
//     cout<<"enter the number of columns of matrix 2 ";
//     cin>>q;
//     int B[p][q];
//     cout<<"enter the elements of the matrix ";
//     for (int i=0;i<p;i++){
//         for(int j=0;j<q;j++){
//             cin>>B[i][j];
//         }
//     }
//     if(p!=n){
//         cout<<"the dense matrix multiplication is not possible ";

//     }
//     else {
//         int sum1 = 0;
//         int C[m][q];
//         for (int j = 0; j < m; j++) {
//             for (int k = 0; k < q; k++) {
//                 for (int i = 0; i < n; i++) {
//                     sum1 = sum1 + A[j][i] * B[i][k];
//                 }
//                 C[j][k] = sum1;
//             }
//         }
//         for (int i=0;i<m;i++){
//             for (int j=0;j<q;j++){
//                 cout<<C[i][j]<<"  ";
//             }
//             cout<<endl;
//         }
//     }

//     return 0;
// }



// q4.2


// #include<iostream> 
// using namespace std;
// class Node
// {
// public:
//     int data;
//     Node *next;
//     Node(int d)
//     {
//         data = d;
//         next = NULL;
//     }
// };
// class singly_linked_list
// {
// public:
//     Node *head;
//     Node *tail;
//     singly_linked_list()
//     {
//         head = NULL;
//         tail = NULL;
//     }
//     void insert_at_head(int data)
//     {
//         Node *node1 = new Node(data);
//         if (head == NULL)
//         {
//             head = node1;
//             tail = node1;
//             return;
//         }
//         else
//         {
//             node1->next = head;
//             head = node1;
//         }
//     }
//     void insert_at_tail(int data)
//     {
//         Node *node1 = new Node(data);
//         if (tail == NULL)
//         {
//             head = node1;
//             tail = node1;
//             return;
//         }
//         else
//         {
//             tail->next = node1;
//             tail = node1;
//         }
//     }
// };

// int main()
// {
//     int r, c;
//     cout << "enter the number of rows ";
//     cin >> r;
//     cout << "enter the number of columns ";
//     cin >> c;
//     singly_linked_list** arr = new singly_linked_list*[r];
//     for (int j = 0; j < r; j++)
//     {
//         arr[j] = new singly_linked_list;
//         for (int i = 0; i < c; i++)
//         {
//             int x;
//             cin >> x;
//             arr[j]->insert_at_tail(x);
//         }
//     }
//     for (int i = 0; i < r; i++)
//     {
//         Node *temp = arr[i]->head;
//         while (temp != NULL)
//         {
//             cout <<temp->data<<" ";
//             temp = temp->next;
//         }
//         cout << endl;
//     }
//     for(int i = 0; i < r; i++){
//         delete arr[i];
//     }
//     delete[] arr;
//     return 0;
// }



// q4.3



// #include<iostream>
// using namespace std;

// void MatMul(int A[][6],int B[][5],int C[][5]){
//     for(int i=0;i<5;i++){
//         for(int j=0;j<5;j++){
//             for(int k=0;k<6;k++){
//                 C[i][j]+=A[i][k]*B[k][j];
//             }
//         }
//     }
// }
// struct node{
//     int data;
//     node* next;
//     int index;
//     node(int val){
//         data=val;
//         next=NULL;
//     }
// };
// void Push(node* &head,int val){
//     node* n=new node(val);
//     if(head==NULL){
//         head=n;
//     }
//     else{
//         node* temp=head;
//         while(temp->next!=NULL){
//             temp=temp->next;
//         }
//         temp->next=n;
//     }
// }

// void Display(node* head){
//     if(head==NULL){
//         return;
//     }
//     cout<<head->data<<"["<<head->index<<"]"<<"->";
//     node* temp=head;
//     while(temp->next!=NULL){
//         cout<<temp->next->data<<"["<<temp->next->index<<"]"<<"->";
//         temp=temp->next;
//     }
//     cout<<"NULL";
// }

// int main(){
// int A[5][6]={{0,0,0,0,9,0},{0,8,0,0,0,0},{4,0,0,2,0,0},{0,0,0,0,0,5},{0,0,2,0,0,0}};
// int B[6][5]={{0,0,0,2,0},{0,5,0,8,0},{0,0,1,0,4},{0,2,0,0,0},{1,0,0,1,0},{0,0,5,0,0}};
// int C[5][5];
// for(int i=0;i<5;i++){
//     for(int j=0;j<5;j++){
//         C[i][j]=0;
// }}
// MatMul(A,B,C);
// for(int i=0;i<5;i++){
//     for(int j=0;j<5;j++){
//         cout<<C[i][j]<<" ";
//     }
//     cout<<endl;
// }
// node* a[5]={NULL,NULL,NULL,NULL,NULL};
// node* b[5]={NULL,NULL,NULL,NULL,NULL};
// for(int i=0;i<5;i++){
//     for(int j=0;j<6;j++){
//         if(A[i][j]!=0){
//             Push(a[i],A[i][j]);
//             node* temp=a[i];
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }
//             temp->index=j;
//         }
//         if(B[j][i]!=0){
//             Push(b[i],B[j][i]);
//             node* temp=b[i];
//             while(temp->next!=NULL){
//                 temp=temp->next;
//             }
//             temp->index=j;
//         }
// }}
// for(int i=0;i<5;i++){
//         Display(a[i]);
//         cout<<endl;
//         Display(b[i]);
//         cout<<endl;
//     }
// int D[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};;
// for(int i=0;i<5;i++){
//     for(int j=0;j<5;j++){
//         if(a[i]!=NULL & b[i]!=NULL){
//         node* temp1=a[i];
//         node* temp2=b[j];
//         bool flag=true;
//         while(flag==true){
//             if(temp1->next==NULL & temp2->next==NULL){
//                 flag=false;
//             }
//             if(flag==true){
//                 if(temp1->index==temp2->index){
//                     D[i][j]+=temp1->data*temp2->data;
                
//                     if(temp1->next!=NULL){
//                         temp1=temp1->next;
//                     }
//                     if(temp2->next!=NULL){
//                         temp2=temp2->next;
//                     }
//                 }
//                 else if(temp1->index>temp2->index){
//                     if(temp2->next!=NULL){
//                         temp2=temp2->next;
//                     }
//                     else{
//                         temp1=temp1->next;
//                     }
//                 }
//                 else if(temp2->index>temp1->index){
//                     if(temp1->next!=NULL){
//                         temp1=temp1->next;
//                     }
//                     else{
//                         temp2=temp2->next;
//                     }
//                 }
//             }
//             else{
//                 if(temp1->index==temp2->index){
//                 D[i][j]+=(temp1->data*temp2->data);
//             }
//             }
//             }
//         }
//     }
// }
//     for(int i=0;i<5;i++){
//     for(int j=0;j<5;j++){
//         cout<<D[i][j]<<" ";
//     }
//     cout<<endl;
// }
// }