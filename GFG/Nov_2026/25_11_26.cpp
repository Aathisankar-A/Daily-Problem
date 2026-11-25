class Solution {
  public:
    using ll = long long;
    const ll MOD = 1e9 + 7;

    ll sum(ll l, ll r){
        if(l > r) return 0;
        return (l + r) * (r - l + 1) / 2;
    }

    ll pref(ll n, ll c){
        if(n <= 0) return 0;

        ll q = n / c;
        ll rem = n % c;

        return c * q * (q + 1) / 2 + rem * (q + 1);
    }

    ll getSum(ll l, ll r, ll a, ll b){
        if(l > r) return 0;

        ll ans = 0;

        if(l <= a){
            ll x = min(r, a);
            ans += sum(l, x) + (x - l + 1);
        }

        l = max(l, a + 1);

        if(l <= r){
            ll c = a - b;

            ans += sum(l, r) + (r - l + 1);

            ans += 2 * b * (pref(r - a, c) - pref(l - 1 - a, c));
        }

        return ans;
    }
    int minTime(int a, int b, int d, int l, int r) {
        // code here
        ll c = a - b;

        ll k = (d - a + c - 1) / c;
        ll T = d + 2LL * b * k;

        ll L = d - r;
        ll R = d - l;

        ll low = 1, high = d - 1;
        ll cut = 0;

        while(low <= high){
            ll mid = low + (high - low) / 2;

            ll g = mid + 1;

            if(mid > a){
                g += 2LL * b * ((mid - a + c - 1) / c);
            }

            if(g < T){
                cut = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        ll x = min(R, cut);
        ll ans = getSum(L, x, a, b);

        ll y = max(L, cut + 1);

        if(y <= R){
            ans += (R - y + 1) * T;
        }

        return ans % MOD;
    }
};
