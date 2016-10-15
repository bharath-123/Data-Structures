#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*createnewnode(int x){
	Node*newNode = new Node;
	newNode -> data = x;
	newNode -> next = NULL;
	return newNode;
}
Node*push(Node*top,int x){
	Node*newNode = createnewnode(x);
	newNode -> next = top;
	top = newNode;
	return top;
}
Node*pop(Node*top){
	if(top == NULL){
		return top;
	}
	else{
	Node*temp = top;
	top = top -> next;
	delete temp;
	return top;
	
}
}
void isempty(Node*top){
	if(top == NULL){
		cout<<"the stack is empty";
	}
	else{
		cout<<"the stack is not empty";
	}
}
void printstack(Node*top){
	Node*temp = top;
	while(temp  != NULL){
		cout<<temp -> data<<" ";
		temp = temp -> next;
	}
}
int main(){
	Node*top = NULL;
	top = push(top,1);
	top = push(top,2);
	top = push(top,3);
	top = push(top,4);
	top = push(top,5);
	top = push(top,6);
	printstack(top);
	cout<<endl;
	top = pop(top);
	printstack(top);
	
	return 0;
}

