// poj 2888
// by utoppia

#include<cstdio>
#include<cstring>

int m;
int mo = 9973;
struct Matrix{
    int a[20][20];
    Matrix () { memset(a,0,sizeof(a));}
    void clear() { memset(a,0,sizeof(a)); }
    friend Matrix operator * (const Matrix& x,const Matrix& y) {
        Matrix ret;
        for(int i=0;i<m;++i)
            for(int j=0;j<m;++j) {
                for(int k=0;k<m;++k)
                    ret.a[i][j] += x.a[i][k]*y.a[k][j] % mo;
                ret.a[i][j] %= mo;
            }
        return ret;
    }
};

Matrix pow(Matrix a,int n) {
    if(n==0) {
        Matrix ret;
        for(int i=0;i<m;++i) ret.a[i][i] = 1;return ret;
    }
    Matrix ret = pow(a,n>>1);
    ret = ret*ret;
    if(n&1) ret = ret*a ;
    return ret;
}
int gcd(int a,int b) { return b==0 ? a : gcd(b,a%b);}
int Sum(Matrix a){
    int ans = 0;
    for(int i=0;i<m;++i) ans += a.a[i][i];
    return ans % mo;
}
int pow(int a,int n) {
    if(n==0) return 1;
    int k=pow(a,n>>1);
    k = k*k % mo;
    if(n&1) k = k*a % mo;
    return k;
}
int phi(int x){
    int ret = x;
    for(int i=2;i*i<=x;++i) if(x%i==0) {
        ret = ret/i*(i-1);
        while(x%i==0) x/=i;
    }
    if(x!=1) ret=ret/x*(x-1);
    return ret%mo;
}
int main() {
    int T,n,k;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&m,&k);
        Matrix a;
        for(int i=0;i<m;++i) for(int j=0;j<m;++j) a.a[i][j] = 1;
        for(int i=0,x,y;i<k;++i) {
            scanf("%d%d",&x,&y);
            a.a[x-1][y-1] = a.a[y-1][x-1] = 0;
        }
        int ans = 0;
        for(int i=1;i*i<=n;++i) if(n%i==0){
            if(i*i==n) {
                ans = (ans+Sum(pow(a,i))*phi(i)%mo)%mo;
            }else {
                ans = (ans + Sum(pow(a,i))*phi(n/i) + Sum(pow(a,n/i))*phi(i)) % mo;
            }
        }
        ans = ans*pow(n%mo,mo-2)%mo;
        printf("%d\n",ans);
    }
    return 0;
}
