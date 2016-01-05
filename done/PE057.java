import java.math.*;

public class PE057 {

    public static final int LIMIT = 1000;    
    
    public static void main(String args[]) {
        String n = String.valueOf(1);
        BigInteger numer = new BigInteger(n);
        BigInteger denom = new BigInteger(n);
        int result = 0;
        for (int i = 0; i < LIMIT; i++) {
            BigInteger a = denom.add(denom);
            BigInteger new_numer = a.add(numer);
            BigInteger new_denom = numer.add(denom);
            String sn = new_numer.toString();
            String sd = new_denom.toString();
            if (sn.length() > sd.length())
                result++;
            numer = new_numer;
            denom = new_denom;            
        }
        System.out.println(result);
    }
}
