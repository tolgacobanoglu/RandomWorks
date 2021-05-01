import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class IZSUTest
{
    @Test
    void waterBillCalculator()
    {
        assertEquals(0,IZSU.waterBillCalculator(0));
        assertEquals(6.9228000000000005,IZSU.waterBillCalculator(1));
        assertEquals(83.0736,IZSU.waterBillCalculator(12));
        assertEquals(89.99640000000001,IZSU.waterBillCalculator(13));
        assertEquals(97.47000000000001,IZSU.waterBillCalculator(14));
        assertEquals(134.838,IZSU.waterBillCalculator(19));
        assertEquals(142.3116,IZSU.waterBillCalculator(20));
        assertEquals(157.7232,IZSU.waterBillCalculator(21));
        assertEquals(-1,IZSU.waterBillCalculator(-1));
    }
}