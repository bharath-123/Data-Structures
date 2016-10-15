#include<iostream>
using namespace std;
int top = -1;
void push(int a[],int x){
	top = top + 1;
	a[top] = x;
}
void pop(int a[]){
	top = top - 1;
}
void isempty(int a[]){
	if(top == -1){
		cout<<"The stack is empty";
	}
	else{
		cout<<"The stack is not empty";
	}
}

void displaystack(int a[]){
	for(int i = 0; i < top + 1 ; i ++){
		cout<<a[i]<<" ";
	}
}

int main(){
	
	
	
	return 0;
}





