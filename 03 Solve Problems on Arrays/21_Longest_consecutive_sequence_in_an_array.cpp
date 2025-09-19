#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int longestConsecutive(vector<int> arr,int n){
    if(n==0){
        return 0;
    }
    int longest=1;
    unordered_set<int> st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt++;
            }
            longest=max(longest,cnt);
        }
        
    }
    return longest;
    
}

int main(){
    vector<int> arr={100, 4, 200, 1, 3, 2};
    int n=arr.size();
    int result=longestConsecutive(arr,n);
    cout<<"Longest Consecutive Sequence in an array is: "<<result<<endl;
}