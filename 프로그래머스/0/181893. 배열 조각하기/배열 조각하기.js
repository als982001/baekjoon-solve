function solution(arr, query) {
    const answer = [];
    
    query.forEach((item, index) => {
        if (index % 2 == 0) {
            arr = arr.slice(0, item + 1)
        } else {
            arr = arr.slice(item);
        }
    })
    
    arr.forEach((item) => {
        answer.push(item);
    })
    
    return answer;
}