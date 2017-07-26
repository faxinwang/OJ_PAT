/*
ʹ������w[i]��ʾ��i�����ڵĿ���ʱ��(����Ϊ��λ)����ʼֵ��Ϊ8*3600(s)
Ȼ�����custom���в����޸�����wԪ�ص�ֵ,֪��17����ǰ�Ŀͻ����������Ϊֹ��
���޸�w[]����Ĺ����м����ۼƹ˿��ܵĵȴ�ʱ��:
//min is the index of min(w[i]) 
if(cus.arrive > w[min] ) {
	waitTime += cus.arrive - w[min]; 
	w[min] += cus.process;
}
else{
	w[min] = cus.arrive + cus.process;
}
*/
#include<iostream> 
#include<algorithm>
#define maxn 10005
using namespace std;

struct Cus{
	int arrive,process;
	bool operator<(const Cus& c)const{
		return arrive < c.arrive;
	}
};
Cus a[maxn];
int w[105], sum;//total second

int main(){
#ifdef WFX
freopen("1017 in.txt","r",stdin);
#endif
	int n,k,i;
	int h,m,s,p;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;++i){
		scanf("%d:%d:%d %d",&h,&m,&s,&p);
		a[i].arrive = h*3600 + m * 60 + s;
		a[i].process = p*60;
	}
	sort(a,a+n);
	for(i=0; i<k; ++i) w[i]  = 8*3600; //�������ڵĿ���ʱ����Ϊ8���� 

	int end = 17*3600;//�°�ʱ�� 
	for(i=0; i<n && a[i].arrive <= end ;++i){
		int min = 0;
		 //�ҵ�������������Ĵ���
		for(int j=1;j<k;++j) if(w[j]<w[min]) min = j; 
		if(w[min] <= a[i].arrive){ //���ڿ���ʱ��С�ڵ��ڹ˿͵���ʱ��,����ȴ� 
			w[min] = a[i].arrive + a[i].process; //���´��ڵĿ���ʱ�� 
		}else{ //���ڿ���ʱ����ڹ˿͵���ʱ�䣬��Ҫ�ȴ� 
			sum += w[min] - a[i].arrive; //�ȴ�ʱ��Ϊ���ڿ���������ʱ�̼�����ʱ�� 
			w[min] += a[i].process; //���´��ڵĿ���ʱ�� 
		}
	}
	printf("%.1lf\n",1.0*sum/60/i);
	
	return 0;
}
