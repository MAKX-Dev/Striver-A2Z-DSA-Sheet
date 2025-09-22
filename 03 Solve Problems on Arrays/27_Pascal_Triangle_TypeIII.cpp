#include<iostream>
#include<vector>
using namespace std;
vector<int> generateRow(int row){
    long long ans=1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);
        ans=ans/(col);
        ansRow.push_back(ans);

    }
    return ansRow;


}
vector<vector<int>> pascalTriangle(int N){
    vector<vector<int>> ans;
    for(int i=1;i<=N;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}
int main(){
    int N = 6; // or any value you want for rows
    vector<vector<int>> triangle = pascalTriangle(N);
    for (int i=0;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++) {
            cout<<triangle[i][j]<<" ";
        }
        cout<<endl;
    }
}