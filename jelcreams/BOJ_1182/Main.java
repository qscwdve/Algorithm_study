import java.util.*;
import java.io.*;

public class Main{
    static int numbers[];
    static int result;
    static int target;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int number;
        number = Integer.parseInt(st.nextToken());
        target = Integer.parseInt(st.nextToken());
        numbers = new int[number];
        result  = 0;
        st = new StringTokenizer(br.readLine());
        for(int i = 0 ; i < number; i++){
            numbers[i] = Integer.parseInt(st.nextToken());
        }
        recursion(0,number,0);
        System.out.println(result);
    }
    static void recursion(int start, int end, int sum){
        for(int i = start; i<end; i++){
            if(sum+numbers[i] == target){
                System.out.println(start +" "+end+" "+sum);
                result++;
            }
            recursion(i+1, end, sum+numbers[i]);
        }
    }
}