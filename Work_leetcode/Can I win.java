public class Solution {
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        List<Integer> candidates = new ArrayList<Integer>();
        for (int i = 1; i <= maxChoosableInteger; i++){
            candidates.add(i);
        }
        return helper(candidates, desiredTotal);
    }

    public boolean helper(List<Integer> candidates, int target){
        if (candidates.size() > 0 && candidates.get(candidates.size()-1) >= target){
            return true;
        }
        for (int i = 0; i < candidates.size(); i++){
            int removed = candidates.remove(i);
            if (!helper(candidates, target-removed)){
                candidates.add(i, removed);
                return true;
            }
            candidates.add(i, removed);
        }
        return false;
    }
}