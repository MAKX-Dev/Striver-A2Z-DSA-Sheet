#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    int prev2=0; 
    int prev=1; 
    int cur_i=prev;
    for(int i=2;i<=n;i++){
        cur_i=prev+prev2;
        prev2=prev;
        prev=cur_i;
    }
    cout<<"nth element in Fibonacci Series is: "<<prev<<endl;
}