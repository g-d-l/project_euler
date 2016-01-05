public class PE108 {
    public static final int BOUND = 1000;

    public static void main(String Args[]) {
        int result = 4;
        int count = 0;
        while (count <= BOUND) {
            ++result;
            count = 0;
            for (int i = result + 1; i <= 2 * result; ++i) {
                if ((i * result) % (i - result) == 0)
                    ++count;
            }
        }
        System.out.println(result);
    }
}
