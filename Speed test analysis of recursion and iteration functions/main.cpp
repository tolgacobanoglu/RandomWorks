#include <iostream>
#include <chrono>
using namespace std;

int triangleDotIteration(int n)
{
    int nThElement=0;
    for(int i=1;i<=n;i++)
    {
        nThElement+=i;
    }
    return nThElement;
}

int triangleDotRecursion(int n)
{
    if(n==1)
    {
        return 1;
    }

    return n + triangleDotRecursion(n-1);
}

int main() {

    int n,m;

    auto start1 = std::chrono::high_resolution_clock::now();
    printf("Enter your n value to calculate how many dot you need with Iteration method :");
    scanf("%d",&n);
    printf("TNS(%d) = %d\n",n,triangleDotIteration(n));
    auto finish1 = std::chrono::high_resolution_clock::now();
    cout << "The Iteration function took " << std::chrono::duration_cast<std::chrono::milliseconds>(finish1 - start1).count() << " milliseconds" << endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    printf("\nEnter your m value to calculate how many dot you need with Recursion method :");
    scanf("%d",&m);
    printf("TNS(%d) = %d\n",m,triangleDotRecursion(m));
    auto finish2 = std::chrono::high_resolution_clock::now();
    cout << "The Recursion function took " << std::chrono::duration_cast<std::chrono::milliseconds>(finish2 -start2).count() << " milliseconds" << endl;

    return 0;
}
