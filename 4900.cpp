#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	map<string, string> digit;
	digit["063"] = "0"; digit["010"] = "1"; digit["093"] = "2"; digit["079"] = "3"; digit["106"] = "4"; digit["103"] = "5"; digit["119"] = "6"; digit["011"] = "7"; digit["127"] = "8"; digit["107"] = "9";
	digit["0"] = "063"; digit["1"] = "010"; digit["2"] = "093"; digit["3"] = "079"; digit["4"] = "106"; digit["5"] = "103"; digit["6"] = "119"; digit["7"] = "011"; digit["8"] = "127"; digit["9"] = "107";

	while (true) {
		string s; cin >> s;
		if (s == "BYE") break;
		int a = 0, b = 0;
		int i = 0;
		while (s[i] != '+') {
			a = a * 10 + stoi(digit[s.substr(i, 3)]);
			i += 3;
		}
		++i;
		while (s[i] != '=') {
			b = b * 10 + stoi(digit[s.substr(i, 3)]);
			i += 3;
		}
		a += b;

		string c = to_string(a);
		cout << s;
		for (int i = 0; i < c.length(); ++i) {
			string d(1, c[i]);
			cout << digit[d];
		}
		cout << "\n";
	}
}