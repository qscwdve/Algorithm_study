import java.util.Stack;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer token;
		Stack<Integer> st  = new Stack<Integer>();
		int loop;
		try {
			
			token = new StringTokenizer(br.readLine());
			loop = Integer.parseInt(token.nextToken());
			
			while(loop-->0) {
				token = new StringTokenizer(br.readLine());
				switch(token.nextToken()) {
				case "push":
					st.push(Integer.parseInt(token.nextToken()));
					break;
				case "top":
					if(st.isEmpty()) bw.write("-1"+"\n");
					else bw.write(st.peek()+"\n");
					break;
				case "size":
					bw.write(st.size()+"\n");
					break;
				case "empty":
					bw.write(( st.empty() ? 1 : 0 )+ "\n");
					break;
				case "pop":
					if(st.isEmpty()) bw.write(-1+"\n");
					else {
						bw.write(st.pop()+"\n");
					}
					break;
				}
				bw.flush();
			}
		} catch(IOException e ) {
			e.printStackTrace();
		}	
	}
}
