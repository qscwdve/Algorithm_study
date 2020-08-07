import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		Node[] node;
		Queue<Node> que = new LinkedList<Node>();
		int N, M;
		int A, B;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		node = new Node[N+1];
		
		for(int i =1; i<=N;i++){
			node[i] = new Node(i);
		}
		
		while(M-->0) {
			st = new StringTokenizer(br.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			node[A].add(B);
			node[B].count++;
		}
		
		for(int j = 1 ; j <=N;j++) {
			if(node[j].count == 0)que.add(node[j]);
		}
		
		Node temp, nd;
		while(!que.isEmpty()) {
			nd = que.poll();
			//System.out.println("nd check "+nd.index+" "+nd.count);
			if( nd.count == 0 ) {
				//System.out.println("index of count 0"+nd.index);
				bw.write(nd.index+" ");
				while(!nd.q.isEmpty()) {
					temp = node[nd.q.poll()];
					temp.count--;
					if(temp.count == 0)
						que.add(temp);
				}
			}
		}
		bw.write("\n");
		bw.flush();
		
	}
}

class Node{
	int index;
	int count = 0;
	Queue<Integer> q = new LinkedList<Integer>();
	Node(int i){
		index =i;
	}
	void add(int v) {
		q.add(v);
	}
}
