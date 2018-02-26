#include <iostream>

using namespace std;

const int N = 1000;
double a[N]; //store the given sequence
double opt[N];//opt[i] means the LIS length from a0 to ai
int path[N];//for LIS backtracking
int max_a,max_b;//max_a is the length of LIS,max_b is the index of the last element of LIS in a[]

void LongestIncreasingSub(int n)
{
    int i, j;
    for(i = 0; i < n; i++)
        opt[i] = 1;
    //opt[i] = max{opt[i],opt[j] + 1}
    for(i = 1;i < n;i++)
    {
       for(j = 0;j < i;j++)
        {
            if(a[i] > a[j] && opt[j] + 1 > opt[i])
            {
              opt[i] = opt[j] + 1;
              //the last step tp i is j
              path[i] = j;
            }
        }
     }
    for(i = 0;i < n;i++)
    {
        if(max_a < opt[i]){
            max_a = opt[i];
            max_b = i;
        }
    }
}

int main()
{
    int n;
    cin>>n;//the length of input sequence
    int i,j;
    for(i = 0; i < n; i++)
            cin>>a[i];
    LongestIncreasingSub(n);
    cout<<"the maximum length of the longest increasing subsequence is:";
    cout<<max_a<<endl;
    cout<<"the longest increasing subsequence is:";

    //LIS backtracking
    for(j = 0,i = max_b;i >= 0;){
        opt[max_a - 1 - j] = a[i];
        i = path[i];
        j++;
        if(j == max_a) break;
    }
    for(i = 0;i < max_a;i++)
        cout<<opt[i]<<' ';

    cout<<endl;
    return 0;
}
