#include<iostream>

using namespace std;

main()
{
    int sum = 0 , input , cnt = 0;
    while(cnt<4){
        cin >> input;
        if(input >=0 && input <1000){
            sum+=input;
            cnt++;
        }
    }
    cout << sum << endl;
}