#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<iterator>
using namespace std;
/*
题目大意：
输入N本书的信息：ID,title,author,keywords,publisher,publish year,
其中keywords由多个单词组成，出year外，其他子段中可能有空格 
输入M个查询，每个查询是上述子段中的某一个。
对每个查询，按升序输出其可能对应的ID。
 
解题思路:
由于title,author,keyword, publisher,year与书的ID都是一对多的关系,
所以将同一title的所有ID都放到一个set<string>中去，
然后将所有的title与其对应的set<string>都放到map<string,set<string> > 中去 
就能一次找到某个title对应所有书的ID了
其他子段都做同样的处理 
*/

map<string,set<string> > titles; //保存一个title对应的所有书的id
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
	scanf("%d",&N); //scanf()不会读取后面的换行符 
	getchar(); //所以需要用getchar()来读取掉后面的换行符 
	while(N--){
		getline(cin,id); //getline()会一并读取掉换行符，但不会添加到字符串中
		
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
