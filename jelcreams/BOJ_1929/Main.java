import java.io.*;
import java.util.*;

public class Main{
    static boolean[] eratos;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int start, end;
        start = Integer.parseInt(st.nextToken());
        end = Integer.parseInt(st.nextToken());

        eratos = new boolean[end+1];

        eratos_set(end);

        for(int i = start; i<=end;i++){
            if(!eratos[i])sb.append(i+"\n");
        }

        System.out.println(sb);
    }

    static void eratos_set(int N){
        eratos[1] = true;
        for(int i = 2; i <= N ;i++){
            if(!eratos[i]){
                for(int j = i*2; j<=N;j+=i) eratos[j] = true;
            }
        }
    }
}