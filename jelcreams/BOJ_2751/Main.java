import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	static boolean[]  arr = new boolean[2000001];
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		int max = 0, temp;
		for(int i = 0; i < N ; i++) {
			temp = Integer.parseInt(br.readLine());
			arr[temp+1000000] = true;
			if(temp>max)max = temp;
		}
		max += 1000000;
		for(int j = 0 ; j <= max ; j++)if(arr[j])sb.append(j-1000000+"\n");
		System.out.println(sb);
		
	}
}
