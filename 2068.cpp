// POJ 2068
// by utoppia

#include<cstdio>
#include<cstring>

int win[2][11][1<<13];
int m[2][11],n,S;

int dfs(int now,int pos,int p) {
    if(win[now][pos][p] != -1) return win[now][pos][p];
    if(p==1) return win[now][pos][p] = 0;
    int nxt;
    if(now==0) nxt = pos;
    else nxt = (pos+1)%n;
    for(int i=1;i<=m[now][pos];++i) if(p>i && !dfs(now^1,nxt,p-i)) return win[now][pos][p] = 1;
    return win[now][pos][p] = 0;
}

int main() {
    while(scanf("%d",&n),n) {
        scanf("%d",&S);
        for(int i=0;i<n;++i) {
            scanf("%d%d",&m[0][i],&m[1][i]);
        }
        memset(win,-1,sizeof(win));
        if(dfs(0,0,S)) printf("1\n");else printf("0\n");
    }
    return 0;
}
