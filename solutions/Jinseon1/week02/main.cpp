#include <iostream>
#include <algorithm>
using namespace std;

int house[200000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> house[i];
    }

    sort(house, house + n);

    int left = 1;
    int right = house[n - 1] - house[0];
    int answer = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        int cnt = 1;
        int last = house[0];

        for (int i = 1; i < n; i++) {
            if (house[i] - last >= mid) {
                cnt++;
                last = house[i];
            }
        }

        if (cnt >= c) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << answer << '\n';

    return 0;
}