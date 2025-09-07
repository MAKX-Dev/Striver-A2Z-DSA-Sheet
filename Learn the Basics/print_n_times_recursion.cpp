#include <iostream>
using namespace std;
void f(int i, int N) {

  if (i > N) {
    return;
  }
    cout << "MAKX" << endl;
    f(i + 1, N);
  
}

int main() {
  int i=1;
  int N;
  cout << "Enter a number: " << endl;
  cin >> N;
  f(i, N);
}