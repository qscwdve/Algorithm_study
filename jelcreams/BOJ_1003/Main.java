import java.io.*;
import java.util.*;

public class Main {
    static int memo[][];
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb;
        memo = new int[2][41];
        int loop = Integer.parseInt(br.readLine());
        int oper;
        sb = new StringBuilder();
        while(loop-- > 0){
            oper = Integer.parseInt(br.readLine());
            fibonacci(oper);
            sb.append(memo[0][oper] +" "+ memo[1][oper]+"\n");
        }
        System.out.println(sb);
    }
    static void fibonacci(int n){
        if(memo[0][n] > 0 && memo[1][n] > 0){
            return;
        }
        if(n == 0){
            memo[0][0] = 1; memo[1][0] = 0;
        }
        else if( n == 1) {
            memo[1][1] = 1; memo[1][1] = 1;
        }
        else{
            fibonacci(n-1);
            fibonacci(n-2);
            memo[0][n] = memo[0][n-1] + memo[0][n-2];
            memo[1][n] = memo[1][n-1] + memo[1][n-2];
        }
    }

}
