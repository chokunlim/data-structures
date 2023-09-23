#include<iostream>
#include<stack>
using namespace std;

string isParenthesis(string str) {

    stack<char> stackdata;
    for (char c : str) {
        if (c == '(') {
           stackdata.push(c);
        } else if (c == ')') {
            if (stackdata.empty()) return "NO";
            stackdata.pop();
        }
    }

     return stackdata.empty() ? "YES" : "NO";

}

int main()
{
    string str;
    cin >> str;

    cout << isParenthesis(str);

    return 0;
}