/*
思路：先按链表的顺序将节点存入数组，然后每K个节点反序输出
	 最后剩下的不足K个按顺序输出 

00100 7 3
00000 4 99999
00100 1 12309
68237 6 55555
33218 3 00000
99999 5 68237
12309 2 33218
55555 7 -1 
*/
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct Node{
	int add,val,next;
	Node(){} 
	Node(int a,int v,int n):add(a),val(v),next(n){}
}d[100005];

int main(){
	int head,n,k;
	int add,val,next;
	//read nodes
	scanf("%d%d%d",&head,&n,&k);
	for(int i=0;i<n;++i) {
		scanf("%d%d%d",&add,&val,&next);
		d[add].val = val;
		d[add].next = next;
	}
	//put the nodes into vector in list order
	vector<Node> v;
	v.reserve(n);
	for(add=head; add!=-1 ;add=d[add].next){
		v.push_back(Node(add,d[add].val,d[add].next));
	}
	//output list in reverse order
	n = v.size(); //有些节点可能不在链表上 
	int i;
	for(i=0; i<n; i+=k){
		for(int j=i+k-1; j<n && j>=i; --j){
			if(j==i){
				if(n-j==k){
					printf("%05d %d -1\n",v[j].add,v[j].val);
				}else if(n-j>=2*k){
					printf("%05d %d %05d\n",v[j].add,v[j].val,v[j+2*k-1].add);
				}else{
					printf("%05d %d %05d\n",v[j].add,v[j].val,v[j+k].add);
				}
			}else{
				printf("%05d %d %05d\n",v[j].add,v[j].val,v[j-1].add);
			}
		}
	}
	//output the left not reversed nodes and the last node 
	if(n%k){
		for(i-=k; i<n-1; ++i)
			printf("%05d %d %05d\n",v[i].add,v[i].val,v[i].next);
		printf("%05d %d -1\n",v[n-1].add,v[n-1].val);
	}
	
	return 0;
}
