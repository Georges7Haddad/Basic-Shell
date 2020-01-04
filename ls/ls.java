import java.io.*;
class ls {
	public static void main(String arg[]){
		File dir = new File("."); 
		for (File file : dir.listFiles()) {
			System.out.print("\u001B[35m" + file.getName()+" " + "\u001B[0m" );
		}
		System.out.println("");
	}
}
