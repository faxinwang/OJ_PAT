#include<cstdio>
#include<iostream>
using namespace std;

int main(){
	int c1,c2,t;
	scanf("%d%d",&c1,&c2);
	t = c2-c1;
	int h,m,s;
	int CLK_TCK = 100;
	
	h = t / CLK_TCK / 3600;
	t -= h * CLK_TCK * 3600;
	
	m = t / CLK_TCK / 60;
	t -= m * CLK_TCK * 60;
	
	double tmp = 1.0*t/	CLK_TCK;
//	cout<<tmp<<endl;
	s = int(tmp + 0.5);	//ËÄÉáÎåÈë 
	
	printf("%02d:%02d:%02d",h,m,s);
	
	return 0;
}
