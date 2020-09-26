import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int first,second;
        first = Integer.parseInt(st.nextToken());
        second = Integer.parseInt(st.nextToken());
        System.out.println(first*second/GCD(first,second));

    }
    static int GCD(int first, int second){
        int temp = 0;
        if(first<second){
            temp = first;
            first = second;
            second = temp;
        }
        while(second != 0){
            temp = first%second;
            first = second;
            second = temp;
        }
        System.out.println(first);
        return first;
    }
}