#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
/*�ο��Ĵ���
*/
const int INF=100000000;
int vis[12];
int a[12],ans;
void DFS(int cur,int temp)//cur�����Ѿ��ƶ��˼����ƣ�temp����Ŀǰ�ƶ��ķѵĲ������Ѳ���д������������һֱ���ɻ�
{
    if(temp>=ans)return;  //��֦ ̫��Ҫ�ˣ���
    if(cur==9)     //ԭ��д��10��ֻ���ƶ�9�� 10�ǹ̶������ ������Ҫ˼�� ��ԭ������ʱ��ʲô��û�� ��һ��������ö��
    {
        ans=temp; //ԭ��temp=0����Ȼ������������ ���Ѿ�ȷ����ǰֵ��ԭ����Ҫ�Ż�
        return;   //���ݣ�������Ȼ�����temp������
    }
     for(int i=1;i<10;i++)//�ݹ���д��������һ��ȫ�����ˣ�+��������أ�
     {
        if(!vis[i])
        {
            for(int k=i+1;k<=10;k++)//�������ȷ��i��Ҫ�Ƶ�ʲôλ��
            {
                if(!vis[k])//����Ҫ��1�ˣ����2,3,4,5���Ѿ����ƶ����� ��ô�⼸���Ʊض�������6�����棬����Ҫ�Ƶ�6��λ��
                {
                    vis[i]=1;
                    DFS(cur+1,temp+abs(a[i]-a[k]));
                    break;//ע�ⲻҪ������ط����� ��������� ��������һ��ȫ���� �����Ƶ��ƶ�����������2�Ƶ�6�ˣ�������ݾ�ֱ������3~6����7������
                }
            }
            vis[i]=0;//�������
        }
     }
    return ;
}
int main()
{
    int cas,s;
    cin>>cas;
    while(cas--)
    {
        for(int i=1;i<=10;i++)
        {
             cin>>s;
             a[s]=i;//����Ϊs�������ڵ�λ��
        }
        memset(vis,0,sizeof(vis));

        ans=INF;
        DFS(0,0);
        cout<<ans<<endl;

    }
}
