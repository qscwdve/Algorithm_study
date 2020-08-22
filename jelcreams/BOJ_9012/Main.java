import java.io.IOException;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class Main {

	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		Stack<Character> st;
		
		int loop = Integer.parseInt(br.readLine());
		String str;
		boolean check;
		char ch;
		
		while(loop-->0) {
			st = new Stack<Character>();
			str = br.readLine();
			check = true;
			for(int i = 0; i<str.length();i++) {
				ch = str.charAt(i);
				switch(ch) {
					case '(':
						st.push(ch);
						break;
						
					case ')':
						if(st.isEmpty()) {
							check = false;
							i = str.length();
						}else {
							st.pop();
						}
				}
			}
			if(check && st.isEmpty()) bw.write("YES\n");
			else bw.write("NO\n");
			bw.flush();
		}
		
	}
}
