public class PalindromeNumber
{
    public void product()
    {
        int result,largestPalindrome=0;
        for (int num1 = 999; num1 >= 100 ; num1-=1)
        {
            for (int num2 = 999; num2 >= 100; num2-=1)
            {
                result=num1*num2;
                if (fun(result))
                {
                    if (result>largestPalindrome)
                    {
                        largestPalindrome=result;
                    }
                }
            }
        }
        System.out.println(largestPalindrome);
    }

    public boolean fun(int number)
    {
        int digit1,digit2,digit3,digit4,digit5,digit6;

        digit1=number%10;
        digit2=(number%100)/10;
        digit3=(number%1000)/100;
        digit4=(number%10000)/1000;
        digit5=(number%100000)/10000;
        digit6=(number%1000000)/100000;

        if (digit1 == digit6)
        {
            if (digit2 == digit5)
            {
                if (digit3 == digit4)
                {
                    return true;
                }
            }
        }

        return false;
    }
}
