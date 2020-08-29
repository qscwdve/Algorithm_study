import java.io.*;
import java.util.*;
public class Main {
    static boolean map[][];
    static int number = 0;
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();
        int test_case = Integer.parseInt(br.readLine());
        int M, N, cabage;
        int X,Y;
        while(test_case-->0){
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            N = Integer.parseInt(st.nextToken());
            cabage = Integer.parseInt(st.nextToken());
            map = new boolean[N][M];
            while(cabage-->0){
                st = new StringTokenizer(br.readLine());
                X = Integer.parseInt(st.nextToken());
                Y = Integer.parseInt(st.nextToken());
                map[Y][X] = true;
            }
            for(int i = 0; i<N ;i++){
                for(int j = 0; j<M; j++){
                    if(map[i][j])bfs(j,i,N,M);
                }
            }
            sb.append(number+"\n");
            number = 0;
        }
        System.out.println(sb);
    }
    static void bfs(int X, int Y, int N, int M){
        Queue<XY> q = new LinkedList<XY>();
        map[Y][X] = false;
        int[] dx = {0,0,1,-1};
        int[] dy = {-1,1,0,0};
        XY t;
        q.add(new XY(X,Y));
        number++;
        while(!q.isEmpty()){
            t = q.poll();
            for(int i = 0;i < 4; i++){
                int x = t.x + dx[i];
                int y = t.y + dy[i];
                if(x>=0 && x<M && y>=0 && y<N){
                    if(map[y][x]){
                        q.add(new XY(x,y));
                        map[y][x] = false;
                    }
                }
            }

        }
    }
}
class XY{
    int x;
    int y;
    XY(int X, int Y){
        this.x = X;
        this.y = Y;
    }
}
