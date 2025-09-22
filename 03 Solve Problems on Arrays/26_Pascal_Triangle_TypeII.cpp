#include<iostream>
#include<vector>
using namespace std;
vector<int> nthRow(int n){
    vector<int> row;
    long long ans=1;
    row.push_back(1);
    for(int i=1;i<n;i++){
        ans=ans*(n-i);
        ans=ans/i;
        row.push_back(ans);
    }
    return row;
}
int main(){
    vector<vector<int>> pascalTriangle={{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1},{1,5,10,10,5,1}};
    int n=pascalTriangle.size();
    n=6;
    vector<int> result=nthRow(n);
    for(int i=0;i<n;i++){
        cout << result[i] <<" ";
    }
    cout << endl;
    }
