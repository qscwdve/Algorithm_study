import java.util.*;



import java.io.*;

public class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int target = Integer.parseInt(br.readLine());
        int [] prime_number = new int[target+1];
        boolean is_prime = true;
        int start, end;
        int k = 0;
        for(int i = 2; i <= target;i++){
            is_prime = true;
            for(int j = 2 ; j <= Math.sqrt(i);j++){
                if(i%j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if(is_prime) prime_number[k++] = i;
        }
        System.out.println(k);
    }
}