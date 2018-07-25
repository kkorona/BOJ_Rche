#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i*i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    vector<int> v;
    int a,b;
    cin >> a >> b;
    // 모든 5이상인 1~8자리수 palindrome을 구한다.
    v.push_back(5);
    v.push_back(7);
    for (int i = 1; i < 10; ++i)
    {
        v.push_back(i*10 + i);
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 1; j < 10; ++j)
        {
            v.push_back(j*100 + i*10 + j);
            v.push_back(j*1000 + i*100 + i*10 + j);
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 1; k < 10; ++k)
            {
                v.push_back(k*10000 + j*1000 + i*100 + j*10 + k);
                v.push_back(k*100000 + j*10000 + i*1000 + i*100 + j*10 + k);
            }
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                for (int l = 1; l < 10; ++l)
                {
                    v.push_back(l*1000000 + k*100000 + j*10000 + i*1000 + j*100 + k*10 + l);
                    v.push_back(l*10000000 + k*1000000 + j*100000 + i*10000 + i*1000 + j*100 + k*10 + l);
                }
            }
        }
    }
    sort(v.begin(), v.end());
    for (vector<int>::size_type i = 0; i < v.size(); ++i)
    {
        if (v[i] >= a && v[i] <= b && isPrime(v[i]))
        {
            cout << v[i] << endl;
        }
    }
    cout << -1 << endl;
    return 0;
}
