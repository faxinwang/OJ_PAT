#include<iostream>
#define maxn 1000005
typedef long long LL; 
/*
题目大意:
输入两个升序序列a和b，求两个序列合并后的中位数.

解题思路: 
不断将序列a与b中较小的一个放入序列c中，如果序列c中的数目达到了(m+n)/2
则最后加入的数字就是中位数.
(好像有二分的方法，我写了一下，没能正确写出来)。 
*/

LL a[maxn],b[maxn];

int main(){
  int m,n;
  scanf("%d",&m);
  for(int i=0; i<m;++i) scanf("%lld",a+i);
  scanf("%d",&n);
  for(int j=0; j<n;++j) scanf("%lld",b+j);
  
  //如果一个序列的所有元素完全小于另一个序列，则可以直接确定中位数的位置 
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
  
  //合并序列 
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
