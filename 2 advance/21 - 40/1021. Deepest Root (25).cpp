/*
1021. Deepest Root (25)
时间限制
1500 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
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


题目大意：
一个无向无环图可以看成是一颗树。树的高度取决于选择那一个顶点作为根节点。
对于给定的无向无环图，找出图中能导致树高度最高的所有顶点，并按升序输出。 

解题思路:
由于是无向图，所以如果找到了一条最长的路径，则路径的两个端点都是符合题意的点。 
由于该题中图的边只有N-1条，比较少，所以使用邻接矩阵更好。
在确定连通分量不超过1个后，就可以确定图中没有环(因为只有N-1条边)
使用DFS找最长路径长度，首先随便用一个点作为起点开始dfs，将找到的最远
点保存在集合s1中。然后用s1中随便一个点p作为起点再做同样的DFS搜索，这次找
的点理论上与p组成了更长的路径，因此有人会用这些点替换掉s1中的点。 
但是，考虑下面这个例子 
5
1 2
1 3
2 4
2 5
如果以1为起点开始找，将找到s1={4,5},然后不论用4还是5，找到的最远的点都是3，
如果用起点4(或5)与终点3替换掉s1里面的元素,得到的结果会是{3,4}或{3,5};
然后实际结果应该是{3,4,5},所以正确的答案应该是两个dfs搜到的点的并集。
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
	//用并查集统计图的连通分量的个数 
	if(cnt>1){
		printf("Error: %d components\n",cnt);
		return 0;
	}
	
	//只有一个连通分量，且只有N-1条边，说明不存在环 
	//一个点可能再多条路径上，所以需要恢复点的可访问性。 
	vis[1] = 1;
	dfs(1,0); //随便从一个点开始找距离该点最远的点(这些点都是边缘上的点) 
	vis[1] = 0;
	int p = *s.begin(); //从最远的点开始dfs,才能找到最长路径
//	copy(s.begin(),s.end(),inserter(res,res.begin()));  
	vis[p] = 1;
	dfs(p,0);
	vis[p] = 0;
	copy(s.begin(),s.end(),inserter(res,res.begin()));
	copy(res.begin(),res.end(),ostream_iterator<int>(cout,"\n"));
		
	return 0;
}


