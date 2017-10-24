#include<iostream>
#include<cstdio>
#include<algorithm> 
using namespace std;

int A[105],B[105]; // soruce sequence, target sequence
int N;

void print(int* a,int n){
	printf("%d",a[0]);
	for(int i=1,len=n-1;i<len; ++i)
		printf(" %d",a[i]);
	printf(" %d\n",a[n-1]);
}


bool cmp_array(int *a,int *b,int n){
	for(int i=0;i<n;++i)
		if(a[i] != b[i]) return false;
	return true;
}


int main(){
	int i,j; 
	scanf("%d",&N);
	for(int i=0;i<N;++i) scanf("%d",A+i);
	for(int i=0;i<N;++i) scanf("%d",B+i);
	
	for(i=0; B[i]<=B[i+1] && i<N-1; ++i); // i will be the end of the sorted range
	for(j= ++i; A[j] == B[j] && j<N; ++j);// see if the following sequence has been modified
		
	if(j == N){ // the following sequence is not modified
		printf("Insertion Sort\n");
		sort(A,A+i+1);
	}
	else{
		printf("Merge Sort\n");
		int k=1;
		bool isNotEqual = true; 
		while(isNotEqual){
			isNotEqual = !cmp_array(A,B,N);
			k *=2;
			for(int i=0; i < N/k; ++i )
				sort(A+i*k, A+(i+1)*k);
			sort(A+k*(N/k), A+N); // sort the last range.
		}
	}
	print(A,N);
	
	
	return 0;
}
