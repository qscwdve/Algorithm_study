import java.util.Deque;
import java.util.LinkedList;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st;
		
		Deque<Integer> dq = new LinkedList<Integer>();
		
		int loop;
		try {
			loop = Integer.parseInt(br.readLine());
			while(loop-->0) {
				st = new StringTokenizer(br.readLine());
				switch(st.nextToken()) {
				case "push_front":
					dq.addFirst(Integer.parseInt(st.nextToken()));
					break;
				case "push_back":
					dq.addLast(Integer.parseInt(st.nextToken()));
					break;
				case "pop_front":
					if(dq.isEmpty())bw.write("-1"+"\n");
					else bw.write(dq.pollFirst()+"\n");
					break;
				case "pop_back":
					if(dq.isEmpty())bw.write("-1"+"\n");
					else bw.write(dq.pollLast()+"\n");
					break;
				case "size":
					bw.write(dq.size()+"\n");
					break;
				case "empty":
					bw.write((dq.isEmpty()? 1:0)+"\n");
					break;
				case "front":
					if(dq.isEmpty())bw.write("-1"+"\n");
					else bw.write(dq.peekFirst()+"\n");
					break;
				case "back":
					if(dq.isEmpty())bw.write("-1"+"\n");
					else bw.write(dq.peekLast()+"\n");
					break;
				}
				bw.flush();
			}
			bw.close();
			br.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}
