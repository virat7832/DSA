class Solution {
public:
    bool isRectangleOverlap(vector<int>& rect1, vector<int>& rect2) {
      // left side
         if(rect1[2]<=rect2[0] || rect2[2]<=rect1[0])
            return false;
// above  side 
        if(rect1[3]<=rect2[1] || rect2[3]<=rect1[1])
            return false;
// neither above nor right
return true;
       
    }
};