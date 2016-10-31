#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*next;
};
struct Q {
	Node*front,*rear;
};
Node*createnewnode(int data){
	Node*newNode = new Node;
	newNode -> data = data;
	newNode -> next = NULL;
	return newNode;
}
Q*createnewqueue(){
	Q*q = new Q;
	q -> front = q -> rear = NULL;
	return q;
}

Q*enqueue(Q*q,int data){
	Node*newNode = createnewnode(data);
	if(q -> front == NULL){
		q -> front = q -> rear = newNode;
		q -> rear = NULL;
	}
	else{
		q -> rear -> next = newNode;
	}
	q -> rear = newNode;
	return q;
}
Q*dequeue(Q*q){
	Node*temp = q -> front;
	if(q -> front == NULL){
		cout<<"The queue is empty";
	}
	else{
		q -> front = q -> front -> next;
	}
	delete temp;
	return q;
	
}
void display(Q*q){
	Node*temp = q -> front;
	if(q -> front == NULL){
		cout<<"The queue is empty";
	}
	else{
		while(temp != NULL){
			cout<<temp -> data<<"->";
			temp = temp -> next;
			
		}
	}
	cout<<endl;
}
int main(){
	Q*q = createnewqueue();
	q = enqueue(q,1);
	q = enqueue(q,2);
	q = enqueue(q,3);
	q = enqueue(q,4);
	q = enqueue(q,5);
	q = enqueue(q,6);
	display(q);
	cout<<q -> rear -> data<<endl;
	cout<<q -> front -> data<<endl;
	q = dequeue(q);
	display(q);
	
	return 0;
}
