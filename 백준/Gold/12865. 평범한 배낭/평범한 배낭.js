const fs = require("fs");

// 백준 제출 시 '/dev/stdin', 로컬 테스트 시 'example.txt'
const input = fs
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "example.txt")
  .toString()
  .trim()
  .split("\n");

const Bigger = (a, b) => {
  return a > b ? a : b;
};

let answer = 0;

// N: 물품의 수
// K: 버틸 수 있는 무게
let [N, K] = input[0].split(" ");
N = Number(N);
K = Number(K);

input.unshift("0 0");

const inputs = input.reduce((acc, item, index) => {
  if (index <= 1) {
    return acc;
  }

  const [weight, value] = item.split(" ");

  const thing = { weight: Number(weight), value: Number(value) };

  acc.push(thing);

  return acc;
}, []);

let dp = new Array(N + 1).fill(0).map(() => {
  const arr = new Array(K + 1);
  arr.fill(0);

  return [...arr];
});

for (let bearableWeight = 0; bearableWeight <= K; ++bearableWeight) {
  for (let idx = 0; idx < inputs.length; ++idx) {
    const { weight, value } = inputs[idx];

    if (bearableWeight - weight >= 0) {
      dp[idx + 1][bearableWeight] = Bigger(
        dp[idx][bearableWeight],
        dp[idx][bearableWeight - weight] + value
      );
    } else {
      dp[idx + 1][bearableWeight] = dp[idx][bearableWeight];
    }
  }
}

console.log(dp[N][K]);
