import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import java.util.*;

public class Main {
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        
        Queue<Node> que;

        int test_case = Integer.parseInt(br.readLine());
        int N,M,result;
        //N 총 개수, M 몇 번째로 나오는지 궁금한 M번 문서
        int[] pri_list;
        Node temp;

        while(test_case-->0){
            result = 0;
            pri_list = new int[10];
            que = new LinkedList<Node>();
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            
            for(int i = 0 ; i<N;i++){
                int pri = Integer.parseInt(st.nextToken());
                pri_list[pri]++;
                que.add(new Node(i,pri));
            }

            for(int j = 9;j>0;j--){
                while(pri_list[j] != 0){
                    temp = que.poll();
                    if(temp.pri != j) que.add(temp);
                    else {
                        result++;
                        pri_list[j]--;
                        if(temp.index == M){
                            j = 0;
                            bw.write(result+"\n");
                            bw.flush();
                            break;
                        }
                    }
                }
            }
            
        }
    }
}
class Node{
    int index;
    int pri;
    Node(int i , int p){
        index =i;
        pri = p;
    }
}
