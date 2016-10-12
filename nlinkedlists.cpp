#include<iostream>
using namespace std;
struct Node{
	int data;
	Node*next;
};
Node*createnewnode(int data){
	Node*temp = new Node;
	temp -> data = data;
	temp -> next = NULL;
	return temp;
}
Node*insertfront(Node*head,int x){
	Node*temp = createnewnode(x);
	temp -> next = head;
	head = temp;
	return head;
}
int listlength(Node*head){
	int count = 0;
	Node*temp = head;
	while(head != NULL){
		count++;
		temp = temp -> next;
	}
	return count;
}
void printlist(Node*head){
	Node*temp = head;
	while(temp  != NULL){
		cout<<temp -> data <<"->";
		temp = temp -> next;
	}
}
int main(){
	Node*headA = NULL;Node*headB = NULL;
	for(int i = 0; i < 5; i++){
		int x;
		cout<<"enter the "<<i + 1 <<" of the first list";
		cin>>x;
		headA = insertfront(headA,x);
	}
	for(int j = 0; j < 3; j++){
		int a;
		cout<<"enter the "<<j + 1<<" of the second list";
		cin>>a;
		headB = insertfront(headB,a);
	}
	cout<<"the first list is ";
	printlist(headA);
	cout<<endl;
	cout<<"the second list is ";
	printlist(headB);
	
	
	return 0;
}
