#include<iostream>
#include <vector>
#include <cmath>
#include<stdio.h>
#include <algorithm>

void func1(int array[], int length)
{
    int sum=0;
    int product =1;
    for (int i = 0; i <length; i++)
    {
        sum+=array[i];
    }
 
    for (int i = 0; i < length; i++)
    {
        product*=array[i];
    }
}

// que 5
// ans: big O (n)
// int sum(Node node)
// {
//     if (node == NULL)
//     {
//         return 0;
//     }
//     return sum(node.left) + node.value + sum(node.right);
// }


// que 6
// ans: 
int isPrime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void func(int n)
{
    int sum=0;
    int product =1;
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d , %d\n", i,j);
        }
    }
}

/*Consider the recursive algorithm below, 
where the random(int n) spends one unit of time to return a random integer 
where the probability of each integer coming as 
random is evenly distributed within the range [0,n]. 
If the average processing time is T(n), what is the value of T(6)?*/

// int function(int n)
// {
//     int i = 0;
//     if (n <= 0)
//     {
//         return 0;
//     }
//     else
//     {
//         i = random(n - 1);
//         printf("this\n");
//         return function(i) + function(n - 1 - i);
//     }
// }

using namespace std;
int main()
{
    // int arr[] = {3,4,66};
    // func1(arr,3);

    // vector <int> vec;
    // vec.push_back(1);
    // cout << *vec.begin();

    vector<int> vec;
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(7);
    vec.push_back(9);
    // cout << binary_search(vec.begin(), vec.end(), 1);
    vec.erase(vec.begin()+1, vec.end());
    cout << vec.at(0);
    cout << vec.at(1);
    // cout << vec.size();

    // cout << (int)2.99;
    return 0;
}


// ANS 1: big O of (n)
// ANS 2: big O of (n*n)