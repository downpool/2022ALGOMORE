package week7;

import java.util.*;

class UnionFind {
    private int[] parent;
    public UnionFind(int n) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    public int Find(int x) {
        if (x == parent[x]) {
            return x;
        }
        // compress the paths
        return parent[x] = Find(parent[x]);
    }
    public void Union(int x, int y) {
        int px = Find(x);
        int py = Find(y);
        if (px != py) {
            parent[px] = py;
        }
    }
    public int size() { // number of groups
        int ans = 0;
        for (int i = 0; i < parent.length; ++i) {
            if (i == parent[i]) ans++;
        }
        return ans;
    }
}


public class sol{
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int M = scan.nextInt(); scan.nextLine();
        UnionFind uf = new UnionFind(N);
        for(int i = 0; i < M; i++){
            int a, b, c;
            a = scan.nextInt(); b = scan.nextInt(); c = scan.nextInt(); scan.nextLine();
            
        }
    }
}