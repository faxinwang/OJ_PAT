#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
	int a[31]={0};//a[i]保存2*i-1行需要的字符数 
	for(int i=1;i<=23;++i){
		int an = i + i*(i-1);
		a[i] = (2 * an) - 1;
	}

	int N,line=1;
	char ch;
	cin>>N>>ch;
	while(a[line]<N) ++line;//找到最大的行数 
	--line;
	if(N<=1){
		printf("%c\n0",ch);
		return 0;
	}
	
	//打印沙漏 
	for(int i=-(line-1);i<line;++i){
		for(int j=1;j<line-abs(i);++j)
			printf(" ");
		for(int k=1;k<=2*abs(i)+1;++k)
			printf("%c",ch);
		printf("\n");
	}
	printf("%d\n",N-a[line]);
	
	return 0;
}
