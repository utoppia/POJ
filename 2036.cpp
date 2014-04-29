// hdu 1352 poj 2036
// by utoppia

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int const nMax = 100100;
double const eps = 1e-9;

inline int dcmp(double x) {
    if(x>-eps && x<eps) return 0;
    return x > 0 ? 1 : -1;
}

struct P{
    double x,y;
    P(double x=0,double y=0):x(x),y(y){};
    void read() { scanf("%lf%lf",&x,&y); }
    bool operator < (const P& u) const {
        if(dcmp(x-u.x)==0) return dcmp(y-u.y)<0;
        return dcmp(x-u.x) < 0;
    }
    friend bool operator == (const P& u,const P& v) { return dcmp(v.x-u.x)==0 && dcmp(u.y-v.y)==0; }
    friend P operator - (const P& u,const P& v) {
        return P(u.x-v.x,u.y-v.y);
    }
    friend double operator * (const P& u,const P& v) {
        return u.x*v.y - u.y*v.x;
    }
    friend double operator ^ (const P& u,const P& v) {
        return u.x*v.x + u.y*v.y;
    }
};
double atan(P u) {
    return atan2(u.y,u.x);
}
P make(P u,P v) {
    if(dcmp(u.x-v.x)==0) return P(u.x,0);
    return P(0,(v.y-u.y)/(v.x-u.x)*(-u.x)+u.y);
}
double mak(P u,P v){
    if(dcmp(u.x-v.x)==0) return 0;
    return (v.y-u.y)/(v.x-u.x);
}
struct L{
    P a,b,c;
    double d;
    void read() { a.read();b.read();if(b<a) swap(a,b);c=make(a,b);d=mak(a,b);}
    friend bool operator < (const L& u,const L& v)  {
        if(dcmp(u.b.x-u.a.x)==0 && dcmp(v.b.x-v.a.x)==0) {
            if(u.c == v.c) {if(u.a==v.a) return u.b < v.b;else return u.a < v.a;}
            else return u.c < v.c;
        }
        else if(dcmp(u.b.x-u.a.x)==0) return false;
        else if(dcmp(v.b.x-v.a.x)==0) return true;
        else if( dcmp(u.d-v.d) == 0) {
            if(u.c == v.c) {if(u.a==v.a) return u.b < v.b;else return u.a < v.a;}
            else return u.c < v.c;
        }else return dcmp(u.d-v.d) < 0;
    }
    void print() { printf("%.3lf %.3lf %.3lf %.3lf\n",a.x,a.y,b.x,b.y); }
};
int dot_on_line(P a,P b,P p) {
    return dcmp((a-b)*(a-p))==0 && dcmp((p-a)^(b-p))>=0;
}
int intersection(L u,L v) {
    if(dcmp(u.d-v.d)==0 && u.c==v.c) return 1;
    return 0;
}

L l[nMax];
int n;
int main() {
    while(scanf("%d",&n),n){
        for(int i=0;i<n;++i) l[i].read();
        sort(l,l+n);
        int ans = n;
        for(int i=1;i<n;++i) if(intersection(l[i-1],l[i])) {
            if(dcmp(l[i].b.x-l[i].a.x)==0 && l[i].a.y<=l[i-1].b.y) {ans--;l[i].b.y = max(l[i].b.y,l[i-1].b.y);}
            else if(dcmp(l[i].b.x-l[i].a.x) && l[i].a.x<=l[i-1].b.x) {ans--; l[i].b.x = max(l[i].b.x,l[i-1].b.x);}
        }
        printf("%d\n",ans);
    }
    return 0;
}

