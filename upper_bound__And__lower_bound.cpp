int upperBound(vector<int> &a, int b){
    int low = 0, high = a.size(), mid;
    int x = high-1;
    while(low<high){
       mid = low + (high - low) / 2;
       if(a[mid]<=b){
            low = mid+1;
        }
        else high = mid;
    }
    for(int i=min(x,low+2);i>=max(0,i-2);i--){
        if(a[i]==b)return i;
    }    
    return -1;
}
int lowerBound(vector<int> &a, int b){
    int low = 0, high = a.size(), mid;
    int x = high-1;
    while(low<high){
        mid = low + (high - low) / 2;
        if(a[mid]>=b){
            high = mid;
        }
        else low = mid+1;
    }
    for(int i=max(0,low-2);i<=min(x, low+2);i++){
     if(a[i]==b)return i;   
    }
    return -1;
}
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    if(A.size()==1){
        if(A[0]==B)return {0,0};
        return {-1,-1};
    }
    vector<int> temp = A;
    vector<int> res;
    int lb = lowerBound(temp, B);
    int ub = upperBound(temp, B);
    res.push_back(lb);
    res.push_back(ub);
    return res;
}
