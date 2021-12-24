#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
// #include <dos.h>
#define TRUE 1
#define FALSE 0
#define MAX 100
int x[MAX], xopt[MAX];
float fopt, cost, weight;
void Init(float *C, float *A, int *n, float *w)
{
    int i;
    FILE *fp;
    fopt = 0;
    weight = 0;
    fp = fopen("cai_tui.in", "r");
    if (fp == NULL)
    {
        printf("\n Khong co file input");
        // delay(2000);
        return;
    }
    fscanf(fp, "%d %f", n, w);
    for (i = 1; i <= *n; i++)
        xopt[i] = 0;
    printf("\n So luong do vat %d:", *n);
    printf("\n Gioi han tui %8.2f:", *w);
    printf("\n Vecto gia tri:");
    for (i = 1; i <= *n; i++)
    {
        fscanf(fp, "%f", &C[i]);
        printf("%8.2f", C[i]);
    }
    printf("\n Vector trong luong:");
    for (i = 1; i <= *n; i++)
    {
        fscanf(fp, "%f", &A[i]);
        printf("%8.2f", A[i]);
    }
    fclose(fp);
}
void swap(int n)
{
    int i;
    for (i = 1; i <= n; i++)
        xopt[i] = x[i];
}
void Update_Kyluc(int n)
{
    if (cost > fopt)
    {
        swap(n);
        fopt = cost;
    }
}
void Try(float *A, float *C, int n, float w, int i)
{
    int j, t = (w - weight) / A[i];
    for (j = t; j >= 0; j--)
    {
        x[i] = j;
        cost = cost + C[i] * x[i];
        weight = weight + x[i] * A[i];
        if (i == n)
            Update_Kyluc(n);
        else if (cost + C[i + 1] * (w - weight) / A[i + 1] > fopt)
        {
            Try(A, C, n, w, i + 1);
        }
        weight = weight - A[i] * x[i];
        cost = cost - C[i] * x[i];
    }
}
void Result(int n)
{
    int i;
    printf("\n Gia tri do vat %8.2f:", fopt);
    printf("\n Phuong an toi uu:");
    for (i = 1; i <= n; i++)
        printf("%3d", xopt[i]);
}
int main(void)
{
    int n;
    float A[MAX], C[MAX], w;
    // clrscr();
    Init(C, A, &n, &w);
    Try(C, A, n, w, 1);
    Result(n);
    getch();
    // return 0;
}
