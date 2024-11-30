function solution(nums) {
    let answer = 0;
    
    const memo = {};
    let count = 0;
    
    nums.forEach(num => {
        if (memo[num] === undefined) {
            memo[num] = true;
            ++count;
        }
    });
    
    if (count > nums.length / 2) {
        answer = nums.length / 2;
    } else {
        answer = count;
    }
    
    return answer;
}