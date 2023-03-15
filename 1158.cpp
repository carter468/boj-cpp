#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, k; cin >> n >> k;

    list<int> people;
    for (int i = 1; i <= n; i++) people.push_back(i);
    cout << "<";
    auto current = people.begin();
    while (people.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            if (++current == people.end()) current = people.begin();
        }
        cout << *current << ", ";
        current = people.erase(current);
        if (current == people.end()) current = people.begin();
    }
    cout << people.front() << ">";
}