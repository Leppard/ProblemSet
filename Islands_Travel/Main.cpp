//
//  main.cpp
//  Islands_Travel
//
//  Created by Leppard on 4/6/15.
//  Copyright (c) 2015 Leppard. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int compute(int a, int b)
{
    int result = a - b;
    if (result < 0)
    {
        result = result*(-1);
    }
    
    return result;
}

int compare(int a_1, int a_2, int b_1, int b_2)
{
    
    int result_1 = compute(a_1, b_1);
    int result_2 = compute(a_2, b_2);
    if (result_1>result_2)
    {
        return result_2;
    }
    else{
        return result_1;
    }
}

int findMin(vector<int> a)
{
    int result = a[0];
    for (int i = 1; a[i] != '\0'; i++)
    {
        if (result > a[i])
        {
            result = a[i];
        }
    }
    return result;
}

int main(void)
{
    int t;
    cin >> t;
    int islands[1000][2] = {0};
    vector<vector<int>> container(1000);
    int value[1000] = {0};
    
    for (int i = 0; i < t; i++)
    {
        cin >> islands[i][0] >> islands[i][1];
    }
    
    
    for (int i = 1; i <= t; i++)
    {
        for (int k = 0; k<i; k++)
        {
            container[i][k] = compare(islands[k][0], islands[k][1], islands[i][0], islands[i][1])+value[k];
        }
        value[i] = findMin(container[i]);
    }
    cout << value[t-1] << endl;
    return 0;
    
}
