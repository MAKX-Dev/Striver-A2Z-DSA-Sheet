#include<bits/stdc++.h>
using namespace std;
int func(int ind,int last,vector<vector<int>> matrix,vector<int> &memo){
    int maxi=0;
    if(ind==0){
        for(int i=0;i<matrix[0].size();i++){
            if(i!=last){
                maxi=max(maxi,matrix[0][i]);
            }
        }
        return maxi;
    }
    if(memo[ind]!=-1){
        return memo[ind];
    }
    maxi=0;
    for(int i=0;i<matrix[0].size();i++){
        if(i!=last){
            int points=matrix[ind][i]+func(ind-1,i,matrix,memo);
            maxi=max(maxi,points);
        }
       
    }
    memo[ind]=maxi;
    return maxi;
}
int ninjaTraining(vector<vector<int>> &matrix,vector<int> &memo){
    int n=matrix.size();
    int m=matrix[0].size();
    return func(n-1,m,matrix,memo);
}
int main(){
    vector<vector<int>> matrix={{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int n=matrix.size();
    vector<int> memo(n,-1);
    int result=ninjaTraining(matrix,memo);
    cout<<"maximum possible merit points are: "<<result<<endl;

}