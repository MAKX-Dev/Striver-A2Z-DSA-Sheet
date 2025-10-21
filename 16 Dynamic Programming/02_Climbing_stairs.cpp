#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=3;
    int pre=1;
    int pre2=1;
    int cur_i=pre;
    for(int i=2;i<=n;i++){
        cur_i=pre+pre2;
        pre2=pre;
        pre=cur_i;
    }
    cout<<"number of unique ways to reach the nth step: "<<pre<<endl;
    return 0;
    }
