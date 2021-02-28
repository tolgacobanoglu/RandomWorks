import java.util.Scanner;

public class Triangle
{
    public static void main(String[] args)
    {
        Scanner input=new Scanner(System.in);


        printer('A');
        int a= input.nextInt();
        printer('B');
        int b= input.nextInt();
        printer('C');
        int c= input.nextInt();

        boolean C1=sideLengthCondition(a);
        boolean C2=sideLengthCondition(b);
        boolean C3=sideLengthCondition(c);
        boolean C4=sidesPrepareCondition(b,c,a);
        boolean C5=sidesPrepareCondition(c,a,b);
        boolean C6=sidesPrepareCondition(a,b,c);

        triangleChecker(C1,C2,C3,C4,C5,C6,a,b,c);

    }

    public static void printer(char element)
    {
        System.out.print(element+" : ");
    }

    public static void triangleChecker(boolean A,boolean B,boolean C,boolean D,boolean E,boolean F,int side1,int side2,int side3)
    {
        if (A&&B&&C)
        {
            if (D&&E&&F)
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
            else
            {
                System.out.println("Not a Triangle");
            }
        }
    }

    public static boolean sideLengthCondition(int side)
    {
        if(side>=1 && side<=50)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public static boolean sidesPrepareCondition(int side1,int side2,int side3)
    {
        if ((side1+side2)>side3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}
