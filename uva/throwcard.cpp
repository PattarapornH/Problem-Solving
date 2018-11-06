/*
LANG: C++
TASK: uva10935_throwingcards1
*/
#include<iostream>
#include <cstdio>
#include <queue>
using namespace std;

int n, x;

void find_res()
{
    queue<int> deck;
    for (int i = 1; i <= n; i++)
    {
        deck.push(i);
    }
    cout << "Discarded cards:";
    //  printf("Discarded cards:");
    while (deck.size() > 1)
    {
        cout << " " << deck.front();
        // printf(" %d", deck.front());
        deck.pop();
        x = deck.front();
        deck.pop();
        if (!deck.empty())
        {
            cout << ",";
        }
        // printf(",");
        deck.push(x);
    }
    printf("\nRemaining card: %d\n", deck.front());
    deck.pop();
}

main()
{
    // queue<int> deck;

    while (true)
    {
        cin >> n;
        if(n == 0){
            break;
        }
        // for (int i = 1; i <= n; i++)
        // {
        //     deck.push(i);
        // }
        find_res();
    }
}