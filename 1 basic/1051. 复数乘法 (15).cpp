#include<iostream>
#include<cstdio>
#include<cmath>
#define Precision 0.01
using namespace std;

int main(){
	double r1,p1,r2,p2;
	cin>>r1>>p1>>r2>>p2; 
	double a = r1*r2*cos(p1+p2);
	double b = r1*r2*sin(p1+p2);
	if(fabs(a)<Precision) a = 0;
	if(fabs(b)<Precision) b = 0;
	if(b<0){
		printf("%.2lf%.2lfi\n",a,b);
	}else{
		printf("%.2lf+%.2lfi\n",a,b);
	}
	
	return 0;
}
