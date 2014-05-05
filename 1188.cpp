// POJ 1188
// by utoppia

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<map>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define DOR(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define CLR(a) memset((a),0,sizeof((a)))
#define pb push_back
#define mp make_pair
#define ins insert
#define F first
#define S second
#define bug puts("Oh Here!");

#define nMax 10010
#define oo 0x7fffffff
#define eps 1e-8

#define LL long long
#define Vec vector<int>
#define Pai pair<int,int>
int t,n,p[nMax];
int main(){
#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
#endif
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",&p[i]);p[0]=0;
        int sg=0;
        sort(p,p+n+1);
        for(int i=n;i>0;i-=2){
            sg ^= (p[i]-p[i-1]-1);
        }
        printf("%s will win\n",sg?"Georgia":"Bob");
    }
    return 0;
}
