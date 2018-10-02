/// Trie Tree solution

#include<iostream>
#define NL      -1
#define M       100005

using namespace std;

struct node{
    int cnt;
    int next[11];
};

node trie[M];
int nxt, head;

int NewTrie(){
    for(int i=0;i<10;i++)trie[nxt].next[i] = NL;
    trie[nxt].cnt = 0;
    return nxt++;
}

void init(){
    nxt = 0;
    head = NewTrie();
    return;
}

void Insert(long long num){
    int curr = head, idx, r = 1000000000;

    while(r){
        idx = (num/r)%10;
        r/=10;
        if(trie[curr].next[idx]==NL)trie[curr].next[idx] = NewTrie();
        curr = trie[curr].next[idx];
        trie[curr].cnt++;
    }
    return;
}

long long SearchMinSum(int k){
    int idx, curr = head, r = 10;
    long long num = 0;
    while(r--){
        for(int i=0;i<10;i++){
            idx = trie[curr].next[i];
            //if(trie[idx].cnt==0)continue;
            if(k<=trie[idx].cnt){
                curr = trie[curr].next[i];
                num = (num*10LL) + i;
                trie[curr].cnt--;
                break;
            }
            else k-= trie[idx].cnt;
        }
    }
    return num;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, a;
    long long x, sum;
    while(scanf("%d", &n)){
        if(!n)break;
        init();
        sum = 0;
        for(int i=1;i<=n;i++){
            scanf("%d", &a);
            Insert(a);
        }
        for(int i=0;i<n-1;i++){
            x = SearchMinSum(1);
            x +=SearchMinSum(1);
            Insert(x);
            sum += x;
        }
        printf("%d\n", sum);
    }
}
