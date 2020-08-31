import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int loop = Integer.parseInt(br.readLine());
        int map[][] = new int[loop+1][loop+1];
        int index;
        //input
        for(int i = 0; i < loop; i++){
            index = 0;
            st = new StringTokenizer(br.readLine());
            while(st.hasMoreTokens()){
                map[i][index++] = Integer.parseInt(st.nextToken());
            }
        }

        //processing
        for(int i = 0; i < loop-1; i++){
            map[i+1][0] += Math.min(map[i][1], map[i][2]);
            map[i+1][1] += Math.min(map[i][0], map[i][2]);
            map[i+1][2] += Math.min(map[i][0], map[i][1]);
        }
        System.out.println(Math.min(map[loop-1][0],Math.min(map[loop-1][1], map[loop-1][2])));


    }
}