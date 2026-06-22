class Solution {
  public:
    int maxArea(vector<int> &height) {
        // code here
        int n = height.size();
        
        int i = 0;
        int j = n-1;
        
        int mx = 0;
        int area = 0;
        
        while(i < j){
            area = min(height[i], height[j]) * (j-i-1);
            mx = max(area, mx);
            
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return mx;
    }
};
