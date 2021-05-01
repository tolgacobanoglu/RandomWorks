public class IZSU
{
    static double waterBillCalculator(int consumptionAmount)
    {
        if(consumptionAmount>=0 && consumptionAmount<=13)
            return (6.41*1.08)*consumptionAmount;
        else if(13<consumptionAmount && consumptionAmount<=20)
            return ((13*6.41)+(consumptionAmount-13)*6.92)*1.08;
        else if(consumptionAmount>20)
            return ((13*6.41)+(7*6.92)+((consumptionAmount-20)*14.27))*1.08;

         return -1;
    }
}
