#include<iostream>
using namespace std;


int step(int n){
	int s=0;
	while(n!=1){
		if(n%2==0) n/=2;
		else n=(3*n+1)/2;
		++s;
	}
	return s;
}

int main(){
	int n;
	cin>>n;
	cout<<step(n);
	
	return 0;
}
