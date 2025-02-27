Sample Input
```cpp
int func(int xyz)
{
   xyz=xyz+1;
   return xyz;
}

int main()
{
	int a, b=5;
	for(int i=0;i<=10;i++)
	{
	  b=b+func(i);
	}
    return 0;
}
```
Output
```
Functions: func, main
Variables: <1 id>
<2 id>
<3 id>
<4 id>
1-->a
2-->b
3-->i
4-->xyz
```
