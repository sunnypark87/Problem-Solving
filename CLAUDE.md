# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Purpose

Personal study repository for algorithms, data structures, and coding practice. The user solves problems on multiple judges — **Baekjoon** (BOJ), **Programmers**, and **Leetcode** — and uses this repo to archive solutions, organized by topic.

## How Claude Should Collaborate

The study loop is:
1. The user writes their own solution **at the repo root** (unsorted scratch).
2. Claude **sorts the file** into the correct `<site>/<lang>/<topic>/<subtopic>/` directory based on the problem's algorithm/data-structure category.
3. Claude reviews that code and explains a better version — clearer logic, better complexity, idiomatic style for the language in question, or stronger data-structure/algorithm choice.
4. After the review, Claude **appends the important takeaways** (key insights, common pitfalls, idiom notes, complexity reasoning) from that review into the destination directory's `README.md`. The README accumulates topic knowledge across all problems in that folder over time.

Therefore:
- **Do not write a solution from scratch unless asked.** Wait for the user's attempt, then critique it.
- **Write the review explanation in Korean.** This is a study repo and the user has explicitly asked that code reviews and explanations be in Korean so they're easier to internalize. Code, identifiers, file paths, and commit messages stay as-is — only the prose (complexity analysis, why-this-is-better, idiom suggestions) is in Korean. Non-review tasks (setup, file moves, tooling) follow whatever language the user is currently using.
- Reviews should teach: name the issue, explain *why* it matters (time/space complexity, readability, language idiom), then show the improved version. Don't just dump replacement code.
- Tailor advice to the target language and judge: BOJ C++ needs fast I/O (`ios::sync_with_stdio(0); cin.tie(0);`); Programmers gives a function signature and expects a return value (no stdin parsing); Leetcode is method-on-class style. Don't apply BOJ idioms to a Programmers JS solution.

## Repository Layout

```
Baekjoon/Cpp/<topic>/<subtopic>/         # finished BOJ C++ solutions
Programmers/Cpp/                         # Programmers C++ solutions (mirrors topic tree)
Programmers/Javascript/                  # Programmers JavaScript solutions (see below)
<root>/Tier_Number_Name.cpp              # work-in-progress / unsorted scratch (BOJ)
test.cpp, testcase.txt, a.out            # local scratch (gitignored)
```

### Topic Tree (used by `Baekjoon/Cpp` and `Programmers/*`)

```
01_DataStructure/      01_Linear (Array/Stack/Queue/Deque/LinkedList), 02_Tree_Heap,
                       03_Map_Set, 04_DisjointSet, ETC
02_Algorithm/          01_Bruteforce_Backtracking, 02_Sort, 03_BinarySearch,
                       04_Divide_Conquer, 05_TwoPointer_SlidingWindow,
                       06_Greedy, 07_DP, 08_PrefixSum, ETC
03_Graph/              01_BFS_DFS, 02_ShortestPath, 03_Tree, 04_MST, 05_TopologicalSort
04_Math/               01_NumberTheory, 02_Combinatorics, 03_Arithmetic, 04_Geometry
05_String/
06_Implementation/
07_NotCompleted/       unsolved attempts kept for later
```

### Extra for `Programmers/Javascript/`

JavaScript is being studied from a lower starting point than C++, so this tree adds a basics layer **before** the topic dirs:

```
00_Basic/
  01_IO/         input parsing patterns (Programmers gives args, but BOJ-style stdin still useful)
  02_BuiltIn/    Array/String/Map/Set built-in methods, iteration patterns, typed numerics
```

Solutions that exist purely to learn a language feature live under `00_Basic/`; real problem solutions go in the topic dirs.

When `Baekjoon/Cpp/Cpp` was set up, finished solutions live in their topic subdirectory. The repo root is **staging only** — once a BOJ solution at the root is done, move it into the matching `Baekjoon/Cpp/<topic>/<subtopic>/` folder.

## File Naming Conventions (per site)

Naming **differs by site** — do not apply one site's rule to another.

- **Baekjoon** (current convention): `Tier_Number_Name.cpp`
  - `Tier`: `B`/`S`/`G`/`P` (Bronze/Silver/Gold/Platinum) + 1–5
  - `Number`: BOJ problem number
  - `Name`: Korean problem name, no spaces
  - Example: `G5_2504_괄호의값.cpp`, `S1_11286_절댓값힙.cpp`
- **Programmers**: `L<Level>_<Name>.<ext>`
  - `Level`: `0`–`5` (Programmers 레벨 0~5 — Lv.0은 코딩 기초 트레이닝)
  - `Name`: 한글 문제명, 공백 없이
  - Example: `L0_a와b출력하기.js`, `L1_같은숫자는싫어.js`
- **Leetcode**: not yet present; same — follow the user's lead.

## Per-Directory `README.md` (Topic Notes)

Every topic and subtopic directory contains a `README.md` that accumulates **what was learned** from solving problems in that folder. This is the knowledge artifact of the study loop — code lives in the `.cpp`/`.js` files, *insight* lives in the README.

When Claude reviews a solution and moves it into a topic directory, it **appends** review takeaways to that directory's `README.md`. Guidelines:
- Korean prose (matches the review-language rule and existing README style).
- Append, don't overwrite. The user's hand-written notes (see `03_Graph/01_BFS_DFS/README.md` for the established style) are authoritative — only add to them.
- Record what is **transferable across problems**: algorithmic gotchas, idiom notes, complexity trade-offs, common pitfalls. Don't restate the problem statement or full solution.
- Keep entries short. Bullet points or 1–3 sentence sub-sections, tagged with the problem (e.g. `### G4 1753 최단경로` then the takeaway). Future readers should be able to scan the file and recall the lesson without re-reading the solution.
- If the existing README already covers the lesson, link to it or extend that section rather than duplicating.

## Running Solutions Locally

There is no build system, no test harness, and no dependencies. Each file is independent.

```bash
# BOJ C++ (stdin-driven)
g++ -std=c++17 -O2 -o a.out path/to/SolutionFile.cpp
./a.out < testcase.txt

# Programmers JS (function-return style, run with Node)
node path/to/SolutionFile.js
```

Programmers problems pass arguments into a `solution(...)` function and expect a return value — they don't read stdin. Reviews should call out when a user's JS solution incorrectly parses stdin instead of accepting parameters.

## Commit Style

Observed pattern in `git log`: `<Tier> <Number> <Name> <lang> 완료`, e.g. `G4 11404 플로이드 c++ 완료`. Match this style for BOJ commits. For Programmers/Leetcode, follow whatever pattern the user establishes once those commits start landing.

## Git Hygiene

`.gitignore` excludes `*.exe`, `*.out`, `testcase.txt`, `.vscode/`, and `test.*`. The `.omc/` directory is tooling state and is not part of the solution archive — never instruct the user to commit it.
