#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        string s = "";
        char c;

        cin >> c;
        s += toupper(c); 

        for (int j = 1; j < n; j++) {
            cin >> c;
            if (toupper(c) != s.back()) {  
                s += toupper(c);
            } 
        }

        //cout << s << endl;

        if (s.compare("MEOW") == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }   
    }

    return 0;
}
