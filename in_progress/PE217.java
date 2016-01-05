public class PE217 {
    public final int N = 47;
    
    public static void main(String Args[]) {
        
    }
    
    public int factorial(int n) {
        if (n == 0)
            return 1;
        else
            return n * factorial(n - 1);
    }
}
