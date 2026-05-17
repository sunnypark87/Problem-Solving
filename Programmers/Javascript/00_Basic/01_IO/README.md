# Input / Output (입출력)

입력 파싱과 출력 포매팅 패턴.

## 📝 학습 노트

> 이 디렉터리의 문제를 풀면서 얻은 인사이트가 누적됩니다.

### 공통 패턴 — Programmers Lv.0 (코딩 기초 트레이닝)

- Lv.0 문제는 BOJ처럼 **`readline`으로 stdin**을 읽고 `console.log`로 출력합니다. (Lv.1+ 정규 문제는 `function solution(...)` 시그니처라 다름 — 헷갈리지 말 것.)
- 기본 스켈레톤:
  ```js
  const readline = require('readline');
  const rl = readline.createInterface({ input: process.stdin, output: process.stdout });
  let input = [];
  rl.on('line', (line) => { input.push(line); })
    .on('close', () => { /* 풀이 */ });
  ```
- 한 줄만 읽는 문제라면 `input`을 배열로 안 만들고 그냥 문자열 한 개로 받아도 됩니다.

### JS 관용구 (Lv.0 단계에서 굳혀둘 것)

- **`let`/`const` 누락 = 암묵적 전역**: `str = input[0]`처럼 키워드 없는 대입은 전역 오염. 항상 `const`/`let` 붙이기.
- **화살표 함수**가 콜백 표준: `rl.on('line', (line) => { ... })`.
- **구조 분해 할당**: 공백 구분 입력은 `const [a, b] = line.split(' ')` 한 줄로 꺼내는 게 인덱스 접근보다 의미가 명확.
- **템플릿 리터럴**: `console.log("a =", x)`보다 `` console.log(`a = ${x}`) ``가 JS다운 표현.
- **문자열 변환은 `map` + `join`**: `for` 루프로 `str += c` 누적하기보다 `[...str].map(...).join('')`이 함수형/관용적.
- **백슬래시 그대로 출력은 `String.raw`**: 일반 문자열·템플릿 리터럴에서 `\(`처럼 인식 안 되는 이스케이프는 백슬래시가 **그냥 버려짐**(→ `(`만 남음). 정규식·경로·LaTeX·특수문자 출력 모두에 유용.
- **입력이 없는 문제는 `readline` 불필요**: 상단에서 바로 `console.log(...)` 한 줄로 끝. Node는 동기 실행 후 자동 종료.

### 문제별 takeaway

#### L0 문자열출력하기
- 입력이 단일 라인일 때는 `input`을 배열로 감쌀 필요 없음. 변수 하나면 충분.

#### L0 a와b출력하기
- 공백 구분 두 값 받기 → `const [a, b] = line.split(' ')`. 인덱스 접근(`input[0]`, `input[1]`)보다 가독성 우위.
- 출력만 하는 문제라면 `Number()` 변환은 불필요(템플릿 리터럴이 알아서 문자열화).

#### L0 특수문자출력하기
- **이스케이프 함정**: 템플릿 리터럴에서 `\(`는 인식되지 않는 이스케이프라 백슬래시가 사라집니다. `\\(`로 써야 `\(`가 그대로 출력됨. (`\\` → `\`, `\'` → `'`, 같은 알려진 이스케이프는 정상 동작.)
- **권장 풀이**: `console.log(String.raw\`!@#$%^&*\(\'"<>?:;\`)` — `String.raw` 태그가 모든 이스케이프 처리를 건너뛰므로 소스와 출력이 1:1 매칭.
- 입력이 없는 문제이므로 `readline` 인터페이스를 만들 필요 없음.

#### L0 대소문자바꿔서출력하기
- 핵심 트릭: `c === c.toUpperCase() ? c.toLowerCase() : c.toUpperCase()`.
  - `toUpperCase`/`toLowerCase`는 알파벳이 아닌 문자(숫자·기호·공백)에 대해 **원본을 그대로 반환**합니다. 그래서 비알파벳은 자동으로 통과되며 별도 분기가 필요 없음.
- **검사용 호출과 변환용 호출을 중복하지 말 것**: `toLowerCase()`를 한 번 계산해서 변수에 저장한 뒤 비교·재사용. 한 글자당 변환 호출 3회 → 1~2회로 감소.
- `for` + 문자열 누적 대신 `[...str].map(...).join('')` 패턴이 표준.
- `[...str]`은 `split('')`과 거의 같지만 **서로게이트 페어(이모지 등)에 안전**합니다.
- 정의해놓고 안 쓰는 함수(예: `isLowerCase`)는 dead code — 제거.
