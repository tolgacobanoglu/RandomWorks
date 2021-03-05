import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner input=new Scanner(System.in);

        int[] alicePoints=new int[3];
        alicePoints[0]=input.nextInt();
        alicePoints[1]=input.nextInt();
        alicePoints[2]=input.nextInt();
        int[] bobPoints=new int[3];
        bobPoints[0]=input.nextInt();
        bobPoints[1]=input.nextInt();
        bobPoints[2]=input.nextInt();

        arrayPrinter(pointsComparator(alicePoints,bobPoints));

    }

    public static int[] pointsComparator(int[] alicePoints,int[] bobPoints)
    {
        int aliceTotalPoints=0;
        int bobTotalPoints=0;

        for (int i = 0; i < 3; i++)
        {
            if (alicePoints[i]>bobPoints[i])
            {
                aliceTotalPoints+=1;
            }
            else if (bobPoints[i]>alicePoints[i])
            {
                bobTotalPoints+=1;
            }
        }

        return new int[]{aliceTotalPoints,bobTotalPoints};
    }

    public static void arrayPrinter(int[] arr)
    {
        for (int element : arr) {
            System.out.print(element+" ");
        }
    }


}
