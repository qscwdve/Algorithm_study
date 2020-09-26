import java.io.*;
import java.util.*;
public class Main {
	public static void main(String [] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int numbers = Integer.parseInt(br.readLine());
		int result = 0;
		int [] array1 = new int[numbers];
		int [] array2 = new int[numbers];
		st = new StringTokenizer(br.readLine());
		int i = 0;
		while(st.hasMoreTokens()) {
			array1[i++] = Integer.parseInt(st.nextToken());
		}
		i = 0;
		st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			array2[i++] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(array1);
		Arrays.sort(array2);
		
		for(int k = 0, j = numbers-1;k<numbers;k++, j--) {
			result += array1[k]*array2[j];
		}
		System.out.println(result);
	}
}
