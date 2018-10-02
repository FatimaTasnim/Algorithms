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

void Insert(int num){
    int curr = head, idx, r = 10000;

    while(r){
        idx = (num/r)%10;
        r/=10;
        if(trie[curr].next[idx]==NL)trie[curr].next[idx] = NewTrie();
        curr = trie[curr].next[idx];
        trie[curr].cnt++;
    }
    return;
}

int SearchMedian(int k){
    int idx, num = 0, curr = head, r = 5;
    while(r--){
        for(int i=0;i<10;i++){
            idx = trie[curr].next[i];
            if(k<=trie[idx].cnt){
                curr = trie[curr].next[i];
                num = (num*10) + i;
                break;
            }
            else k-= trie[idx].cnt;
        }
    }
    return num;
}

int main()
{
    init();
    int n, a;
    double median;
    cin>> n;
    for(int i=1;i<=n;i++){
        cin>>a;
        Insert(a);
        /*if(i%2==0){
            median = (SearchMedian(i/2)*1.0) + (SearchMedian((i/2)+1)*1.0);
            cout << median/2.0 << endl;
        }
        else {median = SearchMedian((i/2)+1);
        printf("%.1lf\n", median);}*/
        cerr << SearchMedian(1) << endl;
    }
}
