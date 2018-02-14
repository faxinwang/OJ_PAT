/*
1025. PAT Ranking (25)
ʱ������
200 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
Programming Ability Test (PAT) is organized by the College of Computer Science and 
Technology of Zhejiang University. Each test is supposed to run simultaneously in 
several places, and the ranklists will be merged immediately after the test. Now 
it is your job to write a program to correctly merge all the ranklists and generate 
the final rank.

Input Specification:
Each input file contains one test case. For each case, the first line contains a 
positive number N (<=100), the number of test locations. Then N ranklists follow, 
each starts with a line containing a positive integer K (<=300), the number of testees, 
and then K lines containing the registration number (a 13-digit number) and the total 
score of each testee. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees. Then print 
the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing 
order of the final ranks. The testees with the same score must have the same rank, 
and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4

��Ŀ����:
����N�������Ŀ��Կ����ɼ�
ÿ������K���ˣ�ÿ���˵���ϢΪ
ID Score
�����¸�ʽ��������˵�������:
ID final_rank location_num local_rank 
���˳��Ϊ��
�Ȱ������ǽ�������(������ͬ���� final_rankҲ��ͬ)
�ٰ�ID�ŷǽ�������
ע�������ʱ�������ǰ�˵ķ�������һ���˲�ͬʱ��
���˵�����Ϊ�����б��е���Ŷ�������һ���˵�����+1 

����˼·:
�ȶ�ÿ�������ֲ��������ÿ���˵�local_rank(�ṹ������)
Ȼ�������˷ŵ�һ�����򣬵ó�ÿ���˵�final_rank(�ṹ������) 
���ر���ÿ���˵�final_rank,���������ֱ�Ӽ��㲢���. 

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


struct Testee{
	string id;
	int score;
	int loc;
	int loc_rank;
	Testee(string id,int score,int loc):id(id),score(score),loc(loc){}
	bool operator>(const Testee& t)const{
		if(score != t.score) return score >= t.score; //nondecreasing order
		return id <= t.id; //nondecreasing order
	}
};

vector<Testee> loc;
vector<Testee> all;

int main(){
#ifdef WFX
freopen("1025 in.txt","r",stdin);
#endif
	int N,K;
	char id[15];
	int sc;
	scanf("%d",&N);
	for(int i=1;i<=N;++i){
		scanf("%d",&K);
		loc.clear();
		loc.reserve(K);
		for(int j=0; j<K; ++j){
			scanf("%s%d",id,&sc);
			loc.push_back(Testee(id,sc,i));
		}
		sort(loc.begin(),loc.end(),greater<Testee>()); //local sort
		//����loc_rank 
		int rank=1;
		loc[0].loc_rank = 1;
		for(int j=1; j<K; ++j){
			if(loc[j].score != loc[j-1].score) rank = j+1;
			loc[j].loc_rank = rank;
		}
		for(int j=0; j<K; ++j) all.push_back(loc[j]);
	}
	sort(all.begin(),all.end(),greater<Testee>()); //global sort
	int rank = 1;
	printf("%d\n",all.size());
	printf("%s %d %d %d\n",&all[0].id[0], 1 ,all[0].loc, all[0].loc_rank);
	for(int i=1,n=all.size(); i<n; ++i){
		if(all[i].score != all[i-1].score) rank=i+1; 
		printf("%s %d %d %d\n",&all[i].id[0], rank, all[i].loc, all[i].loc_rank);
	}
	
	return 0;
}
