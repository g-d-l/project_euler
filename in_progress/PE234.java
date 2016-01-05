import java.util.Arrays;

public class PE234 {
    
    static final long LIMIT = 10000;
    
    public static void main(String args[]) {
        int[] primes = generatePrimes();

            
        long result = 0;
        for (int i = 0; i < primes.length - 2; ++i) {
            long upper = (long) primes[i + 1] * primes[i + 1];
            long lower = (long) primes[i] * primes[i];
            long diff = upper - lower;
            result += finiteArithSum(lower + primes[i], primes[i], diff / primes[i]);
            result += finiteArithSum(upper - primes[i + 1], -1 * primes[i + 1], diff / primes[i + 1]);
            result -= 2 * primes[i] * primes[i + 1];
        }
        long p = primes[primes.length - 2];
        long q = primes[primes.length - 1];
        long upper = LIMIT - (LIMIT % q);
        long pn = (long) Math.floor((double)(upper - p * p) / p);
        long qn = (long) Math.ceil((double)(upper - p * p) / q);
        result += finiteArithSum(p * p + p, p, pn);
        System.out.println(result);
        result += finiteArithSum(upper, -1 * q, qn);
        System.out.println(result + "," + p * p + "," + q);
        if (p * q <= LIMIT)
            result -= 2 * p * q;
        System.out.println(result);
    }
    
    public static int[] generatePrimes() {
        int arraySize = (int) (2 * Math.sqrt(LIMIT));
        boolean[] test = new boolean[arraySize];
        Arrays.fill(test, true);
        int primeCount = 0;
        for (int i = 2; i < arraySize; ++i) {
            if (test[i]) {
                if (i < Math.sqrt(LIMIT))
                    primeCount++;
                for (int j = 2 * i; j < arraySize; j += i)
                    test[j] = false;
            }
        }
        primeCount++;
        int[] primes = new int[primeCount];
        int index = 0;
        for (int i = 2; i < arraySize && index < primeCount; ++i) {
            if (test[i])
                primes[index++] = i;
        }
        return primes;
    }
    
    public static long finiteArithSum(long a, long r, long n) {
        return (n * (a + a + (n - 1) * r)) / 2;
    }
}
