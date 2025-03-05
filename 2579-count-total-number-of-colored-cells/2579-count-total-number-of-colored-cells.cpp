class Solution 
{
public:
    long coloredCells(int n) 
    {
        long cells = 0;

        for (int i = 1; i <= n; i++) 
        {    
           
            if (i == 1) 
            {
                cells = 1; 
            } 
            else 
            {
           
                cells += (4 * (i - 1)); 
            }
        }

        return cells;
    }
};