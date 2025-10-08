



import java.util.*;

class Pair {
    int first, second;
    public Pair(int first, int second) {
        this.first = first; this.second = second;
    }
}

class Triplet implements Comparable<Triplet> {
    int first, second, third;
    Triplet(int first, int second, int third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }

    @Override
    public int compareTo(Triplet other) {
        int cmp = Integer.compare(this.first, other.first);
        if (cmp != 0) return cmp;
        return Integer.compare(this.second, other.second);
    }
}

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        Map<Integer, ArrayList<Pair>> g = new HashMap<>();
        for (int[] flight : flights) {
            int i = flight[0], j = flight[1], cost = flight[2];
            g.computeIfAbsent(i, x -> new ArrayList<>()).add(new Pair(j, cost));
        }


        PriorityQueue<Triplet> t = new PriorityQueue<>();
        t.offer(new Triplet(0, 0, src)); //cost,stoppages,nextNode
        int[][] distances = new int[k + 2][n + 1];
        for (int i = 0; i < k + 2; ++ i) { Arrays.fill(distances[i], 1 << 30); }
        distances[0][src] = 0;

        while (!t.isEmpty()) {
            Triplet curr = t.poll();
            int currCost = curr.first, currLevel = curr.second, currNode = curr.third;

            if (currNode == dst) { return currCost; }

            if (g.containsKey(currNode) && currLevel <= k) {
                for (Pair child: g.get(currNode)) {
                    int newCost = child.second + currCost;
                    if (newCost < distances[currLevel][child.first]) {
                        distances[currLevel][child.first] = newCost;
                        t.offer(new Triplet(newCost, currLevel + 1, child.first));
                    }
                }
            }
        }

        return -1;
    }

    public static void main(String[] args) { System.out.println("------------------DONE------------------"); }
}
