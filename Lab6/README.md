# Sample Input for DFA:
```
3
a b c
2
0 1
3
a 0 b
b 1 c
c 0 a
5
01
011
0110
0101
01001

```
Output:
```
Accepted
Rejected
Rejected
Rejected
Accepted
```

# Sample Input for NFA
## Example 1
```
a
c
9
a 0 a
a 0 b
a 1 b
b 1 a
b 1 c
b 0 c
c 0 b
c 0 c
c 1 c
5
00
010
111
0
1
```
First input is the start state, second input is the ending state.
output:
```
Accepted
Accepted
Accepted
Rejected
Rejected
```

## Example 2 (Epsilon Case)
```
a
c
5
a 0 a
a e b
b 1 b
b 1 c
c 0 c
5
01
0
1
000111
000
```
Output:
```
Accepted
Rejected
Accepted
Accepted
Rejected
```
