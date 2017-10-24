#include<iostream> 
#include<string>
#include<algorithm>
using namespace std;

int a[1001];
int N,M;

bool query(){
	int x,y;
	string str;
	scanf("%d",&x);
	cin>>str;
	if(str=="and"){//x and y are siblings
		scanf("%d",&y);
		cin>>str>>str;
		for(int i=1;i<=N;++i)
			if(a[i]==x)
				if(a[i+1]==y || a[i-1])
					return true;
				else
					return false; 
	}else{
		cin>>str;
		if(str=="a"){//x is a child of y
			cin>>str>>str;
			scanf("%d",&y);
			return x>y;
			for(int i=1;i*2<=N;++i)
				if(a[i]==y)
					if(a[2*i]==x || a[2*i+1]==x){
						return true;
					}else{
						return false;
					}
		}else{
			cin>>str;
			if(str=="root"){//x is the root
				return x==a[1];
			}else{//x is the parent of y
				cin>>str;
				scanf("%d",&y);
				for(int i=1;i*2<=N;++i)
				if(a[i]==x)
					if(a[2*i]==y || a[2*i+1]==y){
						return true;
					}else{
						return false;
					}
			}
		}
	}
}

int main(){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;++i)
		scanf("%d",a+i);
	make_heap(a+1,a+N+1);
	
	while(M--){
		printf("%c\n",query()?'T':'F');
	}
	
	return 0;
}
