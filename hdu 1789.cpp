#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>
typedef long long ll;
using namespace std;
/*̰����Ŀ
�Ȱ��շ�������Ȼ���Խ��������쿪ʼд
��������Ѿ�����ҵ����ǰ������û��λ�õĻ�
��sum+=w[i].b;
*/
int n,t,l,j;
int k=0x7f7f7f7f;
struct node
{
    int a,b;
}w[1000+100];
int vis[1000+100];
int cmp(node x, node y)
{
    if(x.b==y.b) return x.a<y.a;
    return x.b>y.b;
}
int main()
{
    while(cin>>t)
    {
        while(t--)
        {
            memset(vis,0,sizeof(vis));
            cin>>n;
            for(int i=1;i<=n;i++)
                cin>>w[i].a;
            for(int i=1;i<=n;i++)
                cin>>w[i].b;
            sort(w+1,w+n+1,cmp);
            int sum=0;
            for(int i=1;i<=n;i++)
            {
                for(j=w[i].a;j>=1;j--)
                {
                    if(!vis[j])
                    {
                        vis[j]=1;
                        break;
                    }
                }
            if(j==0) sum+=w[i].b;
            }
            cout<<sum<<endl;
        }
    }
}

