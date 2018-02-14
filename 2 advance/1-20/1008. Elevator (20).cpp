/*
1008. Elevator (20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
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

题目大意： 
电梯上升下降一层分别需要6秒和4秒钟的时间，到达后停5秒钟的时间，给定电梯的升降情况，
总共所需要的时间。

解题思路：直接模拟。 

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
