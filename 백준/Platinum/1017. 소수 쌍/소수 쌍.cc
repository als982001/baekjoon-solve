#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
 
#define ll long long
#define MAX_SIZE 50
#define INF 987654321
#define MOD 1000000
using namespace std;
 
int arrA[MAX_SIZE];
int arrB[MAX_SIZE];
int pick;
int idxA, idxB;
 
int matchA[MAX_SIZE];
int matchB[MAX_SIZE];
bool visit[MAX_SIZE];
 
bool isPrime(int a) {
    if (a == 1) return 0;
    else if (a != 2 && a % 2 == 0) return 0;
    
    for (int i = 3; i * i <= a; i += 2) {
        if (a % i == 0) return 0;
    }
 
    return 1;
}
 
bool f(int idx) {
    if (visit[idx]) return 0;
    visit[idx] = 1;
 
    for (int i = 0; i < idxB; i++) {
        if (i == pick) continue;
 
        if (isPrime(arrA[idx] + arrB[i]) && (matchB[i] == -1 || !visit[matchB[i]] && f(matchB[i]))) {
            matchB[i] = idx;
            matchA[idx] = i;
 
            return 1;
        }
    }
 
    return 0;
}
 
int main() {
    int arr[MAX_SIZE];
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    for (int i = 0; i < n; i++) {
        if (arr[0] % 2 == arr[i] % 2) arrA[idxA++] = arr[i];
        else arrB[idxB++] = arr[i];
    }
 
    priority_queue<int> pq;
 
    for (int i = 0; i < idxB; i++) {
        if (isPrime(arrA[0] + arrB[i])) {
            pick = i;
            
            int cnt = 1;
            memset(matchA, -1, sizeof(matchA));
            memset(matchB, -1, sizeof(matchB));
 
            for (int j = 1; j < idxA; j++) {
                memset(visit, 0, sizeof(visit));
                if (f(j)) cnt++;
            }
 
            if (cnt == n / 2) pq.push(-arrB[i]);
        }
    }
 
    if (pq.empty()) puts("-1");
    else {
        while (!pq.empty()) {
            printf("%d ", -pq.top()), pq.pop();
        }
    }
 
    return 0;
}