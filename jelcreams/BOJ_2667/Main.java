import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;


public class Main {
	static int result = 0;
	static int[] Building;
	static int[][] map;
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		Queue<Node> que = new LinkedList<Node>();
		int N = Integer.parseInt(br.readLine());
		String temp;
		int max_size = N*N/2+1;
		map = new int[N][N];
		Building = new  int[max_size];
		
		for(int i = 0; i<N; i++) {
			temp = br.readLine();
			for(int j = 0 ; j < N ; j++) {
				map[i][j] = temp.charAt(j) - '0';
			}	
		}
		
		for(int i = 0 ; i <N ;i++) {
			for(int k = 0; k <N ;k++) {
				if(map[i][k] == 1) BFS(k,i,N-1);
			}
		}
		sb.append(result+"\n");
		Arrays.sort(Building);
		for(int r = max_size-result ; r < max_size; r++) {
			sb.append(Building[r]+"\n");
		}
		System.out.println(sb);
	}
	
	
	static void BFS(int x, int y, int max) {
		StringBuilder sb = new StringBuilder();
		Queue<Node> que = new LinkedList<Node>();
		int buildings = 0;
		
		que.add(new Node(x,y));
		while(!que.isEmpty()) {
			Node temp = que.poll();
			if(map[temp.getY()][temp.getX()] == 1) {
				map[temp.getY()][temp.getX()] = 0;
				buildings++;
				//상
				if(temp.getY()>0&&map[temp.getY()-1][temp.getX()] == 1) {
					que.add(new Node(temp.getX(), temp.getY()-1));
				}
				//하
				if(temp.getY()<max && map[temp.getY()+1][temp.getX()] == 1) {
					que.add(new Node(temp.getX(),temp.getY()+1));
				}
				//좌
				if(temp.getX()>0&& map[temp.getY()][temp.getX()-1] == 1) {
					que.add(new Node(temp.getX()-1,temp.getY()));
				}
				//우
				if(temp.getX()<max && map[temp.getY()][temp.getX()+1] == 1) {
					que.add(new Node(temp.getX()+1,temp.getY()));
				}
			}
		}
		Building[result] = buildings;
		result++;;
	}
}
class Node{
	private int x,y;
	Node(int X, int Y){
		x = X;
		y = Y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
}
