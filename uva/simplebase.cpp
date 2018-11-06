/*
LANG: C++
TASK: uva10473_baseconversion
*/

#include<iostream>
#include<cstring>
#include<stdio.h>
#include<math.h>
using namespace std;

main()
{
    int num = 0;
    int p = 0;
    string str;
    while(true){
        cin >> str;
        if(str[0] == '-'){
             break;
        }
        /*hexadecimal*/
        if(str[0] == '0' && str[1] == 'x'){
            /*convert to decimal*/
            for(int i=str.length()-1; i>=2; i--){
                if(str[i] >= '0' && str[i] <= '9'){
                    num+= (str[i]-'0')*pow(16,p);
                }
                else if(str[i] == 'A'){
                    num+= 10 * pow(16,p);
                }
                else if (str[i] == 'B'){
                    num += 11 * pow(16, p);
                }
                else if (str[i] == 'C'){
                    num += 12 * pow(16, p);
                }
                else if (str[i] == 'D'){
                    num += 13 * pow(16, p);
                }
                else if (str[i] == 'E'){
                    num += 14 * pow(16, p);
                }
                else if (str[i] == 'F'){
                    num += 15 * pow(16, p);
                }
                p++;
            }
            cout << num << endl;
        }
        /*decimal*/
        else{
            /*convert to int*/
            for(int i=str.length()-1; i>=0; i--){
                num+= (str[i]-'0')*pow(10,p);
                p++;
            }
            printf("0x%X\n",num);
        }
        p = 0;
        num = 0;
    }
}