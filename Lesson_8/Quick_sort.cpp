#include <iostream>


void quick_sort(int *a, int start, int finish) {

    if (start < finish - 1)
    {
        int c;
        int opornik = a[(start + finish - 1) / 2];
        int i = start, j = finish -1;
        while (i <= j)
        {
            while (a[i] < opornik)
                i++;
            while (a[j] >= opornik)
                j--;
            if (i >= j)
                break;
            c = a[i];
            a[i] = a[j];
            a[j] = c;
        }
        if (j > start)
        {
            quick_sort(a, start, j);
            quick_sort(a, j + 1, finish - 1);
        }
    }
}


int main()
{
    int n, c, j;
    //cin >> n;
    int a[19] = {5, 4, 4, 56, 6, 7, 5, 16, 3, 4, 0, 3, 10, 43, 234, 72, 3, 0, -3};
    quick_sort(a, 0, 19);
    for (int i=0; i < 19; i++)
        std::cout << a[i] << ' ';
}

