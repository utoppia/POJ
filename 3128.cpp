// poj 3128
// by utoppia

#include<cstdio>
int main() {
    int T;
    int vis[30],num[30];
    char s[30];
    scanf("%d",&T);
    while(T--) {
        scanf("%s",s);
        for(int i=0;s[i];++i) s[i]-='A';
        for(int i=0;i<26;++i) vis[i]=0;
        for(int i=0;i<30;++i) num[i]=0;
        for(int i=0;i<26;++i) if(!vis[i]) {
            int cnt=0,t=i;
            while(!vis[t]){
                cnt ++;
                vis[t]=1;
                t = s[t];
            }
            num[cnt]++;
        }
        int ok = 0;
        for(int i=2;i<27;i+=2) if(num[i]%2) {
            printf("No\n");
            ok = 1;
            break;
        }
        if(ok==0) printf("Yes\n");
    }
    return 0;
}
