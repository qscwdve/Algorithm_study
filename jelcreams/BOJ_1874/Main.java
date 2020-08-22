import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
public class Main {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		boolean check = true;
		Stack<Integer> st = new Stack<Integer>();
		StringBuilder sb = new StringBuilder();
		int top = 0, loop = Integer.parseInt(br.readLine());
		int temp;
		while(loop-->0) {
			temp = Integer.parseInt(br.readLine());
			for(int j = top+1; j <= temp; j++) {
				st.push(j);
				top = j;
				sb.append("+\n");
			}
			if(st.pop()!=temp) {
				check = false;
			}else {
				sb.append("-\n");
			}
			
		}
		if(check) {
			System.out.println(sb);
		}
		else System.out.println("NO");
	}
}
