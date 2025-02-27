#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

bool isdatatype(string s) {
    string dt[100] = {"int", "float", "double", "bool", "long", "return", "for", "while", "do", "if", "else"};
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

int main()
{
    FILE *ptr;
    ptr = fopen("input2.txt", "r");
    char arr[100001];

    vector<string>parser;

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
    }

    set<string>functions, operators, variables, keywords, others ;
    map<string, ll>func, var ;

    for (auto it = parser.begin(); it != parser.end(); ++it) {
        if (isoperator(*it)) {
            operators.insert(*it);
        }
        else if (isdatatype(*it)) {
            keywords.insert(*it);
        }
        else if (next(it) != parser.end() && *next(it) == "(") {
            auto jt = next(it);
            ++jt;
            if(*jt==")") {
                functions.insert(*it) ;
                func[*it]=1;
            }
            else{
                int func_checker = 0 ;
                while (jt != parser.end() && *jt != ")") {
                    if(isdatatype(*jt))
                        func_checker = 1;
                    ++jt;
                }

                if(func_checker) {
                    functions.insert(*it);
                    func[*it]=1;
                }
            }
        }
        else if (next(it) != parser.end() && (*next(it)=="," || *next(it)==")" || *next(it)=="=" || *next(it)=="(")) {
            variables.insert(*it) ;
            var[*it]=1;
        }
        else
            if(var[*it]==0 && func[*it]==0 && *it!="")
                others.insert(*it) ;
    }

    cout << "Functions: " ;
    for (auto it = functions.begin(); it != functions.end(); ++it) {
        if(*it!="")
        {
            cout << *it;
            if (next(it) != functions.end())
                cout << ", ";
        }
    }
    cout << endl;

    cout << "Variables: " ;

    int c=1;
    for(auto it: var) {
        if(it.second>0) {
            cout << "<" << c++ << " id>" << endl ;
            var[it.first] = c-1 ;
        }
    }

    for(auto it: var) {
        if(it.second>0) {
            cout << it.second << "-->" << it.first << endl ;
        }
    }
    cout << endl;

    return 0;
}

