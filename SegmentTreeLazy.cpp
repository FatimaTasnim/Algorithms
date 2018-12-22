#include<bits/stdc++.h>
#define M 100002
using namespace std;
template<class T>
inline bool scan(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
long long tree[M*3],lazy[M*3];
void upLazy(int pos,int low,int high,int st,int en,int val){
    int lft,rgt,mid;
    lft=(pos<<1);rgt=lft+1;
    if(lazy[pos]){
        tree[pos]+= lazy[pos]* (high-low+1);
        if(high!=low){
            lazy[lft]+=lazy[pos];
            lazy[rgt]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(high<low || low>en || high<st)return;
    if(low>=st && high<=en){
        tree[pos]+= (high-low+1)*val;
        if(low!=high){
            lazy[lft]+=val;
             lazy[rgt]+=val;
        }
        return;
    }
    mid=((low+high)>>1);
    upLazy(lft,low,mid,st,en,val);
    upLazy(rgt,mid+1,high,st,en,val);
    tree[pos]=tree[lft]+tree[rgt];
}
long long qrLazy(int pos,int low,int high,int st,int en){
    int lft,rgt,mid;
    lft=(pos<<1);rgt=lft+1;
    if(low>en || high<st || high<low)return 0;
    if(lazy[pos]){
        tree[pos]+= lazy[pos]* (high-low+1);
        if(high!=low){
            lazy[lft]+=lazy[pos];
            lazy[rgt]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(low>=st && high<=en)return tree[pos];
    mid= ((low+high)>>1);
    return qrLazy(lft,low,mid,st,en) + qrLazy(rgt,mid+1,high,st,en);
}
int main()
{
    int c,k=0,r1,r2,n,q,op;
    long long value,ans;
    scan(c);
    while(c--){
        scan(n);scan(q);
        printf("Case %d:\n",++k);
        memset(lazy,0,sizeof lazy);
        memset(tree,0,sizeof tree);
        while(q--){
            scan(op);
            if(!op){
                scan(r1);scan(r2);scan(value);
                if(r1>r2)swap(r1,r2);
                upLazy(1,1,n,r1+1,r2+1,value);
            }
            else{
                scan(r1);scan(r2);
                if(r1>r2)swap(r1,r2);
                ans=qrLazy(1,1,n,r1+1,r2+1);
                printf("%lld\n",ans);
            }
        }
    }
}

