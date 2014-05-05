// POJ 2311
// by utoppia

#include<cstdio>
#include<cstring>

int sg[210][210];
int dfs(int x,int y) {
    if(sg[x][y] != -1) return sg[x][y];
    bool vis[210] = {0};
    for(int i=2;i<=x/2;++i) vis[dfs(i,y) ^ dfs(x-i,y)] = 1;
    for(int i=2;i<=y/2;++i) vis[dfs(x,i) ^ dfs(x,y-i)] = 1;
    for(int i=0;i<210;++i) if(!vis[i]) return sg[x][y] = i;
}

int main() {
    memset(sg,-1,sizeof(sg));
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(dfs(n,m)) printf("WIN\n");
        else printf("LOSE\n");
    }
    return 0;
}
