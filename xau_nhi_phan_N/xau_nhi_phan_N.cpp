#include <iostream>
using namespace std;

#define MAX 100
#define TRUE 1
#define FALSE 0

int n, X[MAX], OK = TRUE, dem = 0;

void Init()
{
    cout << "\n Nhap n=";
    cin >> n;
    for (int i = 0; i < n; i++)
        X[i] = 0;
}
void Result()
{
    cout << "\n Ket qua buoc " << ++dem << ":";
    for (int i = 1; i <= n; i++)
        cout << X[i] << " ";
}

void Next_Bit_String(void)
{
    int i = n; // n =5
    while (i > 0 && X[i] != 0)
    {
        X[i] = 0;
        i--;
    }
    if (i > 0)
    {
        X[i] = 1;
    }
    else
        OK = FALSE;
}

int main()
{
    Init();
    while (OK)
    {
        Result();
        Next_Bit_String();
    }
    system("PAUSE");
    return 0;
}
