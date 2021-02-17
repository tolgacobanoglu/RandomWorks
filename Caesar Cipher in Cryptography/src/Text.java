public class Text
{
    static char newChar;

    public void encrypt(String text, int shift)
    {

        shift = shift%26;

        for (int i = 0 ; i < text.length() ; i++)
        {
            if ((int)text.charAt(i)>=65 && (int)text.charAt(i)<=90)
            {
                if ((int)text.charAt(i)+shift>90)
                {
                    newChar=(char)((int)text.charAt(i)+shift-26);
                }
                else
                {
                    newChar=(char)((int)text.charAt(i)+shift);
                }
                System.out.print(newChar);
            }
            else if ((int)text.charAt(i)>=97 && (int)text.charAt(i)<=122)
            {
                if ((int)text.charAt(i)+shift>122)
                {
                    newChar=(char)((int)text.charAt(i)+shift-26);
                }
                else
                {
                    newChar=(char)((int)text.charAt(i)+shift);
                }
                System.out.print(newChar);
            }
            else
            {
                newChar=text.charAt(i);
                System.out.print(newChar);
            }
        }
    }

    public void decrypt(String text,int shift)
    {
        shift = shift%25;

        for (int i = 0 ; i < text.length() ; i++)
        {
            if ((int)text.charAt(i)>=65 && (int)text.charAt(i)<=90)
            {
                if((int)text.charAt(i)-shift<65)
                {
                    newChar=(char)((int)text.charAt(i)-shift+26);
                }
                else
                {
                    newChar=(char)((int)text.charAt(i)-shift);
                }
                System.out.print(newChar);
            }
            else if ((int)text.charAt(i)>=97 && (int)text.charAt(i)<=122)
            {
                if ((int)text.charAt(i)+shift>122)
                {
                    newChar=(char)((int)text.charAt(i)-shift+26);
                }
                else
                {
                    newChar=(char)((int)text.charAt(i)-shift);
                }
                System.out.print(newChar);
            }
            else
            {
                newChar=text.charAt(i);
                System.out.print(newChar);
            }
        }
    }


}
