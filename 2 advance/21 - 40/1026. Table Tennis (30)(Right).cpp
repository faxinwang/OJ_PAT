#include<iostream>  
#include<vector>  
#include<algorithm>  
#include<string>  
using namespace std;  
  
typedef struct Node  
{  
    int arrive, process, tag;  
    int serve, wait;//...  
}Node;  
typedef struct Table  
{  
    int tag;  
    int freeTime, num;//...  
}Table;  
bool CmpArrive(Node a, Node b)  
{  
    return a.arrive < b.arrive;  
}  
bool CmpServe(Node a, Node b)  
{  
    if(a.serve == b.serve)  
        return a.arrive < b.arrive;  
    else return a.serve < b.serve;  
}  
#define INF 0x6FFFFFFF  
//vector<bool> visited;  
vector<Node> user;  
vector<Table> table;  
void UpdateInfo(int userID, int tableID)  
{  
    user[userID].serve = max(user[userID].arrive, table[tableID].freeTime);  
    user[userID].wait = user[userID].serve-user[userID].arrive;  
    table[tableID].num++;  
    table[tableID].freeTime = user[userID].serve+min(user[userID].process, 7200);  
}  
int main()  
{ 
#ifdef WFX
freopen("1026 in.txt","r",stdin);
#endif
    //input  
    int n;  
    scanf("%d",&n);  
      
    user.resize(n);  
    for(int i = 0; i < n; ++i)  
    {  
        int h, m, s;  
        scanf("%d:%d:%d %d%d",&h,&m,&s,&user[i].process,&user[i].tag);  
        user[i].arrive = h*3600+m*60+s;  
        user[i].process *= 60;  
        user[i].serve = INF; user[i].wait = INF;//initial variable  
    }  
    int k, m;  
    scanf("%d%d",&k,&m);  
      
    table.resize(k);  
    for(int i = 0; i < k; ++i)  
        table[i].freeTime = 8*3600, table[i].tag = 0, table[i].num = 0;  
    for(int i = 0; i < m; ++i)  
    {  
        int c;  
        scanf("%d",&c); c--;  
        table[c].tag = 1;  
    }  
    //process  
    sort(user.begin(), user.end(), CmpArrive);  
    //visited.assign(n, false);  
    for(int i = 0; i < n; ++i)  
    {  
        if(user[i].serve != INF) continue;  
        int minFreeTime = INF;  
        for(int j = 0; j < k; ++j)  
            minFreeTime = min(minFreeTime, table[j].freeTime);  
        int timePoint = max(user[i].arrive, minFreeTime);  
        if(timePoint >= 21*3600) break;  
        vector<int> userList;  
        vector<int> tableList;  
        for(int j = i; j < n; ++j)  
            if(user[j].serve == INF && user[j].arrive <= timePoint) userList.push_back(j);  
        for(int j = 0; j < k; ++j)  
            if(table[j].freeTime <= timePoint) tableList.push_back(j);  
          
        bool flag = false;//record if it is served  
       
            for(int t = 0; t < tableList.size() && !flag; ++t)  
            {  
                if(table[tableList[t]].tag == 1)  
                {  
                    for(int u = 0; u < userList.size(); ++u)  
                    {  
                        if(user[userList[u]].tag == 1)  
                        {  
                            flag = true;  
                            UpdateInfo(userList[u], tableList[t]);  
                            break;  
                        }  
                    }  
                }  
            }  
            
        if(!flag) UpdateInfo(userList[0], tableList[0]);  
        --i;  
    }  
    //output  
    sort(user.begin(), user.end(), CmpServe);  
    for(int i = 0; i < n; ++i)  
    {  
        if(user[i].serve >= 21*3600) break;  
        int h1, m1, s1, h2, m2, s2;  
        int t = user[i].arrive;  
        h1 = t/3600; t %= 3600;  
        m1 = t/60; t %= 60;  
        s1 = t;  
        t = user[i].serve;  
        h2 = t/3600; t %= 3600;  
        m2 = t/60; t %= 60;  
        s2 = t;  
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", h1, m1, s1, h2, m2, s2, (user[i].wait+30)/60);  
    }  
    for(int i = 0; i < k; ++i)  
    {  
        if(i != k-1)  
            printf("%d ",table[i].num);  
        else printf("%d\n",table[i].num);  
    }  
    return 0;  
}  
