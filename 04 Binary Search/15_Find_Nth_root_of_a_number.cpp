#include<bits/stdc++.h>
using namespace std;
 int NthRoot(int N,int M) {
    int low=1;
    int high=M;
    while(low<=high){
        int mid=(high+low)/2;
        long long power=1;
        for(int i=0;i<N;i++){
            power*=mid;
        }
        if(power==M){
            return mid;
        }
        else if(power<M){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
       
    }
int main(){
    int N=3;
    int M=27;
    int result=NthRoot(N,M);
    cout<<" Nth root of M is: "<<result<<endl;

}