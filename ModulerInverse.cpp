#include<bits/stdc++.h>
using namespace std;
int inv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
       return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
}

int myInv(int B, int b){
      /// this one works only if B> b;
      if(b==1)return 0;
      B= B%b;
      int x= 1 + b;
      if(x%B!=0)B-= b;
      x= x/B;
      cout << x << endl;
      if(x<0) x+=b ;
      cout << x << endl;
}
int main()
{
      int B, X , b;
      cin>> B >> b;

      X=inv(B,  b);
      cout << X << endl;
      myInv(B, b);
}
