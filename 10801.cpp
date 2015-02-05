/* uva 10801
NOT AC */
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define x first
#define y second
#define INF 1e9
int n,k,t[10],pos[105];
vector<vii> a(1000);
    vi dist(1000);
    priority_queue<ii, vector<ii>, greater<ii> > pq;
int dijkstra()
{
    for(int i=0;i<=600;i++) dist[i]=INF;
    dist[0]=0;
    pq.push(ii(0,0));
    while(!pq.empty())
    {
        ii front=pq.top();
        //cout<<front.second<<"\n";
        pq.pop();
        int u=front.second;
        int d=front.first;
        if(d==dist[u])
        {
            for(int i=0;i<a[u].size();i++)
            {
                ii v=a[u][i];
                if(dist[u]+v.second<dist[v.first])
                {
                    dist[v.first]=dist[u]+v.second;
                    pq.push(ii(dist[v.first],v.first));
                }
            }
        }
    }
}
int main()
{
            string s;
    freopen("test.inp","r",stdin);
        freopen("test.out","w",stdout);
    while(cin>>n>>k)
    {
        for(int i=0;i<=500;i++) a[i].clear();
        for(int i=0;i<=100;i++) {pos[i]=0;}
        for(int i=1;i<=n;i++) cin>>t[i];
        getline(cin,s);
        for(int i=1;i<=n;i++)
        {
            getline(cin,s);
            stringstream ss(s);
            int u,v;
            ss>>u;
           // cout<<u<<"\n";
           if(u!=0)
           {
                u=u+(i-1)*100;
                if(pos[u-(i-1)*100]!=0)
                {
                    a[u].push_back(ii(pos[u-(i-1)*100],60));
                    a[pos[u-(i-1)*100]].push_back(ii(u,60));
                }
                else pos[u-(i-1)*100]=u;
           }
            while(ss>>v)
            {
             //   cout<<u<<" "<<v<<"\n";
                v=v+(i-1)*100;
                if(pos[v-(i-1)*100]!=0)
                {
                    a[v].push_back(ii(pos[v-(i-1)*100],60));
                    a[pos[v-(i-1)*100]].push_back(ii(v,60));
                }
                else pos[v-(i-1)*100]=v;
                a[u].push_back(ii(v,abs((u%100)-(v%100))*t[i]));
                a[v].push_back(ii(u,abs((u%100)-(v%100))*t[i]));
                u=v;
            }
        }
        dijkstra();
        for(int i=0;i<300;i++) cout<<i<<" "<<dist[i]<<"\n";
       /* {
            cout<<i<<" ";
            for(int j=0;j<a[i].size();j++) cout<<a[i][j].x<<" ";
            cout<<"\n";
        }
        int res=1e9;
            for(int i=1;i<=5;i++)  res=min(res,dist[k+(i-1)*100]);
            if(res==1e9) cout<<"IMPOSSIBLE";
            else cout<<res;
            cout<<"\n";*/
    }
    return 0;
}
