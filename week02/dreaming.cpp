#include<iostream>
#include<cstring>
using namespace std;


void convert(string str,int A[],int len)
{
    for(int i=0; i<len; i++){
        A[i] = str[i] - '0';
    }
}

void find_res(int A[],int B[],int res[],int lenA,int lenB)
{
    int dis = lenA - lenB;
    /* increase */
    for(int i=0; ; i++){
        if(i-dis >= 0){
            res[i] = A[i] + B[i-dis];
        }
        else{
            res[i] = A[i];
        }
        if(i == lenA){
            break;
        }
    }
    /* carry */
    for(int i=lenA-1; i>0; i--){
        if(res[i] >= 10){
            res[i-1] += 1;
            res[i] = res[i]%10;
        }
    }

}
main()
{
    string str1,str2;
    int res[301];
    cin >> str1;
    cin >> str2;
    int lenA = str1.length();
    int lenB = str2.length();
    int A[lenA];
    int B[lenB];
    convert(str1,A,lenA);
    convert(str2,B,lenB);
    if(lenA > lenB){
        find_res(A,B,res,lenA,lenB);
    }
    else{
        find_res(B,A,res,lenB,lenA);
    }

    int len = (lenA > lenB) ? lenA:lenB;
    for(int i=0; i<len; i++){
        cout << res[i];
    }
    cout << endl;    
}