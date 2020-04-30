class Solution {
    public int lastStoneWeight(int[] stones) 
    {
    int n=stones.length;
    PriorityQueue <Integer> pq = new PriorityQueue<Integer>(n,new MyComparator());
    for(int i=0;i<n;i++){
        pq.offer(stones[i]);
    }
        while(pq.size() != 1){
            int a = pq.peek();
            pq.poll();
             int b = pq.peek();
            pq.poll();
            pq.offer(a-b);
        }
        return pq.peek();
    }
}
class MyComparator implements Comparator{
    public int compare(Object obj1,Object obj2){
        Integer a = (Integer)obj1;
        Integer b = (Integer)obj2;
        if(a> b){
            return -1;
        }
        else {
            return 1;
        }
    }
}
