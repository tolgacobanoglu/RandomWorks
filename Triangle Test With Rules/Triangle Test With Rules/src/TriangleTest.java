public class TriangleTest
{
    public void testCounter(int number)
    {
        System.out.print(number+". Test : ");
    }

    public void errorMessage()
    {
        System.out.println("error");
    }

    public void sidesLengthTest(int a,int b,int c)
    {
        boolean C1=Triangle.sideLengthCondition(a);
        boolean C2=Triangle.sideLengthCondition(b);
        boolean C3=Triangle.sideLengthCondition(c);
        if (!(C1 & C2 & C3))
        {
            errorMessage();
        }
    }

    public void sidesLengthTest(int a,int b)
    {
        errorMessage();
    }

    public void sidesLengthTest(int a,int b,int c,int d)
    {
        errorMessage();
    }

    public void sidesEqualitionTest(int a,int b,int c)
    {
            if((a+b)==c||(a+c)==b||(b+c)==a)
            {
                errorMessage();
            }
    }

    public void sidesUnknownValueEntered(String test,int b,int c)
    {
        errorMessage();
    }

    public void sidesUnknownValueEntered(char letter,int b,int c)
    {
        errorMessage();
    }

    public void sidesUnknownValueEntered(char letter1,char letter2,char letter3)
    {
        errorMessage();
    }

    public void triangleConditions(int side1,int side2,int side3)
    {
        if(side1==side2&&side1==side3)
        {
            System.out.println("Equilateral");
        }
        else if ((side1==side2&&side1!=side3)||(side1==side3&&side1!=side2))
        {
            System.out.println("Isosceles");
        }
        else
        {
            System.out.println("Scalene");
        }
    }
}
