#include<iostream>
using namespace std;
int front = -1,rear = -1;
void enqueue(int q[],int x,int *rear){
	*rear = *rear + 1;
	q[*rear] = x;
}
void dequeue(int q[],int *front){
	q[*front] = 0;
	*front = *front + 1;
}
int getfrontelement(int q[],int *front){
	return q[*front];
}
void displayqueue(int q[],int *rear,int *front){
	int n = *rear - *front;
	for(int i = 0 ; i < n; i++){
		cout<<q[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int a[1000];
	enqueue(a,1,&rear);
	enqueue(a,2,&rear);
	enqueue(a,3,&rear);
	enqueue(a,4,&rear);
	enqueue(a,5,&rear);
	enqueue(a,6,&rear);
	displayqueue(a,&rear,&front);
	dequeue(a,&front);
	displayqueue(a,&rear,&front);
	return 0;
}

