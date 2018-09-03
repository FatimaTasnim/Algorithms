#include<bits/stdc++.h>
#define M 100000

using namespace std;

int Arr[M+3], Tree[M*4 + 3]; /// M*3 will Do. But using 4 for safety issue

void BuildTree(int Node,int Start, int End){
    if(Start==End){
        Tree[Node]= Arr[Start]; /// Leaf Node
        return;
    }

    int Mid = (End + Start)/2; /// dividing into two parts
    int Left= Node * 2; /// fixing Left for the left node which will contain the result of Left Part
    int Right= Left+1;

    BuildTree(Left, Start, Mid);
    BuildTree(Right, Mid+1, End);

    Tree[Node] = min(Tree[Left], Tree[Right]);
}/// Time Complexity O(N)

void UpdateSingleIndex(int Node, int Start, int End, int Index, int Value){
    if(Start == End){
        Arr[Index] = Value;
        Tree[Node] = Arr[Index];
        return;
    }

    int Mid = (End + Start)/2;
    int Left = Node * 2;
    int Right = Left + 1;

    if(Start <= Index && Index <= Mid)
        UpdateSingleIndex(Left, Start, Mid, Index, Value);

    else
        UpdateSingleIndex(Right, Mid+1, End, Index, Value);

    Tree[Node] = min(Tree[Left], Tree[Right]);

} /// Time Complexity O(logN)

int SearchTree(int Node, int Start, int End, int Ls, int Rs){
    if(Ls > End || Rs < Start) {
        return INT_MAX; /// Out of Range so Returning a Maximum Number.
    }

    if(Ls <= Start && Rs >= End){
        return Tree[Node];
        /// Properly within the range so returning the value of this node
    }

    /// rest is for partial range
    int Mid = (End + Start)/2;
    int Left = Node * 2 ;
    int Right = Left + 1;

    int LAns = SearchTree(Left, Start, Mid, Ls, Rs);
    int RAns = SearchTree(Right, Mid+1, End, Ls, Rs);

    return  min(LAns, RAns) ;

} /// Time Complexity O(logN)

int main()
{
    int n, q, r1, r2;
    char op;

    scanf("%d%d",&n,&q);
    for(int i=1; i <= n; i++)scanf("%d", &Arr[i]);

    BuildTree(1, 1, n);
    cerr << Tree[8] << endl;
    while(q--){
        cin>> op >> r1 >> r2;

        /// If op = 'q' then output the smallest number within that range.
        /// else replaced the r1th value of the array by r2.

        if(op == 'q'){
            printf("%d\n", SearchTree(1, 1, n, r1, r2));
        }

        else UpdateSingleIndex(1, 1, n, r1, r2);
    }

}

