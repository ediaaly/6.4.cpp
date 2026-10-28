#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// Створення масиву
void Create(double a[], const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = (Low * 10 + rand() % ((High - Low) * 10 + 1)) / 10.0;
}

// Виведення масиву
void Print(double a[], const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(7) << a[i];

    cout << endl;
}

// Сума елементів з непарними номерами
double Sum1(double a[], const int n)
{
    double s = 0;

    for (int i = 0; i < n; i += 2)
        s += a[i];

    return s;
}

// Сума між першим і останнім від'ємними елементами
double Sum2(double a[], const int n)
{
    int first = -1;
    int last = -1;
    double s = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            if (first == -1)
                first = i;

            last = i;
        }
    }

    if (first != -1 && first < last)
    {
        for (int i = first + 1; i < last; i++)
            s += a[i];
    }

    return s;
}

// Стиснення масиву
void Compress(double a[], const int n)
{
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < -1 || a[i] > 1)
        {
            a[k] = a[i];
            k++;
        }
    }

    for (int i = k; i < n; i++)
        a[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL));

    int n;

    cout << "n = ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid n" << endl;
        return 1;
    }

    double* a = new double[n];

    int Low = -20;
    int High = 37;

    Create(a, n, Low, High);

    cout << "Original array:" << endl;
    Print(a, n);

    cout << "Sum1 = " << Sum1(a, n) << endl;
    cout << "Sum2 = " << Sum2(a, n) << endl;

    Compress(a, n);

    cout << "Modified array:" << endl;
    Print(a, n);

    delete[] a;

    return 0;
}