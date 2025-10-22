#include<bits/stdc++.h>
using namespace std;
int sumOf(vector<int> weights){
    int sum=0;
    for(int i=0;i<weights.size();i++){
        sum+=weights[i];
    }
    return sum;
}
int findDays(vector<int>&weights,int mid){
    int days=1;
    int load=0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]+load>mid){
            days+=1;
            load=weights[i];

        }
        else{
            load+=weights[i];
        }
       
    }
    return days;

}
int shipWithinDays(vector<int>& weights,int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=sumOf(weights);
        while(low<=high){
            int mid=(high+low)/2;
            int numberOfDays=findDays(weights,mid);
            if(numberOfDays<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }
int main(){
    vector<int> weights={3, 2, 2, 4, 1, 4};
    int days=3;
    int result=shipWithinDays(weights,days);
    cout<<"Minimum possible capacity: "<<result<<endl;
    return 0;

}


