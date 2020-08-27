import java.io.*;
import java.util.*;
public class Main {
    static boolean map[][][];
    public static void main(String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String temp;
        int N, M;
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        map = new boolean[2][N][M];
        //초기화 끝

        //map 입력
        for(int i = 0 ; i < N; i++){
            temp = br.readLine();
            for(int j = 0; j < M; j++){
                if(temp.charAt(j)-'0' == 0){
                    map[1][i][j] = true;
                    map[0][i][j] = true;
                }
            }
        }
        //map입력 끝

        //BFS 처리
        System.out.println(bfs(N,M,1));
                
    }


    static int bfs(int N, int M, int count){
        Queue<NodeXY> q = new LinkedList<NodeXY>();
        int n = N-1;
        int m = M-1;
        NodeXY cur;
        int x, y, c, chan;
        map[0][0][0] = false;
        map[1][0][0] = false;
        q.add(new NodeXY(0,0,count,1));
        while(!q.isEmpty()){
            cur = q.poll();
            x = cur.x;
            y = cur.y;
            c = cur.count;
            chan = cur.chance;
            if(x == m && y == n)return c;
            //상
            if(chan>0){
                if(y>0 && !map[chan][y-1][x])q.add(new NodeXY(x,y-1,c+1,chan-1));
                if(y<n && !map[chan][y+1][x])q.add(new NodeXY(x,y+1,c+1,chan-1));
                if(x>0 && !map[chan][y][x-1])q.add(new NodeXY(x-1,y,c+1,chan-1));
                if(x<m && !map[chan][y][x+1])q.add(new NodeXY(x+1,y,c+1,chan-1));
            }
            if(y>0&&map[chan][y-1][x]){
               q.add(new NodeXY(x,y-1,c+1,chan));
               map[chan][y-1][x] = false;
            }
            //하
            if(y<n&&map[chan][y+1][x]){
                q.add(new NodeXY(x,y+1,c+1,chan));
                map[chan][y+1][x] = false;
            }
            //좌
            if(x>0&&map[chan][y][x-1]){
                q.add(new NodeXY(x-1,y,c+1,chan));
                map[chan][y][x-1] = false;
            }
            //우
            if(x<m&&map[chan][y][x+1]){
                q.add(new NodeXY(x+1,y,c+1,chan));
                map[chan][y][x+1] = false;
            }

        }
        return -1;
    }
}
class NodeXY{
    int x;
    int y;
    int count;
    int chance;
    NodeXY(int X, int Y, int Count, int Chance){
        this.x = X;
        this.y = Y;
        this.count = Count;
        this.chance = Chance;
    }
}
