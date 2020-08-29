import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
public class Main{
    static int memo[];
    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int temp = Integer.parseInt(br.readLine());
        memo = new int[temp+1];
        System.out.println(making(temp, 0));

    }
    //top-down
    static int making(int n, int time){
        int n1 = 10000001, n2 =11000001;
        if(memo[n] > 0 && time >= memo[n]) return memo[n];
        if(n == 1) return memo[1] = time;
        else {
            if(n%3 == 0) n1 = making(n/3, time+1);
            if(n%2 == 0) n2 = making(n/2, time+1);
            memo[n] = Math.min(making(n-1, time+1),Math.min(n1, n2));
            return memo[n];
        }
    }
}
