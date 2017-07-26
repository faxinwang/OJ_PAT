#include<iostream>
using namespace std;


int maxSum(int *a,int n,int &first,int &last){
	//if the sequence is -1 0 -2,then the output should be 0 0 0,
	//so the maxsum should be initialized to -1
	int maxsum=-1,thissum=0,begin=0;
	first=last=a[0];
	for(int i=0;i<n;++i){
		thissum+=a[i];
		if(maxsum<thissum){
			maxsum=thissum;
			first=a[begin];
			last=a[i];
		}else if(thissum<0){
			thissum=0;
			begin=i+1;
		}
	}
	//If all the K numbers are negative, then its maximum sum is 
	//defined to be 0, and you are supposed to output the first and the 
	//last numbers of the whole sequence.
	if(maxsum==-1){
		maxsum=0;
		first=a[0];
		last=a[n-1];
	}
	return maxsum;
}

int main(){
	int K,a[10001];
	int maxsum,first,last;
	cin>>K;
	for(int i=0;i<K;++i){
		scanf("%d",a+i);
	}
	maxsum=maxSum(a,K,first,last);
	cout<<maxsum<<' '<<first<<' '<<last<<endl;
		
	return 0;
}
