// BOJ 2110 공유기 설치 (Gold IV)
// 정렬 + 매개변수 탐색(이분 탐색)
// 시간 복잡도: O(N log N + N log(maxX))

#include <bits/stdc++.h>
using namespace std;

// 공유기 사이 최소 거리를 dist 이상으로 유지하면서 c개 이상 설치할 수 있는지 판단
bool canInstall(const vector<int>& houses, int c, int dist) {
    int count = 1;              // 첫 집에는 항상 설치
    int last = houses[0];       // 마지막으로 설치한 집의 좌표
    for (size_t i = 1; i < houses.size(); i++) {
        if (houses[i] - last >= dist) {
            count++;
            last = houses[i];
            if (count >= c) return true;
        }
    }
    return count >= c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    vector<int> houses(n);
    for (int& x : houses) cin >> x;
    sort(houses.begin(), houses.end());

    // 답이 될 수 있는 거리의 범위: [1, 가장 먼 두 집의 거리]
    int lo = 1, hi = houses[n - 1] - houses[0];
    int answer = 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (canInstall(houses, c, mid)) {
            answer = mid;       // mid 거리로 가능 → 더 넓혀 본다
            lo = mid + 1;
        } else {
            hi = mid - 1;       // 불가능 → 거리를 줄인다
        }
    }

    cout << answer << '\n';
    return 0;
}
