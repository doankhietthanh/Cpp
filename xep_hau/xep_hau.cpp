#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 100
#define TRUE 1
#define FALSE 0

int X[100], XUOI[MAX], NGUOC[MAX], chuaxet[MAX];
int n, dem = 0;

void Init()
{

    cout << "\n Nhap n=";
    cin >> n;
    for (int i = 1; i <= n; i++)
        chuaxet[i] = TRUE;
    for (int i = 1; i <= 2 * n + 1; i++)

    {
        XUOI[i] = TRUE;
        NGUOC[i] = TRUE;
    }
}

void Result(void)
{
    cout << "\n Phuonn an " << ++dem << ": ";
    for (int i = 1; i <= n; i++)
    {
        cout << X[i] << " ";
    }
}

void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (chuaxet[j] && XUOI[i - j + n] && NGUOC[i + j - 1])
        {
            X[i] = j;
            chuaxet[j] = FALSE;
            XUOI[i - j + n] = FALSE;
            NGUOC[i + j - 1] = FALSE;
            if (i == n)
                Result();
            else
                Try(i + 1);

            chuaxet[j] = TRUE;
            XUOI[i - j + n] = TRUE;
            NGUOC[i + j - 1] = TRUE;
        }
    }
}
int main()
{
    Init();
    Try(1);
    system("PAUSE");
    return 0;
}