#include <iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
/*�� n �Ľ׳��� base �����µ�λ����������һ���򵥵ķ���������log10��n��+ 1���� n ����ʮ�����µ�λ����
�ɴ˿�֪ log base��n�� ����n��base �����µ�λ�����ٸ��ݻ��׹�ʽ��log base��n�� == log��n��/ log��base��������������ǽ׳ˣ�����log��ԭ���أ�
����log base ��n���� == �� log��n�� + log��n-1�� + log��n-2�� + ��������+ log��1���� / log��base������ sum �����һ�� log��n��) �Ϳ��Կ��ٵ������
*/double a[1000];
void pre(int x)
{
	for(int i=1;i<=x;i++)
		a[i]=a[i-1]+log((double)i);
}
int f(int x,int y)
{
	int m=(int)(a[x]/log((double)y))+1;
	return m;
}
int main()
{
    int t,w=0;
	cin>>t;
	while(t--)
	{
	    memset(a,0,sizeof(a));
		int n,m;
		cin>>n>>m;
		pre(n);
		cout<<"Case "<<++w<<": "<<f(n,m)<<endl;
	}

}
