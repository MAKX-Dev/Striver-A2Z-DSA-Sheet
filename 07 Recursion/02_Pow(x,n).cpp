#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
    double ans=1.0;
    long long nn=n;
    if(nn<0){
        nn=-1*(long long)n;
    }
    while(nn>0){
        if(nn%2==1){
            ans=ans*x;
            nn=nn-1;

        }
        else{
        x=x*x;
        nn=nn/2;
        }
    }
    if(n<0){
        ans=double(1.0)/double(ans);
        }
        return ans;
    }
int main(){
    double x=2.0000;
    int n=10;
    double result=myPow(x,n);
    cout<<"x^n ="<<result<<" ";
    return 0;

}