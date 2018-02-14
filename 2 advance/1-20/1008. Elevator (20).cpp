/*
1008. Elevator (20)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
The highest building in our city has only one elevator. A request list is made 
up with N positive numbers. The numbers denote at which floors the elevator 
will stop, in specified order. It costs 6 seconds to move the elevator up one 
floor, and 4 seconds to move down one floor. The elevator will stay for 5 
seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill 
the requests on the list. The elevator is on the 0th floor at the beginning 
and does not have to return to the ground floor when the requests are fulfilled.

Input Specification:
Each input file contains one test case. Each case contains a positive integer N, 
followed by N positive numbers. All the numbers in the input are less than 100.

Output Specification:
For each test case, print the total time on a single line.

Sample Input:
3 2 3 1

Sample Output:
41

��Ŀ���⣺ 
���������½�һ��ֱ���Ҫ6���4���ӵ�ʱ�䣬�����ͣ5���ӵ�ʱ�䣬�������ݵ����������
�ܹ�����Ҫ��ʱ�䡣

����˼·��ֱ��ģ�⡣ 

*/ 
#include<iostream>
#include<cstdio>
using namespace std;

int totalTime(int *a,int n){
	int time=0,curFloor=0;
	for(int i=0;i<n;++i){
		if(curFloor<a[i]){
			time+=6*(a[i]-curFloor);
		}else{
			time+=4*(curFloor-a[i]);
		}
		time+=5;
		curFloor=a[i];
	}
	return time;
}


int main(){
	int N;
	cin>>N;
	int *a = new int[N];
	for(int i=0;i<N;++i)
		scanf("%d",a+i);
	cout<<totalTime(a,N)<<endl;
	
	delete []a; 
	return 0;
}
