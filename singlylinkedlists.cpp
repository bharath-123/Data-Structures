#include<iostream>
#include<stdio.h>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*head;
Node*tail(){
	Node*temp = head;
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	return temp;
}

Node*createnewnode(int data){
	Node*newNode = new Node;
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode; 
}
void insertfront(int x){
	Node*newNode = createnewnode(x);
	newNode -> next = head;
	head = newNode; 
	
}
void insertend(int x){
	Node*newNode = createnewnode(x);
	Node*temp1 = tail();
	temp1 -> next = newNode;	
}
void insertnode(int x,int n){
	Node*newNode = createnewnode(x);
	Node*temp = head;
	for(int i = 1 ; i < n - 1 ; i++ ){
		temp = temp -> next;
	}
	newNode -> next = temp -> next;
	temp -> next = newNode;
	
}
//using iteration//
int listlength1(){
	Node*temp = head;
	int count = 0;
	while(temp != NULL){
		count++;
		temp = temp -> next;
	}
	return count;
}
//using recursion//
int listlength2(Node*head){
	if(head == NULL){
		return 0;
	}
	else {
		return 1 + listlength2(head -> next);
	}
	
}
void delfront(){
	Node*temp;
	cout<<endl;
	cout<<head -> data <<" is deleted";
	temp = head;
	head = head -> next;
	delete temp;
	
}
void delend(){
	Node*temp1;
	Node*temp2 = head;
	while(temp2 -> next -> next != NULL ){
		temp2 = temp2 -> next;
	}
	temp1 = temp2 -> next;
	temp2 -> next = NULL;
	delete temp1;
}
void delnode(Node*temp,int n){
	Node*temp1 = temp;
	Node*temp2 = head;
	for(int i = 0 ; i < n - 1 ; i++){
		temp2 = temp2 -> next;
	}
	temp2 -> next = temp1 -> next;
	delete temp1;
	
}
void deln(int n){	
	Node*temp1 = head;
	for(int i = 0; i < n - 2 ;i++){
		temp1 = temp1 -> next;
	}
	Node*temp2 = temp1 -> next;
	temp1 -> next = temp2 -> next;
	delete temp2;
}
void delkey(int key){
	Node*temp1 = head;
	Node*temp2 = head -> next;
	if(temp1 != NULL && temp1 -> data == key){
		head = head -> next;
		delete temp1;
	}
	else{
		while( temp1 != NULL ){
			if(temp2 -> data == key){
				temp1 -> next = temp2 -> next;
				delete temp2;
			}
			else {
				temp1 = temp1 -> next;
				temp2 = temp2 -> next;
			}
			
			
		}
	}
	
	
}
void delpos(int n){
	Node*temp1 = head;
	Node*temp2 = head -> next;
	if(n == 1){
		head = head -> next;
		delete temp1;
	}
	else{
		for(int i = 0; i < n - 2;i++){
			temp1 = temp1 -> next;
			temp2 = temp2 -> next;
		}
		temp1 -> next = temp2 -> next;
		delete temp2; 
	}
}
void update(int x){
	Node*temp = head;
	while(temp != NULL){
		temp -> data = temp -> data + x;
		temp = temp -> next;
	}
}
//with iteration//
void reverse(){
	Node*current = head;
	Node*prev = NULL;
	Node*next;
	while(current != NULL){
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	head = current;
}
void rotate(int k ){
	
	for(int i = 0; i < k; i++){
	Node*t = tail();
	
	Node*temp1 = head;
	while(temp1 -> next -> next != NULL){
		temp1 = temp1 -> next;
	}
	t -> next = head;
	temp1 -> next = NULL;
	head = t;
}
}


void printlist(){
	Node*temp = head;
	if(head == NULL){
		cout<<"list is empty";
	}
	while(temp != NULL){
		cout<<temp -> data<<"->";
		temp = temp -> next;
	}
	
}
int main(){
	insertfront(1);
	insertfront(24);
	insertfront(23);
	insertfront(22);
	insertfront(32);
	insertfront(43);
	insertfront(53);
	printlist();
	reverse();
	cout<<endl;
	printlist();
	return 0;
}
