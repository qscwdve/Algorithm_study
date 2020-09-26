import java.io.*;
import java.util.*;
public class Main {
	static boolean memo[];
	public static void main(String [] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		
		int computers = Integer.parseInt(br.readLine()); //컴퓨터 수
		int edge = Integer.parseInt(br.readLine()); // 이어진 간선 수
		Graph gr = new Graph(computers); //인접 그래프 사용
		int root, node;
		
		memo = new boolean[computers+1]; // 방문 체크용
		
		for(int i = 0 ; i<edge ; i++) {
			st = new StringTokenizer(br.readLine());
			while(st.hasMoreTokens()) {
				root = Integer.parseInt(st.nextToken());
				node = Integer.parseInt(st.nextToken());
				gr.put(root, node); //양방향으로 노드 연결
			}
		}
		System.out.println(BFS(gr));
	}
	
	static int BFS(Graph gr) {
		int result = 0;
		Queue<Integer> List = new LinkedList<Integer>();
		ArrayList<Integer> temp;
		
		List.add(1);
		int node;
		while(!List.isEmpty()) {
			node = List.poll();
			if(!memo[node]) {
				memo[node] = true;result++;
				temp = gr.getNode(node);
				for(int i = 0 ; i < temp.size(); i++) {
					if(!memo[temp.get(i)])List.add(temp.get(i));
				}
				temp.clear();
			}
			
		}
		
		return result-1;
	}
}


class Graph{
	ArrayList<ArrayList<Integer>> graphList;
	
	Graph(int size){
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
