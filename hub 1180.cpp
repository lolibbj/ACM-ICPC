#include <stdio.h>  
#include <algorithm>  
#include <iostream>  
#include <queue>  
#include <string.h>  
using namespace std;  
  
const int N = 50;  
const int INF = 1000000;  
  
char Map[N][N];  
bool vis[N][N];  
int n, m;  
  
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  
  
struct node  
{  
    int x, y;  
    int step;  
    friend bool operator < (const node &a, const node &b)  
    {  
        return a.step > b.step;  
    }  
};  
  
node st;  
  
bool check(int x, int y)  
{  
    if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && Map[x][y] != '*') return true;  
    else return false;  
}  
  
int bfs(int x, int y)  
{  
    char c;  
    priority_queue <node> q;  
    node s_pos;  
    s_pos.x = x;  
    s_pos.y = y;  
    s_pos.step = 0;  
    vis[s_pos.x][s_pos.y] = 1;  
    q.push(s_pos);  
    while(!q.empty())  
    {  
        node tmp = q.top();  
        q.pop();  
        for(int i = 0; i < 4; i ++)  
        {  
            node tmp2;  
            tmp2 = tmp;  
            tmp2.x += dir[i][0];  
            tmp2.y += dir[i][1];  
            tmp2.step += 1;  
            if(check(tmp2.x, tmp2.y) && (Map[tmp2.x][tmp2.y] == '-' || Map[tmp2.x][tmp2.y] == '|'))  
            {  
                if(tmp2.step % 2 == 1)  
                {  
                    if(Map[tmp2.x][tmp2.y] == '-') c = '|';  
                    else if(Map[tmp2.x][tmp2.y] == '|') c = '-';  
                }  
                else c = Map[tmp2.x][tmp2.y];  
                tmp2.x += dir[i][0];  
                tmp2.y += dir[i][1];  
                if((c == '-' && (dir[i][1] == -1 || dir[i][1] == 1)) || (c == '|' && (dir[i][0] == -1 || dir[i][0] == 1)))  
                {  
                    tmp2.step += 1;  
                }  
            }  
            if(check(tmp2.x, tmp2.y))  
            {  
                if(Map[tmp2.x][tmp2.y] == 'T') return tmp2.step;  
                vis[tmp2.x][tmp2.y] = 1;  
                q.push(tmp2);  
            }  
        }  
    }  
    return -1;  
}  
  
int main()  
{  
    while(~scanf("%d%d", &n, &m))  
    {  
        for(int i = 0; i < n; i ++)  
            for(int j = 0; j < m; j ++)  
            {  
                cin >> Map[i][j];  
                if(Map[i][j] == 'S')  
                {  
                    st.x = i;  
                    st.y = j;  
                }  
            }  
        memset(vis, 0, sizeof(vis));  
        int ans = bfs(st.x, st.y);  
        printf("%d\n", ans);  
    }  
    return 0;  
}  

