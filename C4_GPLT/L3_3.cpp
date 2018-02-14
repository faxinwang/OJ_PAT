/*
L3-003. �罻��Ⱥ
ʱ������
1000 ms
�ڴ�����
65536 kB
���볤������
8000 B
�������
Standard
����
��Խ
���罻����ƽ̨ע��ʱ���û�ͨ���������Լ�����Ȥ���ã��Ա��ҵ����Լ���Ȥ��Ͷ�����ѡ�
�в�����Ȥ��ͬ�����Ǿ��γ��ˡ��罻��Ⱥ�����������д�����ҳ����еļ�Ⱥ��

�����ʽ��
����ĵ�һ�и���������N��<=1000�������罻�����е��û����������û���1��N��ţ���
���N�У�ÿ�а����и�ʽ�г�ÿ���˵���Ȥ���ã�

Ki: hi[1] hi[2] ... hi[Ki]

����Ki��>0���ǵ�i���˵���Ȥ��������hi[j]�ǵ�i���˵ĵ�j����Ȥ�ı�ţ���ŷ�ΧΪ[1, 1000]�ڵ�������

�����ʽ��
�����ڵ�һ��������������м�Ⱥ��������Ȼ���ڵڶ��а��ǵ�����˳�����ÿ����Ⱥ
���û������������ּ���1���ո�ָ�������β�����ж���ո�

����������
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4

���������
3
4 3 1

����˼·:
���Ƚ������˰�����Ȥ����, ��������ͬһ��(����ĳһ����ͬ��Ȥ)�������ն�����ͬһ������
����С����˹���ͼ, �������ڵ�һ���˺�����������֮����һ�������
���������˽�������һ��������ͨ�������ɵ�ͼ, Ȼ��ͳ�Ƴ�������ͨ�����е�����
���Ҫ�������������. 

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
	//����Ⱥ���հ��÷��� 
	for(int id=1; id<=n; ++id){
		scanf("%d:",&k);
		for(int j=0; j<k; ++j){
			scanf("%d",&hi);
			grp[hi].push_back(id);
			if(MaxHi < hi) MaxHi = hi;
		}
	}
	//��������ͼ
	for(int i=1; i<=MaxHi; ++i){
		vector<int> &v = grp[i];
		if(v.size() <= 1) continue;
		for(int j=v.size()-1; j>0; --j){
			g[v[0]].push_back(v[j]);
			g[v[j]].push_back(v[0]);
		}
	}
	
	//ͳ�Ƹ��������� 
	vector<int> ans;
	for(int i=1; i<=n; ++i){
		if(!vis[i]){
			if(g[i].size()==0) ans.push_back(1); //��һ���˹��ɵ���ͨ���� 
			else{
				int cnt=1;
				vis[i] = 1;
				dfs(i,cnt);
				ans.push_back(cnt);
			}
		}
	}
	
	//�������� 
	sort(ans.begin(), ans.end());
	printf("%d\n",ans.size());
	for(int i=ans.size()-1; i>0; --i) printf("%d ",ans[i]);
	printf("%d\n",ans[0]);
	
	return 0;
}
