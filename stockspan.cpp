#include<iostream>
#include<stack>
using namespace std;
int ar[100000];
int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i = 0 ;i < n; i++){
			cin>>ar[i];
		}
		int*span = new int[n];
		stack<int> st;
		st.push(0);
		span[0] = 1;
		for(int j = 1;  j < n; j++ ){
			while(!st.empty() && ar[j] >= ar[st.top()]){
				st.pop();
			}
			if(st.empty()){
				span[j]= j + 1;
			}
			else{
				span[j] = j - st.top();
			}
			st.push(j);
		}
	for(int k = 0 ; k < n; k++){
		cout<<span[k]<<" ";
	}
	}
	
	
	return 0;
}
