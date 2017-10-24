#include<iostream> 
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
//表示一个结点 
struct Node{
  int address;	//当前结点的地址 
  int key,next; 
  Node(int ads,int k,int nxt):address(ads),key(k),next(nxt){}
  Node():key(0),next(-1),address(-1){}
};

//输出一个结点 
ostream& operator<<(ostream& out,const Node& nd) {
  if(nd.next == -1) 
    printf("%05d %d %d",nd.address,nd.key,nd.next);
  else
    printf("%05d %d %05d",nd.address,nd.key,nd.next);
  return out;
}

typedef map<int,Node> Map; //key是address，value是Node结构体 

int main(){
  Map m; 
  int head,N,i;
  int  address,key,next;
  scanf("%d%d",&head,&N);
  while(N--){
    scanf("%d%d%d",&address,&key,&next);
    m[address] = Node(address,key,next);  
  }
  //开始分裂 
  address = head;
  vector<Node> v1,v2;//v1 v2分别保存两个分裂后的链表 
  while(address!= -1){
    int key = m[address].key;
    bool find = false;
    for(int i=0;i<v1.size();++i)//在v1中找当前结点的key是否存在 
      if(abs(v1[i].key) == abs(key)){
        find = true;
        break;
      }
    //如果不存在，就放入v1中，否则放入v2中 
    if(!find){
      if(v1.size()){
        v1[v1.size()-1].next = address;//将上一个结点的next设为当前结点的地址 
        v1.push_back(Node(address,key,-1));
        //每次放入一个结点，都将改结点的next设为-1 
      }
      else 
        v1.push_back(Node(address,key,-1));
    }
    else{
      if(v2.size()){
        v2[v2.size()-1].next = address;
        v2.push_back(Node(address,key,-1));
      }
      else
        v2.push_back(Node(address,key,-1));
    }
    //访问下一个结点 
    address = m[address].next;
  }
  //输出两个链表,copy是algorithm下的一个模板函数 
  copy(v1.begin(),v1.end(),ostream_iterator<Node>(cout,"\n"));
  copy(v2.begin(),v2.end(),ostream_iterator<Node>(cout,"\n"));
}
