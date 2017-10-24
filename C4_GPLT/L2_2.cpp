#include<iostream> 
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
//��ʾһ����� 
struct Node{
  int address;	//��ǰ���ĵ�ַ 
  int key,next; 
  Node(int ads,int k,int nxt):address(ads),key(k),next(nxt){}
  Node():key(0),next(-1),address(-1){}
};

//���һ����� 
ostream& operator<<(ostream& out,const Node& nd) {
  if(nd.next == -1) 
    printf("%05d %d %d",nd.address,nd.key,nd.next);
  else
    printf("%05d %d %05d",nd.address,nd.key,nd.next);
  return out;
}

typedef map<int,Node> Map; //key��address��value��Node�ṹ�� 

int main(){
  Map m; 
  int head,N,i;
  int  address,key,next;
  scanf("%d%d",&head,&N);
  while(N--){
    scanf("%d%d%d",&address,&key,&next);
    m[address] = Node(address,key,next);  
  }
  //��ʼ���� 
  address = head;
  vector<Node> v1,v2;//v1 v2�ֱ𱣴��������Ѻ������ 
  while(address!= -1){
    int key = m[address].key;
    bool find = false;
    for(int i=0;i<v1.size();++i)//��v1���ҵ�ǰ����key�Ƿ���� 
      if(abs(v1[i].key) == abs(key)){
        find = true;
        break;
      }
    //��������ڣ��ͷ���v1�У��������v2�� 
    if(!find){
      if(v1.size()){
        v1[v1.size()-1].next = address;//����һ������next��Ϊ��ǰ���ĵ�ַ 
        v1.push_back(Node(address,key,-1));
        //ÿ�η���һ����㣬�����Ľ���next��Ϊ-1 
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
    //������һ����� 
    address = m[address].next;
  }
  //�����������,copy��algorithm�µ�һ��ģ�庯�� 
  copy(v1.begin(),v1.end(),ostream_iterator<Node>(cout,"\n"));
  copy(v2.begin(),v2.end(),ostream_iterator<Node>(cout,"\n"));
}
