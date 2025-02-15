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
int main()
{
    std::vector<float> weight(20), profit(20);
    float capacity;
    int num;

    std::cout << "\nEnter the no. of objects:- ";
    std::cin >> num;

    std::cout << "\nEnter the wts and profits of each object:- ";

for (int i = 0; i < num; i++)
    {
        std::cin >> weight[i] >> profit[i];
    }

    std::cout << "\nEnter the capacity of knapsack:- ";
    std::cin >> capacity;

    std::vector<float> ratio(num);
    for (int i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }



for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                std::swap(ratio[j], ratio[i]);
                std::swap(weight[j], weight[i]);
                std::swap(profit[j], profit[i]);
            }
        }
    }

    knapsack(num, weight, profit, capacity);
    return 0;
}
