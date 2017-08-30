#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

struct Info{
	string id;
	int n;
}info[1001];
 

int main(){
	int N,a,b;
	string id;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		cin>>id>>a>>b;
		info[a].id = id;
		info[a].n = b;
	}
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		cin>>a;
		cout<<info[a].id<<" "<<info[a].n<<endl;
	}
	
	
	
	return 0;
}
