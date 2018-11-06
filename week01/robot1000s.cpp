#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

int cal_energy(string dir)
{
    int cnt = 0;
    int x = 0, y = 0;
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
        cnt++;
    }
    return abs(x) + abs(y);
}

int lost_command(string dir,int k)
{
    int cnt = 0;
    string lost_dir = dir;

    if(dir.length() <= k){
        return 0;
    }
    else if(dir.length() - k == 1){
        return 1;
    }
    else{
        int N = 0, S = 0, W = 0, E = 0;
        for(int i=0; i<dir.length(); i++){
            if(dir[i] == 'N'){
                N++;
            }
            else if(dir[i] == 'S'){
                S++;
            }
            else if(dir[i] == 'E'){
                E++;
            }
            else if(dir[i] == 'W'){
                W++;
            }
        }
        if(N <= S && N != 0){
            for(int i=0; i<dir.length(); i++){
                if(lost_dir[i] == 'N'){
                    lost_dir[i] = '0';
                    cnt++;
                    if(cnt == k){
                        return cal_energy(lost_dir);
                    }
                }
            }
        }
        else if(S < N && S != 0){
            for(int i=0; i<dir.length(); i++){
                if(lost_dir[i] == 'S'){
                    lost_dir[i] = '0';
                    cnt++;
                    if(cnt == k){
                        return cal_energy(lost_dir);
                    }
                }
            }
        }

        if(E <= W && E != 0){
            for(int i=0; i<dir.length(); i++){
                if(lost_dir[i] == 'E'){
                    lost_dir[i] = '0';
                    cnt++;
                    if(cnt == k){
                        return cal_energy(lost_dir);
                    }
                }
            }
        }
        else if(W < E && W != 0){
            for(int i=0; i<dir.length(); i++){
                if(lost_dir[i] == 'W'){
                    lost_dir[i] = '0';
                    cnt++;
                    if(cnt == k){
                        return cal_energy(lost_dir);
                    }
                }
            }
        }

        for(int i=0; i<lost_dir.length(); i++){
            if(lost_dir[i] != '0'){
                lost_dir[i] = '0';
                cnt++;
                if(cnt == k) return cal_energy(lost_dir);
            }
        }
    }
    return cal_energy(lost_dir);
}

main()
{
    string dir;
    int k;
    int energy;
    cin >> dir;
    cin >> k;
    energy = lost_command(dir,k);
    cout << energy*2 << endl;
}