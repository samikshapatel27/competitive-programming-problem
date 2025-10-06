# Frequency Assignment with Interference Constraints

## Problem Statement

You are managing a wireless network of `n` devices labeled from `1` to `n`. The network is represented as an undirected graph where edges represent communication links.

Each device must be assigned a transmission frequency from `1` to `k`. However, due to interference constraints:

1. **Direct Interference**: If two devices are connected by an edge, they cannot have the same frequency.
2. **Secondary Interference**: If two devices share a common neighbor, their frequencies must differ by at least 2.

Your task is to determine the **maximum number of devices** that can be assigned frequencies satisfying these constraints, or determine if it's impossible to assign frequencies to all devices.

## Input Format

The first line contains three integers: `n`, `m`, `k`  
- `n` (1 ≤ n ≤ 2000): number of devices  
- `m` (0 ≤ m ≤ min(5000, n×(n-1)/2)): number of communication links  
- `k` (1 ≤ k ≤ 10^9): available frequencies

The next `m` lines each contain two integers `u` and `v` representing a communication link between devices `u` and `v` (1-indexed).

## Output Format

Output a single integer:
- The maximum number of devices that can be assigned frequencies satisfying the constraints
- If all devices can be assigned, output `n`

## Examples

### Example 1
Input:
4 4 3
1 2
2 3
3 4
4 1
Output:
3

### Example 2
Input:
5 4 2
1 2
2 3
3 4
4 5
Output:
4

### Example 3
Input:
3 3 2
1 2
2 3
1 3
Output:
2

## Constraints
- Time limit: 2 seconds
- Memory limit: 256 MB