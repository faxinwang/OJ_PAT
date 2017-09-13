#include<stdio.h>

double A[6];
int a[1001],A2=0;

void compute(int *a,int n){
  int count =0;
//  for(int i=0;i<6;++i){
//    A[i]=0;
//  }
  for(int i=0,flag=1;i<n;++i){
    if(a[i]%10==0){
      A[1]+=a[i];
    } 
    else if(a[i]%5==1){
      A[2]+= flag*a[i];
      flag=-flag;
      A2=1;//说明A2这类数字存在 
    }
    else if(a[i]%5==2){
      ++A[3];
    }
    else if(a[i]%5==3){
      A[4]+=a[i];
      ++count;
    }
    else if(a[i]%5==4){
      if(A[5]<a[i]) A[5] = a[i];
    }
  }
  
  if(count) A[4] /= count;
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d",a+i);
  compute(a,n);
  
  for(int i=1;i<=5;++i){
    if(A[i]){
      if(i==4)
        printf("%.1lf",A[i]);
      else
        printf("%.0lf",A[i]);
    }else{
      if(i==2 && A2){
        printf("0");
      }else{
        printf("N");
      }
    }
    if(i<5) printf(" ");
  }
  puts("");
  
  return 0;
}
