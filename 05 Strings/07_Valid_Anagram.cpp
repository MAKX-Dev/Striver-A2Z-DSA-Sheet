#include<bits/stdc++.h>
using namespace std;
bool anagramStrings(string& s, string& t){
    if (s.size()!=t.size()) return false;
    vector<int> freq(256,0); 
    for(char c : s) freq[c]++;
    for(char c : t) freq[c]--;
    for(int count : freq){
        if(count!=0) return false;
    }
    return true;
}
int main(){
    string s = "anagram" , t = "nagaram";
    if(anagramStrings){
        cout<<"TRUE"<<endl;
    }
    else{
        cout<<"FALSE"<<endl;
    }
    return 0;
}