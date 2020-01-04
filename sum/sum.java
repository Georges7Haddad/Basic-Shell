import java.util.Scanner;
class sum {
	public static void main(String arg[]) {
		Scanner in = new Scanner(System.in);
		int num1, num2, sum;
		num1 = in.nextInt();
		num2 = in.nextInt();
		
		System.out.println(num1 + "+" + num2);
		sum = num1 + num2;
		System.out.println(sum);
	}
}
