#include<iostream>
using namespace std;
void f(int i,int N){
    if(i>N){
        return;
    }
  cout<<i<<endl;
  f(i+1,N);
  
}
int main(){
    int N;
  int i=1;
  cout<<"Enter the number: "<<endl;
  cin>>N;
  f(i,N);
  
}