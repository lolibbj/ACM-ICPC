#include<cstdio>
#include<cstdio>
#include<iostream>
using  namespace  std;
long long mod(long long  a,long long b,long long c) {
    long long ans=1;
    while(b) {
        if(b&1)//λ�����൱��b%2==1.
            ans=ans*a%c;
        a=a*a%c;
        b>>=1;//λ�����൱��b/=2.
    }
    return ans;
}
int main () {
    long long b,p,k;
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" mod "<<k<<"=";
    cout<<mod(b,p,k)%k;
}
//a^b%c=(a%c)^b%c 
//a^b mod c=((a^2)^b/2)mod c,b��ż��
//a^b mod c=((a^2)^b/2*a)mod c,b������
//��������������ʽ�����ǿ��Եó����µĽ���:
//1.���b��ż�������ǿ��Լ�k=a^2 mod c,��ô��(k)^b2 mod c
//2.���b ���������ǿ��Լ�k=a^2 mod c,��ô��((k)^b2 mod c*a)mod c(��������) 
/*
 1 int poww(int a, int b) {
 2     int ans = 1, base = a;
 3     while (b != 0) {
 4         if (b & 1 != 0)
 5             ans *= base;
 6         base *= base;
 7         b >>= 1;
 8     }
 9     return ans;
10 }
*/ 
//a^b=((a^2)^b/2),b��ż��
//a^b=((a^2)^b/2*a),b������

