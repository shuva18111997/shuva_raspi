import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.regex.*;

public class Solution {

    /*
     * Complete the timeConversion function below.
     */
    static String timeConversion(String s) {
        String[] arr = s.split(":");
        String sec = arr[2].substring(0,2);
        String AMorPM = arr[2].substring(2);
        if(AMorPM.equals("AM"))
        {
            if(arr[0].equals("12"))
                return ("00:"+arr[1]+":"+sec);
            else
                return (arr[0]+":"+arr[1]+":"+sec);
        }
        else
        {
            int hour = Integer.parseInt(arr[0]);
            if(hour != 12)
                hour += 12;
            String h = Integer.toString(hour);
            return(h+":"+arr[1]+":"+sec);
        }
    }

    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String s = scan.nextLine();

        String result = timeConversion(s);

        bw.write(result);
        bw.newLine();

        bw.close();
    }
}
