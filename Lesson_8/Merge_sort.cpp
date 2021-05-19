#include <iostream>
#include <random>


void merge_sort(int *a, int start, int finish)
{

    if (finish - start > 1)
    {
        merge_sort(a, start, (finish + start) / 2);
        merge_sort(a, (finish + start) / 2 + 1, finish);

        int* c = new int [(finish + start) / 2 + 1 - start];
        int* d = new int [finish + 1 - (finish + start) / 2-1];

        for (int k = start; k <= (finish + start) / 2; k++)
            c[k - start] = a[k];
        for (int k = (finish + start) / 2 + 1; k <= finish; k++)
            d[k - (finish + start) / 2 - 1] = a[k];

        int i = 0, j = 0, k = start;

        while (i <= (finish + start) / 2 - start && j <= finish - (finish + start) / 2 - 1)
        {
            if (c[i] < d[j])
            {
                a[k] = c[i];
                i++;
                k++;
            }
            else
            {
                a[k] = d[j];
                j++;
                k++;
            }
        }
        if (i > (finish + start) / 2 - start)
            for (int t = 0; t + k <= finish; t++)
                a[t + k] = d[j + t];
        else
            for (int t = 0; t + k <= finish; t++)
                a[t + k] = c[i + t];

        delete [] c;
        delete [] d;
    }
    else if (finish - start == 1)
    {
        int c;
        if(a[start] > a[finish])
        {
            c = a[start];
            a[start] = a[finish];
            a[finish] = c;
        }
    }
}

const int finish = 30;


int main()
{
    int c, j;
    int a[finish];

    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned int> distribution(10, 2*finish);
    unsigned int dice_roll;
    dice_roll = distribution(generator);

    for (int N = 0; N <= finish; N++) {
        for (long int i = 0; i < N; i++)
            a[i] = distribution(generator);
    }

    std::cout << "Create massive: " << std::endl;

    for (int i = 0; i < finish; i++)
            std::cout << a[i] << ' ';

    merge_sort(a, 0, finish);
    std::cout << std::endl;
    std::cout << "Result after merge sort: " << std::endl;

    for (int i = 0; i < finish; i++)
            std::cout << a[i] << ' ';
    std::cout << std::endl;

    std::cout << "“о, что тут написано, в консоли не прочесть" <<std::endl;

    return 0;
}

