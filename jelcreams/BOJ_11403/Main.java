import java.io.*;
import java.util.*;
public class Main {
	static boolean memo[][];
	static int count = 0;
	public static void main(String [] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int size = Integer.parseInt(br.readLine());
		Graph gr = new Graph(size);
		String temp;
		memo = new boolean[size][size];
		
		for(int i = 0;i < size; i++) {
			temp = br.readLine();
			for(int j = 0; j< size; j++) {
				if(temp.charAt(j*2) - '0' == 1) {
					gr.putSingle(i, j);
				}
			}
		}
		for(int k = 0; k < size; k++) {
			BFS(gr, k);
		}
		
		for(int i = 0 ; i < size; i++) {
			for(int j = 0 ; j < size; j++) {
				if(memo[i][j])bw.append("1 ");
				else bw.append("0 ");
			}
			bw.append("\n");
		}
		bw.flush();
		
	}
	
	static void BFS(Graph gr, int start) {
		boolean[] mem = new boolean[gr.size];
		Queue<Integer> que = new LinkedList<Integer>();
		que.add(start);
		int node;
		ArrayList<Integer> temp;
		while(!que.isEmpty()) {
			node = que.poll();
			temp = gr.getNode(node);
			for(int i = 0; i<temp.size();i++) {
				if(!mem[temp.get(i)]) {
					mem[temp.get(i)] = true;
					que.add(temp.get(i));
				}
				// memo[start][temp.get(i)] = true;
			}
		}
        for(int k = 0; k < gr.size; k++)if(mem[k])memo[start][k] =true;
	}
		
}


class Graph{
	ArrayList<ArrayList<Integer>> graphList;
	int size;
	Graph(int size){
		this.size = size;
		this.graphList = new ArrayList<ArrayList<Integer>>();
		for(int i = 0 ; i < size+1;i++) {
			this.graphList.add(new ArrayList<Integer>());
		}
	}
	ArrayList<Integer> getNode(int index) {
		return this.graphList.get(index);
	}
	void put(int node1, int node2) {
		graphList.get(node1).add(node2);
		graphList.get(node2).add(node1);
	}
	void putSingle(int node1,int node2) {
		graphList.get(node1).add(node2);
	}
	void printGraphAdjList() {
		for(int i = 1; i < graphList.size();i++) {
			System.out.print(i+" -> ");
			for(int j = 0; j < graphList.get(i).size();j++) {
				System.out.print(graphList.get(i).get(j)+" ");
			}
			System.out.println("");
		}
	}
}
