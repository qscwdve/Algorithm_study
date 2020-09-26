import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;


public class Main {
	static boolean time[] = new boolean[100001];
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int N,K;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		BFS(N,K);
		
		
	}
	static void BFS(int start, int end) {
		Queue<Node> que = new LinkedList<Node>();
		
		que.add(new Node(start,0));
		time[start] = true;
		while(!que.isEmpty()) {
			Node temp = que.poll();
			if(temp.index == end) {
				System.out.println(temp.time);
				return;
			}else {
				if(temp.index>0 && !time[temp.index-1]) {
					time[temp.index-1]=true;
					que.add(new Node(temp.index - 1,temp.time+1));
				}
				if(temp.index<100000&& !time[temp.index+1]) {
					time[temp.index+1]=true;
					que.add(new Node(temp.index + 1,temp.time+1));
				}
				if(temp.index<=50000&& !time[temp.index*2]) {
					time[temp.index*2]=true;
					que.add(new Node(temp.index * 2,temp.time+1));
				}
			}
		}
	}
}
class Node{
	int index;
	int time;
	Node(int i , int t){
		index = i;
		time = t;
	}
}
