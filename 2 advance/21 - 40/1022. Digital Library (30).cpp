/*
1022. Digital Library (30)
ʱ������
1000 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
A Digital Library contains millions of books, stored according to their titles, authors, 
key words of their abstracts, publishers, and published years. Each book is assigned an 
unique 7-digit number as its ID. Given any query from a reader, you are supposed to output 
the resulting books, sorted in increasing order of their ID's.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive 
integer N (<=10000) which is the total number of books. Then N blocks follow, each contains 
the information of a book in 6 lines:

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white 
	space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].

It is assumed that each book belongs to one author only, and contains no more than 5 key words; 
there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which 
is the number of user's search queries. Then M lines follow, each in one of the formats shown below:

1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year

Output Specification:
For each query, first print the original query in a line, then output the resulting book 
ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.

Sample Input:
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla

Sample Output:
1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found


��Ŀ���⣺
����N�������Ϣ��ID,title,author,keywords,publisher,publish year,
����keywords�ɶ��������ɣ���year�⣬�����ֶ��п����пո� 
����M����ѯ��ÿ����ѯ�������ֶ��е�ĳһ����
��ÿ����ѯ���������������ܶ�Ӧ��ID��
 
����˼·:
����title,author,keyword, publisher,year�����ID����һ�Զ�Ĺ�ϵ,
���Խ�ͬһtitle������ID���ŵ�һ��set<string>��ȥ��
Ȼ�����е�title�����Ӧ��set<string>���ŵ�map<string,set<string> > ��ȥ 
����һ���ҵ�ĳ��title��Ӧ�������ID��
�����Ӷζ���ͬ���Ĵ��� 
*/ 

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;

map<string,set<string> > titles; //����һ��title��Ӧ���������id
map<string,set<string> > authors;
map<string,set<string> > keys;
map<string,set<string> > publishers;
map<string,set<string> > years;

int main(){
#ifdef WFX
freopen("1022 in.txt","r",stdin);
#endif 
	int N;
	string id,title,auth,words,pub,year;
	string key;
	scanf("%d",&N); //scanf()�����ȡ����Ļ��з� 
	getchar(); //������Ҫ��getchar()����ȡ������Ļ��з� 
	while(N--){
		getline(cin,id); //getline()��һ����ȡ�����з�����������ӵ��ַ�����
		
		getline(cin, title);
		titles[title].insert(id);
		
		getline(cin,auth);
		authors[auth].insert(id);
		
		getline(cin,words);
		stringstream ss(words);
		while(ss>>key) keys[key].insert(id);
		
		getline(cin,pub);
		publishers[pub].insert(id);
		
		getline(cin,year);
		years[year].insert(id);
	}
	
	int M;
	string query;
	scanf("%d",&M);  
	getchar();
	while(M--){
		getline(cin,query);
		cout<<query<<endl;
		char ch  = query[0];
		query = query.substr(3);
		set<string>* s=0;
	
		switch(ch){
		case '1': s = titles.find(query) != titles.end()? 		&titles[query] : 0 ;		break;
		case '2': s = authors.find(query) != authors.end()? 	&authors[query] : 0;	 	break;
		case '3': s = keys.find(query) != keys.end()? 			&keys[query]: 0; 			break;
		case '4': s = publishers.find(query)!= publishers.end()? &publishers[query]:0;		break;
		case '5': s = years.find(query) != years.end()? 		&years[query]:0;			break;
		}
		if(s != 0)
			copy(s->begin(),s->end(),ostream_iterator<string>(cout,"\n"));
		else
			cout<<"Not Found"<<endl;
	}
	
	
	return 0;
}
