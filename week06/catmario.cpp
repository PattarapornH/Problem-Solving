#include<iostream>
using namespace std;

main()
{
    int N,M;
    cin >> N >> M;
    int timer[N];
    int A,B;
    for (int i = 0; i < N; i++){
        timer[i] = 999999999;
    }        
    for (int i = 0; i < M; i++){
        cin >> A >> B;
        if(timer[A-1] > B){
            timer[A-1] = B;
        }
    }
    int sum = 0;
    for(int i = 0; i < N; i++){
        sum += timer[i];
    }
    cout << sum << endl;
    for(int i = 0; i < N; i++){
        cout << i+1 << " " << timer[i] << endl;
    }

}