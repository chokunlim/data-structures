#include <iostream>
#include <bits/stdc++.h>
#include <set>
using namespace std;

int main() 
{
    int n;
    cin >> n;

    int studentNum[n];
    for (int i= 0; i < n; i++) {
        studentNum[i] = i;
    }

    map<int, set<int>> m;
    int maxSet = 0;
    for (int i = 0; i < n; i++) {
       
        int left, right;
        cin >> left;
        cin >> right;
            m[studentNum[i]].insert(i+1);
        

        if (left > 0) { 
            m[studentNum[i]].insert(left);
            studentNum[left-1] = studentNum[i]; }
        if (right > 0) { 
            m[studentNum[i]].insert(right);
            studentNum[right-1] = studentNum[i]; 
        }
        
        int len = m[studentNum[i]].size();
        maxSet = max(maxSet, len);
    }

    cout << maxSet << endl;

    return 0;
}
