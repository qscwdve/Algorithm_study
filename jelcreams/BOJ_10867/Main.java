import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] arr = new boolean[2001];
        StringBuilder sb = new StringBuilder();
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        while(st.hasMoreTokens()){
            arr[Integer.parseInt(st.nextToken())+1000] = true;
        }
        for(int i = 0;i<2001;i++)if(arr[i])sb.append((i-1000)+" ");
        sb.append('\n');
        System.out.println(sb);
    }
}
