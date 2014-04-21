// POJ 1845
// by utoppia

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>

using namespace std;
typedef long long ll;
int const mod=9901;

ll EXP(ll a,ll b)
{
	if(b==0)return 1;
	ll k=EXP(a,b/2);
	k=(k*k)%mod;
	if(b&1)return (k*a)%mod;
	return k;
}

int a[10001];
int p[4000],k;

void make_p()
{
	int i;
	for(i=2;i<=100;i++)if(!a[i]){
		p[k++]=i;
		for(int j=i*i;j<10001;j+=i)a[j]=1;
	}
	for(;i<10001;i++)if(!a[i])p[k++]=i;
	return ;
}

void sovle(int a,int b)
{
	ll ans=(ll)1;
	for(int i=0;i<k&&p[i]<=a;i++)if(a%p[i]==0)
	{
		int c(0);
		while(a%p[i]==0)
		{
			c++;
			a/=p[i];
		}
	//	printf("p=%d c=%d\n",p[i],c);
		ans=(ans*(EXP(p[i],c*b+1)+mod-1))%mod;
		ans=(ans*EXP(p[i]-1,mod-2))%mod;
	}
	if(a>1){
		a%=mod;
	//	printf("a = %d\n",a);
		if(a==1){
			ans=(ans*(b+1))%mod;
		}else{
			ans=(ans*(EXP(a,b+1)+mod-1))%mod;
			ans=(ans*EXP(a-1,mod-2))%mod;
		}
	}
	printf("%d\n",(int)ans);
	return ;
}

int main()
{
	make_p();
	int a,b;
	while(cin>>a>>b)
	{
		sovle(a,b);
	}
	return 0;
}
