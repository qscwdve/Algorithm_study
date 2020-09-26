import java.util.*;
import java.io.*;

public class Main{
    static int N;
    static int[] chess;
    static int result;

    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        chess = new int[N];
        NQueen(0);
        System.out.println(result);

    }
    static boolean checking(int index){
        for(int i = 0; i < index; i++){
            if(chess[i] == chess[index]) return false;
            if(chess[i] == chess[index]-(index-i) || chess[i] == chess[index]+(index-i))return false;
        }
        return true;
    }
    static void NQueen(int depth){
        if(depth == N) {
            result++;
            return;
        }

        for(int i = 0; i<N;i++){
            chess[depth] = i;
            if(checking(depth)) NQueen(depth+1);
        }
    }
}