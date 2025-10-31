#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    const vector<string> keypad={
        "",     
        "",     
        "abc",  
        "def",  
        "ghi",  
        "jkl",  
        "mno",  
        "pqrs", 
        "tuv",  
        "wxyz"  
    };
    vector<string> allCombinations;
    void findCombinations(int index,string currentString,string& digits){
        if (index==digits.length()){
            allCombinations.push_back(currentString);
            return;
        }
        char currentDigit=digits[index];
        string lettersToTry=keypad[currentDigit-'0'];
        for(char letter : lettersToTry){
            findCombinations(index+1,currentString+letter,digits);
        }
    }
    vector<string> letterCombinations(string digits){
        if(digits.empty()){
            return {};
        }
        findCombinations(0, "", digits);
        return allCombinations;
    }
};
int main(){
    Solution sol;
    string digits="23";
    vector<string>result=sol.letterCombinations(digits);
    cout<<"Combinations for "<<digits<<":"<<endl;
    for (const string& s : result){
        cout<<s<<" ";
    }
    cout<<endl;
    return 0;
}