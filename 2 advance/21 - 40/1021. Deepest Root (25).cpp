/*
1021. Deepest Root (25)
ʱ������
1500 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
A graph which is connected and acyclic can be considered a tree. The height of the tree 
depends on the selected root. Now you are supposed to find the root that results in a 
highest tree. Such a root is called the deepest root.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive 
integer N (<=10000) which is the number of nodes, and hence the nodes are numbered from 
1 to N. Then N-1 lines follow, each describes an edge by given the two adjacent nodes' numbers.

Output Specification:
For each test case, print each of the deepest roots in a line. If such a root is not unique, 
print them in increasing order of their numbers. In case that the given graph is not a tree, 
print "Error: K components" where K is the number of connected components in the graph.

Sample Input 1:
5
1 2
1 3
1 4
2 5

Sample Output 1:
3
4
5

Sample Input 2:
5
1 3
1 4
2 5
3 4

Sample Output 2:
Error: 2 components


��Ŀ���⣺
һ�������޻�ͼ���Կ�����һ���������ĸ߶�ȡ����ѡ����һ��������Ϊ���ڵ㡣
���ڸ����������޻�ͼ���ҳ�ͼ���ܵ������߶���ߵ����ж��㣬������������� 

����˼·:
����������ͼ����������ҵ���һ�����·������·���������˵㶼�Ƿ�������ĵ㡣 
���ڸ�����ͼ�ı�ֻ��N-1�����Ƚ��٣�����ʹ���ڽӾ�����á�
��ȷ����ͨ����������1���󣬾Ϳ���ȷ��ͼ��û�л�(��Ϊֻ��N-1����)
ʹ��DFS���·�����ȣ����������һ������Ϊ��㿪ʼdfs�����ҵ�����Զ
�㱣���ڼ���s1�С�Ȼ����s1�����һ����p��Ϊ�������ͬ����DFS�����������
�ĵ���������p����˸�����·����������˻�����Щ���滻��s1�еĵ㡣 
���ǣ���������������� 
5
1 2
1 3
2 4
2 5
�����1Ϊ��㿪ʼ�ң����ҵ�s1={4,5},Ȼ������4����5���ҵ�����Զ�ĵ㶼��3��
��������4(��5)���յ�3�滻��s1�����Ԫ��,�õ��Ľ������{3,4}��{3,5};
Ȼ��ʵ�ʽ��Ӧ����{3,4,5},������ȷ�Ĵ�Ӧ��������dfs�ѵ��ĵ�Ĳ�����
*/

#include<iostream>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<iterator>
#define maxn 10005
using namespace std;

vector<int> g[maxn];
int vis[maxn];
int pre[maxn];
int N,cnt,maxLen=0;
set<int> s,res;

void dfs(int u,int len){
	vector<int>& ui = g[u];
	for(int i=0;i<ui.size();++i){
		if(!vis[ui[i]]){
			vis[ui[i]] = 1;
			dfs(ui[i],len+1);
			vis[ui[i]] = 0;
		}
	}
	
	if(len > maxLen){
		maxLen = len;
		s.clear();
		s.insert(u);
	}else if(len==maxLen){
		s.insert(u);
	}
}


int find(int x){
	if(pre[x] == 0) return x;
	return pre[x] = find(pre[x]);
}

void Union(int a,int b){
	int fa = find(a);
	int fb = find(b);
	if(fa != fb){
		--cnt;
		pre[fb] = fa;
	}
}


int main(){
#ifdef WFX
freopen("1021 in.txt","r",stdin);
#endif
	int u,v;
	scanf("%d",&N);
	cnt = N;
	for(int i=1;i<N;++i){ //input N-1 edge
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
		Union(u,v);
	}
	//�ò��鼯ͳ��ͼ����ͨ�����ĸ��� 
	if(cnt>1){
		printf("Error: %d components\n",cnt);
		return 0;
	}
	
	//ֻ��һ����ͨ��������ֻ��N-1���ߣ�˵�������ڻ� 
	//һ��������ٶ���·���ϣ�������Ҫ�ָ���Ŀɷ����ԡ� 
	vis[1] = 1;
	dfs(1,0); //����һ���㿪ʼ�Ҿ���õ���Զ�ĵ�(��Щ�㶼�Ǳ�Ե�ϵĵ�) 
	vis[1] = 0;
	int p = *s.begin(); //����Զ�ĵ㿪ʼdfs,�����ҵ��·��
//	copy(s.begin(),s.end(),inserter(res,res.begin()));  
	vis[p] = 1;
	dfs(p,0);
	vis[p] = 0;
	copy(s.begin(),s.end(),inserter(res,res.begin()));
	copy(res.begin(),res.end(),ostream_iterator<int>(cout,"\n"));
		
	return 0;
}


