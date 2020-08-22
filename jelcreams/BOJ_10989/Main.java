import java.io.*;
import java.util.*;
public class Main {
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int[] array = new int[10001];
		int loop = Integer.parseInt(br.readLine());
		
		while(loop-->0) {
			array[Integer.parseInt(br.readLine())]++;
		}
		for(int i = 1 ; i < 10001; i++) {
			while(array[i]-->0)bw.write(i+"\n");
		}
		bw.flush();
	}
}
