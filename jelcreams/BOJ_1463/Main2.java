import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
public class Main{
    static boolean memo[];
    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int temp = Integer.parseInt(br.readLine());
        memo = new boolean[temp+1];
        System.out.println(making(temp, 0));

    }
    //BFS
    static int making(int n, int time){
        Queue<Point> que = new LinkedList<Point>();
        que.add(new Point(n, time));
        Point temp = new Point(n, time);
        while(!que.isEmpty()){
            temp = que.poll();

            if(temp.index == 1) break;
            

            if(temp.index%3 == 0 && !memo[temp.index/3]){
                que.add(new Point(temp.index/3, temp.count+1));
                memo[temp.index/3] = true;
            }
            if(temp.index%2 == 0 && !memo[temp.index/2]){
                que.add(new Point(temp.index/2, temp.count+1));
                memo[temp.index/2] = true;
            } 
            que.add(new Point(temp.index-1, temp.count+1));
            memo[temp.index -1] = true;
        }
        return temp.count;
    }
}
class Point{
    int count;
    int index;
    Point(int i, int c){
        this.index = i;
        this.count = c;
    }
}
