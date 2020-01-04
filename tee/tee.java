import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
class tee {
	public static void main(String arg[]) {
		File file = new File(arg[0]);
		Scanner scan = new Scanner(System.in);
		String string;
		scan.hasNext();
		FileWriter fwriter = null;
		try{
			fwriter = new FileWriter(arg[0]);
                }
                catch(IOException e) {
			e.printStackTrace();
                }
		while(scan.hasNext()) {
			string = scan.nextLine();
			System.out.println("'" + string + "'");
			string = string + "\n";
			try{
				fwriter.write(string);
			}
			catch(IOException e) {
				e.printStackTrace();
			}
		}
		try{
			fwriter.close();
		}
                catch(IOException e) {
			e.printStackTrace();
                }
		System.out.println("");
		System.out.println("\u001B[36m" + "Done Writing" + "\u001B[0m");
	}
}
