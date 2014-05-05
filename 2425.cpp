// HDU 2425
// by utoppia

#include<cstdio>
#include<cstring>
int const nMax = 1001000;

int first[nMax],to[nMax],nxt[nMax],e;
void addadge(int u,int v){
    to[e]=v;nxt[e]=first[u];first[u]=e;e++;
}
int sg[nMax];
int dfs(int u){
    if(sg[u]!=-1) return sg[u];
    int vis[1001]= {0};
    for(int i=first[u];i!=-1;i=nxt[i]) {
        vis[dfs(to[i])]=1;
    }
    for(int j=0;;j++) if(!vis[j]) return sg[u]=j;
}

int main(){
    int n,m;
    while(~scanf("%d",&n)){
        memset(first,-1,sizeof(first));e=0;
        for(int i=0,j,k;i<n;i++) {
            scanf("%d",&j);
            while(j--) {
                scanf("%d",&k);
                addadge(i,k);
            }
        }
        memset(sg,-1,sizeof(sg));
        while(~scanf("%d",&m),m){
            int SG=0,k;
            while(m--){
                scanf("%d",&k);
                SG ^= dfs(k);
            }
            printf("%s\n",SG?"WIN":"LOSE");
        }
    }
    return 0;
}
