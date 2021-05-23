import java.util.PriorityQueue;
import java.util.Queue;

public class Customer
{
    private String name;
    private String surname;
    private double balance;
    private String id;
    private String password;
    Queue<String> passwords = new PriorityQueue<>();
    
    public Customer(String name, String surname, double balance, String id)
    {
        this.setName(name);
        this.setSurname(surname);
        this.setBalance(balance);
        this.setId(id);
    }

    public String toString()
    {
        return "Name : " + getName() + "\nSurname : " + getSurname() + "\nID : " + getId() + "\nBalance : " + getBalance();
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
