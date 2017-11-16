import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class MinMax 
{
    public static void main(String[] args) throws IOException 
    {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int liczba;
        for (int licznik = 0; licznik < 15; licznik++) 
        {
            System.out.print("Liczba " + licznik + ": ");
            liczba = Integer.parseInt(reader.readLine());
            if (liczba < min)
            {
                min = liczba;
            }
            if (liczba > max)
            {
                max = liczba;
            }   
        }
        System.out.println("Ró¿nica: " + (max - min));
    }
}

