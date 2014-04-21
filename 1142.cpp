// hdu 1333 , poj 1142
// by utoppia

#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int p[11000],a[11000],k;
void init() {
    for(int i=2;i<1000;++i) if(!a[i]) {
        p[k++] = i;
        for(int j=i*i;j<11000;j+=i) a[j]=1;
    }
    for(int i=1000;i<11000;++i) if(!a[i]) p[k++] = i;

}
int sum(int x) {
    int ans = 0;
    while(x) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}
int chk(int x) {
    int s1 = sum(x);
    int s2 = 0;
    int cnt=0;
    for(int i=0;i<k&&p[i]<=x;++i) if(x%p[i]==0) {
        while(x%p[i]==0) {
            s2 += sum(p[i]);
            x /= p[i];
            cnt ++;
        }
    }
    if(x!=1) s2 += sum(x),cnt++;
    return cnt!=1 && s1 == s2;
}
int main() {
    int n;
    init();
    while(scanf("%d",&n),n){

        for(int i=n+1;;++i) if(chk(i)){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
