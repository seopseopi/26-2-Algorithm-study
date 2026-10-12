
# 백준 2110번 공유기 설치

N, C = map(int, input().split())

houses = []
for _ in range(N):
    houses.append(int(input()))

# 집의 좌표 정렬
houses.sort()

left = 1
right = houses[-1] - houses[0]
answer = 0

while left <= right:
    mid = (left + right) // 2

    # 첫 번째 집에 공유기 설치
    count = 1
    last = houses[0]

    # 최소 mid 거리만큼 떨어진 집에 설치
    for house in houses[1:]:
        if house - last >= mid:
            count += 1
            last = house

    if count >= C:
        # 설치 가능 → 거리 늘리기
        answer = mid
        left = mid + 1
    else:
        # 설치 불가능 → 거리 줄이기
        right = mid - 1

print(answer)
