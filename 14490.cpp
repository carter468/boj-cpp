#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int main() {
    string input;
    cin >> input;

    int idx = input.find(":");
    int x = stoi(input.substr(0, idx));
    int y = stoi(input.substr(idx + 1));

    int g = gcd(x, y);
    cout << x / g << ':' << y / g;
}