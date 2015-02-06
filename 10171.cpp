#include <iostream>
#include <vector>
using namespace std;
int y[50][50],m[50][50];
vector<int> a,b;
bool checky[50],checkm[50];
int n;
int main()
{
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
            {
                y[i][j]=1e9;
                m[i][j]=1e9;
                if(i==j) y[i][j]=m[i][j]=0;
            }

        for(int i=1;i<=n;i++)
        {
            char c2,c1;
            char u,v;
            int w;
            cin>>c1>>c2;
            if(c2=='U')
            {
                cin>>u>>v>>w;
                if(c1=='Y')
                    y[u-'A'][v-'A']=min(w,y[u-'A'][v-'A']);
                else
                    m[u-'A'][v-'A']=min(w,m[u-'A'][v-'A']);
            }
            else
            {
                cin>>u>>v>>w;
                if(c1=='Y')
                {
                    y[u-'A'][v-'A']=min(w,y[u-'A'][v-'A']);
                    y[v-'A'][u-'A']=min(w,y[v-'A'][u-'A']);;
                }

                else
                {
                    m[u-'A'][v-'A']=min(w,m[u-'A'][v-'A']);
                    m[v-'A'][u-'A']=min(w,m[v-'A'][u-'A']);;

                }
            }
        }
        for(int k=0;k<26;k++)
            for(int u=0;u<26;u++)
                for(int v=0;v<26;v++)
                {
                    y[u][v]=min(y[u][v],y[u][k]+y[k][v]);
                    m[u][v]=min(m[u][v],m[u][k]+m[k][v]);
                }

        char s1,t1;
        cin>>s1>>t1;
        int s,t;
        s=s1-'A';
        t=t1-'A';
        vector<char> cur;
        int res=1e9+7;
        for(int i=0;i<26;i++)
        if(y[s][i]+m[t][i]<res && y[s][i]!=1e9 && m[t][i]!=1e9)
        {
            res=y[s][i]+m[t][i];
            cur.clear();
            cur.push_back(i+'A');
        }
        else if(y[s][i]+m[t][i]==res && y[s][i]!=1e9 && m[t][i]!=1e9)
        {
            cur.push_back(i+'A');
        }
        if(res!=1e9+7)
        {
            cout<<res<<" ";
            for(int i=0;i<cur.size()-1;i++) cout<<cur[i]<<" ";
            cout<<cur[cur.size()-1];
            cout<<"\n";
        }
        else cout<<"You will never meet."<<"\n";
    }
    return 0;
}
