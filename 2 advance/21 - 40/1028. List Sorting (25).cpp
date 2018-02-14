/*
1028. List Sorting (25)
时间限制
200 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
Excel can sort records according to any column. Now you are supposed to imitate this function.

Input
Each input file contains one test case. For each case, the first line contains two integers 
N (<=100000) and C, where N is the number of records and C is the column that you are supposed 
to sort the records with. Then N lines follow, each contains a record of a student. A 
student's record consists of his or her distinct ID (a 6-digit number), name (a string 
with no more than 8 characters without space), and grade (an integer between 0 and 100, 
inclusive).

Output
For each test case, output the sorting result in N lines. That is, if C = 1 then the records 
must be sorted in increasing order according to ID's; if C = 2 then the records must be 
sorted in non-decreasing order according to names; and if C = 3 then the records must be 
sorted in non-decreasing order according to grades. If there are several students who have 
the same name or grade, they must be sorted according to their ID's in increasing order.

Sample Input 1
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60

Sample Output 1
000001 Zoe 60
000007 James 85
000010 Amy 90

Sample Input 2
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98

Sample Output 2
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60

Sample Input 3
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90

Sample Output 3
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90

题目大意:
输入N(<=10000)个学生的信息，根据一下三种不同子段排序:
c1: increasing order according to ID's 
c2: non-decreasing order according to names
c3: non-decreasing order according to grades
如果姓名或成绩相同，则按ID升序排序
*/ 
#include<iostream> 
#include<algorithm>
#include<cstring>
#define maxn 100005
using namespace std;

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
