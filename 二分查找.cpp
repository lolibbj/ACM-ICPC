#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int a[1000];
/*�ȶ�a�����������
��a[1]��a[n]֮��ȡ�м���a[mid]
���Ѱ�ҵ���t>a[mid] i=mid+1;
t<a[mid] j=mid-1;
��ѭ��i<=j��ȥѰ��a[mid]==t������*/ 
int erfen(int l,int r,int t)
{
    int i=l,j=r;
    while(i<=j)
    {
    	int mid=(i+j)/2;
        if(t==a[mid]) return mid;
        if(t>a[mid]) i=mid+1;
        if(t<a[mid]) j=mid-1;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int q;
    cin>>q;
    int m=erfen(1,n,q);
    cout<<m<<endl;
}

