#include<bits/stdc++.h>
using namespace std;
int sumOfElements(vector<int> C){
    int sum=0;
    for(int i=0;i<C.size();i++){
        sum+=C[i];
    }
    return sum;
}
int countPainters(vector<int> &C,int mid){
    int n=C.size();
    int painters=1;
    long long boardsPainter=0;
    for (int i=0;i<n;i++){
        if (boardsPainter+C[i]<=mid){
            boardsPainter+=C[i];
        }
        else{
            painters++;
            boardsPainter=C[i];
        }
    }
    return painters;
}
int paint(int A,int B,vector<int>& C){
        int low=*max_element(C.begin(),C.end());
        int high=sumOfElements(C);
        int result=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            int paintersNeeded=countPainters(C,mid);
            if(paintersNeeded<=A){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        long long MOD=10000003LL;
        long long ans=((long long)result*(long long)B)%MOD;
        return (int)ans;
    }
int main(){
    int A=10;
    int B=1;
    vector<int> C={1, 8, 11, 3};
    int result=paint(A,B,C);
    cout<<result<<endl;
}