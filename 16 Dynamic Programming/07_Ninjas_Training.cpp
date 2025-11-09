#include <bits/stdc++.h>
using namespace std;
int func(const vector<vector<int>> &points){
    int n=points.size();
    if (n==0) return 0;
    vector<int> prev(4,0);
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++){
        vector<int> temp(4, 0);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for (int task=0;task<=2;task++){
                if (task!=last){
                    temp[last]=max(temp[last],points[day][task]+prev[task]);
                }
            }
        }
        prev=temp;
    }
    return prev[3];
}

int ninjaTraining(const vector<vector<int>> &matrix) {
    return func(matrix);
}

int main() {
    vector<vector<int>> matrix = {{10, 40, 70}, {20, 50, 80}, {30, 60, 90}};
    int result=ninjaTraining(matrix);
    cout << "maximum possible merit points are: " << result << endl;
    return 0;
}