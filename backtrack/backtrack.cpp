#include <iostream>
#include <stdlib.h>

using namespace std;

#define MAX 100
#define TRUE 1
#define FALSE 0
int n, X[MAX], chuaxet[MAX], dem = 0;
void Init(void)
{
    cout << "\n Nhap n =";
    cin >> n;
    for (int i = 1; i <= n; i++)
        chuaxet[i] = TRUE;
}
void Result(void)
{
    cout << "\n Ket qua buoc" << ++dem << ":";
    for (int i = 1; i <= n; i++)
        cout << X[i] << " ";
}
void Try(int i)
{
    for (int j = 1; j <= n; j++)
    {
        if (chuaxet[j])
        {
            X[i] = j;
            chuaxet[j] = FALSE;
            if (i == n)
                Result();
            else
                Try(i + 1);
            chuaxet[j] = TRUE;
        }
    }
}

int main()
{
    Init(); //Nhap n = 3
    Try(1);
    system("PAUSE");
    return 0;
}
