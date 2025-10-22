#include <bits/stdc++.h>
using namespace std;
int main(){
vector<int> height={7, 5, 1, 2, 6};
  int n=height.size();
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      int secondJump=INT_MAX;
      int firstJump=prev+abs(height[i]-height[i-1]);
      if(i>1)
        secondJump=prev2+abs(height[i]-height[i-2]);
      int cur_i=min(firstJump,secondJump);
      prev2=prev;
      prev=cur_i;
        
  }
  cout<<"minimum amount of energy required is: "<<prev<<endl;
  return 0;
}