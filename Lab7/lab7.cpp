#include<bits/stdc++.h>
using namespace std;

int main() {
    map<char,map<char,string>>mp;
    char starting_nt ;
    cin >> starting_nt ;

    int m;
    cin >> m ;

    for(int i=0; i<m; i++) {
        char f, s ;
        string t ;
        cin >> f >> s >> t ;
        mp[f][s] = t ;
    }

    string in ;
    cin >> in ;

    stack<char> stck, input ;
    string matched = "" ;
    input.push('$') ;
    for(int i=in.size()-1;i>=0;i--)
        input.push(in[i]);

    stck.push('$') ;
    stck.push(starting_nt) ;

    while(1) {
        cout << endl << matched << "\t" << "\t" ;

        stack<char> tmp1=stck, tmp2=input;
        while(!tmp1.empty())
        {
            auto ch=tmp1.top();
            cout<<ch;
            tmp1.pop();
        }
        cout<<"\t"<<"\t";
        while(!tmp2.empty())
        {
            auto ch=tmp2.top();
            cout<<ch;
            tmp2.pop();
        }
        cout<<"\t"<<"\t";

        if(stck.size()==1 && input.size()==1 && matched==in) {
            cout << endl ;
            cout << "Accepted" ;
            break;
        }

        char ch1 = stck.top() ;
        char ch2 = input.top() ;
        if(ch1==ch2) {
            string str(1, ch1) ;
            matched += str ;
            stck.pop() ;
            input.pop() ;
        }
        else if(mp[ch1][ch2].size()) {
            string str = mp[ch1][ch2] ;
            cout << ch1 << " --> " << str ;
            stck.pop() ;
            if(str=="n")
                continue;
            for(int i=str.size()-1;i>=0;i--)
                stck.push(str[i]);
        }
        else {
            cout << endl << "Rejected!!" << endl ;
            break;
        }
    }
}
