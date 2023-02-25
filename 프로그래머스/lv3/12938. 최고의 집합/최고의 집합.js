function solution(n, s) {
    let answer = [];
    
    if (n > s) return [-1];
    
    const num = Math.floor(s / n);
    const r = s % n;
    
    for (let i = 0; i < n; ++i) {
        answer.push(num);
    }
    
    for (let t = 0, idx = answer.length - 1; t < r; ++t, --idx) {
        ++answer[idx];
    }
    
    return answer;
}