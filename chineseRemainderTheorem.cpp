#include<bits/stdc++.h>
using namespace std;
int inv(int B, int b){
      int b0=b,t,q,x0=0,x1=1;
      if(b==1)return 0;
      while(B>1){
            q= B/b;
            t= b;
            b= B%b; B= t;
            t= x0;
            x0= x1- q*x0;
            x1= t;
      }
      if(x1< 0)x1+= b0;
      return x1;
}
int n;
int num[101],rem[101];
int FindMinX(){
      int i,b,B=1,res=0,x;
      for(i=0;i<n;i++)B*= num[i];

      res=0;
      for(i=0;i<n;i++){
            b= B/num[i];
            cout << rem[i]  << " " << inv(b,num[i]) << " " << b << endl;
            res+= rem[i] * inv(b, num[i]) * b;
      }
      cout << res << endl;
      x= res%B;
      return x;
}
int main()
{
      int i;
      cin>> n;
      for(i=0;i<n;i++){
            cin>> num[i];
      }
      for(i=0;i<n;i++){
            cin>> rem[i];
      }
      cout << FindMinX() << endl;
}
