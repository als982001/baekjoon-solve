#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    int coupon = chicken;                  // 시작 쿠폰 = 주문한 치킨 수

    while (coupon >= 10) {                 // 10장 모일 때마다 교환
        int exch = coupon / 10;            // 이번에 교환해서 받는 서비스 치킨 수
        answer += exch;                     // 서비스 치킨 누적
        coupon = (coupon % 10) + exch;     // 남은 쿠폰 + 서비스 치킨에서 받은 쿠폰
    }
    return answer;
}