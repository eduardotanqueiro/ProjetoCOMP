class Factorial {
    public static int factorial(int n, int i) {
        if (n == 0)
            return 1;
        return n * factorial(n-1);
    }

    public static void main(String[] args) {
        factorial(1,2);
		factorial(3);
    }
}
