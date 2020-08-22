import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

public class Main {
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st;
		
		Stack<Integer> stack = new Stack<Integer>();
		Queue<Integer> que = new LinkedList<Integer>();
		
		int node, edge, start;
		st = new StringTokenizer(br.readLine());
		node = Integer.parseInt(st.nextToken());
		edge = Integer.parseInt(st.nextToken());
		start = Integer.parseInt(st.nextToken());
		
		int [][] map = new int[node+1][node+1];
		int A,B;
		//node와 간선 처리
		for(int i = edge; i>0;i--) {
			st = new StringTokenizer(br.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			map[A][B] = 2; 
			map[B][A] = 2;
		}
		
		sb.append(DFS(node,start,map));
		sb.append(BFS(node,start,map));
		System.out.println(sb);
	}
	static StringBuilder DFS(int node, int start, int[][] map) {
		StringBuilder sb = new StringBuilder();
		Stack<Integer> st = new Stack<Integer>();
		st.push(start);
		//DFS 처리
		while(!st.isEmpty()) {
			int temp = st.pop();
			if(map[temp][temp] != -1) {
				sb.append(temp+" ");
				for(int k = node; k>0; k--) {
					if(map[temp][k] == 2) {
						map[temp][k] = 1;
						map[k][temp] = 1;
						st.push(k);
					}
				}
			}
			map[temp][temp] = -1;
		}
		sb.append("\n");
		return sb;
	}
	static StringBuilder BFS(int node, int start, int[][]map) {
		StringBuilder sb = new StringBuilder();
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(start);
		//BFS 처리
		while(!que.isEmpty()) {
			int temp = que.poll();
			if(map[temp][temp] != -2) {
				sb.append(temp+" ");
				for(int k = 1; k <=node; k++) {
					if(map[temp][k] == 1) {
						map[temp][k] = 0;
						map[k][temp] = 0;
						que.add(k);
					}
				}
			}
			map[temp][temp] = -2;
		}
		sb.append("\n");
		return sb;
	}
}
