/*
1004. Counting Leaves (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A family hierarchy is usually presented by a pedigree tree. Your job is to 
count those family members who have no child.

Input
Each input file contains one test case. Each case starts with a line 
containing 0 < N < 100, the number of nodes in a tree, and M (< N), the 
number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is 
the number of its children, followed by a sequence of two-digit ID's of 
its children. For the sake of simplicity, let us fix the root ID to be 01.

Output
For each test case, you are supposed to count those family members who 
have no child for every seniority level starting from the root. The 
numbers must be printed in a line, separated by a space, and there 
must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root
and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; 
and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input
2 1
01 1 02

Sample Output
0 1

题目大意：
给定一颗树的结构，求该树中从第二层(根结点下面的一层)开始往下的每一层中叶结点的个数

解题思路：
用数组来存储树结构，用数据level[i]记录第i+1层中叶结点的个数。那么怎么知道哪些结点是
叶结点哪些不是呢，由于题目告诉了不是叶结点的ID，所以可以用一个数组flag来标记每一个结点的
属性，flag[i]=0表示结点i是叶结点。那么怎么求叶结点i所在的层数呢，由于使用了数组来保存
树结构，parent[i]就是i的父结点的编号,这样一直往上追溯，并记录追溯的次数，就知道结点i的
层数了，就可以 ++level[i] 了。遍历flag数组，对所有的叶结点进行求层数的操作，最后输出level
数组就OK了。 
*/
#include<iostream> 
using namespace std;

int parent[105];//parent[id] 保存的是id的父节点的id
char flag[105];//flag[i]=0 表示i是一个叶子节点 
int level[100];//level[i]记录第i层叶子节点的个数 

//求节点的深度 
int deepth(int id,int d){
	if( parent[id] ){
		return deepth(parent[id],d+1);
	}
	return d;
}

int main(){
	int n,m;//n Nodes, m non-leaf nodes
	int id,k,subId;
	cin>>n>>m;
	parent[1] = 0;
	//输入m条non-left nodes 
	for(int i=0;i<m;++i){
		cin>>id>>k;
		//标记出所有的non-left nodes
		flag[id] = 1;
		for(int j=0;j<k;++j){
			cin>>subId;
			parent[subId] = id;
		}
	}
	int MaxDeepth=0;
	for(int i=1;i<=n;++i){
		if(flag[i] == 0){
			int d = deepth(i,1);
			if(d>MaxDeepth) MaxDeepth = d; 
			++level[d];
		}
	}
//	cout<<"MaxDeepth:"<<MaxDeepth<<endl;
	cout<<level[1];
	for(int i=2;i<=MaxDeepth;++i){
		cout<<" "<<level[i];
	}
	cout<<endl;
	
	return 0;
}
