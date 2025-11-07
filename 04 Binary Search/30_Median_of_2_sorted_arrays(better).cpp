#include<bits/stdc++.h>
using namespace std;
double median(vector<int> &arr1,vector<int> &arr2){
    int m=arr1.size();
    int n=arr2.size();
    int j=0;
    int i=0;
    int s=(m+n);
    int ind2=s/2;
    int ind1=ind2-1;
    int cnt=0;
    int ind1el=-1; int ind2el=-1;
    while(i<m && j<n){
        if(arr1[i]<arr2[j]){
            if(cnt==ind1) ind1el=arr1[i]; 
            if(cnt==ind2) ind2el=arr2[i];
            cnt++;
            i++;
        } 
        else{
            if(cnt==ind1) ind1el=arr1[j];
            if(cnt==ind2) ind2el=arr2[j];
            cnt++;
            i++;
        }
    }
    while(i<m){
        if(cnt==ind1) ind1el=arr1[i];
        if(cnt==ind2) ind2el=arr2[i];
        cnt++;
        j++;
    }
    while(j<n){
        if(cnt==ind1) ind1el=arr1[j];
        if(cnt==ind2) ind2el=arr2[j];
    }
    if(s%2==1){
        return (double)ind2el;
    }
    else{
        return ((double)ind2el+double(ind1el))/2.0;
    }

}
int main(){
    vector<int> arr1={2,4,6};
    vector<int> arr2={1,3,5};
    double result=median(arr1,arr2);
    cout<<result<<endl;

}