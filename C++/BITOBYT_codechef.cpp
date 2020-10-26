#include <iostream>
#include <vector>

#define ll long long

using namespace std;

class bitobyt {
private:
	int time;
	vector <ll> ans;
public:
	bitobyt(int t) {
		time = t;
		ans.assign(3, 0);
	}
	vector <ll> numOfCitizen() {
		if (!time) {
			return ans;
		}
		--time;
		int q = (time / 26) ;
		int r = (time % 26);
		ll s = 1;
		s = s << q;
	
		if(r < 2) {
			ans.at(0) = s;
		}
		else if(r < 10) {
			ans.at(1) = s;
		}
		else {
			ans.at(2) = s;
		}
//		cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
		return ans;
	}
};

int main() {
	int test = 0, time = 0;
	vector <ll>ans (3);
	cin >> test;
	while(test--) {
		cin >> time ;
		bitobyt *b = new bitobyt(time);
		ans = b->numOfCitizen();
		cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
		delete(b);
	}
	return 0;
}
