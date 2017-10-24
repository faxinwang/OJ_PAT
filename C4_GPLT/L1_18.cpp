#include<iostream>
#include<cstdio>
using namespace std;

void Dang(int& h,int& m){
	if(h>=0 && h < 12){
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
		return;
	}
	if(h==12 && m==0){
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
		return;
	}
	int count=h-12;
	if(m) ++count;
	while(count--){
		printf("Dang");
	}
}

int main(){
	int hh,mm;
	scanf("%d:%d",&hh,&mm);
	Dang(hh,mm);
	
	return 0;
}
