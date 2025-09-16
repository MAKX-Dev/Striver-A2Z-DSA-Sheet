#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string twoSum(int n,vector<int> &book,int target){
    int left=0;
    int right=n-1;
    sort(book.begin(),book.end());
    while(left<right){
        int sum=book[left]+book[right];
        if(sum=target){
            return "YES";
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
       
    }
    return "NO";
}
int main(){
    int n=5;
    int target=14;
    vector<int> book={2,6,5,8,11};
    string result=twoSum(n,book,target);
    cout<<result<<endl;


}

