/*
1014. Waiting in Line (30)
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
Suppose a bank has N windows open for service. There is a yellow line in front of 
the windows which devides the waiting area into two parts. The rules for the 
customers to wait in line are:

1. The space inside the yellow line in front of each window is enough to contain 
a line with M customers. Hence when all the N lines are full, all the customers 
after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.

2. Each customer will choose the shortest line to wait in when crossing the yellow line. 
If there are two or more lines with the same length, the customer will always 
choose the window with the smallest number. 

3. Customer[i] will take T[i] minutes to have his/her transaction processed. 

4. The first N customers are assumed to be served at 8:00am.

Now given the processing time of each customer, you are supposed to tell the exact 
time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 custmers 
waiting inside the yellow line. There are 5 customers waiting with transactions 
taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer1 
is served at window1 while customer2 is served at window2. Customer3 will wait 
in front of window1 and customer4 will wait in front of window2. Customer5 will 
wait behind the yellow line.

At 08:01, customer1 is done and customer5 enters the line in front of window1 since 
that line seems shorter now. Customer2 will leave at 08:02, customer4 at 08:06, 
customer3 at 08:07, and finally customer5 at 08:10.

Input
Each input file contains one test case. Each case starts with a line containing 
4 positive integers: N (<=20, number of windows), M (<=10, the maximum capacity 
of each line inside the yellow line), K (<=1000, number of customers), and Q (<=1000, 
number of customer queries).
The next line contains K positive integers, which are the processing time of the K customers.
The last line contains Q positive integers, which represent the customers who are asking 
about the time they can have their transactions done. The customers are numbered from 1 to K.

Output
For each of the Q customers, print in one line the time at which his/her transaction is 
finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that 
since the bank is closed everyday after 17:00, for those customers who cannot be served 
before 17:00, you must output "Sorry" instead.

Sample Input
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7

Sample Output
08:07
08:06
08:10
17:00
Sorry

��Ŀ���⣺
���д�8:00�㿪ʼ�ϰ࣬17:00�°࣬������N�������ṩ�����ָ���ÿ���˵ĵ���ʱ���
����Ҫ�ķ���ʱ�䣬��ÿ������ɷ����뿪��ʱ�䡣

����˼·�� 
�������¼ÿ�����ڵĿ���ʱ�䣬ÿ��һ���˿;ͽ��ù˿�"����"������ʱ������Ĵ����ϣ�
���øù˿�����Ҫ�ķ���ʱ���ۼӵ��ô����������¸ô��ڵĿ���ʱ�䡣���º�Ŀ���ʱ��
��Ϊ�ù˿��뿪��ʱ�䡣
*/ 
#include<iostream>
#include<cstdio> 
#include<queue>
#define MAX 1001
using namespace std;

int processTime[MAX];
int leaveTime[MAX];
int timeBase[20+1]={0};
queue<int> que[20+1];
int endTime=60*9;//there is 9 hours from 8:00 to 17:00


int main(){
	int N,M,K,Q;// num of window,capacity of line,customers,num of querys
	cin>>N>>M>>K>>Q;
	for(int i=0;i<K;++i)
		scanf("%d",processTime+i);
	int cur=0;
	for(int i=0;cur < N*M && cur<K; ++cur){
		que[i].push(cur);
		leaveTime[cur]=timeBase[i]+processTime[cur];
		timeBase[i]=leaveTime[cur];
		i=(i+1)%N;
	}
	for(int min;cur<K;++cur){
		//find earliest leave customer
		int min_wait=0xfffffff;
		for(int i=0;i<N;++i){
			int cus=que[i].front();
			if(min_wait>leaveTime[cus]){
				min_wait=leaveTime[cus];
				min=i;
			}
		}
		que[min].pop();
		que[min].push(cur);
		leaveTime[cur]=timeBase[min]+processTime[cur];
		timeBase[min]=leaveTime[cur];
	}
	while(Q--){
		int query;
		scanf("%d",&query);
		--query;
		if(leaveTime[query]-processTime[query] >= endTime){
			cout<<"Sorry"<<endl;
		}
		else{
			int h=leaveTime[query]/60;
			int m=leaveTime[query]%60;
			printf("%02d:%02d\n",h+8,m);
		}
	}
	
	return 0;
}
