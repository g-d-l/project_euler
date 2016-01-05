import java.math.*;

public class PE055 {
    
    public static final int LIMIT = 10000;
    
    public static void main(String args[]) {
        int result = 0;
        for (int i = 1; i < LIMIT; i++) {
            String str = String.valueOf(i);
            BigInteger bi = new BigInteger(str);
            for (int j = 0; j < 50; j++) {
                bi = bi.add(reverse(bi));
                if (isPalindrome(bi)) {
                    result++;
                    break;
                }
                    
            }
        }
        System.out.println(LIMIT - result - 1);
    }
    
    
    public static boolean isPalindrome(BigInteger bi) {
        String str = bi.toString();
        for (int i = 0; i < str.length() / 2; i++) {
            if (str.charAt(i) != str.charAt(str.length() - i - 1))
                return false;
        }
        return true;
    }
    
    
    public static BigInteger reverse(BigInteger bi) {
        String str = bi.toString();
        char[] array = new char[str.length()];
        for (int i = 0; i < str.length(); i++)
            array[i] = str.charAt(str.length() - i - 1);
        String str2 = new String(array);
        BigInteger new_bi = new BigInteger(str2);
        return new_bi;
    }
}
