class Solution {
public:
    int segmentCost(string& s, int l, int m, vector<vector<int>>& factors){
        int best = m;

        for(int d : factors[m]){
            int groups = m / d;
            int changes = 0;

            for(int offset = 0; offset < d; offset++){
                for(int t = 0; t < groups / 2; t++){
                    if(s[l + offset + t * d] != s[l + offset + (groups - 1 - t) * d]){
                        changes++;
                    }
                }
            }

            best = min(best, changes);
        }

        return best;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> factors(n + 1);

        for(int d = 1; d <= n / 2; d++){
            for(int m = 2 * d; m <= n; m += d){
                factors[m].push_back(d);
            }
        }

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for(int l = 0; l < n; l++){
            for(int r = l + 1; r < n; r++){
                cost[l][r] = segmentCost(s, l, r - l + 1, factors);
            }
        }

        vector<int> prev(n);

        for(int start = 0; start < n; start++){
            prev[start] = cost[start][n - 1];
        }

        for(int seg = 2; seg <= k; seg++){
            vector<int> cur(n, n);

            int limit = n - 1 - 2 * (seg - 1);

            for(int start = 0; start + 2 * seg <= n; start++){
                for(int e = start + 1; e <= limit; e++){
                    cur[start] = min(cur[start],
                        cost[start][e] + prev[e + 1]);
                }
            }

            prev.swap(cur);
        }

        return prev[0];
    }
};
