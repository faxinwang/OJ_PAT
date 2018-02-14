/*
L3-002. 堆栈
时间限制
200 ms
内存限制
65536 kB
代码长度限制
8000 B
判题程序
Standard
作者
陈越
大家都知道“堆栈”是一种“先进后出”的线性结构，基本操作有“入栈”（将新元素插入栈顶）
和“出栈”（将栈顶元素的值返回并从堆栈中将其删除）。现请你实现一种特殊的堆栈，它多了
一种操作叫“查中值”，即返回堆栈中所有元素的中值。对于N个元素，若N是偶数，则中值定义
为第N/2个最小元；若N是奇数，则中值定义为第(N+1)/2个最小元。

输入格式：
输入第一行给出正整数N（<= 10^5）。随后N行，每行给出一个操作指令，为下列3种指令之一：
Push key
Pop
PeekMedian
其中Push表示入栈，key是不超过10^5的正整数；Pop表示出栈；PeekMedian表示查中值。

输出格式：
对每个入栈指令，将key入栈，并不输出任何信息。对每个出栈或查中值的指令，在一行中打印相
应的返回结果。若指令非法，就打印“Invalid”。

输入样例：
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop

输出样例：
Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid


解题思路: 
一开始想着用排序的方法找中值, 于是选择了O(n)时间复杂度的计数排序算法,
结果第2,3,4个测试点还是超时了.大一做这个题的时候还没有学习线段树, 现在过几天
要去西安参加ACM的现场赛了, 于是想找点线段树的题目巩固一下线段树, 于是就找到了这个题目.
这个方法也是在网上看到的, 在每个结点中记录现有数据落在该区间的个数, 如果某个数被Pop掉了,
就找到线段树中该数所对应的叶结点, 将其计数器减一; 反之, 如果某个数被push进来了, 则找到
该数对应的叶节点并将其计数器加一; 对于查询第k大值, 首先看当前树的左子树中计数器cnt的值, 
如果k<=cnt, 则第k大值在左子树中, 否则第k大值是右子树中的第 k - LC.cnt 大值. 
*/ 
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5+5;

//使用计数排序, 还是超时, 改用线段树 
/*
void count_sort(vector<int>& a,int *b,int N){
	int max = *max_element(a.begin(),a.end());
	int c[max+1];
	fill(c,c+max+1,0);
	for(int i=0;i<N;++i) ++c[a[i]];
	for(int i=1;i<=max;++i) c[i] += c[i-1];
	for(int i=N;i>0;--i){
		b[ c[a[i-1]] -1 ] = a[i-1];
		--c[a[i-1]];
	}
}
*/
class Stack{
private:
	vector<int> v;
	struct SegTree{
		int L,M,R;
		int cnt;//记录该区间内值的个数 
	}*ST;
	
	void pushup(int k){
		ST[k].cnt = ST[k<<1].cnt + ST[(k<<1)+1].cnt;
	}
public:
	Stack(int Max){
		v.reserve(10);
		ST = new SegTree[Max<<2];
		build(1,1, Max);
	}
	~Stack(){ delete[] ST;}
	//建树 
	void build(int rt, int L, int R){
		ST[rt].L = L;
		ST[rt].R = R;
		ST[rt].M = L + (R-L) /2;
		ST[rt].cnt = 0;
		if(L==R) return;
		build(rt<<1, L, ST[rt].M);
		build((rt<<1)+1, ST[rt].M+1, R); 
	}
	//单点更新 
	void update(int rt, int x, int val){
		if(ST[rt].L == ST[rt].R && ST[rt].L == x){
			ST[rt].cnt += val;
		}
		else{
			if(x<=ST[rt].M) update(rt<<1, x, val);
			else update((rt<<1)+1, x, val);
			pushup(rt);
		}
	}
	//单点查询 
	int query(int rt,int k){
		if(ST[rt].L == ST[rt].R) return ST[rt].L;
		int LC = rt<<1, RC = LC+1;
		if(k <= ST[LC].cnt){
			return query(LC, k);
		}else{
			return query(RC, k-ST[LC].cnt);
		}
	}
	
	void Push(int x){
		v.push_back(x);
		update(1, x, 1);
	}
	int Pop(){
		int tmp = v.back();
		v.pop_back();
		update(1, tmp, -1);
		return tmp;
	}
	int PeekMedian(){
		return query(1, (v.size()+1)/2);
	}
	int size(){
		return v.size();
	}
};

int main(){
#ifdef WFX
freopen("in.txt","r",stdin);
#endif
	int N,x;
	Stack s(maxn);
	string op;
	scanf("%d",&N);
	while(N--){
		cin>>op;
		if(op=="Push"){
			scanf("%d",&x);
			s.Push(x);
		}else if(op=="Pop"){
			if(s.size())
				cout<<s.Pop()<<endl;
			else
				cout<<"Invalid"<<endl;
		}else{
			if(s.size())
				cout<<s.PeekMedian()<<endl;
			else
				cout<<"Invalid"<<endl;
		}
	}
	
	return 0;
}
