package BOJ_1932;
import java.io.*;
import java.util.*;

public class Main{
    public static void main(String [] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int loop = Integer.parseInt(br.readLine());
        int tri_angle[][] = new int[loop+1][loop+1];
        int index = 0;
        //ют╥б
        for(int i = 0; i < loop;i++){
            index = 0;
            st = new StringTokenizer(br.readLine());
            while(st.hasMoreTokens()){
                tri_angle[i][index++] = Integer.parseInt(st.nextToken());
            }
        }
        //bottom up
        for(int j = loop-2; j>=0;j--){
            for(int k = 0; k <= j; k++){
                tri_angle[j][k] += Math.max(tri_angle[j+1][k], tri_angle[j+1][k+1]);
            }
        }
        
        System.out.println(tri_angle[0][0]);

    }
}