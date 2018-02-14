/*
1026. Table Tennis (30)
时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
A table tennis club has N tables available to the public. The tables are numbered from 1 to N. 
For any pair of players, if there are some tables open when they arrive, they will be assigned 
to the available table with the smallest number. If all the tables are occupied, they will have 
to wait in a queue. It is assumed that every pair of players can play for at most 2 hours.

Your job is to count for everyone in queue their waiting time, and for each table the number 
of players it has served for the day.

One thing that makes this procedure a bit complicated is that the club reserves some tables 
for their VIP members. When a VIP table is open, the first VIP pair in the queue will have 
the priviledge to take it. However, if there is no VIP in the queue, the next pair of players 
can take it. On the other hand, if when it is the turn of a VIP pair, yet no VIP table is 
available, they can be assigned as any ordinary players.

Input Specification:
Each input file contains one test case. For each case, the first line contains an integer 
N (<=10000) - the total number of pairs of players. Then N lines follow, each contains 2 
times and a VIP tag: HH:MM:SS - the arriving time, P - the playing time in minutes of a 
pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not. It is guaranteed 
that the arriving time is between 08:00:00 and 21:00:00 while the club is open. It is assumed 
that no two customers arrives at the same time. Following the players' info, there are 
2 positive integers: K (<=100) - the number of tables, and M (< K) - the number of VIP 
tables. The last line contains M table numbers.

Output Specification:
For each test case, first print the arriving time, serving time and the waiting time for 
each pair of players in the format shown by the sample. Then print in a line the number 
of players served by each table. Notice that the output must be listed in chronological 
order of the serving time. The waiting time must be rounded up to an integer minute(s). 
If one cannot get a table before the closing time, their information must NOT be printed.

Sample Input:
9
20:52:00 10 0
08:00:00 20 0
08:02:00 30 0
20:51:00 10 0
08:10:00 5 0
08:12:00 10 1
20:50:00 10 0
08:01:30 15 1
20:53:00 10 1
3 1
2

Sample Output:
08:00:00 08:00:00 0
08:01:30 08:01:30 0
08:02:00 08:02:00 0
08:12:00 08:16:30 5
08:10:00 08:20:00 10
20:50:00 20:50:00 0
20:51:00 20:51:00 0
20:52:00 20:52:00 0
3 3 2


*/
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
