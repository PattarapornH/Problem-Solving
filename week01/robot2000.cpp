#include<iostream>
using namespace std;

main()
{
    char dir[101];
    char cmd[1000];
    for(int i=0; i<1000; i++){
        cmd[i] = '\0';
    }
    char curr = 'N'; // current direction
    int cnt = 0;
    int turn = 0; // number of turn right
    cin >> dir;
    for(int i=0; i<101; i++){
        if(dir[i] == '\0'){
            break;
        }
        else if(dir[i] == 'Z'){
            cmd[cnt++] = 'Z';
            curr = 'N';
            continue;
        }

        if(curr == 'N'){
            if(dir[i] == 'E'){
                turn = 1; 
            }
            else if(dir[i] == 'S'){
                turn = 2;
            }
            else if(dir[i] == 'W'){
                turn = 3;
            }
            for(int j=0; j<turn; j++){
                cmd[cnt++] = 'R';
            }
            curr = dir[i];
        }
        else if(curr == 'E'){
            if(dir[i] == 'N'){
                turn = 3;
            }
            else if(dir[i] == 'S'){
                turn = 1;
            }
            else if(dir[i] == 'W'){
                turn = 2;
            }
            for(int j=0; j<turn; j++){
                cmd[cnt++] = 'R';
            }
            curr = dir[i];
        }
        else if(curr == 'S'){
            if(dir[i] == 'N'){
                turn = 2;
            }
            else if(dir[i] == 'E'){
                turn = 3;
            }
            else if(dir[i] == 'W'){
                turn = 1;
            }
            for(int j=0; j<turn; j++){
                cmd[cnt++] = 'R';
            }
            curr = dir[i];
        }
        else if(curr == 'W'){
            if(dir[i] == 'N'){
                turn = 1; 
            }
            else if(dir[i] == 'E'){
                turn = 2;
            }
            else if(dir[i] == 'S'){
                turn = 3;
            }
            for(int j=0; j<turn; j++){
                cmd[cnt++] = 'R';
            }
            curr = dir[i];
        }

        if(dir[i] == curr){
            cmd[cnt++] = 'F';
        }

        turn = 0; //set turn
    }
    cnt=0;
    while(cmd[cnt] != '\0'){
        cout << cmd[cnt];
        cnt++; 
    }
    cout << endl;
}