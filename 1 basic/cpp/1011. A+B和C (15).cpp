#include<cstdio>

int main(){
  int N;
  scanf("%d",&N);
  for(int i=1;i<=N;++i){
    long long a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("Case #%d: %s\n",i,(a+b>c?"true":"false"));
  }
  
  return 0;
}
