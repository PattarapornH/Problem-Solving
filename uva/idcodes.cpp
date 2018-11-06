/*
LANG: C++
TASK: uva146_idcodes
*/

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

main()
{
    // int x[] = {1,2,1};
    // cout << next_permutation(x,x+3) << endl;
    // cout << x[0] << " " << x[1] << " " << x[2];
    char seq[60];
    while(true){
        cin >> seq;
        if(seq[0] == '#'){
            break;
        }
        if(next_permutation(seq,seq+strlen(seq))){
            // for(int i=0; i<strlen(seq); i++){
            //     cout << seq[i];
            // }
            cout << seq;
        }
        else{
            cout << "No Successor";
        }
        cout << "\n";
    }
}