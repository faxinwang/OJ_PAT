#include<iostream>
#include<cstdio>
using namespace std;

int s[1001];

int main(){
	int a,b,c;
	int N,max=0;
	scanf("%d",&N);
	for(int i=0; i<N; ++i){
		scanf("%d-%d %d",&a,&b,&c);
		s[a] += c;
		if(s[a] > s[max]) max = a;
	}
	cout<<max<<" "<<s[max]<<endl;
	
	return 0;
}
