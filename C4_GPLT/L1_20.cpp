#include<iostream>
#include<deque>
using namespace std;
int ID[100000]={0};

int main(){
	int N,M,id;
	scanf("%d",&N);
	for(int i=0;i<N;++i){ //����N������Ȧ 
		int k;
		scanf("%d",&k);
		if(k==1){
			scanf("%d",&id);//ֻ��һ����������Ȧ��������ȷ�����Ƿ������� 
			continue;
		}
		for(int j=0;j<k;++j){
			scanf("%d",&id);
			ID[id] = 1;//ID[id]=1 ��ʾ������id�����ѣ�Ϊ0��ʾidû���� 
		}
	}
	deque<int> d;
	scanf("%d",&M);
	for(int i=0;i<M;++i){
		scanf("%d",&id);
		if(ID[id]==0){
			ID[id]=1;//����������Ϊ�����ѣ���û�ظ���ѯʱ�ظ���� 
			d.push_back(id);
		}
	}
	if(d.size()){
		for(int i=0;i<d.size()-1;++i){
			printf("%05d ",d[i]);
		}
		printf("%05d",d[d.size()-1]);
	}else{
		printf("No one is handsome");
	}
	
	return 0;
}
