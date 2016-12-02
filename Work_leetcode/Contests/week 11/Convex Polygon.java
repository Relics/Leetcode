public class Solution {
    public boolean isConvex(List<List<Integer>> points) {
        if(points == null || points.size() <= 2) return true;
		points.add(points.get(0));
		points.add(points.get(1));
		
		boolean isNeg = false;
		for(int i = 2; i < points.size(); i++){
			int dx1 = points.get(i - 1).get(0) - points.get(i - 2).get(1);
			int dy1 = points.get(i - 1).get(1) - points.get(i - 2).get(1);
			int dx2 = points.get(i).get(0) - points.get(i - 1).get(0);
			int dy2 = points.get(i).get(1) - points.get(i - 1).get(1);
			
			long vector = dy2*dx1 - dy1*dx2;
			if(i == 2) isNeg = (vector < 0);
			else if(!(vector < 0 && isNeg || vector > 0 && !isNeg)) return false;
		}
		return true;
    }
}