/*
L3-002. ��ջ
ʱ������
200 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
��Ҷ�֪������ջ����һ�֡��Ƚ�����������Խṹ�����������С���ջ��������Ԫ�ز���ջ����
�͡���ջ������ջ��Ԫ�ص�ֵ���ز��Ӷ�ջ�н���ɾ������������ʵ��һ������Ķ�ջ��������
һ�ֲ����С�����ֵ���������ض�ջ������Ԫ�ص���ֵ������N��Ԫ�أ���N��ż��������ֵ����
Ϊ��N/2����СԪ����N������������ֵ����Ϊ��(N+1)/2����СԪ��

�����ʽ��
�����һ�и���������N��<= 10^5�������N�У�ÿ�и���һ������ָ�Ϊ����3��ָ��֮һ��
Push key
Pop
PeekMedian
����Push��ʾ��ջ��key�ǲ�����10^5����������Pop��ʾ��ջ��PeekMedian��ʾ����ֵ��

�����ʽ��
��ÿ����ջָ���key��ջ����������κ���Ϣ����ÿ����ջ�����ֵ��ָ���һ���д�ӡ��
Ӧ�ķ��ؽ������ָ��Ƿ����ʹ�ӡ��Invalid����

����������
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

���������
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


����˼·: 
һ��ʼ����������ķ�������ֵ, ����ѡ����O(n)ʱ�临�Ӷȵļ��������㷨,
�����2,3,4�����Ե㻹�ǳ�ʱ��.��һ��������ʱ��û��ѧϰ�߶���, ���ڹ�����
Ҫȥ�����μ�ACM���ֳ�����, �������ҵ��߶�������Ŀ����һ���߶���, ���Ǿ��ҵ��������Ŀ.
�������Ҳ�������Ͽ�����, ��ÿ������м�¼�����������ڸ�����ĸ���, ���ĳ������Pop����,
���ҵ��߶����и�������Ӧ��Ҷ���, �����������һ; ��֮, ���ĳ������push������, ���ҵ�
������Ӧ��Ҷ�ڵ㲢�����������һ; ���ڲ�ѯ��k��ֵ, ���ȿ���ǰ�����������м�����cnt��ֵ, 
���k<=cnt, ���k��ֵ����������, �����k��ֵ���������еĵ� k - LC.cnt ��ֵ. 
*/ 
#include<iostream>
#include<vector>
using namespace std;
const int maxn = 1e5+5;

//ʹ�ü�������, ���ǳ�ʱ, �����߶��� 
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
		int cnt;//��¼��������ֵ�ĸ��� 
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
	//���� 
	void build(int rt, int L, int R){
		ST[rt].L = L;
		ST[rt].R = R;
		ST[rt].M = L + (R-L) /2;
		ST[rt].cnt = 0;
		if(L==R) return;
		build(rt<<1, L, ST[rt].M);
		build((rt<<1)+1, ST[rt].M+1, R); 
	}
	//������� 
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
	//�����ѯ 
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
