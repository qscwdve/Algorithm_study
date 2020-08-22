import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.util.Queue;
import java.io.IOException;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		Queue<Integer> queue = new LinkedList<Integer>();
		
		try {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int loop = Integer.parseInt(st.nextToken());
			int temp = -1;
			while(loop-->0) {
				st = new StringTokenizer(br.readLine());
				switch(st.nextToken()) {
				case "push":
					temp = Integer.parseInt(st.nextToken());
					queue.add(temp);
					break;
				case "pop":
					if(queue.isEmpty())bw.write("-1"+"\n");
					else bw.write(queue.remove()+"\n");
					break;
				case "size":
					bw.write(queue.size()+"\n");
					break;
				case "empty":
					bw.write((queue.isEmpty() ? 1 : 0) + "\n");
					break;
				case "front":
					if(queue.isEmpty()) bw.write("-1"+"\n");
					else bw.write(queue.peek()+"\n");
					break;
				case "back":
					if(queue.isEmpty())bw.write(-1+"\n");
					else bw.write(temp+"\n");
					break;
				}
				bw.flush();
			}
			br.close();
			bw.close();
		}catch(IOException e) {
			e.printStackTrace();
		}

	}

}
