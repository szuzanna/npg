import java.applet.Applet;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.event.ActionEvent ;
import java.awt.event.ActionListener;
# 
public class Kalkulator extends Applet implements ActionListener 
{
    static double wartosc = 0.0;
    static double pamiec = 0.0;
    static int operacja =0;
    Label wyswietlacz = new Label("" + wartosc + ".", Label.LEFT);
    Label tytul = new Label("Kalkulator", Label.CENTER);
    Button b1 = new Button("1");
    Button b2 = new Button("2");
    Button b3 = new Button("3");
    Button b4 = new Button("4");
    Button b5 = new Button("5");
    Button b6 = new Button("6"); 
    Button b7 = new Button("7");
    Button b8 = new Button("8");
    Button b9 = new Button("9");
    Button b0 = new Button("0");
    Button bPlus = new Button("+");
    Button bMinus = new Button("-");
    Button bMnoznik = new Button("*");
    Button bDzielnik = new Button("/");
    Button bSum = new Button("=");
    Button bC = new Button("C"); 
 
    public void init() 
    {
        Panel panel = new Panel();
        panel.setLayout(new GridLayout(4, 4));
        panel.add(b7);
        panel.add(b8);
        panel.add(b9);
        panel.add(bPlus);
        panel.add(b4);
        panel.add(b5);
        panel.add(b6);
        panel.add(bMinus);
        panel.add(b1);
        panel.add(b2);
        panel.add(b3);
        panel.add(bMnoznik);
        panel.add(b0);
        panel.add(bDzielnik);
        panel.add(bSum);
        panel.add(bC);
        setLayout(new BorderLayout());
        add(BorderLayout.NORTH, tytul);
        add(BorderLayout.SOUTH, panel);
        add(BorderLayout.CENTER, wyswietlacz);
        wyswietlacz.setFont(new Font("Arial", Font.BOLD, 30)); 
        tytul.setFont(new Font("Arial", Font.ITALIC, 16));
        b0.addActionListener(this);
        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);
        b4.addActionListener(this);
        b5.addActionListener(this);
        b6.addActionListener (this);
        b7.addActionListener(this);
        b8.addActionListener(this);
        b9.addActionListener(this);
        bPlus.addActionListener(this);
        bMinus.addActionListener(this);
        bMnoznik.addActionListener(this);
        bDzielnik.addActionListener(this);
        bSum.addActionListener(this);
        bC.addActionListener(this);
    }
     
    public void actionPerformed(ActionEvent evt) 
    {
        if (evt.getSource() != bPlus && evt.getSource() != bSum 
            && evt.getSource() != bMinus && evt.getSource() != bMnoznik 
            && evt.getSource () != bDzielnik && evt.getSource() != bC) 
        {
            wartosc = 10 * wartosc + 
                Double.parseDouble(((Button) evt.getSource()).getLabel());
            wyswietlacz.setText("" + wartosc + ".");
        } 
 
        else if (evt.getSource() == bPlus) 
        {
            pamiec = wartosc;
            wartosc = 0.0;
            operacja=1;
        }
        else if (evt.getSource() == bMinus)
        {
            pamiec = wartosc;
            wartosc = 0.0;
            operacja=2; 
        }
        else if (evt.getSource() == bMnoznik)
        {
            pamiec = wartosc;
            wartosc = 0.0;
            operacja=3;
        }
        else if (evt.getSource() == bDzielnik)
        {
            pamiec = wartosc;
            wartosc = 0.0;
            operacja = 4; 
        }
        else if (evt.getSource() == bC)
        {
            pamiec = 0.0;
            wartosc=pamiec;
            wyswietlacz.setText("" + wartosc + "."); 
        }
        else
        {
            if(operacja==1)
            {
                pamiec +=wartosc; 
                wartosc = pamiec;
                wyswietlacz.setText("" + wartosc + ".");
            }
            else if (operacja==2)
            {
                pamiec -=wartosc;
                wartosc = pamiec; 
                wyswietlacz.setText("" + wartosc + ".");
            }
            else if (operacja==3)
            {
                pamiec = pamiec*wartosc;
                wartosc = pamiec;
                wyswietlacz.setText ("" + wartosc + ".");
            }
            else if (operacja==4)
            {
                pamiec = pamiec/wartosc;
                wartosc = pamiec;
                wyswietlacz.setText("" + wartosc + "."); 
            }
            wartosc=pamiec;
        }
    }
}
