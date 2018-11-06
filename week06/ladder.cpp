#include<iostream>
using namespace std;

main()
{
    int N,M;
    cin >> N >> M;
    int path[N];
    int pos = 0;
    int dice = 0;
    for(int i=0 ; i<N; i++){
        cin >> path[i];
    }
    for(int i=0; i<M; i++){
        cin >> dice;
        pos+=dice;
        if(path[pos-1] != 0 && pos < N){
            pos+=path[pos-1];
        }
        pos = (pos < 0) ? 0 : pos;
    }
    pos = (pos > N)? N:pos;
    cout << pos << endl;
}