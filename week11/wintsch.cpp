/*
TASK: wintsch
*/

#include <iostream>
#include <vector>
using namespace std;

int n;
int s[1010]; //start
int t[1010]; //end time
int w[1010]; //weight
int max_weight = -1;
int index;
int weight[1010];
vector<int> num_work[1010];
void init()
{
    // weight[0] = w[0];
    // num_work[0].push_back(1);
    for (int i = 0; i < n; i++)
    {
        weight[i] = w[i];
        num_work[i].push_back(i+1);
    }
}

void find_weight()
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (weight[j] + w[i] > weight[i] &&  t[j] <= s[i])
            {
                weight[i] = weight[j] + w[i];
                num_work[i] = num_work[j];
                num_work[i].push_back(i+1);
                // cout << i+1 << endl;
                // cout << weight[i] << endl;
            }
            if (weight[i] > max_weight)
            {
                max_weight = weight[i];
                index = i;
            }
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> t[i] >> w[i];
    }
    // cout << "---------\n";
    init();
    find_weight();
    cout << max_weight << "\n";
    cout << num_work[index].size() << "\n";
    vector<int>::iterator it;
    for (it = num_work[index].begin(); it != num_work[index].end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
}