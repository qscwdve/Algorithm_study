import java.io.*;
import java.util.*;

public class Main{
    static boolean[] prime;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int loop = Integer.parseInt(br.readLine());
        int result = 0;
        prime = new boolean[1001];
        eratos(1001);
        st = new StringTokenizer(br.readLine());
        while(st.hasMoreTokens()){
            if(!prime[Integer.parseInt(st.nextToken())]) result++;
        }
        System.out.println(result);
    }

    static void eratos(int N){
        prime[1] = true;
        for(int i = 2; i < N;i++){
            if(!prime[i]){
                for(int j = i*2;j<N;j+=i){
                    prime[j] = true;
                }
            }
         }
    }
}