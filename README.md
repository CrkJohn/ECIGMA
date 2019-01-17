# ECIGMA
package arswLaboratorio1;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.Scanner;

public class EOF {
	
	public static void main(String[] args) throws IOException {
		Scanner sc  = new Scanner(System.in);
		int ntc = 1;
		while(sc.hasNext()){
			String str = sc.nextLine();
			System.out.println(ntc+" "+str);
			ntc++;
		}
	}

}
