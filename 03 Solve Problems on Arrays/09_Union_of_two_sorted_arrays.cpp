#include<iostream>
#include<vector>
using namespace std;
vector<int> sortedArray(vector<int> a,vector<int> b){
    int n1=a.size();
    int n2=b.size();
    int i=0;
    int j=0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(unionArr.empty() || unionArr.back()!=a[j]){
                unionArr.push_back(a[i]);
            }
            i++;
        
        }
        else if(unionArr.empty()==0 || unionArr.back()!=a[j]){
            unionArr.push_back(b[i]);
        }
        j++;
    }
    while(i<n1){
        if(unionArr.back()!=a[i]){
            unionArr.push_back(a[i]);
        }
        i++;
    }
     while(j<n2){
        if(unionArr.back()!=a[j]){
            unionArr.push_back(a[j]);
        }
        j++;
    }
    return unionArr;
}
int main(){
    int n1;
    cin>>n1;
    vector<int> a(n1);
    for(int i=0;i<n1;i++){
        cin>>a[i];
    }
    int n2;
    cin>>n2;
    vector<int> b(n2);
    for(int j=0;j<n2;j++){
        cin>>a[j];
    }
    vector<int> result=sortedArray(a,b);
     cout << "Union of the two arrays: ";
    for(int val:result){
        cout<<val<<" ";
    }
    /*Above is SAME as 
    for(int i=0;i<result.size();i++){
    cout<<result[i]<<endl;
    }*/
    cout << endl;
    return 0;
}
    
