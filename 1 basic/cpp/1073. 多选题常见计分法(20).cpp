/*
1073. 多选题常见计分法(20)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
CHEN, Yue
批改多选题是比较麻烦的事情，有很多不同的计分方法。有一种最常见的计分方法是：
如果考生选择了部分正确选项，并且没有选择任何错误选项，则得到50%分数；
如果考生选择了任何一个错误的选项，则不能得分。本题就请你写个程序帮助老师批改多选题，
并且指出哪道题的哪个选项错的人最多。

输入格式：
输入在第一行给出两个正整数N（<=1000）和M（<=100），分别是学生人数和多选题的个数。
随后M行，每行顺次给出一道题的满分值（不超过5的正整数）、选项个数（不少于2且不
超过5的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。注意每题
的选项从小写英文字母a开始顺次排列。各项间以1个空格分隔。最后N行，每行给出一个学
生的答题情况，其每题答案格式为“(选中的选项个数 选项1 ……)”，按题目顺序给出。
注意：题目保证学生的答题情况是合法的，即不存在选中的选项数超过实际选项数的情况。

输出格式：
按照输入的顺序给出每个学生的得分，每个分数占一行，输出小数点后1位。最后输出错得最
多的题目选项的信息，格式为：“错误次数 题目编号（题目按照输入的顺序从1开始编号）-选项号”。
如果有并列，则每行一个选项，按题目编号递增顺序输出；再并列则按选项号递增顺序输出。
行首尾不得有多余空格。如果所有题目都没有人错，则在最后一行输出“Too simple”。

输入样例1：
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)

输出样例1：
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b

输入样例2：
2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)

输出样例2：
5.0
5.0
Too simple

解题思路：

*/ 
#include<iostream> 
#include<cstdio> 
#include<string>
#include<vector>
#include<algorithm>
#define maxn 1005
using namespace std;

//保存每一个题目的信息 
struct Porblem{
	int Score; //该题的总分数 
	int Selections; //选项个数 
	string ans; //该题的答案 
	int arr[5]; //arr[i]表示'a'+i选项的错误次数 
}p[maxn];

//保存每一个错误信息
struct Error{
	int cnt,pid,sid;
	Error(int c,int p,int s):cnt(c),pid(p),sid(s){}
	bool operator>(const Error& err)const{
		if(cnt != err.cnt) return cnt > err.cnt;
		if(pid != err.pid) return pid < err.pid;
		return sid < err.sid;
	}
};

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int N,M,t;
	char ch;
	scanf("%d%d",&N,&M);
	for(int i=1; i<=M; ++i){
		scanf("%d%d%d", &p[i].Score, &p[i].Selections, &t);
		for(int j=0; j<t; ++j) cin>>ch, p[i].ans += ch;
//		cout<<p[i].Score<<' '<<p[i].Selections<<' ' <<p[i].ans<<endl;
	}
	//依次读取每一个人的答案
	for(int i=0; i<N; ++i){ 
		double score = 0;
		for(int j=1; j<=M; ++j){
			int s=0;
			string ans = p[j].ans;
			cin>>ch>>t;
			for(int k=0; k<t; ++k){
				cin>>ch;
				size_t idx = ans.find(ch);
				if( idx != string::npos ){
					if(s != -1) ++s;
					ans[idx] = '#';
				}
				else{
					s = -1;
					++p[j].arr[ch-'a'];
				} 
			}
			if(s == p[j].ans.size()) score += p[j].Score; //get full score in this problem
			else if(s > 0) score += p[j].Score / 2.0; // get 50% score in this problem
			cin>>ch; // read ')'
			
			for(int k=0,n=ans.size(); k<n; ++k) if(ans[k]!='#') ++p[j].arr[ans[k]-'a'];
		}
		printf("%.1lf\n", score);
	}
	
	vector<Error> v;
	for(int i=1; i<=M; ++i){
		for(int j=0; j<5; ++j){
			if( p[i].arr[j] ) v.push_back(Error(p[i].arr[j], i, j));
		}
	}
	if(v.empty()){
		printf("Too simple\n");
	}else{
		sort(v.begin(),v.end(), greater<Error>());
		printf("%d %d-%c\n",v[0].cnt, v[0].pid, v[0].sid+'a');
		for(int i=1,n=v.size(); i<n; ++i){
			if(v[i].cnt != v[i-1].cnt) break;
			printf("%d %d-%c\n",v[i].cnt, v[i].pid, v[i].sid+'a');
		}
	}
	
	return 0;
}
