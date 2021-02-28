public class TestRunner
{
    public static void main(String[] args)
    {
        TriangleTest test=new TriangleTest();

        test.testCounter(1);
        test.sidesLengthTest(-1,1,1);
        test.testCounter(2);
        test.sidesLengthTest(0,0,1);
        test.testCounter(3);
        test.sidesLengthTest(51,52,75);
        test.testCounter(4);
        test.sidesUnknownValueEntered('T',1,5);
        test.testCounter(5);
        test.sidesUnknownValueEntered(':','.','/');
        test.testCounter(6);
        test.sidesLengthTest(1,2);
        test.testCounter(7);
        test.sidesLengthTest(2,4,5,8);
        test.testCounter(8);
        test.sidesEqualitionTest(2,4,6);
        test.testCounter(9);
        test.triangleConditions(5,5,5);
        test.testCounter(10);
        test.triangleConditions(3,3,4);
        test.testCounter(11);
        test.triangleConditions(3,4,5);
    }



}
