#include<cstdio>

int a[105]; 

// 翻转数组中在区间[m,n)之间的元素 
int reverse(int m,int n){
	for(int i=0,mid=(n-m)/2; i<mid;++i){
		int t = a[m+i];
		a[m+i] = a[n-i-1];
		a[n-i-1] = t;
	}
}


int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		scanf("%d",a+i);
		
	m %= n;
	reverse(0,n-m);
	reverse(n-m,n);
	reverse(0,n);
	
	printf("%d",a[0]);
	for(int i=1;i<n;++i)
		printf(" %d",a[i]);
	
	return 0;
}
