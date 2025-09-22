#include<iostream>
#include<vector>
using namespace std;
int res=1;
int nCr(int n,int r){
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);

    }
    return res;
}
int main(){
    vector<vector<int>> pascalTriangle={{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1},{1,5,10,10,5,1}};
    int n=pascalTriangle.size();
    int r=5;
    int c=3;
    nCr(r-1,c-1);
    int result=res;
    cout<<"Required element is: "<<result<<endl;


}