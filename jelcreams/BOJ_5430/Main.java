import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Deque<Integer> dq;
		StringTokenizer st;
		StringBuilder sb;
		int test_case, array_length;
		char[] function_array;
		boolean check, check2;
		int deque_size = 0;
		test_case = Integer.parseInt(br.readLine());
		
		while(test_case-->0) {
			check = true;
			check2 = false;
			sb = new StringBuilder();
			dq = new LinkedList<Integer>();
			function_array = br.readLine().toCharArray();
			array_length = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine(),"[,]");
			
			while(array_length-->0) {
				dq.add(Integer.parseInt(st.nextToken()));
			}
			
			for(int i =0 ; i < function_array.length;i++) {
				if(function_array[i] == 'R') {
					check = !check;
				}
				else {
					if(dq.isEmpty()) {
						System.out.println("error");
						check2 = true;
						break;
					}
					else {
						if(check)dq.pollFirst();
						else dq.pollLast();
					}
				}
			}
			deque_size = dq.size();
			if(check2) continue;
			sb.append("[");
			for(int j = 0;j<deque_size;j++) {
				if(check)sb.append(dq.pollFirst());
				else sb.append(dq.pollLast());
				if(j+1 == deque_size)break;
				else sb.append(",");
			}
			sb.append("]");
			System.out.println(sb);
		}
		
	}
}
