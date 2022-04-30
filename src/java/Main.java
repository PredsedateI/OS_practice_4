import java.util.Scanner;
import java.io.*;

public class Main {
	public static short basic;
	public static long b;
	public static long c;

	public static long f(long i) {
		if (i == basic) {
			return 0;
		}
		long temp = 0;
		for (int n = 1; n <= 100000000; n++) {
			temp += 2 * b + c - i;
		}
		return f(i - 1) + temp;
	}

	public static void main(String args[]) throws Exception {
        	long result;
		long i;
		Scanner scan = new Scanner(new FileReader("temp/hub.txt"));
		basic = scan.nextShort();
		b = scan.nextLong();
		c = scan.nextLong();
		i = scan.nextLong();
		
		long ts, te;
		ts = System.currentTimeMillis();
		result = f(i);
		te = System.currentTimeMillis();
		long dt = te - ts;
		
        	FileWriter fout = new FileWriter("temp/java.txt");
        	fout.write(Long.toString(result) + ' ' + Long.toString(dt));
        	fout.close();
	}
}