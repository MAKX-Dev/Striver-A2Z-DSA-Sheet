#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int countGoodNumbers(int index,int n){
    if(index==n){
        return 1;
    }
    long long result=0;
    if(index%2==0){
        for(int digit : {0, 2, 4, 6, 8}){
            result=(result+countGoodNumbers(index+1,n))%MOD;
        }
    } 
    else{
        for(int digit : {2, 3, 5, 7}){
            result=(result+countGoodNumbers(index+1,n))%MOD;
        }
    }
    return (int)result;
}
int cntGoodNumbers(long long n){
    return countGoodNumbers(0,static_cast<int>(n));
}
int main(){
    long long n=50;
    int result=cntGoodNumbers(n);
    cout<<"total number of good digit strings: " <<result<< endl;
    return 0;
}