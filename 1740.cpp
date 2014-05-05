// POJ 1740
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

int a[nMax];
int n;

int main(){
#ifndef ONLINE_JUDGE
//    freopen("input.txt","r",stdin);
#endif
    while(scanf("%d",&n),n){
        CLR(a);
        for(int i=0,j;i<n;i++){
            scanf("%d",&j);
            a[j]++;
        }
        if(n&1) printf("1\n");
        else {
            int ok=0;
            for(int i=0;i<=100;i++) if(a[i]&1) {
                ok=1;
                break;
            }
            printf("%d\n",ok);
        }
    }
    return 0;
}
