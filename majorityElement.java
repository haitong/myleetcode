/*
Given an array of size n, find the majority element. The majority element is the element that appears more than . n/2 . times.

You may assume that the array is non-empty and the majority element always exist in the array.
 * */
public class Solution {
    public int majorityElement(int[] num) {
        HashMap<Integer,Integer> h = new HashMap<Integer,Integer>();
        for (int i : num){
            if(h.containsKey(i)){
                h.put(i,h.get(i)+1);
            }
            else h.put(i,1);
        }
        int res=0, appear=0;
        for(Map.Entry<Integer,Integer> entry : h.entrySet()){
            int key = entry.getKey();
            int val = entry.getValue();
            if(appear < val){
                appear = val;
                res = key;
            }
        }
        return res;
    }
}
