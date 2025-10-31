#include<bits/stdc++.h>
using namespace std;
void func(int number,int currentSum,int k,int n,vector<int>&combinationSum,vector<vector<int>>&allPossibleSets){
    if(k==0){
        if (currentSum==n) {
            allPossibleSets.push_back(combinationSum);
        }
        return;
    }
    if (number>9 || currentSum>n){
        return;
    }
    combinationSum.push_back(number);
    func(number+1,currentSum+number,k-1,n,combinationSum,allPossibleSets);
    combinationSum.pop_back();
    func(number+1,currentSum,k,n,combinationSum,allPossibleSets);
}
vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> combinationSum;
        vector<vector<int>>allPossibleSets;
        func(1,0,k,n,combinationSum,allPossibleSets);
        return allPossibleSets;
    }
int main(){
    int k=3;
    int n=9;
    vector<vector<int>>result=combinationSum3(k,n);
    for (int i=0;i<result.size();i++){
        cout<<"[ ";
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}