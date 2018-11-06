/*
LANG: C++
TASK: uva10921_telephone
*/

#include<iostream>
#include<cstring>
using namespace std;

main()
{
    string phone;
    // cin >> phone;
    while(cin >> phone){
        for(int i=0; i<phone.length(); i++){
            if(phone[i] >= 'A' && phone[i] <= 'Z'){
                if(phone[i] == 'S'){
                    cout << 7;
                }
                else if(phone[i] == 'V'){
                    cout << 8;
                }
                else if(phone[i] == 'Y' || phone[i] == 'Z'){
                    cout << 9;
                }
                else{
                    cout << (phone[i] - 'A')/3 + 2 ;
                }
            }
            else{
                cout << phone[i] ;
            }
        }
        cout << "\n";
    }
}