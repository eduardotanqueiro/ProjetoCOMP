class ClassTeste {

    public static void main(String[] args) {
        int a;
        a = 10_0000_00000;  //out
        a = 100;
        a = 100000;
        a = 2147483647; 
        a = 2147483648;     //out
        a = 2147483649;     //out
        a = 12147483649;    //out
        a = 1___0___0;
        a = 10___00____00;
        a = 214__748_3647;
        a = 214__748_3648;  //out
        a = 214__748_3649;  //out
        a = 1214748364__9;  //out

        a = -10_0000_00000;  //out
        a = -100;
        a = -100000;
        a = -2147483647; 
        a = -2147483648;     //out
        a = -2147483649;     //out
        a = -12147483649;    //out
        a = -1___0___0;
        a = -10___00____00;
        a = -214__748_3647;
        a = -214__748_3648;  //out
        a = -214__748_3649;  //out
        a = -1214748364__9;  //out

        a = +10_0000_00000;  //out
        a = +100;
        a = +100000;
        a = +2147483647; 
        a = +2147483648;     //out
        a = +2147483649;     //out
        a = +12147483649;    //out
        a = +1___0___0;
        a = +10___00____00;
        a = +214__748_3647;
        a = +214__748_3648;  //out
        a = +214__748_3649;  //out
        a = +1214748364__9;  //out

    }
}