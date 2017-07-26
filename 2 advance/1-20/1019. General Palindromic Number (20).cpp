#include<iostream>  
using namespace std;
const int maxn = 1e8+1;

int a[maxn];

void print(int k){
	printf("%d",a[k-1]);
	for(int i=k-2;i>0; --i){
		printf(" %d",a[i]);
	}
}

int main(){
	int N,b,k=1;
	cin>>N>>b;
	
	while(N){
		a[k++] = N % b;
		N /= b;
	}
	bool flag = 0;
	for(int i=1,len=k/2; i<=len; ++i){
		if(a[i] != a[k-i]){
			flag = 1;
			break;
		}
	}
	if(flag==0){
		cout<<"Yes"<<endl;
		print(k) ;
	}else{
		cout<<"No"<<endl; 
		print(k) ;
	}
	
	return 0;
}
