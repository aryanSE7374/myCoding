import java.util.Scanner;



//leetcode problem


class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int res[] = new int[n];
        int l=0,r=n-1;
        while ((l<n)&&(nums[l]<0)){
            l++;
        }
        while ((r>=0)&&(nums[r]>0)){
            r--;
        }
        int zeroes = r-l+1;//num of zeroes
        int i = 0;
        for ( ; i < (r-l+1); i++) {
            res[i]=0;
        }
        l--;r++;
        while((l>=0)&&(r<n)){
            
            if (Math.pow(nums[l], 2)>(Math.pow(nums[r], 2))) {
                res[i]=(int)Math.pow(nums[r], 2);
                i++;
                r++;
            }
            else
            {
                res[i] = (int)Math.pow(nums[l], 2);
                i++;
                l--;
            }
            // l--;r++;
        }
        while (l>=0){
            res[i]=(int)Math.pow(nums[l],2);
            l--;i++;
        }
        while (r<n){
            res[i]=(int)Math.pow(nums[r], 2);
            r++;i++;
        }
        return res;
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            String str = scanner.next();
            if (str.length() <= 10) {
                System.out.println(str);
            } else {
                System.out.println(str.charAt(0) + Integer.toString(str.length() - 2) + str.charAt(str.length() - 1));
            }
        }
    }
}
