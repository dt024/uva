#include <iostream>
#include <map>
#include <vector>
#include <stdio.h>
using namespace std;
int n,m,d,c[100][100];
int main()
{
    map<string,int> mm;
    int ca=0;
    while(cin>>n>>m)
    {   ++ca;
        if(n==0 && m==0) break;
        mm.clear();
        d=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                c[i][j]=1e9;
                if(i==j) c[i][j]=0;
            }
        for(int i=1;i<=m;i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            if(mm[s1]==0) {++d; mm[s1]=d;}
            if(mm[s2]==0) {++d; mm[s2]=d;}
            c[mm[s1]][mm[s2]]=c[mm[s2]][mm[s1]]=1;
        }
        for(int k=1;k<=n;k++)
            for(int u=1;u<=n;u++)
                for(int v=1;v<=n;v++)
                c[u][v]=min(c[u][v],c[u][k]+c[k][v]);
        int res=-1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if(i!=j)
            {
                res=max(res,c[i][j]);

            }

        cout<<"Network "<<ca<<": ";
        if(res==1e9) cout<<"DISCONNECTED";
        else cout<<res;
        cout<<"\n\n";
    }
    return 0;
}
