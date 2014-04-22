// hdu 1299 poj 2917
// by utoppia

#include<cstdio>
int sovle(int x) {
    int ans = 1;
    for(int i=2,j;i*i<=x;++i) if(x%i==0) {
        j=0;
        while(x%i==0) {
            ++j;
            x/=i;
        }
        //printf("x=%d i=%d j=%d\n",x,i,j);
        ans *= (2*j+1);
    }
    if(x!=1) ans *= 3;
    return ans/2+1;
}
int main() {
    int n,T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas){
        scanf("%d",&n);
        printf("Scenario #%d:\n%d\n\n",cas,sovle(n));
    }
    return 0;
}
