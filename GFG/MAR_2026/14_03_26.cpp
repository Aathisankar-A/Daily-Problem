/*
class Node {
    int data;
    Node left, right;

    Node(int val) {
        this.data = val;
        this.left = null;
        this.right = null;
    }
}
*/
class Solution {
    int min_col = 0;
    int max_col = 0;
    
    public void preorder(Node root, int row, int col, HashMap<Integer, int[]> mp){
        if(root != null){
            if(!mp.containsKey(col) || row < mp.get(col)[1]){
                mp.put(col, new int[]{root.data, row});
            }
            
            if(col < min_col)
                min_col = col;
            
            if(col > max_col)
                max_col = col;
                
            preorder(root.left, row+1, col-1, mp);
            preorder(root.right, row+1, col+1, mp);
        }
    }
    
    public ArrayList<Integer> topView(Node root) {
        // code here
        HashMap<Integer, int[]> mp = new HashMap<>();
        
        preorder(root, 0, 0, mp);
        
        ArrayList<Integer> res = new ArrayList<>();
        
        for(int i = min_col; i <= max_col; i++){
            res.add(mp.get(i)[0]);
        }
        return res;
    }
}
