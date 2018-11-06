#include<iostream>
using namespace std;

main()
{
	int n,m;
	int num,score;
	cin >> n >> m;
	int sub[n+1];
	int max[n+1];
	for(int i=1; i<n+1; i++){
		max[i] = 0;
		sub[i] = 0;
	}
	for(int i=0; i<m;i++){
		cin >> num >> score;
		if(score>max[num]){
			max[num] = score;
		}
		sub[num]++;
	}
	int sum = 0;
	for(int i=1; i<n+1; i++){
		if(sub[i]<=5){
			sum+=max[i];
		}
	}
	cout << sum << endl;
}