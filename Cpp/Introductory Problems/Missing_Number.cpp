#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,N,xum = 0;
    scanf("%d",&N);
    for (int i = 1; i <= N;i++)
        xum ^= i;
    for (int i =1; i <= N-1; i++)
        {
            scanf("%d",&x);
            xum ^= x;
        }
    printf("%d\n", xum);
}