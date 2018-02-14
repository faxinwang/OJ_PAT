/*
1004. Counting Leaves (30)
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

��Ŀ���⣺
����һ�����Ľṹ��������дӵڶ���(����������һ��)��ʼ���µ�ÿһ����Ҷ���ĸ���

����˼·��
���������洢���ṹ��������level[i]��¼��i+1����Ҷ���ĸ�������ô��ô֪����Щ�����
Ҷ�����Щ�����أ�������Ŀ�����˲���Ҷ����ID�����Կ�����һ������flag�����ÿһ������
���ԣ�flag[i]=0��ʾ���i��Ҷ��㡣��ô��ô��Ҷ���i���ڵĲ����أ�����ʹ��������������
���ṹ��parent[i]����i�ĸ����ı��,����һֱ����׷�ݣ�����¼׷�ݵĴ�������֪�����i��
�����ˣ��Ϳ��� ++level[i] �ˡ�����flag���飬�����е�Ҷ������������Ĳ�����������level
�����OK�ˡ� 
*/
#include<iostream> 
using namespace std;

int parent[105];//parent[id] �������id�ĸ��ڵ��id
char flag[105];//flag[i]=0 ��ʾi��һ��Ҷ�ӽڵ� 
int level[100];//level[i]��¼��i��Ҷ�ӽڵ�ĸ��� 

//��ڵ����� 
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
	//����m��non-left nodes 
	for(int i=0;i<m;++i){
		cin>>id>>k;
		//��ǳ����е�non-left nodes
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
