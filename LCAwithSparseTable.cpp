#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

int len;
int spr[20][MAX*3+3], tracker[20][MAX*3+3];
int arr[MAX*3];

void sparse()
{
    int i,j;

    for(j=1;(1<<j)<=len;j++)
        for(i=1;(i+(1 << j) - 1)<=len;i++){
           if(spr[j-1][i]<spr[j-1][i+(1<<(j-1))]){
            spr[j][i] = spr[j-1][i];
            tracker[j][i] = tracker[j-1][i];
           }
           else{
            spr[j][i] = spr[j-1][i+(1<<(j-1))];
            tracker[j][i] = tracker[j-1][i+(1<<(j-1))];
           }
        }
}

int index;
vector < int > graph[MAX+3];
bool mark[MAX+3];
int first_occurrence[MAX+3], level[MAX+3], tree[MAX*3 + 3];

void EulerTour(int src){
    for(int i=0;i<graph[src].size();i++){
        int x = graph[src][i];
        if(!mark[x]){
            mark[x] = 1;
            index++;
            first_occurrence[x] = index;
            level[x] = level[src] + 1;
            tree[index] = x;
            arr[index] = level[x];
            EulerTour(x);
            index++;
            arr[index] = level[src];
            tree[index] = src;
        }
    }
}

void Initialization(int src){
    index = 1;
    tree[src] = 1;
    first_occurrence[src] = 1;
    arr[src]=level[src] = 1;
    mark[src]=1;
}

int main()
{
    int n, a, b,e;
    cin>> n >> e;
    for(int i = 0;i<e;i++){
        cin>>a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    Initialization(1); /// Assuming source = 1
    EulerTour(1);

    for(int i=1;i<=index;i++){
        cout  << i << " tree " << tree[i] << " level " << arr[i] << endl;
    }
    cout << "First Occurrences \n";
    for(int i=1;i<=n;i++){
        cout << i << "--> " << first_occurrence[i] << endl;
    }

    for(int i=1;i<=index;i++){
        spr[0][i] = arr[i];
        tracker[0][i] = tree[i];
    }
    len = index;
    sparse();

    int q, n1, n2, r1, r2, r, lca, lca_level;
    cin>> q;
    while(q--){
        cin >> n1 >> n2;
        r1 = first_occurrence[n1];
        r2 = first_occurrence[n2];
        if(r1>r2)swap(r1,r2);
        cout << r1 << " " << r2 << endl;
        a=r2-r1+1;
        r= 31-__builtin_clz(a);
        if(spr[r][r1]<spr[r][(r2)-(1<<r)+1]){
            lca_level = spr[r][r1];
            lca = tracker[r][r1];
        }
        else{
            lca_level = spr[r][(r2)-(1<<r)+1];
            lca = tracker[r][(r2)-(1<<r)+1];
        }
        cout << lca  << " " << lca_level<< endl;
    }

}
