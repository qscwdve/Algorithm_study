import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import java.util.Queue;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int check, loop;

        Queue<Integer> que = new LinkedList<Integer>();

        String[] str = br.readLine().split(" ");
        String result = "<";

        loop = Integer.parseInt(str[0]);
        check = Integer.parseInt(str[1]);

        for(int i =1;i<=loop;i++){
            que.add(i);
        }

        while(!que.isEmpty()){
            for(int j = 0; j<check-1;j++){
                que.add(que.poll());
            }
            result+=que.poll()+", ";
        }

        bw.write(result.substring(0,result.length()-2)+">");
        bw.flush();
        bw.close();
        br.close();
    }
}
