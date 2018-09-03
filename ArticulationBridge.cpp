#include<bits/stdc++.h>
using namespace std;
int Time = 0;
int low[1001], discovery[1001], parent[1001];
bool mark[1001];
vector <int> graph[1001];
vector < pair <int, int> > ab;
void ArticulationBridges(int node){
    mark[node]= true ;
    low[node] = discovery[node] = ++Time;
    int len = graph[node].size();
    for(int i=0;i<len; i++){
        int temp = graph[node][i];
        if(parent[node]==temp)continue;
        parent[temp] = node;
        if(mark[temp] ){
            low[node] = min(low[node], discovery[temp]);
        }
        else{
            ArticulationBridges(temp);
            low[node] = min(low[node], low[temp]);
            if(discovery[node] < low[temp]){
                ab.push_back(make_pair(node, temp));
            }
        }
    }
}
int main()
{
    int nodes, edges,a,b,Start;
    cin >>  nodes >> edges;
    for(int i=0;i<edges;i++){
        cin>> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //cin>> Start;
    Start=1;
    parent[Start]=-1;
    ArticulationBridges(Start);
    cout << "Articulation Bridges:\n";
    for(int i=0;i<ab.size();i++){
        cout << ab[i].first << " " << ab[i].second  << endl;
    }
}
