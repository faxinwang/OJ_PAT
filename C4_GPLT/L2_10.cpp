/*
L2-010. 排座位
时间限制
150 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
布置宴席最微妙的事情，就是给前来参宴的各位宾客安排座位。无论如何，总不能把两个死对头排到同一
张宴会桌旁！这个艰巨任务现在就交给你，对任何一对客人，请编写程序告诉主人他们是否能被安排同席。

输入格式：
输入第一行给出3个正整数：N（<= 100），即前来参宴的宾客总人数，则这些人从1到N编号；M为已知两
两宾客之间的关系数；K为查询的条数。随后M行，每行给出一对宾客之间的关系，格式为：“宾客1 宾客2 关系”，
其中“关系”为1表示是朋友，-1表示是死对头。注意两个人不可能既是朋友又是敌人。最后K行，每行给
出一对需要查询的宾客编号。

这里假设朋友的朋友也是朋友。但敌人的敌人并不一定就是朋友，朋友的敌人也不一定是敌人。只有单纯
直接的敌对关系才是绝对不能同席的。

输出格式：
对每个查询输出一行结果：如果两位宾客之间是朋友，且没有敌对关系，则输出“No problem”；如果
他们之间并不是朋友，但也不敌对，则输出“OK”；如果他们之间有敌对，然而也有共同的朋友，则输
出“OK but...”；如果他们之间只有敌对关系，则输出“No way”。

输入样例：
7 8 4
5 6 1
2 7 -1
1 3 1
3 4 1
6 7 -1
1 2 1
1 4 1
2 3 -1
3 4
5 7
2 3
7 2
输出样例：
No problem
OK
OK but...
No way

解题思路：
将每个人看出一个顶点，如果两个人有朋友关系，则在这两个人所对应的点上连一条线。并用1标记
标记他们之间的朋友关系，如果两个人是敌对关系，则用-1标记着两个人之间的关系。最后如果要查询
的两个人有敌对关系，就需要看他们有没有共同的好友，用DFS搜索即可，根据搜索结果即可判断应该
输出什么结果。 
*/
#include<iostream>
#include<string>
using namespace std;
short R[101][101]={0};
int N,M,K;

void DFS(int u,bool* visited){
	visited[u] = true;
	for(int i=1;i<=N;++i)
		if(R[u][i]==1 && !visited[i])
			DFS(i,visited);
}

string relationship(int i,int j){
	if(R[i][j]==1){	//朋友关系 
		return "No problem";
	}else if(R[i][j]==0){	//没有关系 
		return "OK";
	}else{	//敌对关系,需要看有没有共同的朋友 
		bool visited[N+1];
		fill(visited,visited+N+1,0);
		DFS(i,visited);
		if(visited[j])//i,j有共同好友 
			return "OK but...";
		return "No way";	//i,j无共同好友 
	}
}

int main(){
	scanf("%d%d%d",&N,&M,&K);
	for(int a=1;a<=M;++a){
		int i,j,r;
		scanf("%d%d%d",&i,&j,&r);
		R[i][j]=r;
		R[j][i]=r;
	}
	for(int a=0;a<K;++a){
		int i,j;
		scanf("%d%d",&i,&j);
		cout<<relationship(i,j)<<endl;
	}
	
	return 0;
}
