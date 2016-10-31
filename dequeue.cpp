#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*next,*prev;
};
struct Q {
	Node*front,*rear;
};
Node*createnewnode(int data){
	Node*newNode = new Node;
	newNode -> data = data;
	newNode -> next = NULL;
	newNode -> prev = NULL;
	return newNode;
}
Q*createnewqueue(){
	Q*q = new Q;
	q -> front = q -> rear = NULL;
	return q;
}
Q*enqueuerear(Q*q,int data){
	Node*newNode = createnewnode(data);
	if(q -> front == NULL){
		q ->  front = q -> rear = newNode;
	}
	else{
		q -> rear -> next = newNode;
		newNode -> prev = q -> rear;
		q -> rear = newNode;
	}
	
	return q;
}
Q*enqueuefront(Q*q,int data){
	Node*newNode = createnewnode(data);
	if( q -> front == NULL){
		q -> front = newNode;
	}
	else{
		newNode -> next = q -> front;
		q -> front = newNode;
		
	}
	
	return q;
}
Q*delfront(Q*q){
	Node*temp = q -> front;
	if(temp == NULL){
		return 0 ;
	}
	else{
		q -> front = q -> front -> next;
		
		delete temp;
		
	}
	return q;
}
Q*delrear(Q*q){
	Node*temp = q -> rear;
	if(q -> rear  == NULL){
		return 0;
	}
	else{
		q -> rear = q -> rear -> prev;
		q -> rear -> next = NULL;
		delete temp;
	}
	return q;
}
int getfront(Q*q){
	return q -> front -> data;
}
int getrear(Q*q){
	return q -> rear -> data;
}
void display(Q*q){
	Node*temp = q -> front;
	if(q -> front == NULL){
		cout<<"The queue is empty";
	}
	else{
		while(temp != NULL){
			cout<<temp -> data<<"<-->";
			temp = temp -> next;
			
		}
	}
	cout<<endl;
}
int main(){
	Q*q = createnewqueue();
	q = enqueuerear(q,1);
	q = enqueuerear(q,2);
	q = enqueuerear(q,3);
	q = enqueuerear(q,4);
	q = enqueuerear(q,5);
	q = enqueuerear(q,6);
	q = enqueuerear(q,7);
	q = enqueuerear(q,100);
	q = enqueuerear(q,10);
	display(q);
	q = enqueuefront(q,33);
	display(q);
	q = delfront(q);
	display(q);
	q = delrear(q);
	display(q);	
	cout<<getfront(q)<<" "<<getrear(q);
	return 0;
}
