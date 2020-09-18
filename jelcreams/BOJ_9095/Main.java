import java.util.*;
import java.io.*;

public class Main{
    static int memoization[];
    public static void main(String[]args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        memoization = new int[12];
        memoization[1] = 1;
        memoization[2] = 2;
        memoization[3] = 4;
        for(int i = 4; i<12;i++)memoization[i] = memoization[i-1]+memoization[i-2]+memoization[i-3];
        for(int i = 0; i < cases; i++){
            sb.append(memoization[Integer.parseInt(br.readLine())]+"\n");
        }
        System.out.println(sb);
    }
    
}