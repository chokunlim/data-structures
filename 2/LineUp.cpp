#include <iostream>
#include <vector>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    int temp;
    cin >> temp;
    
    vector<vector<int>> rows;
    vector<int> insertRow = {temp};
    rows.push_back(insertRow);
    
    int index = 0;
    for (int i = 1; i < n; i++) {
        cin >> temp;
        //หากเลขที่ของนักเรียนคนต่อไปมากกว่าเลขที่ของปลายแถว
        if (temp > rows[index].back())
            rows[index].push_back(temp);
        //หากเลขที่ของนักเรียนคนต่อไปน้อยกว่าเลขที่ของหัวแถว
        else if (temp < rows[index].front())
            rows[index].insert(rows[index].begin(), temp);
        //ขึ้นแถวใหม่
        else {
            insertRow = {temp};
            rows.push_back(insertRow);
            index++;
        }
    }
    
    for (const auto& row : rows) {
        for (const auto& n : row) {
            cout << n << " ";
        }
       puts("");
    }

    return 0;
}