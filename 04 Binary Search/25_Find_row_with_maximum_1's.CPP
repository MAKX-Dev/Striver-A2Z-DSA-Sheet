#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &mat,int x){
    int n=mat.size();
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(mat[mid]>=x){
            ans=mid;
            high=mid-1;

        }
        else{
            low=mid+1;
        }
    }
    return ans;
}
int rowWithMax1s(vector <vector<int>> & mat){
    int m=mat.size();
    if(m==0) return -1;
    int cnt_max=0;
    int ind=-1;
    for(int i=0;i<m;i++){
        int n=mat[i].size();
        int cnt=n-lowerBound(mat[i], 1);
        if(cnt>cnt_max){
            cnt_max=cnt;
            ind=i;
        }
    }
    return ind;
  }
int main(){
    vector<vector<int>> mat={{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int result=rowWithMax1s(mat);
    cout<<"index of the row with the maximum number of ones is: "<<result<<endl;
}