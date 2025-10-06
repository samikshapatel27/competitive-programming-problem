# Frequency Assignment with Interference Constraints

## Problem Overview
This is an original competitive programming problem designed for Codeforces Div1/Div2 contests. The problem involves assigning frequencies to devices in a wireless network with both direct and secondary interference constraints.

## Key Features
- **Originality**: Not a known variation of existing problems
- **Appropriate Difficulty**: Suitable for Div2 medium-hard / Div1 easy-medium
- **Multiple Solution Approaches**: Can be solved with graph analysis and combinatorial optimization
- **Strong Test Cases**: Includes edge cases and challenging scenarios
- **AI-Tested**: Validated against Qwen AI model which failed on 3 attempts

## Problem Structure
- Devices as graph vertices, communication links as edges
- Two types of interference constraints:
  - Direct interference: Adjacent devices cannot share frequency
  - Secondary interference: Devices sharing a common neighbor must have frequencies differing by at least 2

## Solution Strategy
The optimal solution involves:
1. Graph analysis (bipartiteness checking, triangle and cycle detection)
2. Special case handling for small k values and edge cases
3. Understanding that even bipartite graphs like 4-cycles cannot assign all devices due to distance-2 constraints
4. Conservative approach for non-bipartite graphs where complex constraints prevent full assignment

## AI Testing Results
The problem was tested against Qwen 3-235B-A22B-2507 model with three attempts:

### Attempt 1: Simple Greedy BFS
- Failed due to local optimization without global consideration
- Couldn't handle triangle constraints properly

### Attempt 2: Enhanced with Triangle Detection  
- Still failed on complex graph structures
- Greedy approach couldn't guarantee optimal node selection

### Attempt 3: Maximum Independent Set on Conflict Graph
- Conflict modeling was incomplete
- Greedy MIS algorithm is suboptimal for this problem

All three attempts failed on at least one test case, confirming the problem's non-trivial nature.

## Files Description
- `problem.md`: Complete problem statement
- `solution.cpp`: Optimal accepted solution
- `solution_bf.cpp`: Brute-force reference solution for small cases
- `solution.md`: Detailed solution explanation
- `idea.md`: Problem development process and AI testing insights
- `test_cases/`: Comprehensive test cases
- `qwen/`: Three failed attempts by Qwen AI model
- `generator.cpp`: Test case generator
- `requirements.json`: Time and memory constraints

## Verification
The solution has been tested against:
- Small cases (verified by brute-force)
- Edge cases (no edges, single node, complete graphs)
- Complex scenarios (triangles, odd cycles, dense graphs)
- AI-generated attempts (all failed)

## Expected Performance
- Time Complexity: O(n²) worst case
- Space Complexity: O(n + m)
- Fits within 2s time limit for n ≤ 2000

## Usage
1. Compile the solution: `g++ -std=c++17 -O2 solution.cpp -o solution`
2. Run against test cases: `./solution < test_cases/1.in`
3. Compare with expected output