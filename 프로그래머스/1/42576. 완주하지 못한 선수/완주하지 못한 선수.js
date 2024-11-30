function solution(participant, completion) {
    let answer = '';
    
    const memo = {};
    
    participant.forEach((name, index) => {
        if (memo[name]) {
            ++memo[name];
        } else {
            memo[name] = 1;
        }
    });
    
    completion.forEach(name => {
        if (--memo[name] === 0) {
            delete memo[name];
        }
    });
    
    answer = Object.keys(memo)[0];
    
    return answer;
}