public class ATM
{
    Customer customer;

    public ATM(Customer customer)
    {
        this.customer=customer;
    }

    public void deposit(Customer customer,double depositAmount)
    {
        if (depositAmount<=0)
        {
            System.out.println("Please enter valid amount for deposit");
        }
        else
        {
            customer.setBalance(customer.getBalance()+depositAmount);
            System.out.println("You deposit +"+depositAmount+"$ and new balance :"+customer.getBalance());
        }
    }

    public void withdraw(Customer customer,double withdrawAmount)
    {
        if (withdrawAmount<=0)
        {
            System.out.println("Please enter valid amount for deposit");
        }
        else if(customer.getBalance() < withdrawAmount)
        {
            System.out.println("Your balance is not enough for that amount");
        }
        else
        {
            customer.setBalance(customer.getBalance()-withdrawAmount);
            System.out.println("You withdraw -"+withdrawAmount+"$ and new balance :"+customer.getBalance());
        }
    }

    public void moneyTransfer(Customer customer1,Customer customer2,double amount)
    {
        //customer1 transfer money to customer2
        if (amount <= 0)
        {
            System.out.println("Please enter valid amount for transfer");
        }
        else if(customer1.getBalance() < amount)
        {
            System.out.println("Your balance is not enough to transfer");
        }
        else
        {
            customer1.setBalance(customer1.getBalance()-amount);
            customer2.setBalance(customer2.getBalance()+amount);
            System.out.println("You send "+amount+" to the "+customer2.getName()+" with customer id "+customer1.getId());
        }
    }

    public boolean checkDigit(String newPassword) // check 4 digit
    {
        if (newPassword.length()==4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public boolean checkNumber(String newPassword)
    {
        int convertedToIntOfPassword=Integer.parseInt(newPassword);

        if (convertedToIntOfPassword>999 && convertedToIntOfPassword<=9999)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public boolean checkBetweenTheYear(String newPassword)
    {
        if (Integer.parseInt(newPassword)>=1900 && Integer.parseInt(newPassword)<=2000)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    public boolean checkSameDigits(String newPassword)
    {
        char controlChar=newPassword.charAt(0);
        int counter=1;
        for (int i=1;i<=3;i+=1)
        {
            if (newPassword.charAt(i) == controlChar)
            {
                counter+=1;
            }
        }
        if (counter==4)
        {
            return false;
        }
        return true;
    }

    public boolean checkRepeatingTwoDigits(String newPassword)
    {
        if (newPassword.charAt(0)==newPassword.charAt(2))
        {
            if (newPassword.charAt(1)==newPassword.charAt(3))
            {
                return false;
            }
        }
        return true;
    }

    public void checkLastPasswords(String newPassword)
    {
        int size=customer.passwords.size();

        if (size==1)
        {
            if (customer.passwords.peek().equals(newPassword))
            {
                System.out.println("You cannot change your passwords");
            }
            else
            {
                customer.passwords.add(newPassword);
                customer.setPassword(newPassword);
            }
        }
        if (size==2)
        {
            if (customer.passwords.peek().equals(newPassword))
            {
                System.out.println("You cannot change your passwords");
            }
            else
            {
                String firstPassword=customer.passwords.remove();
                if (customer.passwords.peek().equals(newPassword))
                {
                    System.out.println("You cannot change your passwords");
                    String secondPassword=customer.passwords.remove(); //to restore password queue
                    customer.passwords.add(firstPassword);
                    customer.passwords.add(secondPassword);
                }
                else
                {
                    String secondPassword=customer.passwords.remove();//to restore password queue and add third password(new password)
                    customer.passwords.add(firstPassword);
                    customer.passwords.add(secondPassword);
                    customer.passwords.add(newPassword);
                    customer.setPassword(newPassword);
                }
            }
        }
        if (size==3)
        {
            if (customer.passwords.peek().equals(newPassword))
            {
                System.out.println("You cannot change your passwords");
            }
            else
            {
                customer.passwords.remove();
                if (customer.passwords.peek().equals(newPassword))
                {
                    System.out.println("You cannot change your passwords");
                }
                else
                {
                    String secondPassword=customer.passwords.remove();
                    if (customer.passwords.peek().equals(newPassword))
                    {
                        System.out.println("You cannot change your passwords");
                    }
                    else
                    {
                        String thirdPassword=customer.passwords.remove();
                        customer.passwords.add(secondPassword);
                        customer.passwords.add(thirdPassword);
                        customer.passwords.add(newPassword);
                        customer.setPassword(newPassword);
                    }
                }
            }
        }
    }

    public void changePassword(String newPassword)
    {
        if (checkDigit(newPassword) && checkNumber(newPassword) && checkBetweenTheYear(newPassword) && checkSameDigits(newPassword) && checkRepeatingTwoDigits(newPassword))
        {
            checkLastPasswords(newPassword);
        }
    }

    public void createPassword(String newPassword)//for queue size=0 and new account
    {
        if (customer.passwords.size()==0)
        {
            if (checkDigit(newPassword) && checkNumber(newPassword) && checkBetweenTheYear(newPassword) && checkSameDigits(newPassword) && checkRepeatingTwoDigits(newPassword))
            {
                customer.passwords.add(newPassword);
                customer.setPassword(newPassword);
            }
            else
            {
                System.out.println("Your password is invalid");
            }
        }
        else
        {
            System.out.println("You have password,you cannot create new one just change it");
        }
    }

}