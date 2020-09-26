import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
public class Main{
    static int memo[];
    static int result[][];

    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int temp = Integer.parseInt(br.readLine());
        memo = new int[temp+1];
        result = new  int[temp+1][3];
        int index = 1;
        while(temp-->0){
            memo[index++] = Integer.parseInt(br.readLine());
        }
        System.out.println(dynamic(0,index-1, 0));
    }
    static int dynamic(int start,int max, int count){
        int number1=0,number2=0;

        if(result[start][count] > 0) return result[start][count];

        if(start == max) return result[start][count] = memo[start];

        if(start + 2 <= max) number1 =  dynamic(start + 2, max, 1);

        if(count+1 < 3) number2 = dynamic(start+1,max,count+1);
        
        if(number1 != 0 || number2 != 0)
            return result[start][count] = memo[start] + Math.max(number1,number2);
        return 0;
    }
}
