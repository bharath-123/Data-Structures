#include<iostream>
#include<cstdio>
using namespace std;
struct Node{
	int data;
	Node*next,*prev;
};
Node*createnewnode(int data){
	Node*newNode = new Node;
	newNode -> data = data;
	newNode -> next = newNode -> prev = NULL;
	return newNode;
}
Node*tail(Node*head){
	Node*temp = head;
	while(temp != NULL){
		temp = temp -> next;
	}
	return temp;
}
Node*insertfront(Node*head,int data){
	Node*newNode = createnewnode(data);
	if(head == NULL){
		head = newNode;
		return head;
	}
	else{
		newNode -> next = head;
		head = newNode;
		newNode -> prev = NULL;
		return head;
	}
}
Node*insertend(Node*head,int data){
	Node*newNode = createnewnode(data);
	Node*temp = head;
	if(head == NULL){
		head = newNode;
		return head;
	}
	while(temp -> next != NULL){
		temp = temp ->  next;
	}
	newNode -> next = NULL;
	newNode -> prev = temp;
	temp -> next = newNode;
	return head;
	
}

Node*insertnode(Node*head,int n,int data){
	Node*newNode = createnewnode(data);
	Node*temp1 = head;
	Node*temp2 = head -> next;
	if(head == NULL){
		head = newNode;
		return head;
	}
	else{
	
	for(int i = 0; i < n - 2; i++){
		temp1 = temp1 -> next;
		temp2 = temp2 -> next;
	}
	temp1 -> next = newNode;
	newNode -> prev = temp1;
	newNode -> next = temp2;
	temp2 -> prev = newNode;
	return head;
}
}
Node*delfront(Node*head){
	Node*temp = head;
	head = head -> next;
	head -> prev = NULL;
	delete temp;
	return head;
}
Node*delend(Node*head){
	Node*temp = head;
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	temp -> prev -> next = NULL;
	delete temp;
	return head;
	
}
Node*delnode(Node*head ,int n){
	Node*temp1 = head;
	for(int i = 0; i < n - 1 ; i++){
		temp1 = temp1 -> next;
	}
	temp1 -> prev -> next = temp1 -> next;
	temp1 -> next -> prev = temp1 -> prev;
	delete temp1;
	return head;
	
}
void reverse(Node*head){
	Node*temp1 =  head;
	Node*temp2 = head -> next;
	if(head == NULL)
	return ;
	else{
		
	}
	while(temp2 != NULL){
		
	}
}
void printlist(Node*head){
	Node*temp = head;
	while(temp != NULL){
		cout<<temp -> data <<"<-->";
		temp = temp -> next;
	}
}

int main(){
	Node*headA = NULL;
	
	headA = insertfront(headA,1);
	headA = insertfront(headA,2);
	headA = insertfront(headA,3);
	headA = insertfront(headA,4);
	headA = insertfront(headA,5);
	headA = insertend(headA,6);
	headA = insertnode(headA,2,7);
	printlist(headA);
	cout<<endl;
	reverse(headA);
	cout<<endl;
	printlist(headA);
	
	
	return 0;
}
