class Solution {
  public:
  int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    int solve(int from, int to, int d){
        int fromJug = 0, toJug = 0;
        int steps = 0;

        while(fromJug != d && toJug != d){
            if(fromJug == 0){
                fromJug = from;
                steps++;
            }
            else if(toJug == to){
                toJug = 0;
                steps++;
            }
            else{
                int pour = min(fromJug, to - toJug);
                toJug += pour;
                fromJug -= pour;
                steps++;
            }
        }

        return steps;
    }
    
    int minSteps(int m, int n, int d) {
        // Code here
        if(d > max(m, n)) return -1;

        if(d % gcd(m, n) != 0) return -1;

        return min(solve(m, n, d), solve(n, m, d));
    }
};
