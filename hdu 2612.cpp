#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int INF=204;
int M=0xffffff;
int n,m,z;
char cnt[INF][INF];
int bx[]={1,-1,0,0};
int by[]={0,0,1,-1};
int dis[INF][INF][2];
int vis[INF][INF];
/*dis�����¼�����ͼ�ϵ�λ������Ҫ�Ĳ���
֮��������ά������ΪҪ��¼����״̬��Y��M��
֮��ȥѰ�ҵ���@λ�õ���С����
Ҫ��dis�����ʼ��Ϊ����󣨿��ܲ�����@��
���ݽϴ�Ӧ�ó�ʼ��ΪM���Ǹ�ֵ��0x7f7f7f7f������
*/
struct node
{
    int x;
    int y;
    int step;
};
queue<node>q;
bool check(int x,int y)
{
    if(x<1||x>n||y<1||y>m||vis[x][y]||cnt[x][y]=='#') return false;
    return true;
}
void bfs(int fx,int fy,int ans)
{
    memset(vis,0,sizeof(vis));
    vis[fx][fy]=1;
    q.push((node){fx,fy,ans});
    while(!q.empty())
    {
        node ss=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            node sw=ss;
            sw.x+=bx[i];
            sw.y+=by[i];
            sw.step++;
            if(check(sw.x,sw.y))
            {
                vis[sw.x][sw.y]=1;
                if(cnt[sw.x][sw.y]=='@')
                   dis[sw.x][sw.y][z]=sw.step;
                q.push(sw);
            }
        }
    }
}

int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<2;i++)
            for(int j=1;j<=n;j++)
            for(int k=1;k<=m;k++)
            dis[j][k][i]=M;
        for(int i=1; i<=n; i++)
            for(int j=1;j<=m;j++)
                cin>>cnt[i][j];
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
            {
                if(cnt[i][j]=='Y')
                {
                    z=1;
                    bfs(i,j,0);
                }
                if(cnt[i][j]=='M')
                {
                    z=0;
                    bfs(i,j,0);
                }
            }
        int ans=M;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(cnt[i][j]=='@')
                   {
                        ans=min(ans,dis[i][j][0]+dis[i][j][1]);
                   }
            }
        }
        cout<<ans*11<<endl;
    }
}
