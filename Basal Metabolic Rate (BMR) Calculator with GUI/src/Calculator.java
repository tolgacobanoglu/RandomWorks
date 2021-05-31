import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator implements ActionListener
{
    JFrame frame=new JFrame("BMR Calculator");

    JLabel labelAge=new JLabel("Age");
    JTextField textFieldAge=new JTextField();

    JLabel labelGender=new JLabel("Gender");
    JRadioButton maleButton =new JRadioButton("Male");
    JRadioButton femaleButton =new JRadioButton("Female");
    ButtonGroup genderGroup=new ButtonGroup();

    JLabel labelResultType=new JLabel("Result type");
    JRadioButton kilocaloriesButton=new JRadioButton("kilocalories");
    JRadioButton kilojoulesButton =new JRadioButton("kilojoules");
    ButtonGroup resultTypeGroup=new ButtonGroup();

    JLabel labelEquationType =new JLabel("Equation type");
    JRadioButton mifflinButton=new JRadioButton("Mifflin-St Jeor Equation");
    JRadioButton revisedButton=new JRadioButton("Revised Harris-Benedict Equation");
    ButtonGroup equationGroup=new ButtonGroup();

    JLabel labelWeight=new JLabel("Weight (kg)");
    JTextField weightTextField=new JTextField();

    JLabel labelHeight=new JLabel("Height (cm)");
    JTextField heightTextField=new JTextField();

    JTextArea result=new JTextArea();

    JButton calculateButton=new JButton("Calculate");

    Calculator()
    {

        labelAge.setBounds(15,10,50,50);
        textFieldAge.setBounds(15,55,80,35);

        labelGender.setBounds(15,120,80,35);
        maleButton.setBounds(15,158,100,30);
        femaleButton.setBounds(15,188,100,30);
        genderGroup.add(maleButton);
        genderGroup.add(femaleButton);

        labelResultType.setBounds(15,245,100,50);
        kilojoulesButton.setBounds(15,283,100,30);
        kilocaloriesButton.setBounds(15,313,100,30);
        resultTypeGroup.add(kilocaloriesButton);
        resultTypeGroup.add(kilojoulesButton);

        labelEquationType.setBounds(15,363,100,30);
        mifflinButton.setBounds(15,393,300,30);
        revisedButton.setBounds(15,413,300,30);
        equationGroup.add(mifflinButton);
        equationGroup.add(revisedButton);

        labelWeight.setBounds(250,10,100,50);
        weightTextField.setBounds(250,50,80,35);

        labelHeight.setBounds(250,120,100,50);
        heightTextField.setBounds(250,160,80,35);

        calculateButton.setFocusable(false);
        calculateButton.setBounds(200,550,100,50);
        calculateButton.addActionListener(this);

        result.setBounds(250,245,150,150);

        frame.add(labelResultType);
        frame.add(labelAge);
        frame.add(textFieldAge);
        frame.add(maleButton);
        frame.add(femaleButton);
        frame.add(labelGender);
        frame.add(kilocaloriesButton);
        frame.add(kilojoulesButton);
        frame.add(labelEquationType);
        frame.add(mifflinButton);
        frame.add(revisedButton);
        frame.add(labelWeight);
        frame.add(labelHeight);
        frame.add(weightTextField);
        frame.add(heightTextField);
        frame.add(result);
        frame.add(calculateButton);


        frame.setLayout(null);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(500,700);
        frame.setResizable(false);
        frame.setLocationRelativeTo(null);


    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        double BMR=0;
        if(e.getSource()==calculateButton)
        {
            if (Integer.parseInt(textFieldAge.getText())>=15 && Integer.parseInt(textFieldAge.getText())<=80)
            {
                if (femaleButton.isSelected())
                {
                    if (kilojoulesButton.isSelected())
                    {
                        if (mifflinButton.isSelected())
                        {
                            BMR=4.1868*((Integer.parseInt(weightTextField.getText())*10)+(Integer.parseInt(heightTextField.getText())*6.25)-(Integer.parseInt(textFieldAge.getText())*5)-161);
                        }
                        else if(revisedButton.isSelected())
                        {
                            BMR=4.1868*((Integer.parseInt(weightTextField.getText())*9.247)+(Integer.parseInt(heightTextField.getText())*3.098)-(Integer.parseInt(textFieldAge.getText())*4.330)-447.593);
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null,"You miss something","ERROR",JOptionPane.WARNING_MESSAGE);
                        }
                    }
                    else if (kilocaloriesButton.isSelected())
                    {
                        if (mifflinButton.isSelected())
                        {
                            BMR=(Integer.parseInt(weightTextField.getText())*10)+(Integer.parseInt(heightTextField.getText())*6.25)-(Integer.parseInt(textFieldAge.getText())*5)-161;
                        }
                        else if(revisedButton.isSelected())
                        {
                            BMR=(Integer.parseInt(weightTextField.getText())*9.247)+(Integer.parseInt(heightTextField.getText())*3.098)-(Integer.parseInt(textFieldAge.getText())*4.330)-447.593;
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null,"You miss something","ERROR",JOptionPane.WARNING_MESSAGE);
                        }
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null,"You miss something","ERROR",JOptionPane.WARNING_MESSAGE);
                    }
                }
                else if (maleButton.isSelected())
                {
                    if (kilojoulesButton.isSelected())
                    {
                        if (mifflinButton.isSelected())
                        {
                            BMR=4.1868*((Integer.parseInt(weightTextField.getText())*10)+(Integer.parseInt(heightTextField.getText())*6.25)-(Integer.parseInt(textFieldAge.getText())*5)+5);
                        }
                        else if(revisedButton.isSelected())
                        {
                            BMR=4.1868*((Integer.parseInt(weightTextField.getText())*13.397)+(Integer.parseInt(heightTextField.getText())*4.799)-(Integer.parseInt(textFieldAge.getText())*5.677)+88.362);
                        }
                        else
                        {
                            JOptionPane.showMessageDialog(null,"You miss something","ERROR",JOptionPane.WARNING_MESSAGE);
                        }
                    }
                    else if (kilocaloriesButton.isSelected())
                    {
                        if (mifflinButton.isSelected())
                        {
                            BMR=((Integer.parseInt(weightTextField.getText())*10)+(Integer.parseInt(heightTextField.getText())*6.25)-(Integer.parseInt(textFieldAge.getText())*5)+5);
                        }
                        else if(revisedButton.isSelected())
                        {
                            BMR=((Integer.parseInt(weightTextField.getText())*13.397)+(Integer.parseInt(heightTextField.getText())*4.799)-(Integer.parseInt(textFieldAge.getText())*5.677)+88.362);
                        }
                    }
                    else
                    {
                        JOptionPane.showMessageDialog(null,"You miss something","ERROR",JOptionPane.WARNING_MESSAGE);
                    }

                }
                else
                {
                    JOptionPane.showMessageDialog(null,"You miss something","ERROR",JOptionPane.WARNING_MESSAGE);
                }
            }
            else
            {
                JOptionPane.showMessageDialog(null,"Invalid Age","ERROR",JOptionPane.WARNING_MESSAGE);
            }
        }

        result.setText(""+BMR);
    }
}
