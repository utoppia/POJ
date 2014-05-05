// POJ 2368
// by utoppia

#include<cstdio>
#include<cstring>
#include<math.h>

int k,l;
int main(){
    while(~scanf("%d",&k)){
        if(k<=2) {
            puts("0");
            return 0;
        }
        int n=(int)sqrt(1.0*k+0.5);
        for(l=3;l<=n+1;l++)if(k%l==0){
            printf("%d\n",l-1);
            return 0;
        }
        if(k%2==0 && k/2-1>=2) printf("%d\n",k/2-1);
        else printf("%d\n",k-1);
        return 0;
    }
    return 0;
}
