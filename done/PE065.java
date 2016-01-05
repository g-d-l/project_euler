import java.math.BigInteger;

public class PE065 {
    public static final int CONVERGENT = 100;
    
    public static void main(String[] args) {    
        BigInteger num = new BigInteger("1");
        int val = (CONVERGENT % 3 == 0) ? (2 * CONVERGENT) / 3 : 1;
        BigInteger denom = new BigInteger(Integer.toString(val));
        for (int i = CONVERGENT - 1; i > 1 ; i--) {
            BigInteger copy = new BigInteger(denom.toString());
            BigInteger c = new BigInteger(Integer.toString((i % 3 == 0) ? (2 * i) / 3 : 1)); 
            denom = denom.multiply(c);
            denom = denom.add(num);
            num = copy;
        }
        denom = denom.multiply(new BigInteger("2"));
        denom = denom.add(num);
        String NumResult = denom.toString();
        int sum = 0;
        for (int i = 0; i < NumResult.length(); ++i) {
            sum += NumResult.charAt(i) - 0x30;
        }
        System.out.println(sum);
    }
}
