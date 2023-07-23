class Solution {
public:
typedef long long ll;
    bool check(int mid, vector<int> &vec)
{
    vector<ll> v;
        for(auto t: vec)
            v.push_back(1LL*t);
    ll n = v.size();
    for (ll i = n - 1; i > 0; i--)
    {
        if (v[i] > mid)
        {
            ll val = v[i] - mid;
            v[i] = mid;
            v[i - 1] += val;
        }
    }
    for (auto t : v)
    {
        if (t > mid)
            return false;
    }
    return true;
}
// void inforkc()
// {
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//         cin >> v[i];
//     int l = 0, r = 1e18, ans = 0;
//     while (l <= r)
//     {
//         int mid = (l + r) / 2;
//         if (check(mid, v))
//         {
//             ans = mid;
//             r = mid - 1;
//         }
//         else
//             l = mid + 1;
//     }
//     cout << ans;
// }
    int minimizeArrayValue(vector<int>& v) {

        ll l = 0, r = 1e9, ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid, v))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
    }
};