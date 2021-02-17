import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
	    Text text=new Text();
        Scanner input=new Scanner(System.in);

        System.out.println("Enter your statement for processing");
        String statement= input.nextLine();

        System.out.println("How many has been shifted ?");
        byte shiftNo=input.nextByte();

        System.out.println("Do u want 1-) Encrypt & 2-) Decrypt");
        byte choice= input.nextByte();


        if(choice==1)
        {
            text.encrypt(statement,shiftNo);
        }
        else
        {
            text.decrypt(statement,shiftNo);
        }

    }
}
