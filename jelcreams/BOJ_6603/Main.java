import java.util.*;
import java.io.*;

public class Main{
    public static void main(String [] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        StringTokenizer st;
        int loop = -1;
        int index;
        while(loop != 0){
            sb = new StringBuilder();
            st = new StringTokenizer(br.readLine());
            loop = Integer.parseInt(st.nextToken());
            int[] array = new int[loop];
            index = 0;
            while(st.hasMoreTokens()){
                array[index++] = Integer.parseInt(st.nextToken());
            }
            recursion(array, new int[6], 0, loop, 6,0, sb);
            System.out.println(sb);

        }

    }
    static void recursion(int [] array,int[] maked, int start, int end, int depth, int cur,StringBuilder sb){
        int [] temp = maked.clone(); 
        if(start > end) return;
        if(cur == depth){
            for(int i = 0; i<6; i++)sb.append(maked[i]+" ");
            sb.append("\n");
            return;
        }
        for(int i = start; i < end; i++){
            temp[cur] = array[i];
            recursion(array, temp, i+1, end, depth, cur+1,sb);
        }
    }

}