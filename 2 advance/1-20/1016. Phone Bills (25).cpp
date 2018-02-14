/*
1016. Phone Bills (25)
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
A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the 
time of day when the call is made. When a customer starts connecting a long-distance 
call, the time will be recorded, and so will be the time when the customer hangs up 
the phone. Every calendar month, a bill is sent to the customer for each minute 
called (at a rate determined by the time of day). Your job is to prepare the bills 
for each month, given a set of phone call records.

Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure,
and the phone call records. The rate structure consists of a line with 24 non-negative 
integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, 
and so on for each hour in the day. The next line contains a positive number N (<= 1000), 
followed by N lines of records. Each phone call record consists of the name of the 
customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), 
and the word "on-line" or "off-line". For each test case, all dates will be within a 
single month. Each "on-line" record is paired with the chronologically next record for 
the same customer provided it is an "off-line" record. Any "on-line" records that are 
not paired with an "off-line" record are ignored, as are "off-line" records not paired 
with an "on-line" record. It is guaranteed that at least one call is well paired in the 
input. You may assume that no two records for the same customer have the same time. 
Times are recorded using a 24-hour clock.

Output Specification:
For each test case, you must print a phone bill for each customer.
Bills must be printed in alphabetical order of customers' names. For each customer, first 
print in a line the name of the customer and the month of the bill in the format shown by 
the sample. Then for each time period of a call, print in one line the beginning and ending 
time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The 
calls must be listed in chronological order. Finally, print the total charge for the 
month in the format shown by the sample.

Sample Input:
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line

Sample Output:
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80

��Ŀ���⣺
ĳͨ�Ź�˾�Ļ��Ѱ����ӼƷѣ�ÿ��24Сʱ�ļ۸������ͬ�����ڸ���һ���˵�ͨ����¼��
����������ͨ���·ݣ���ʼʱ��(ʱ����)�ͽ���ʱ�䣬��ÿ���˵����˵���

����˼·�� 
1.��ÿ��ʱ:��:�� ��ʽ��ʱ��ת��Ϊ�Է���Ϊ��λ��ʱ�䡣 
2.ʹ��map<string,vector<Call> > ���ݽṹ���������˵�ͨ����¼��key��ͨ���ߵ�����
3.����ÿһ��ͨ���Ļ���ʱ�����ô��³���ʼ��ͨ����������ķ��ü�ȥ���³���ʼ��ͨ��
  ��ʼ���ʱ�������ͨ�����á�
*/ 
#include<bits/stdc++.h>
using namespace std;

int toll[24];

//����PhoneCall��¼ 
struct Call{
	int dd,hh,mm,time;
	string flag;
	//time������³�����ǰʱ�̵ķ����� 
	Call(int d,int h,int m,string f):dd(d),hh(h),mm(m),flag(f){
		time = d*24*60 + h*60 + m;
	}
	bool operator<(const Call& call)const{
		return time<call.time;
	}
};

//���ش��³���ʼ����Ļ����ܶ� 
double chargeByTime(Call& c){
	double fee = 0;
	double feePerDay = 0;
	for(int h=0;h<24; ++h) feePerDay += toll[h]*60;
	fee += feePerDay * c.dd;
	for(int h=0;h<c.hh; ++h) fee += toll[h]*60;
	fee += toll[c.hh]*c.mm;
	return fee;
}

//�����s��e�Ļ��Ѷ�� 
double Fee(Call& s, Call& e){
	return (chargeByTime(e) - chargeByTime(s)) / 100;
}


int main(){
#ifdef WFX
freopen("1016 in.txt","r",stdin);
#endif 
	string name,flag;
	map<string,vector<Call> > mp;
	int N,mon,d,h,m;
	for(int i=0;i<24;++i) scanf("%d",toll+i);
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		cin>>name;
		scanf("%d:%d:%d:%d",&mon,&d,&h,&m);
		cin>>flag;
		mp[name].push_back(Call(d,h,m,flag));
	}
	map<string,vector<Call> >::iterator pos;
	for(pos=mp.begin(); pos!=mp.end(); ++pos){
		vector<Call> &v = pos->second;
		sort(v.begin(),v.end());
		vector<Call> v2;
		//���ҳ����кϷ��ļ�¼ 
		for(int i=0,len=v.size()-1; i<len;++i){
			if(v[i].flag=="on-line" && v[i+1].flag=="off-line"){
				v2.push_back(v[i]);
				v2.push_back(v[i+1]);
				++i; 
			}
		}
		//����Ϸ���¼��Ϊ�� 
		if(v2.size()){
			//����������·� 
			printf("%s %02d\n",pos->first.c_str(), mon);
			double sum=0,fee;
			for(int i=0,len=v2.size()-1; i<len;i+=2){
				int diff = v2[i+1].time - v2[i].time;//ͨ�������� 
				fee = Fee(v2[i],v2[i+1]); //�ñ�ͨ������ 
				sum += fee;
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",
					v2[i].dd, v2[i].hh, v2[i].mm, 
					v2[i+1].dd, v2[i+1].hh, v2[i+1].mm,diff,fee);
			}
			printf("Total amount: $%.2lf\n",sum);
		}
	}
	
	return 0;
}
