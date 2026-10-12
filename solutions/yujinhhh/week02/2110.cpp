#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool canInstall(const vector<int>& houses, int routers, int distance) {
    int count = 1;
    int last = houses.front();

    for (size_t i = 1; i < houses.size(); ++i) {
        if (houses[i] - last >= distance) {
            ++count;
            last = houses[i];
            if (count >= routers) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    vector<int> houses(n);
    for (int& house : houses) {
        cin >> house;
    }
    sort(houses.begin(), houses.end());

    int low = 1;
    int high = houses.back() - houses.front();
    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canInstall(houses, c, mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
