	#include <iostream>
	#include <string>
	#include <vector>

	using namespace std;

	using PCI = std::pair<char,int>;

	void get(const string &s,vector<PCI> &mp) {
		for(int i = 0;i < s.size();i++) {
			int j = i;
			while(j < s.size() && s[j] == s[i]) j++;
			mp.emplace_back(s[i],j - i);
			i = j - 1;
		}
	}


	int main() {
		// freopen("input.txt","r",stdout);
		string s,t;
		cin >> s >> t;
		vector<PCI> mp1,mp2;
		get(s,mp1);
		get(t,mp2);
		bool ans = true;
		if(mp1.size() != mp2.size()) {
			cout << "No" << endl;
			return 0;
		}
		for(int i = 0;i < mp1.size();i++) {
			if(mp1[i].first != mp2[i].first) {
				ans = false;
				break;
			}
			if (!(mp1[i].second == mp2[i].second || mp1[i].second < mp2[i].second && mp1[i].second >= 2)) {
				ans = false;
				break;
			}
		}

		if(ans) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}
