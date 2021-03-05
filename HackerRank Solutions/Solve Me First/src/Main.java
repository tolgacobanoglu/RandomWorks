import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner input=new Scanner(System.in);

        int a= input.nextInt();
        int b= input.nextInt();

        int sum = solveMeFirst(a,b);

        System.out.println(sum);
    }

    public static int solveMeFirst(int a,int b)
    {
        return a+b;
    }
}
