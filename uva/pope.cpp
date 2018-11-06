/*
TASK: uva957_popes
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> elec;
int y,p;
int elec_year;
int first;
int last;
int max_pope;

void find_max()
{

    // int max_pope = -1;
    for (int i = p - 1; elec[i] >= y; i--)
    {
        //v[i] is last
        vector<int>::iterator low = lower_bound(elec.begin(),elec.end(),elec[i]-y+1);
        // cout << low-elec.begin() << " ";
        if (i - (low - elec.begin()) + 1 >= max_pope)
        {
            max_pope = i - (low - elec.begin()) + 1;
            first = elec[low-elec.begin()];
            last = elec[i];
        }
    }
    // return max_pope;
}

main()
{
    while(cin >> y){
        // cin >> y;
        cin >> p;
        elec.clear();
        // max_pope = -1;
        for(int i=0; i<p; i++){
            cin >> elec_year;
            elec.push_back(elec_year);
        }
        // vector<int>::iterator it = lower_bound(elec.begin(),elec.end(),2);
        // cout << it - elec.begin() ;
        find_max();
        cout << max_pope << " " << first << " " << last << "\n";
        // cout << find_max() << " " << first << " " << last << "\n";
    }
}