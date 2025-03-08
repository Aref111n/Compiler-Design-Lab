## Sample Input 1
```
E
13
E i Te
E ( Te
e + +Te
e ) n
e $ n
T i Ft
T ( Ft
t + n
t * *Ft
t ) n
t $ n
F i i
F ( (E)
 
i+i*i
```
## Output
```
Matched         Stack           Input           Action

                E$              i+i*i$          E --> Te
                Te$             i+i*i$          T --> Ft
                Fte$            i+i*i$          F --> i
                ite$            i+i*i$
i               te$             +i*i$           t --> n
i               e$              +i*i$           e --> +Te
i               +Te$            +i*i$
i+              Te$             i*i$            T --> Ft
i+              Fte$            i*i$            F --> i
i+              ite$            i*i$
i+i             te$             *i$             t --> *Ft
i+i             *Fte$           *i$
i+i*            Fte$            i$              F --> i
i+i*            ite$            i$
i+i*i           te$             $               t --> n
i+i*i           e$              $               e --> n
i+i*i           $               $
Accepted
```

## Sample Input 2
```
E
13
E i Te
E ( Te
e + +Te
e ) n
e $ n
T i Ft
T ( Ft
t + n
t * *Ft
t ) n
t $ n
F i i
F ( (E)

i*+i
```

## Output
```
Matched         Stack           Input           Action

                E$              i*+i$           E --> Te
                Te$             i*+i$           T --> Ft
                Fte$            i*+i$           F --> i
                ite$            i*+i$
i               te$             *+i$            t --> *Ft
i               *Fte$           *+i$
i*              Fte$            +i$
Rejected!!
```
