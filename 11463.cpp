#include <iostream>
#include <stdio.h>
using namespace std;
int n,r,c[200][200];
int main()
{
   // freopen("test.inp","r",stdin);
    int tc;
    cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        cin>>n;
        cin>>r;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) c[i][j]=1e9;

        for(int i=1;i<=r;i++)
        {
            int u,v;
            cin>>u>>v;
            c[u][v]=1;
            c[v][u]=1;
            c[u][u]=0;
            c[v][v]=0;
        }
        int s,t;
        cin>>s>>t;
        for(int k=0;k<n;k++)
            for(int u=0;u<n;u++)
                for(int v=0;v<n;v++)
                    c[u][v]=min(c[u][v],c[u][k]+c[k][v]);
        int res=0;
        for(int i=0;i<n;i++)
        {
            if(c[s][i]!=1e9 && c[i][t]!=1e9)
            res=max(res,c[s][i]+c[i][t]);
        }
        cout<<"Case "<<z<<": "<<res<<"\n";
    }
}
