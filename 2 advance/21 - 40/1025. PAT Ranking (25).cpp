#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
题目大意:
输入N个考场的考试考生成绩
每个考场K个人，每个人的信息为
ID Score
按如下格式输出所有人的总排名:
ID final_rank location_num local_rank 
输出顺序为：
先按分数非降序排序(分数相同的人 final_rank也相同)
再按ID号非降序排序
注意排序的时候如果当前人的分数与上一个人不同时，
该人的名次为他在列表中的序号而不是上一个人的名次+1 

解题思路:
先对每个考场局部排序，算出每个人的local_rank(结构体排序)
然后将所有人放到一起排序，得出每个人的final_rank(结构体排序) 
不必保存每个人的final_rank,可以在最后直接计算并输出. 
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
		//计算loc_rank 
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
