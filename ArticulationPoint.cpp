#include<bits/stdc++.h>
using namespace std;
int Time=0;
int low[1001], discovery[1001],parent[1001];
bool track[10001],mark[1001];
vector < int > graph[1001];
vector < int > ap;
void ArticulationPoint(int node){
    mark[node] = true;
    int child=0,temp;
    discovery[node] = low[node] = Time++;
    for(int i=0;i<graph[node].size();i++){
        temp = graph[node][i];
        if(!mark[temp]){
            child++;
            parent[temp] = node;
            ArticulationPoint(temp);
            low[node] = min(low[node], low[temp]);
            if(parent[node]){
                cout << "Node " << node << " " << "dis node " << discovery[node] << " "  << "low temp " << low[temp] << endl;
                if(discovery[node] <= low[temp] && !track[node]){

                    ap.push_back(node);
                    track[node] = 1;
                    /// because same node would have more than one adj node with grater equal low value so in that case have to push only once.
                   // cout << "Phase 1: "<< endl;
                }
            }
        }
        else{
            if(temp != parent[node]){
                    low[node] = min(low[node], discovery[temp]);
            }
        }
    }
    if(!parent[node] && child>1 && !track[node])ap.push_back(node), track[node] = 1;
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
    cin>> Start;
    parent[Start]=0;
    ArticulationPoint(Start);
    for(int i=1;i<=nodes;i++){
        cout << i << " " << discovery[i] << " " << low[i] << " " << parent[i] << endl;
    }
    cout << "Articulation Points:\n";
    for(int i=0;i<ap.size();i++){
        cout << ap[i] << endl;
    }
}
