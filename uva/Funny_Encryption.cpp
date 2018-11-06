#include<iostream>
#include<cmath>
using namespace std;

int convert_to_dec(int x,int k)
{
    int res =0 ,cnt = 0;
    while(k!=0){
        res += (k%10)*pow(x,cnt++);
        k/=10;
    }
    return res;
}
int convert(int x,int k)
{
    int cnt = 0;
    while(k != 0){
        if(k%x == 1){
            cnt++;
        }
        k = k/x;
    }
    return cnt;
}

main()
{
    int n,k;
    cin >> n;
    int bin[n],hex[n];
    for(int i=0; i<n; i++){
        cin >> k; 
        bin[i] = convert(2,k);
        hex[i] = convert(2,convert_to_dec(16,k));
    }
    for(int i=0 ;i<n;i++){
        cout << bin[i] << " " << hex[i] << endl;
    }
}