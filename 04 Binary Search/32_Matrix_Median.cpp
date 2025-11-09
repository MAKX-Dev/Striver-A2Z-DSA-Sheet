#include<bits/stdc++.h>
using namespace std;
int countLessEqual(vector<int>& row,int mid){
        return upper_bound(row.begin(),row.end(),mid)-row.begin();
    }
int findMedian(vector<vector<int>>& matrix){
        int rows=matrix.size();
        int cols=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[0][cols-1];
        for(int i=1;i<rows;i++){
            low=min(low,matrix[i][0]);
            high=max(high,matrix[i][cols-1]);
        }
        while(low<high){
            int mid=(low+high)/2;
            int count=0;
            for(int i=0;i<rows;i++){
                count+=countLessEqual(matrix[i],mid);
            }
            if(count<(rows*cols+1)/2){
                low=mid+1;
            }
            else
                high=mid;
        }
        return low;
    }
int main(){
    vector<vector<int>> matrix={{1, 4, 9}, {2, 5, 6}, {3, 7, 8}};
    int result=findMedian(matrix);
    cout<<"median of the given matrix is: "<<result<<endl;
}