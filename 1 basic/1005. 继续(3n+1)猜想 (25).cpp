
#include<cstdio>
using namespace std;

int a[105];//ȫ�������Ԫ�س�ʼֵΪ0 

void process(int n){
	while(n>1){
		if( n % 2 == 0 ) n/=2;
		else n = (n*3+1)/2;
		if(n<105 && a[n]==2){
			a[n] = 1; //������,������ 
		}
	}
}

int main(){
	int n,tmp;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&tmp);
		a[tmp] = 2; //������,δ������
	}
	
	for(int i=1;i<=100;++i)
		if(a[i]==2) process(i);
	
	//�ҵ���һ��δ�����ǵ��� 
	int min;
	for(min=1;a[min]!=2;++min);
	//�Ӵ�С���
	for(int i=104;i>=min;--i) {
		if(a[i]==2 && i!=min) printf("%d ",i);
		else if(i==min)printf("%d",min);
	}
	
	return 0;
}
