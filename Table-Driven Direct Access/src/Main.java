import java.util.Scanner;

public class Main
{
    public static void main(String[] args) {
        MonthsLanguageTable monthsLanguageTable = new MonthsLanguageTable();

        Scanner scanner = new Scanner(System.in);
        boolean condition = true;


        do {
            try
            {
                System.out.println("TR or EN ??");
                String language = scanner.nextLine();
                System.out.println("Choose month : ");
                int month = scanner.nextInt();
                if (!monthsLanguageTable.getLanguageMap().containsKey(language))
                {
                    System.out.println("Invalid language choice!!");
                    break;
                }
                monthsLanguageTable.takeMonthsAndPrint(month,language);
                condition = false;
            }
            catch (Exception e)
            {
                System.out.println(e.getLocalizedMessage());
            }

        }while (condition);

    }
}
