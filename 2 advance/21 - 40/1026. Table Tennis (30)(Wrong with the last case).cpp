#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iterator>
#define maxn 10005
#define maxk 105
using namespace std;

/*
题目大意：
乒乓球俱乐部有N张球桌提供服务，其中有M张是为VIP准备的，来客按到达时间和是否是VIP排队
使用球桌.每次最多只能使用2小时. 
如果队列中有VIP并且有VIP桌子可供使用，则VIP优先获得VIP桌子的使用权，
如果没有VIP桌子，则VIP将和普通人一样进行分配.
如果队列中没有VIP，则其他人可以使用VIP桌子。

要求统计每个人的等待时间以及每张球桌的服务的人数。

解题思路:
开一个Table数组和Customer数组
依次为每一个顾客安排桌子：
首先确定一个时间点timePoint为当前要安排的顾客的arriveTime和最小freeTime中的较大值。
然后找出所有达到时间小于等于该时间点的顾客 和 freeTime小于等于该时间点的所有桌子
	如果有vip顾客和vip桌子，则将vip顾客安排到id号最小的vip桌子上
	否则将最先到达的顾客安排到id号最小的桌子(包括vip桌子)

如果有人的playTime大于2小时则需要截断 
如果timepoint大于等于End，则结束安排. 

*/


struct Customer{
	int arriveTime,serveTime,playTime; //second
	bool tag;
};

struct Table{
	int freeTime; //最早空闲时间 second
	int served; //统计该球桌服务过的人数
	int tag;
}; 

const int StartTime = 8 * 3600; //second
const int EndTime = 21 * 3600; //second
const int INF = 1<<30;
Customer cus[maxn];
Table tab[maxk];

bool sort_by_serve(const Customer& c1,const Customer&c2){
	if(c1.serveTime != c2.serveTime)
		return c1.serveTime < c2.serveTime;
	return c1.arriveTime < c2.arriveTime;
}
bool sort_by_arrive(const Customer& c1, const Customer &c2) {
	return c1.arriveTime < c2.arriveTime;
}

int update(Table& t,Customer& c){
	c.serveTime = max(t.freeTime,c.arriveTime);
	t.freeTime = c.serveTime + c.playTime;
	++t.served; 
	return t.freeTime;
}

inline int round(int sec){
	return (sec+30)/60 ; //大于等于30秒向上舍入 
}

ostream& operator<<(ostream& out, const Customer& c){
	printf("%02d:%02d:%02d %02d:%02d:%02d %d",
			c.arriveTime/3600, c.arriveTime%3600/60, c.arriveTime%60,
			c.serveTime/3600, c.serveTime%3600/60, c.serveTime%60,
			round(c.serveTime - c.arriveTime));
	return out;
}

int serving(int N,int K){
	int newFree;
	priority_queue<int, vector<int>, greater<int> > Q;
	for(int i=0; i<K; ++i) Q.push(StartTime);
	for(int i=0; i<N; ++i){
		if(cus[i].serveTime != INF) continue;
		int timePoint = max(Q.top(), cus[i].arriveTime);
		
		if(timePoint >= EndTime) return i;
		vector<int> c,t;
		for(int j=i;j<N && cus[j].arriveTime <= timePoint; ++j)
			if(cus[j].serveTime == INF) c.push_back(j);
		for(int j=1; j<=K; ++j) if(tab[j].freeTime <= timePoint) t.push_back(j);
		bool flag = false;
	
		for(int a=0; a<c.size() && !flag; ++a){
			if(cus[c[a]].tag == 1) for(int b=0; b<t.size(); ++b){
				if(tab[t[b]].tag == 1){
					flag = true;
					newFree = update(tab[t[b]], cus[c[a]]);
					break;
				}
			}
		}
			
		if(!flag) newFree = update(tab[t[0]],cus[c[0]]);
		--i;
		
		Q.pop();
		Q.push(newFree);
	}
	return N;
}


int main(){
#ifdef WFX
freopen("1026 in.txt","r",stdin);
#endif
	int N,K,M;
	int h,m,s,p,isVip;
	scanf("%d",&N);
	for(int i=0;i<N;++i){
		scanf("%d:%d:%d %d %d",&h,&m,&s,&p,&isVip);
		cus[i].arriveTime = h*3600 + m*60 + s;
		cus[i].playTime = min(p * 60,7200); //截断使用时间 
		cus[i].tag = isVip;
		cus[i].serveTime = INF;
	}
	sort(cus,cus+N,sort_by_arrive);
	int i,id;
	scanf("%d%d",&K,&M);
	//input M vip tables
	for(int i=1; i<=M; ++i){
		 scanf("%d", &id);
		 tab[id].tag = 1; // tab数组下标为该table的id 
	}
	for(int i=1;i<=K;++i) tab[i].freeTime = StartTime; //id num of tables in range [1,K]
	int n = serving(N,K); 
	sort(cus, cus+n, sort_by_serve);

	copy(cus,cus+n,ostream_iterator<Customer>(cout,"\n"));
	printf("%d",tab[1].served);
	for(int i=2;i<=K;++i) printf(" %d",tab[i].served);
	printf("\n");
	
	return 0;
} 
