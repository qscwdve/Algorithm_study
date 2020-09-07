import java.util.*;
import java.io.*;

public class Main{
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int loop = Integer.parseInt(br.readLine());
        int[] distance = new int[loop];
        int[] colonnade = new int[loop];
        int temp;
        int distan = 999999999;
        int result = 0;
        for(int i = 0; i < loop; i++){
            colonnade[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(colonnade);
        for(int j = 0; j< loop-1; j++){
            distance[j] = colonnade[j+1] - colonnade[j];
        }
        for(int k = 0; k<loop-2; k++){
            temp = GCD(distance[k], distance[k+1]);
            if(temp < distan) distan = temp;
        }
        for(int x = 0; x <loop-1; x++){
            result += distance[x]/distan - 1;
        }
        System.out.println(result);
    }
    static int GCD(int a, int b){
        if(b == 0) return a;
        int r;
        if(a < b){
            r = a;
            a = b;
            b = r;
        }
        while(b != 0){
            r = a%b;
            a = b;
            b = r;
        }
        return a;
    }
}