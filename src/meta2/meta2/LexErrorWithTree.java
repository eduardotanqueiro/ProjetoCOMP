class LexErrorWithTree {
    public static int factorial(int n) { "asdasd
        n = f("ol\1a");
        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {
        int argument;
        argument = Integer.parseInt(args[0]);
        System.out.print((factorial(argument)));
    }
}
