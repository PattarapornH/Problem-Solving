#include<iostream>
using namespace std;

main()
{
    int cnt = 0;
    int x = 0, y = 0;
    char dir[101];
    cin >> dir;
    while(dir[cnt] != '\0'){
        if(dir[cnt] == 'N'){
            y++;
        }
        else if(dir[cnt] == 'S'){
            y--;
        }
        else if(dir[cnt] == 'E'){
            x++;
        }
        else if(dir[cnt] == 'W'){
            x--;
        }
        else if(dir[cnt] == 'Z'){
            x = 0;
            y = 0;
        }
        cnt++;
    }
    cout << x << " " << y << endl;
}

