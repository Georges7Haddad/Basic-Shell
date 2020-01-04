import java.util.Scanner;
class substract {
        public static void main(String arg[]) {
                Scanner in1 = new Scanner(System.in);
                int num1, num2, difference;
                num1 = in1.nextInt();
                num2 = in1.nextInt();
                difference = num1 - num2;
		System.out.println(num1 + "-" + num2);
                System.out.println(difference);
        }
}

