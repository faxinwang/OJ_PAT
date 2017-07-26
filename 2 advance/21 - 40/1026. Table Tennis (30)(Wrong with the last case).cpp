#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<iterator>
#define maxn 10005
#define maxk 105
using namespace std;

/*
��Ŀ���⣺
ƹ������ֲ���N�������ṩ����������M����ΪVIP׼���ģ����Ͱ�����ʱ����Ƿ���VIP�Ŷ�
ʹ������.ÿ�����ֻ��ʹ��2Сʱ. 
�����������VIP������VIP���ӿɹ�ʹ�ã���VIP���Ȼ��VIP���ӵ�ʹ��Ȩ��
���û��VIP���ӣ���VIP������ͨ��һ�����з���.
���������û��VIP���������˿���ʹ��VIP���ӡ�

Ҫ��ͳ��ÿ���˵ĵȴ�ʱ���Լ�ÿ�������ķ����������

����˼·:
��һ��Table�����Customer����
����Ϊÿһ���˿Ͱ������ӣ�
����ȷ��һ��ʱ���timePointΪ��ǰҪ���ŵĹ˿͵�arriveTime����СfreeTime�еĽϴ�ֵ��
Ȼ���ҳ����дﵽʱ��С�ڵ��ڸ�ʱ���Ĺ˿� �� freeTimeС�ڵ��ڸ�ʱ������������
	�����vip�˿ͺ�vip���ӣ���vip�˿Ͱ��ŵ�id����С��vip������
	�������ȵ���Ĺ˿Ͱ��ŵ�id����С������(����vip����)

������˵�playTime����2Сʱ����Ҫ�ض� 
���timepoint���ڵ���End�����������. 

*/


struct Customer{
	int arriveTime,serveTime,playTime; //second
	bool tag;
};

struct Table{
	int freeTime; //�������ʱ�� second
	int served; //ͳ�Ƹ����������������
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
	return (sec+30)/60 ; //���ڵ���30���������� 
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
		cus[i].playTime = min(p * 60,7200); //�ض�ʹ��ʱ�� 
		cus[i].tag = isVip;
		cus[i].serveTime = INF;
	}
	sort(cus,cus+N,sort_by_arrive);
	int i,id;
	scanf("%d%d",&K,&M);
	//input M vip tables
	for(int i=1; i<=M; ++i){
		 scanf("%d", &id);
		 tab[id].tag = 1; // tab�����±�Ϊ��table��id 
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
