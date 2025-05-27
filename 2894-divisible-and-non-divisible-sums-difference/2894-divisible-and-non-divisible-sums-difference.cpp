class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total_Sum = ((n+1)*n)/2;

        int divisibleSum = 0;
        int i = 1;
        while(i*m <= n){
            divisibleSum += (i*m);
            i++;
        }

        int non_divisible_Sum = total_Sum - divisibleSum; 
        return non_divisible_Sum - divisibleSum;
    }
};