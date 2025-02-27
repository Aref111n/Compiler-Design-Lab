#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

bool isdatatype(string s) {
    string dt[8] = {"int", "float", "double", "bool", "long"};
    for(auto it: dt) {
        if(it==s)
            return 1;
    }
    return 0;
}

bool isoperator(char ch) {
    char op[20] = {'+', '-', '*', '/', '%', '=', '<', '>'};
    for(auto it: op) {
        if(it==ch)
            return 1;
    }
    return 0;
}

bool isoperator(string s) {
    string op[20] = {"+", "-", "*", "/", "%", "=", "<", ">", ">=", "<=", "==", "+=", "-=", "*=", "/=", "++", "--"};
    for(auto it: op) {
        if(it==s)
            return 1;
    }
    return 0;
}

int performer(int a, int b, string s) {
    if(s=="/")
        return a/b;
    else if(s=="*")
        return a*b;
    else if(s=="+")
        return a+b;
    else if(s=="-")
        return a-b;
}

map<string, ll>mp ;

int main()
{
    FILE *ptr;
    ptr = fopen("eq.txt", "r");
    char arr[100001];

    vector<string>parser;

    mp["/"]=1;
    mp["*"]=1;
    mp["+"]=2;
    mp["-"]=2;

    int p = 0;
    while (fgets(arr, 100001, ptr))
    {
        string curr = "";
        for (int i = 0; arr[i] != '\0'; i++) {
            if(arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\n') {
                //cout << curr << endl ;
                parser.push_back(curr) ;
                curr = "" ;
                continue;
            }
            else if(arr[i]=='(' || arr[i]==')' || arr[i]=='{' || arr[i]=='}' || arr[i]==',' || arr[i]==';') {
                //cout << curr << endl ;
                parser.push_back(curr) ;
                curr = "" ;
                curr += arr[i] ;
                //cout << arr[i] << endl ;
                parser.push_back(curr) ;
                curr = "";
                continue;
            }
            else if(isoperator(arr[i])) {
                //cout << curr << endl ;
                parser.push_back(curr) ;
                if(isoperator(arr[i+1])) {
                    curr = "" ;
                    curr += arr[i] ;
                    curr += arr[i+1] ;
                    //cout << arr[i] << arr[i+1] << endl ;
                    parser.push_back(curr) ;
                    i++;
                }
                else {
                    // cout << arr[i] << endl ;
                    curr = "" ;
                    curr += arr[i] ;
                    parser.push_back(curr) ;
                }

                curr = "" ;
                continue;
            }
            curr += arr[i] ;
        }

        if(curr.size())
            parser.push_back(curr) ;
    }

    int MAX_PRECEDENCE = 3;
    map<int, int>count_op ;
    for (auto it = parser.begin(); it != parser.end(); ++it) {
        if(*it==" " || *it=="")
            continue;
        if(isoperator(*it)) {
            count_op[mp[*it]]++ ;
        }
    }

    for (auto tt = parser.begin(); tt != parser.end(); ++tt)
        cout << *tt ;
    cout << endl ;

    int c=0 ;
    while(c<MAX_PRECEDENCE) {
        while(count_op[c]>0) {
            for (auto it = parser.begin(); it != parser.end(); ++it) {
                if(*it==" " || *it=="")
                    continue;
                if(isoperator(*it)) {
                    if(mp[*it]==c) {
                        int a = stoll(*prev(it)) ;
                        int b = stoll(*next(it)) ;
                        int ans = performer(a, b, *it) ;
                        parser.insert(it, to_string(ans));
                        parser.erase(prev(it));
                        parser.erase(next(it));
                        parser.erase(it);
                        count_op[c]-- ;

                        for (auto tt = parser.begin(); tt != parser.end(); ++tt)
                            cout << *tt ;
                        cout << endl ;
                        if(count_op[c]==0)
                            break;
                    }
                }
            }
        }
        c++ ;
    }

    return 0;
}
