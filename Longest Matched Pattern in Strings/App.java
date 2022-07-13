import java.util.Arrays;
import java.util.Comparator;
import java.util.TreeSet;

public class App {
    public static void main(String[] args) throws Exception 
    {    
        String[] elements = {"tolgasXvelkozz","tolgasYvelkozz","tolgasZvelkozz"};
        System.out.println(longestCommonPattern(elements));
    }

    public static String longestCommonPattern(String[] elements)
    {
        Arrays.sort(elements, Comparator.comparingInt(String::length)); //sort of parameter 
        TreeSet<String> patternsSet = matchedPattern(elements[0], elements[1]);
        String[] patterns = new String[patternsSet.size()]; 
        patternsSet.toArray(patterns);

        int currentIndex = patterns.length - 1;
        String longestCommonPattern = patterns[currentIndex];
        int i = 2;

        for (; i < elements.length;) 
        {
            if(elements[i].contains(longestCommonPattern))
            {
                i++;
            }
            else
            {
                i = 2;
                currentIndex--;
                longestCommonPattern = patterns[currentIndex];
            }
        }

        return longestCommonPattern;
    }

    public static TreeSet<String> matchedPattern(String firstElement,String secondElement)  
    {
        String common = ""; 
        StringBuilder stringBuilder = new StringBuilder();
        TreeSet<String> patterns = new TreeSet<>(); //benefits of treeset collection, it return us sorted common patterns and we dont do extra sorting operation
        for (int i = 0; i < firstElement.length(); i++) 
        {
            for (int j = 0; j < secondElement.length(); j++) 
            {
                if(firstElement.charAt(i) == secondElement.charAt(i))
                {
                    stringBuilder.append(firstElement.charAt(i));
                    break;
                }
                else
                {
                    stringBuilder = new StringBuilder();
                }
            }    
            if(stringBuilder.length()>common.length())
            {
                common = stringBuilder.toString();
                patterns.add(common);
            }
        }
        
        return patterns;
    }
}
