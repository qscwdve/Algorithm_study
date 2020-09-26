import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;
public class Main{
    public static void main(final String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        String pre;
        List<Problem> al = new ArrayList<>();
        while(N-->0){
            al.add(new Problem(br.readLine()));
        }
        Collections.sort(al);
        
        pre = al.get(0).str;
        for(Problem st : al){
            if(pre.equals(st.str)) continue; 
            else{
                sb.append(pre+'\n');
                pre = st.str;
            }
        }
        sb.append(al.get(al.size()-1).str);
        System.out.println(sb);
    }
}
class Problem implements Comparable<Problem>{
    String str;
    Problem(String s){
        this.str = s;
    }
    public int compareTo(Problem s){
        if(this.str.length() > s.str.length()) return 1;
        else if(this.str.length() < s.str.length()) return -1;
        else{
            if(this.str.compareTo(s.str)>0) return 1;
            else if(this.str.compareTo(s.str)<0) return -1;
            else return 0;
        }
    }
}
