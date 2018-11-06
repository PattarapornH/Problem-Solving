/*
    . space
    x grass
    # stone
*/
#include<iostream>
using namespace std;

main()
{
    int N,M;
    cin >> N >> M;
    string field[N];
    char cmd;
    int pos;
    for(int i=0; i<N; i++){
        cin >> field[i];
    }

    for(int i=0; i<M; i++){
        cin >> cmd >> pos;
        if(cmd == 'L'){
            //eat from left
            for(int i=0; i<N && field[pos-1][i] =='x'; i++){
                field[pos-1][i] = '.';
            }
        }
        else if(cmd == 'R'){
            //eat from right
            for (int i = N-1; i >= 0 && field[pos - 1][i] == 'x'; i--){
                field[pos - 1][i] = '.';
            }
        }
        else if(cmd == 'U'){
            //eat from upper
            for (int i = 0; i < N && field[i][pos-1] == 'x'; i++){
                field[i][pos-1] = '.';
            }
        }
        else if(cmd == 'D'){
            //eat from lower
            for (int i = N-1; i >= 0 && field[i][pos-1] == 'x'; i--){
                field[i][pos-1] = '.';
            }
        }
        else if(cmd == 'A'){
            //add grass row
            for (int i = 0; i < N ; i++){
                if(field[pos-1][i] != '#'){
                    field[pos - 1][i] = 'x';
                }
            }
        }
        else if(cmd == 'B'){
            //add grass col
            for (int i = 0; i < N ; i++){
                if(field[i][pos-1] != '#'){
                    field[i][pos - 1] = 'x';
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        cout << field[i] << endl;
    }
}