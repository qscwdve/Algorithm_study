import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
    static int[][] map;
    static int time = 0;
    static int number = 0;
    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken()), M = Integer.parseInt(st.nextToken());
        map = new int[N][M];
        String temp;
        int M2 = M*2;
        // 초기화 끝
        for (int i = 0; i < N; i++) {
            temp = br.readLine();
            for (int j = 0; j < M2; j += 2) {
                if (temp.charAt(j) - '0' == 1)
                    map[i][j / 2] = 999;
            }
        }
        // 입력 끝
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                if (map[i][j] - time > 0)
                    bfs(N, M, ++time);
        }
        System.out.println(time);
        System.out.println(number);

    }

    static void bfs( int N,  int M,  int count) {
        Queue<Point> q = new LinkedList<Point>();
        Point t;
        int x, y;
        int[] dx = { 0, 0, -1, 1 };
        int[] dy = { -1, 1, 0, 0 };
        q.add(new Point(0, 0));
        number = 0;
        while (!q.isEmpty()) {
            t = q.poll();
            for (int i = 0; i < 4; i++) {
                x = t.x + dx[i];
                y = t.y + dy[i];
                if (x >= 0 && x < M && y >= 0 && y < N) {
                    if (map[y][x] < count) {
                        q.add(new Point(x, y));
                    } else if(map[y][x] > count ) number++;
                    map[y][x] = count;
                }
            }
        }
    }
}

class Point {
    int x, y;

    Point( int X, int Y) {
        this.x = X;
        this.y = Y;
    }
}
