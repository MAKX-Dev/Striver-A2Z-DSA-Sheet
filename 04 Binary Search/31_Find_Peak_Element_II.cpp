#include<bits/stdc++.h>
using namespace std;
int maxElement(const vector<vector<int>>& mat,int n,int m,int col){
    int maxValue = INT_MIN;
    int ind = -1;
    for(int i = 0; i < n; i++){
        if(mat[i][col] > maxValue){
            maxValue = mat[i][col];
            ind = i;
        }
    }
    return ind;
}
vector<int> findPeakGrid(vector<vector<int>> &mat){
    int n=mat.size();
    if(n==0) return {-1, -1};
    int m=mat[0].size();
    int low=0;
    int high=m-1;
    while(low<=high){
        int mid=(low+high)/2;
        int row=maxElement(mat,n,m,mid);
        int left=(mid-1>=0) ? mat[row][mid-1] : INT_MIN;
        int right=(mid+1<m) ? mat[row][mid+1] : INT_MIN;
        if(mat[row][mid]>left && mat[row][mid]>right){
            return {row,mid};
        }
        else if(mat[row][mid]<left){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    vector<int> result=findPeakGrid(mat);
    if(result.size()==2 && result[0]!=-1){
        cout<<"indices of peak element are: "<<result[0]<<" , "<<result[1]<<endl;
        cout<<"peak element is: "<<mat[result[0]][result[1]]<<endl;
    } else {
        cout<<"No peak found"<<endl;
    }
    return 0;
}