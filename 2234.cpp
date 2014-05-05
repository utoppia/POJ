// POJ 2234
// by utoppia

#include<cstdio>
int main() {
    int n,a,sg;
    while(scanf("%d",&n) != EOF) {
        sg = 0;
        while(n--) scanf("%d",&a),sg ^= a;
        printf("%s\n",sg?"Yes":"No");
    }
    return 0;
}
