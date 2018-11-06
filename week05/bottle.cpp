/*
LANG: C++
TASK: bottle
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

vector<int> bott;

int cnt_broke(int d)
{
    int cnt=0;
    cout << d << endl;
    vector<int>::iterator up;
    while (true){
        up = upper_bound(bott.begin(), bott.end(), d);
        if(up == bott.end()){
            break;
        }
        // cout << "broke : " << *up << " ";
        // (*up) = -1;
        cnt++;
        up--;
        if(*up != -1 && *up <= d){
            // cout << *(up) << " ";
            (*up) = -1;
            cnt++;
        }
        up++;
        up++;
        if (*up != -1 && *up <= d){
            // cout << *(up) << " ";
            (*up) = -1;
            cnt++;
        }
    }
    // cout << endl;
    return cnt;
}

main()
{
    int n,m;
    int height;
    vector<int> bott;
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        scanf("%d",&height);
        bott.push_back(height);
    }
    cout << "==============\n";
    int down;
    vector<int>::iterator it;
    for(it = bott.begin(); it!=bott.end(); it++){
        cout << *it << " ";
    }
    cout << "\n==============\n";
    vector<int>::iterator up;
    for (int i = 0; i < m; i++){
        scanf("%d",&down);
        printf("%d\n",cnt_broke(down));
    }
}






// main()
// {
//     int n,m;
//     int num;
//     int cnt = 0;
//     scanf("%d %d",&n,&m);
//     int height[n];
//     for(int i=0; i<n; i++){
//         scanf("%d",&height[i]);
//     }
//     // printf("==========\n");
//     for(int i=0; i<m; i++){
//         scanf("%d",&num);
//         cnt=0;
//         for(int j=0; j<n; j++){
//             if(height[j] > num && height[j] != -1){
//                 height[j] = -1;
//                 cnt++;
//                 // cout << j << " ";
//                 if (j + 1 < n && height[j+1] != -1 && height[j+1] <= num){
//                     height[j + 1] = -1;
//                     cnt++;
//                     // cout << j+1 << " ";
//                 }
//                 if (j - 1 >= 0 && height[j - 1] != -1 && height[j - 1] <= num){
//                     height[j - 1] = -1;
//                     cnt++;
//                     // cout << j-1 << " ";
//                 }
//             }
//             // cout << "\n";
//         }
//         printf("%d\n", cnt);
//     }
// }