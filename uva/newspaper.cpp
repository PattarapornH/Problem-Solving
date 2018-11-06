/*
LANG: C++
TASK: uva11340_newspaper
*/

#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
using namespace std;

int n, k;
char ch;
double p;
map<char, double> price; // price each character

int find_price(string txt)
{
    int res=0;
    for (int j = 0; j < txt.length(); j++){
        map<char, double>::iterator it = price.find(txt[j]);
        if (it != price.end()){
            // cout << txt[j] << " \n"; 
            res += it->second;
        }
    }
    return res;
}

main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    scanf("%d",&n);

    for(int i=0; i<n; i++){
        double res = 0;
        scanf("%d",&k);
        // cout << "input price each charater\n";
        for(int j=0; j<k; j++){
            scanf(" %c",&ch);
            scanf("%lf",&p);
            price.insert(pair<char,double> (ch,p));
        }
        // cout << "input line\n";
        int m;
        scanf("%d", &m);
        cin.ignore();
        // cout << "input text\n";
        for(int j=0; j<m; j++){
            string txt = "";
            getline(cin, txt);
            // cout << txt << endl;
            res+=find_price(txt);
            // cout << res << endl;
        }
        res /= 100;
        printf("%0.2lf$\n", res);
        price.clear();
    }
}