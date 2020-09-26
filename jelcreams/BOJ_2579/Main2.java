import java.io.*;

public class Main2{
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int loop = Integer.parseInt(br.readLine());
        int stair[] = new int[301];
        int result[] = new int[301];
        for(int i = 1 ; i <= loop;i++)stair[i] = Integer.parseInt(br.readLine());
        result[1] = stair[1];
        result[2] = stair[2]+stair[1];
        for(int j = 3; j <= loop; j++){
            result[j] =  max(result[j-3] + stair[j-1] + stair[j], result[j-2]+ stair[j]);
        }
        System.out.println(result[loop]);
    }
    static int max(int a, int b){
        return a > b ? a : b;
    }
}