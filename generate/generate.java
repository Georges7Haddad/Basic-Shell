import java.util.Random;
class generate {
	public static void main(String arg[]) {
		int first, second;
		Random random = new Random();
		first = random.nextInt(11);
		second = random.nextInt(11);
		System.out.println(first + " " + second);	
	}
}
