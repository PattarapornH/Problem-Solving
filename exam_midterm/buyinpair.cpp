/*
LANG: C++
TASK: mid60_buyinpair
*/

#include<iostream>
using namespace std;

main()
{
	long long a,b;
	int n;
	int cnt = 0;
	cin >> n >> a >> b;
	long long price[n];
	for(int i=0;i<n;i++){
		cin >> price[i];
	}
	int sum = 0;
	cout << price.begin() << endl;
	for(int i=0;i<n;i++){
		// for(int j=i+1;j<n;j++){
		// 	if(price[i]+price[j] >= a && price[i]+price[j] <= b){
		// 		cnt++;
		// 	}
		// }
	}
	cout << cnt << endl;
}