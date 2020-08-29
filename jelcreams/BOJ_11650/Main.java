import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
public class Main{
    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        List<Point> point = new ArrayList<>();
        int N = Integer.parseInt(br.readLine());
        int x,y;
        while(N-->0){
            st = new StringTokenizer(br.readLine());
            x = Integer.parseInt(st.nextToken());
            y = Integer.parseInt(st.nextToken());
            point.add(new Point(x,y));
        }
        Collections.sort(point);
        for(Point p : point){
            sb.append(p.x+" "+p.y+'\n');
        }
        System.out.println(sb);
    }
}

class Point implements Comparable<Point>{
    int x,y;
    Point(int X,int Y){
        this.x = X;
        this.y = Y;
    }
    public int compareTo(Point s){
        if(this.x > s.x) return 1;
        else if(this.x < s.x) return -1;
        else{
            if(this.y > s.y) return 1;
            else if(this.y < s.y) return -1;
            else return 0;
        }
    }
}
