/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    public void buildGraph(Node node, Node parent, HashMap<Integer, ArrayList<Integer>> mp){
        if(node == null) return;
        
        mp.putIfAbsent(node.data, new ArrayList<>());
        
        if(parent != null){
            mp.putIfAbsent(parent.data, new ArrayList<>());
            
            mp.get(node.data).add(parent.data);
            mp.get(parent.data).add(node.data);
        }
    
        buildGraph(node.left, node, mp);
        buildGraph(node.right, node, mp);
    }
    
    public int minTime(Node root, int target) {
        // code here
        HashMap<Integer, ArrayList<Integer>> graph = new HashMap<>();
        
        buildGraph(root, null, graph);
        
        Queue<Integer> q = new ArrayDeque<>();
        q.add(target);
        
        Set<Integer> vis = new HashSet<>();
        vis.add(target);
        
        int time = 0;
        
        while(!q.isEmpty()){
            int size = q.size();
            int flag = 0;
            
            for(int i = 0; i < size; i++){
                int front = q.poll();
                for(int next : graph.get(front)){
                    if(!vis.contains(next)){
                        flag = 1;
                        vis.add(next);
                        q.add(next);
                    }
                }
            }
            if(flag == 1)
                time++;
        }
        return time;
    }
}
