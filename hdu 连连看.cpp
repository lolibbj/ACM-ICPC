#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 1000+100
int n,m,a,b,c,d,flag;
int map[MAXN][MAXN];
bool vis[MAXN][MAXN];
int bx[]={-1,1,0,0};
int by[]={0,0,1,-1};
/*�ؼ���Ѱ����ת�ǵĴ�����step����¼dirt��ʾ����
ö���ĸ�����ֻҪ����ͬ˵��������һ��ת��step�ͼ�1
�淽��Ļ��Ѿ��߹����ɵ������һ��ʼ���淽��
*/ 
void dfs(int x,int y,int step,int dirt)
{
	if(flag) return;
	if(x>n||x<1||y>m||y<1||vis[x][y]) return;//Խ������Ѿ��� 
	if(step==2&&x!=c&&y!=d) return;//ת�����ε���û�� 
	if(step>2) return; 
	if(x==c&&y==d&&step<=2)
	{
		flag=1;
		return;
	}
	if(map[x][y])//�����ĵ㲻Ϊ0���Ҳ������ 
	{
		if(x!=a||y!=b) return;
	}
    vis[x][y]=true;
	for(int i=0;i<4;i++)
	{
		int dx=x+bx[i];
		int dy=y+by[i];
		if(i==dirt) dfs(dx,dy,step,dirt);
		else dfs(dx,dy,step+1,i);
    } 
	vis[x][y]=false;
}
/*bool check(int x,int y,int fx,int fy)
{
	if(map[x][y]!=map[fx][fy]||(!map[x][y]||!map[fx][fy])||((x==fx)||(y==fy))) return false;
	else if(x<1||x>n||y<1||y>m||fx<1||fx>n||fy<1||fy>m) return false;
	else if(map[x][y]==map[fx][fy]&&map[x][y])
	{
		for(int i=0;i<4;i++)
		    dfs(x,y,0,i);
		if(!flag) return true;
		else return false;
	}
	else return false;
}
*/int main()
{
	while(scanf("%d %d",&n,&m)!=EOF&&n!=0&&m!=0)
	{
		memset(map,0,sizeof(map));
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		    cin>>map[i][j];
		int k;
		cin>>k;
		while(k--)
		{
		    cin>>a>>b>>c>>d;
              if(a==c&&b==d)//�����յ���ͬ 
			  {
                  cout<<"NO"<<endl;
                  continue;
              }
              if(a<1||a>n||b<1||b>m||c<1||c>n||d<1||d>m)//Խ�� 
              {
                  cout<<"NO"<<endl;
                  continue;
              }
              if(map[a][b]==map[c][d]&&map[a][b])
              {
                  flag=0;
                  for(int i=0;i<4;i++)
                      dfs(a,b,0,i);
                  if(!flag)
                    cout<<"NO"<<endl;
                  else
                     cout<<"YES"<<endl;
              }
              else
                  cout<<"NO"<<endl;
		}
	}
	return 0;
 } 
