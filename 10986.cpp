#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1e9
int n,m,s,t;
int u1,v1,w;
int main()
{
    priority_queue <ii,vector<ii>,greater<ii> > pq;
    vector<vii> a;
    vi d;
    int ts;
    //cin>>ts;
    //for(int k=1;k<=ts;k++)
    //{
        cin>>n>>m>>s>>t;
        for(int i=1;i<n;i++) a[i].clear();
        for(int i=1;i<=m;i++)
        {
            cin>>u1>>v1>>w;
            a[u1].push_back(ii(v1,w));
            a[v1].push_back(ii(u1,w));
        }
        pq.push(ii(0,s));

        d.assign(n,INF);
        d[s]=0;
        while(!pq.empty())
        {
            ii front=pq.top();
            int du=front.first;
            int u=front.second;
            if(du==d[u])
            {
                for(int j=0;j<a[u].size();j++)
                {
                    ii v=a[u][j];
                    if(d[u]+v.second<d[v.first])
                    {
                        d[v.first]=d[u]+v.second;
                        pq.push(ii(d[v.first],v.first));
                    }
                }
            }
        }
        cout<<d[t]<<"\n";
   // }
}
