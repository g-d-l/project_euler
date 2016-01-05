import java.util.Arrays;
import java.lang.Math;

class Node {
    int val;
    boolean iterated;
}

public class PE243 {
    
    public final static int START_LEN = 32;
    
    public static void main(String Args[]) {
        
    }
    
    public static Node[] doubleSize(Node[] original) {
        Node[] doubled = Arrays.copyOf(original, 2 * original.length);
        for (int i = original.length; i < 2 * original.length; ++i)
            doubled[i].val = i;       
        for (int i = 2; i < original.length; ++i) {
            if (doubled[i].iterated) {
                int start = (int) Math.ceil((double) original.length / i) * i;
                for (int j = start; j < 2 * original.length; j += i) {
                    doubled[j].val *= i - 1;
                    doubled[j].val /= i;
                }
            }
        }
        return doubled;
    }
}
