Input Sample:
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
Operators: +, ++, <=, =
Variables: a, b, i, xyz
Keywords: for, int, return
Others: (, ), ,, 0, 1, 10, 5, ;, {, }
```
