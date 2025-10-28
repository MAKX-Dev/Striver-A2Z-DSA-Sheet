#include <bits/stdc++.h>
using namespace std;
void generate(int n, string given,vector<string>& result) {
    if (given.length()==n) {
        result.push_back(given);
        return;
    }
    generate(n, given+ "0",result);
    if (given.empty() || given.back()!='1'){
        generate(n,given+"1",result);
    }
}

int main(){
    int n=2;
    vector<string> result;
    generate(n, "",result);
    for (string& s : result){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}