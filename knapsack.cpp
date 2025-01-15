#include <iostream>
#include <vector>
#include <algorithm>

void knapsack(int n, std::vector<float> &weight, std::vector<float> &profit, float capacity)
{
    std::vector<float> x(n, 0.0);
    float tp = 0;
    int i;
    float u = capacity;

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            tp += profit[i];
            u -= weight[i];
        }
    }

if (i < n)
        x[i] = u / weight[i];

    tp += (x[i] * profit[i]);

    std::cout << "\nThe result vector is:- ";
    for (i = 0; i < n; i++)
        std::cout << x[i] << "\t";

    std::cout << "\nMaximum profit is:- " << tp;
}
