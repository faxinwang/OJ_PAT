#include<iostream> 
#include<algorithm>
#include<cstring>
#define maxn 100005
using namespace std;

/*
题目大意:
输入N(<=10000)个学生的信息，根据一下三种不同子段排序:
c1: increasing order according to ID's 
c2: non-decreasing order according to names
c3: non-decreasing order according to grades
如果姓名或成绩相同，则按ID升序排序
*/

struct Stu{
	char  id[8];
	char name[10];
	int grade;
};

Stu s[maxn];
int a[maxn];

bool sort_by_id(int s1,int s2){
	return strcmp(s[s1].id , s[s2].id) < 0;
}

bool sort_by_name(int s1,int s2){
	return strcmp(s[s1].name , s[s2].name) <=0 ;
}

bool sort_by_grade(int s1,int s2){
	return s[s1].grade <= s[s2].grade;
}

int main(){
	int n,c;
	scanf("%d%d",&n,&c);
	for(int i=0;i<n;++i){
//		cin>>s[i].id>>s[i].name>>s[i].grade;
		scanf("%s%s%d",s[i].id,s[i].name, &s[i].grade);
	}
	for(int i=0;i<n;++i) a[i] = i;
	switch(c){
	case 1: sort(a,a+n, sort_by_id);	break;
	case 2: sort(a,a+n, sort_by_name); 	break;
	case 3: sort(a,a+n, sort_by_grade);	break;
	}
	for(int i=0;i<n;++i){
		//提交测试好好几次，有时候cout快，有时候printf快。 
//		cout<<s[a[i]].id<<" "<<s[a[i]].name<<" "<<s[a[i]].grade<<endl;
		printf("%s %s %d\n",&s[a[i]].id[0], &s[a[i]].name[0], s[a[i]].grade);
	} 
	
	
	return 0;
}
