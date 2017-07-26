#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
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
