#include<iostream>
#define maxn 1000005
typedef long long LL; 
/*
��Ŀ����:
����������������a��b�����������кϲ������λ��.

����˼·: 
���Ͻ�����a��b�н�С��һ����������c�У��������c�е���Ŀ�ﵽ��(m+n)/2
������������־�����λ��.
(�����ж��ֵķ�������д��һ�£�û����ȷд����)�� 
*/

LL a[maxn],b[maxn];

int main(){
  int m,n;
  scanf("%d",&m);
  for(int i=0; i<m;++i) scanf("%lld",a+i);
  scanf("%d",&n);
  for(int j=0; j<n;++j) scanf("%lld",b+j);
  
  //���һ�����е�����Ԫ����ȫС����һ�����У������ֱ��ȷ����λ����λ�� 
  int mid=(m+n-1)>>1;
  if(a[m-1] < b[0]){
  	if(mid < m){
  		printf("%lld",a[mid]); return 0;
	}else{
		printf("%lld",b[mid-m]); return 0;
	}
  }
  
  if(b[n-1] < a[0]){
  	if(mid < n){
		printf("%lld",b[mid]); return 0;
	}else{
		printf("%lld",a[mid-n]); return 0;
	} 
  }
  
  //�ϲ����� 
  int i,j,sum=m+n;
  for(i=0,j=0; i<m && j<n ;){
	if(a[i] < b[j]){
		++i; 
		if((i+j)*2 >= sum){
			printf("%lld",a[i-1]); return 0;
		}
	}else{
		++j;
		if((i+j)*2 >= sum){
			printf("%lld",b[j-1]); return 0;
		}
	}
  }
  
  if(i<m) printf("%lld",a[mid-n + i-1]);
  if(j<n) printf("%lld",b[mid-m + j-1]);
  
  return 0;
}
