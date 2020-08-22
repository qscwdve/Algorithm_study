import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;


public class Main {
	static boolean map[][];
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		int N, M;
		String temp;
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new boolean[N][M];
		
		for(int i=0;i<N;i++) {
			temp = br.readLine();
			for(int j=0;j<M;j++) {
				if(temp.charAt(j) - '0' == 1) map[i][j] = true;
			}
		}
		BFS(N-1,M-1);
		
		
	}
	
	static void BFS(int N, int M) {
		Queue<Node> que = new LinkedList<Node>();
		que.add(new Node(0,0,1));
		map[0][0] = false;
		while(!que.isEmpty()) {
			Node temp = que.poll();
			if(temp.x == M && temp.y == N) {
				System.out.println(temp.time);
			}
			//상
			if(temp.y > 0 && map[temp.y-1][temp.x]) {
				map[temp.y-1][temp.x] = false;
				que.add(new Node(temp.x,temp.y-1,temp.time+1));
			}
			//하
			if(temp.y < N && map[temp.y+1][temp.x]) {
				map[temp.y+1][temp.x] = false;
				que.add(new Node(temp.x,temp.y+1,temp.time+1));
			}
			//좌
			if(temp.x > 0 && map[temp.y][temp.x-1]) {
				map[temp.y][temp.x-1] = false;
				que.add(new Node(temp.x-1,temp.y,temp.time+1));
			}
			//우
			if(temp.x < M && map[temp.y][temp.x+1]) {
				map[temp.y][temp.x+1] = false;
				que.add(new Node(temp.x+1,temp.y,temp.time+1));
			}
		}
	}
}

class Node{
	int x;
	int y;
	int time;
	Node(int X, int Y, int Time){
		x = X;
		y = Y;
		time = Time;
	}
}
