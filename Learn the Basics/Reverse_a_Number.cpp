#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number:  "<<endl;
    cin>>n;
    int revN=0;
    while(n>0){
    int lastdigit=n%10;
    revN=revN*10+lastdigit;
        n=n/10;
    }
    cout<<"Reverse of the number is:  "<<revN<<endl;





   
}