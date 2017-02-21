#include <iostream>

using namespace std;

struct node{
int data;
node *next;
};

class List{
node* head;
public:
List(int a){
head=new node;
head->data=a;
head->next=NULL;
}
void push_data (int data){
if (head!=NULL){
node* temp=head;
while (temp->data!=data && temp!=NULL){
temp=temp->next;
}
node* tmp=new node;
tmp->data=data;
temp->next->data=tmp->data;
tmp->next=temp->next->next;
temp->next=tmp;
}
}
void set (int i, int a){
if (head!=NULL){
node* temp=head;
for (int j=1; j<=i; j++){
temp=temp->next;
}
temp->data=a;
}
}
int get(int i){
if (head!=NULL){
int a;
node* temp=head;
for (int j=1; j<=i; j++){
temp=temp->next;
}
a=temp->data;
return a;
}
}
void push_head (int a){
if (head!=NULL){
node* temp=new node;
temp->data=a;
temp->next=head;
head=temp;
}
}
void push_back (int a){
if (head!=NULL){
node* temp=new node;
while (temp->next!=NULL){
temp=temp->next;
}
temp->next->data=a;
temp->next->next=NULL;
}
}
int delete_back (){
if (head!=NULL){
if (head->next==NULL){
int a=head->data;
delete head;
return a;
}
node* temp=head;
while (temp->next->next!=NULL){
temp=temp->next;
}
int a=temp->next->data;
delete temp->next;
temp->next=NULL;
return a;
}
}
int delete_head (){
if (head!=NULL){
node* temp=head;
head=temp->next;
int a=temp->data;
delete temp;
return a;
}
}
~List(){
while (head!=NULL){
node* temp=head;
head=head->next;
delete temp;
}
}
};


int main(){
List L(31);
L.push_back(15);
L.push_head(4);
cout�L.get(2)�endl;
L.set(2, 8);
cout�L.get(2)�endl;
cout�L.delete_head();
return 0;
}
