/*
L3-003. 社交集群
时间限制
1000 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
在社交网络平台注册时，用户通常会输入自己的兴趣爱好，以便找到和自己兴趣相投的朋友。
有部分兴趣相同的人们就形成了“社交集群”。现请你编写程序，找出所有的集群。

输入格式：
输入的第一行给出正整数N（<=1000），即社交网络中的用户总数（则用户从1到N编号）。
随后N行，每行按下列格式列出每个人的兴趣爱好：

Ki: hi[1] hi[2] ... hi[Ki]

其中Ki（>0）是第i个人的兴趣的数量，hi[j]是第i个人的第j项兴趣的编号，编号范围为[1, 1000]内的整数。

输出格式：
首先在第一行输出整个网络中集群的数量，然后在第二行按非递增的顺序输出每个集群
中用户的数量。数字间以1个空格分隔，行首尾不得有多余空格。

输入样例：
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

输出样例：
3
4 3 1

解题思路:
首先将所有人按照兴趣分组, 所有属于同一组(具有某一个共同兴趣)的人最终都属于同一个集合
将该小组的人构成图, 方法是在第一个人和其他所有人之间连一条无向边
最终所有人将构成由一个或多个连通分量构成的图, 然后统计出所有连通分量中的人数
最后按要求排序输出即可. 

*/
#include<iostream> 
#include<vector> 
#include<algorithm>
#define maxn 1005
using namespace std;

vector<int> grp[maxn];
vector<int> g[maxn];
bool vis[maxn];

void dfs(int i,int &cnt){
	vector<int>& v = g[i];
	for(int j=g[i].size()-1; j>=0; --j){
		if(!vis[v[j]]){
			vis[v[j]] = 1;
			dfs(v[j], ++cnt);
		}
	}
}

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int n,k,hi,MaxHi=0;
	scanf("%d",&n);
	//将人群安照爱好分组 
	for(int id=1; id<=n; ++id){
		scanf("%d:",&k);
		for(int j=0; j<k; ++j){
			scanf("%d",&hi);
			grp[hi].push_back(id);
			if(MaxHi < hi) MaxHi = hi;
		}
	}
	//构造无向图
	for(int i=1; i<=MaxHi; ++i){
		vector<int> &v = grp[i];
		if(v.size() <= 1) continue;
		for(int j=v.size()-1; j>0; --j){
			g[v[0]].push_back(v[j]);
			g[v[j]].push_back(v[0]);
		}
	}
	
	//统计各集合人数 
	vector<int> ans;
	for(int i=1; i<=n; ++i){
		if(!vis[i]){
			if(g[i].size()==0) ans.push_back(1); //由一个人构成的连通分量 
			else{
				int cnt=1;
				vis[i] = 1;
				dfs(i,cnt);
				ans.push_back(cnt);
			}
		}
	}
	
	//排序后输出 
	sort(ans.begin(), ans.end());
	printf("%d\n",ans.size());
	for(int i=ans.size()-1; i>0; --i) printf("%d ",ans[i]);
	printf("%d\n",ans[0]);
	
	return 0;
}
