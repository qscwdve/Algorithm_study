import java.io.*;
import java.util.*;

public class Main{
    static boolean [] map = new boolean[2000001];
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        long loop = Long.parseLong(br.readLine());
        long a, b, sum;
        for(int j = 0 ; j < loop; j++){
            st = new StringTokenizer(br.readLine());
            a = Long.parseLong(st.nextToken());
            b = Long.parseLong(st.nextToken());
            sum = a+b;
            if(sum<4)System.out.println("NO");
            if(sum%2 == 0) System.out.println("YES");

           
            System.out.println("NO");
        }

    }
    static void prime(long target){
        for(int i = 2; i<target;i++){
            for(int j = i*i; j<target;j++){
            }
        }
    }
    static boolean primecheck(long target){
        for(long i = 2; i <= Math.sqrt(target); i++){
            if(target%i == 0) return false;
        }
        return true;
    }
}