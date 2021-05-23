public class Main
{
    public static void main(String[] args)
    {
	    Customer customer1=new Customer("Cristiano","Ronaldo",128,"0001");
	    Customer customer2=new Customer("Lionel","Messi",56,"0002");
        ATM atm=new ATM(customer1);

		System.out.println(customer1.toString());
		System.out.println(customer2.toString());
	    atm.deposit(customer1,-1);
	    atm.deposit(customer1,3);
	    atm.withdraw(customer1,-5);
	    atm.withdraw(customer1,133);
	    atm.withdraw(customer1,3);
	    atm.moneyTransfer(customer1,customer2,-5);
	    atm.moneyTransfer(customer1,customer2,500);
        atm.moneyTransfer(customer1,customer2,5);
		atm.createPassword("4444");
        System.out.println(customer1.getPassword());
		atm.createPassword("4484");
        System.out.println(customer1.getPassword());
        atm.changePassword("4485");
        atm.changePassword("4486");
        System.out.println(customer1.passwords);
        atm.createPassword("6666");
    }
}
