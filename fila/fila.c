#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);

    int invisibles = 0;
    int heights[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &heights[i]);
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (i == N - 1)
        {
            continue;
        }

        for (int j = 0; j < N - i - 1; j++)
        {
            if (heights[i + j + 1] >= heights[i])
            {
                invisibles++;
                break;
            }
        }
    }

    printf("%d\n", invisibles);

    return 0;
}