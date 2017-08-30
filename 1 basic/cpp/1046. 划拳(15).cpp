#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int a1,b1,a2,b2;
	int T,c1=0,c2=0;
	cin>>T;
	while(T--){
		scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		int sum = a1+a2;
		if(sum == b1 && sum!=b2) ++c2; //¼×win 
		if(sum == b2 && sum!=b1) ++c1; //ÒÒwin
	} 
	cout<<c1<<" "<<c2<<endl;
	
	return 0;
}
