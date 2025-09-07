#include <iostream>
using namespace std;
void f(int i, int N) {
  if (i < 1) {
    return;
  }
  cout << i << " ";
  f(i - 1, N);
}

int main() {
  int N;
  cout << "Enter the value of N: ";
  cin >> N;
  f(N, N);
}