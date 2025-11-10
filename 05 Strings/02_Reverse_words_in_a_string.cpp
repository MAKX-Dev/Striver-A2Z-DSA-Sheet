#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s){
    int n=s.size();
    string word="";
    string ans="";
    reverse(s.begin(),s.end());
    for(int i=0;i<n;i++){
        while(i<n && s[i]!=' '){
            word+=s[i];
            i++;
        }
        if(!word.empty()){
            reverse(word.begin(),word.end());
            if(!ans.empty()) ans += ' ';
            ans += word;
            word.clear();
        }
    }
    return ans;
}
int main(){
    string s= "the sky is blue";
    string result=reverseWords(s);
    cout<<result<< endl;

}