import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
	static int[]  arr;
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		arr = new int[N];
		for(int i = 0; i< N ; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		Arrays.sort(arr);
		
		int M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			if(binary_Search(Integer.parseInt(st.nextToken())))sb.append("1 ");
			else sb.append("0 ");
		}
		System.out.println(sb);
		
	}
	static boolean binary_Search(int find) {
		int pivot = (arr.length)/2+1;
		int left = 0, right = arr.length-1;
		if(find < arr[left] || arr[right]<find) return false;
		while(left<=right) {
			if(arr[pivot] == find) {
				return true;
			}
			else if(arr[pivot] > find) {
				right = pivot-1;
			}else {
				left = pivot+1;
			}
			pivot = (right+left)/2;
		}
		return false;
	}
}
