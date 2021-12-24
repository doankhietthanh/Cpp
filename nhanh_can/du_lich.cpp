#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#define MAX 20
int n,
    P[MAX], B[MAX], C[20][20], count = 0;
int A[MAX], XOPT[MAX];
int can, cmin, fopt;
void Read_Data(void)
{
    int i, j;
    FILE *fp;
    fp = fopen("du_lich.in", "r");
    if (fp == NULL)
    {
        printf("\n Khong co file input");
        // delay(2000);
        return;
    }
    fscanf(fp, "%d", &n);
    printf("\n So thanh pho: %d", n);
    printf("\n Ma tran chi phi:");
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
        {
            fscanf(fp, "%d", &C[i][j]);
            printf("%5d", C[i][j]);
        }
    }
}
int Min_Matrix(void)
{
    int min = 1000, i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i != j && min > C[i][j])
                min = C[i][j];
        }
    }
    return (min);
}
void Init(void)
{
    int i;
    cmin = Min_Matrix();
    fopt = 32000;
    can = 0;
    A[1] = 1;
    for (i = 1; i <= n; i++)
        B[i] = 1;
}
void Result(void)
{
    int i;
    printf("\n Hanh trinh toi uu %d:", fopt);
    printf("\n Hanh trinh:");
    for (i = 1; i <= n; i++)
        printf("%3d->", XOPT[i]);
    printf("%d", 1);
}
void Swap(void)
{
    int i;
    for (i = 1; i <= n; i++)
        XOPT[i] = A[i];
}
void Update_Kyluc(void)
{
    int sum;
    sum = can + C[A[n]][A[1]];
    if (sum < fopt)
    {
        Swap();
        fopt = sum;
    }
}
void Try(int i)
{
    int j;
    for (j = 2; j <= n; j++)
    {
        if (B[j])
        {
            A[i] = j;
            B[j] = 0;
            can = can + C[A[i - 1]][A[i]];
            if (i == n)
                Update_Kyluc();
            else if (can + (n - i + 1) * cmin < fopt)
            {
                count++;
                Try(i + 1);
            }
            B[j] = 1;
            can = can - C[A[i - 1]][A[i]];
        }
    }
}
int main(void)
{
    // clrscr();
    Read_Data();
    Init();
    Try(2);
    Result();
    getch();
    return 0;
}