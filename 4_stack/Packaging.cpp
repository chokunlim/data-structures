#include <iostream>
#include <stack>
using namespace std;

int main() 
{
    double a , b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    string str;
    cin >> str;

    stack<double> pricestack;
    stack<char> itemstack;
    stack<int> countstack;

    int count = 0;
    for (char c : str) {
        switch (c) {
            case '{':
                pricestack.push(0.05);
                if (count > 0) {
                    countstack.push(count);
                    count = 0;
                    //cout << "COUNT ADDED: " << count << endl;
                }
            case '(':
                pricestack.push(0.07);
                if (count > 0) {
                    countstack.push(count);
                    count = 0;
                    //cout << "COUNT ADDED: " << count << endl;
                }
            case '[':
                pricestack.push(0.1);
                if (count > 0) {
                    countstack.push(count);
                    count = 0;
                    //cout << "COUNT ADDED: " << count << endl;
                }
                break;

            case '}':
                if (count > 0) {
                countstack.push(count);
                count = 0;
                //cout << "COUNT ADDED: " << count << endl;
                } else { pricestack.pop(); }
                break;
            case ')':
                if (count > 0) {
                    countstack.push(count);
                    count = 0;
                    //cout << "COUNT ADDED: " << count << endl;
                } else { pricestack.pop(); }

                break;
            case ']':
                if (count > 0) {
                countstack.push(count);
                count = 0;
                //cout << "COUNT ADDED: " << count << endl;
                } else { pricestack.pop(); }
                break;
            default:
                itemstack.push(c);
                count++;
                break;
        }
    }

    double total = 0.0;
    int tax = 0;
    while(!countstack.empty()) {

        //cout << "size " << countstack.size() << endl;
        //cout << "top  " << countstack.top() << endl;

        double price = 0.0;
        for (int j = 0; j < countstack.top(); j++) {

            switch (itemstack.top()) {
                case 'A':
                    price += a;
                    break;
                case 'B':
                    price += b;
                    break;
                case 'C':
                    price += c;
                    break;
            }

            itemstack.pop();
        }

        if (!pricestack.empty() && pricestack.size() > 1) {
            cout << tax << " " << total << endl;
            total += price;
            tax += pricestack.top() * price;
            pricestack.pop(); 
        } else if (!pricestack.empty() && pricestack.size() == 1) {
            cout << tax << " " << total << endl;
            tax += pricestack.top() * (price + total);
            total += price;
            pricestack.pop(); 
        } else {
            cout << tax << " " << total << endl;
            total += price;
        }

        countstack.pop();
    }

    int cost = total + tax;
    cout << cost << endl;
    return 0;
}
