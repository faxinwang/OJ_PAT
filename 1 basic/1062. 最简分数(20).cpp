#include<iostream>
#include<cstdio>
using namespace std;

int GCD(int n,int m){
	return m==0?n:GCD(m,n%m);
}

int main(){
	int n1,m1,n2,m2,k;
	scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
	if(n1*m2 > n2*m1){
		swap(n1,n2);
		swap(m1,m2);
	}
	for(int i=1,flag=0; i<=k; ++i){
		if(GCD(k,i)==1){
			if(n1*k<i*m1 && i*m2<n2*k){
				if(flag==0){
					printf("%d/%d",i,k);
					flag = 1;
				}else{
					printf(" %d/%d",i,k);
				}
			}
		}
	}
	cout<<endl; 
	
	return 0;
}
