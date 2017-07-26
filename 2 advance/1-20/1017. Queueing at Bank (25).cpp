/*
使用数组w[i]表示第i个窗口的空闲时刻(以秒为单位)，初始值均为8*3600(s)
然后根据custom队列不断修改数组w元素的值,知道17点以前的客户都服务完毕为止。
在修改w[]数组的过程中即可累计顾客总的等待时间:
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
	for(i=0; i<k; ++i) w[i]  = 8*3600; //将各窗口的空闲时刻设为8点整 

	int end = 17*3600;//下班时间 
	for(i=0; i<n && a[i].arrive <= end ;++i){
		int min = 0;
		 //找到最早空闲下来的窗口
		for(int j=1;j<k;++j) if(w[j]<w[min]) min = j; 
		if(w[min] <= a[i].arrive){ //窗口空闲时间小于等于顾客到来时间,无需等待 
			w[min] = a[i].arrive + a[i].process; //更新窗口的空闲时刻 
		}else{ //窗口空闲时间大于顾客到达时间，需要等待 
			sum += w[min] - a[i].arrive; //等待时间为窗口空闲下来的时刻减到达时刻 
			w[min] += a[i].process; //更新窗口的空闲时刻 
		}
	}
	printf("%.1lf\n",1.0*sum/60/i);
	
	return 0;
}
