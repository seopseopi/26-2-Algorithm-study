#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

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

    int left = 1;
    int right = houses.back() - houses.front();
    int answer = 0;

    while (left <= right) {
        int distance = left + (right - left) / 2;
        int installed = 1;
        int lastHouse = houses.front();

        for (int i = 1; i < n; ++i) {
            if (houses[i] - lastHouse >= distance) {
                ++installed;
                lastHouse = houses[i];
            }
        }

        if (installed >= c) {
            answer = distance;
            left = distance + 1;
        } else {
            right = distance - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
