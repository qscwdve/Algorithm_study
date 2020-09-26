
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

import java.io.IOException;

import java.util.Stack;

public class Main {
    public static void main(String[] args)throws IOException{
        Stack<Character> stac = new Stack<Character>();
        Stack<Character> fistac = new Stack<Character>();

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        String temp = br.readLine();
        for(int i = 0;i<temp.length();i++){
            stac.push(temp.charAt(i));
        }

        bw.flush();
        int loop = Integer.parseInt(br.readLine());

        while(loop-->0){
            temp = br.readLine();

            switch(temp){
                case "L":
                    if(stac.isEmpty())break;
                    else fistac.push(stac.pop());
                break;

                case "D":
                    if(fistac.isEmpty())break;
                    else stac.push(fistac.pop());
                break;

                case "B":
                    if(stac.isEmpty())break;
                    else stac.pop();
                break;

                default:
                    stac.push(temp.charAt(2));
            }
        }

        while(!stac.isEmpty())fistac.push(stac.pop());
        while(!fistac.isEmpty())bw.write(fistac.pop());

        bw.flush();
        bw.close();
        br.close();
    }
}
