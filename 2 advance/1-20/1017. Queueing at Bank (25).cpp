/*
1017. Queueing at Bank (25)
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
Suppose a bank has K windows open for service. There is a yellow line in front of 
the windows which devides the waiting area into two parts. All the customers have 
to wait in line behind the yellow line, until it is his/her turn to be served and 
there is a window available. It is assumed that no window can be occupied by a single 
customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are 
supposed to tell the average waiting time of all the customers.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 
numbers: N (<=10000) - the total number of customers, and K (<=100) - the number of 
windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, 
and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], 
MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.
Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait 
in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served 
nor counted into the average.

Output Specification:
For each test case, print in one line the average waiting time of all the customers, 
in minutes and accurate up to 1 decimal place.

Sample Input:
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10

Sample Output:
8.2

��Ŀ���⣺
������K�������ṩ����ÿ���˿��ڽ��ܷ���ǰ�������ڻ�������ȴ���ÿ���˿͵�
����ʱ�䲻�ܳ���һСʱ���ָ��������˵ĵ���ʱ�����Ҫ�����ʱ�䳤�ȣ�������
ƽ���ȴ�ʱ�䡣 

����˼·�� 
ʹ������w[i]��ʾ��i�����ڵĿ���ʱ��(����Ϊ��λ)����ʼֵ��Ϊ8*3600(s)
Ȼ�����custom���в����޸�����wԪ�ص�ֵ,ֱ��17����ǰ�Ŀͻ����������Ϊֹ��
���޸�w[]����Ĺ����м����ۼƹ˿��ܵĵȴ�ʱ��:
//min is the index of min(w[i]) 
if(cus.arrive > w[min] ) {
	waitTime += cus.arrive - w[min]; 
	w[min] += cus.process;
}
else{
	w[min] = cus.arrive + cus.process;
}
*/
#include<iostream> 
#include<algorithm>
#define maxn 10005
using namespace std;

struct Cus{
	int arrive,process;
	bool operator<(const Cus& c)const{
		return arrive < c.arrive;
	}
};
Cus a[maxn];
int w[105], sum;//total second

int main(){
#ifdef WFX
freopen("1017 in.txt","r",stdin);
#endif
	int n,k,i;
	int h,m,s,p;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i){
		scanf("%d:%d:%d %d",&h,&m,&s,&p);
		a[i].arrive = h*3600 + m * 60 + s;
		a[i].process = p*60;
	}
	sort(a,a+n);
	for(i=0; i<k; ++i) w[i]  = 8*3600; //�������ڵĿ���ʱ����Ϊ8���� 

	int end = 17*3600;//�°�ʱ�� 
	for(i=0; i<n && a[i].arrive <= end ;++i){
		int min = 0;
		 //�ҵ�������������Ĵ���
		for(int j=1;j<k;++j) if(w[j]<w[min]) min = j; 
		if(w[min] <= a[i].arrive){ //���ڿ���ʱ��С�ڵ��ڹ˿͵���ʱ��,����ȴ� 
			w[min] = a[i].arrive + a[i].process; //���´��ڵĿ���ʱ�� 
		}else{ //���ڿ���ʱ����ڹ˿͵���ʱ�䣬��Ҫ�ȴ� 
			sum += w[min] - a[i].arrive; //�ȴ�ʱ��Ϊ���ڿ���������ʱ�̼�����ʱ�� 
			w[min] += a[i].process; //���´��ڵĿ���ʱ�� 
		}
	}
	printf("%.1lf\n",1.0*sum/60/i);
	
	return 0;
}
