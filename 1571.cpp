// hdu 1309 poj 1571
// by utoppia

#include<cstdio>
int main() {
    double money,car,count,pre,now;
    int month,i,j,T;
    while(~scanf("%d%lf%lf%d",&month,&count,&money,&T),month>0){
        i = 0;
        scanf("%d%lf",&j,&pre);T--;
        car = (money+count)*(1.0-pre);
        count = money/month;
        i++;
        while(T--){
            scanf("%d%lf",&j,&now);
            //printf("now = %lf\n",now);
            //printf("money=%lf car=%lf\n",money,car);
            if(car >= money) continue;
            for(;i<j;i++){
                if(car >= money) break;
                money -= count;
                car = car*(1.0-pre);
                //printf("money=%lf car=%lf i=%d\n",money,car,i);
            }

            //if(money<car || i>month) break;
            pre = now;
        }
        while(car<money){
            car*=(1.0-pre);
            money-=count;
            i++;
        }
        if(i==2) printf("%d month\n",i-1);
        else printf("%d months\n",i-1);
    }
    return 0;
}
