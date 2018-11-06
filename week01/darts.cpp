#include<iostream>
#include<math.h>
using namespace std;

main()
{
    int n;
    double d;
    int x,y;
    int pts = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        d = sqrt((x*x)+(y*y));
        if(d <= 2){
            pts += 5;
        }
        else if(d > 2 && d <= 4){
            pts += 4;
        }
        else if(d > 4 && d <= 6){
            pts += 3;
        }
        else if(d > 6 && d <= 8){
            pts += 2;
        }
        else if(d > 8 && d <= 10){
            pts += 1;
        }
    }
    cout << pts << endl;
}