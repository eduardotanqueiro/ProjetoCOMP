//Compilar com flag -e2

class Factorial {

    public static int factorial(int n) {

        if (n == 0)

            return 1;

        return * factorial(n-1);

    }



    public static void main([]String args) {

        int argument;

        argument = Integer.parseInt(args[0]);

        System.out.print(factorial(argument));

    }

}

