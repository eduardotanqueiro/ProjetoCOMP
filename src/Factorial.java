class Factorial {
    // teste COMENTARIO
    /*
     * teste comement
     * 
     */
    public static int factorial(int n) {

        if (n == 0)
            return 1;
        return n * factorial(n - 1);
    }

    public static void main(String[] args) {

        int argument;
        argument = Integer.parseInt(args[0]);

        String my_string = "abc\jxdxd";

        System.out.print(factorial(argument));
        

    }
}