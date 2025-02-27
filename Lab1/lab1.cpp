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

    for(auto it: parser) {
        if(it==" " || it=="")
            continue;
        cout << it << endl ;
    }

    return 0;
}

