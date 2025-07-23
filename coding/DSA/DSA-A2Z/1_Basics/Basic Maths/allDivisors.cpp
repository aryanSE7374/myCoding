class Solution {
  public:
/*
Given a positive integer n, The task is to find the value of Σi F(i) 
where i is from 1 to n and function F(i) is defined as the sum of all divisors of i.
*/

    int F(int n){ //function F(n) is defined as the sum of all divisors of n
        int sum=0;
        for (int i = 1; i*i <= n; i++)
        {
            if (n%i==0)
            {
                sum+=i;
                if (n/i!=i){sum+=(n/i);}
            }
        }
        return sum;
    }

    int sumOfDivisors(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum+=F(i);
        }
        return sum;
    }
};


