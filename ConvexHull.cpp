#include<bits/stdc++.h>
#define MAX 100005
using namespace std;

struct Points{
    long long x;
    long long y;

    //Points(int a, int b): x(a), y(b) {}
};

int P;
Points Pp[MAX], Cc[MAX], P0;

inline long long TriArea(Points a, Points b, Points c){
    return a.x *(b.y-c.y) + b.x *(c.y-a.y) + c.x*(a.y-b.y);
}

inline long long SqDist(Points a, Points b){
    return ((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y));
}

bool compare(Points a, Points b){
    if(!TriArea(P0,a,b))
        return SqDist(P0,a)<SqDist(P0,b);

    double d1x = a.x - P0.x, d1y = a.y - P0.y;
    double d2x = b.x - P0.x, d2y = b.y - P0.y;

    return (atan2(d1y,d1x)-atan2(d2y,d2x))<0;
}

void ConvexHull(int n){
    int i, j, track=0;

    for(i=1;i<n;i++){
        if(Pp[i].x<Pp[track].x || (Pp[i].x==Pp[track].x and Pp[i].y>Pp[track].y))
            track = i;
    }

    swap(Pp[0], Pp[track]);
    P0 = Pp[0];

    sort(Pp+1, Pp+n, compare);

    Cc[0] = Pp[0], Cc[1] = Pp[1], Cc[2] = Pp[2];

    for(i=j=3;i<n;i++){
        while(TriArea(Cc[j-2], Cc[j-1], Pp[i])<=0)j--;
        Cc[j++] = Pp[i];
    }

    P = j;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%lld %lld",&Pp[i].x , &Pp[i].y);
    }
    ConvexHull(n);
    for(int i=0;i<P;i++){
        printf("%lld %lld\n", Cc[i].x, Cc[i].y);
    }
}
