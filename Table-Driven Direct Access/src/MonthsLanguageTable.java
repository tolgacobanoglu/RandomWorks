import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class MonthsLanguageTable
{

    private HashMap<String, String[]> languageMap;

    public MonthsLanguageTable() {
        languageMap = new HashMap<>();
        this.insertEN();
        this.insertTR();
    }

    public HashMap<String, String[]> getLanguageMap() {
        return languageMap;
    }

    private void insertTR()
    {
        String[] months = {"Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran","Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};
        languageMap.put("TR",months);
    }

    private void insertEN()
    {
        String[] months = {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
        languageMap.put("EN",months);
    }

    public void takeMonthsAndPrint(int number,String countryCode)
    {
        if (isValidMonthRange(number))
        {
            String[] months = languageMap.get(countryCode);
            System.out.println(months[number-1]);
        }
        else
        {
            System.out.println("INVALID MONTHS RANGE");
        }
    }

    private boolean isValidMonthRange(int number)
    {
        return number>0 && number<=12;
    }
}
