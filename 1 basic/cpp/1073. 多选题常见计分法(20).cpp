/*
1073. ��ѡ�ⳣ���Ʒַ�(20)
ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
CHEN, Yue
���Ķ�ѡ���ǱȽ��鷳�����飬�кܶ಻ͬ�ļƷַ�������һ������ļƷַ����ǣ�
�������ѡ���˲�����ȷѡ�����û��ѡ���κδ���ѡ���õ�50%������
�������ѡ�����κ�һ�������ѡ����ܵ÷֡����������д�����������ʦ���Ķ�ѡ�⣬
����ָ���ĵ�����ĸ�ѡ��������ࡣ

�����ʽ��
�����ڵ�һ�и�������������N��<=1000����M��<=100�����ֱ���ѧ�������Ͷ�ѡ��ĸ�����
���M�У�ÿ��˳�θ���һ���������ֵ��������5������������ѡ�������������2�Ҳ�
����5��������������ȷѡ�������������ѡ�����������������������ȷѡ�ע��ÿ��
��ѡ���СдӢ����ĸa��ʼ˳�����С��������1���ո�ָ������N�У�ÿ�и���һ��ѧ
���Ĵ����������ÿ��𰸸�ʽΪ��(ѡ�е�ѡ����� ѡ��1 ����)��������Ŀ˳�������
ע�⣺��Ŀ��֤ѧ���Ĵ�������ǺϷ��ģ���������ѡ�е�ѡ��������ʵ��ѡ�����������

�����ʽ��
���������˳�����ÿ��ѧ���ĵ÷֣�ÿ������ռһ�У����С�����1λ�������������
�����Ŀѡ�����Ϣ����ʽΪ����������� ��Ŀ��ţ���Ŀ���������˳���1��ʼ��ţ�-ѡ��š���
����в��У���ÿ��һ��ѡ�����Ŀ��ŵ���˳��������ٲ�����ѡ��ŵ���˳�������
����β�����ж���ո����������Ŀ��û���˴��������һ�������Too simple����

��������1��
3 4 
3 4 2 a c
2 5 1 b
5 3 2 b c
1 5 4 a b d e
(2 a c) (3 b d e) (2 a c) (3 a b e)
(2 a c) (1 b) (2 a b) (4 a b d e)
(2 b d) (1 e) (1 c) (4 a b c d)

�������1��
3.5
6.0
2.5
2 2-e
2 3-a
2 3-b

��������2��
2 2 
3 4 2 a c
2 5 1 b
(2 a c) (1 b)
(2 a c) (1 b)

�������2��
5.0
5.0
Too simple

����˼·��

*/ 
#include<iostream> 
#include<cstdio> 
#include<string>
#include<vector>
#include<algorithm>
#define maxn 1005
using namespace std;

//����ÿһ����Ŀ����Ϣ 
struct Porblem{
	int Score; //������ܷ��� 
	int Selections; //ѡ����� 
	string ans; //����Ĵ� 
	int arr[5]; //arr[i]��ʾ'a'+iѡ��Ĵ������ 
}p[maxn];

//����ÿһ��������Ϣ
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
	//���ζ�ȡÿһ���˵Ĵ�
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
