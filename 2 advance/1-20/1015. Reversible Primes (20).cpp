#include<iostream>
#include<cstdio>
#define Max 100005
using namespace std;

char pri[Max];
void init_pri(){
	pri[0] = pri[1] = 1;
	for(int i=2;i*i<=Max;++i)
		if(pri[i]==0)
			for(int j=i*i; j<=Max;j+=i)
				pri[j] = 1;
}

int reverse(int N,int d){
	int rev = 0;
	while(N){
		rev = rev*d + N % d;
		N /= d;
	}
	return rev;
}

int main(){
	int N,D; //N <= 10^5, 1<D<=10
	init_pri();
//	printPri();
	
	while(cin>>N){
		if(N<0) break;
		scanf("%d",&D);
		if(pri[N]==1){
			cout<<"No"<<endl;
			continue;
		}
		int rev = reverse(N,D);
		if(pri[rev] == 0){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}
