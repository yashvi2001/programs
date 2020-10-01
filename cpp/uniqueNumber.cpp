#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements";
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x.at(i);
    }
    cout << "\nUnique number is " << accumulate(x.begin(), x.end(), 0L, bit_xor<int>()) << endl;
    return 0;
}
