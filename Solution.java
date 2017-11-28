import java.util.ArrayList;

public class Solution {
    private static int tetri_count = 0;

    private char map[][];
    private int map_size;
    private ArrayList<Tetrimino> list = new ArrayList();

    private Solution() {
        initTetriList2();
        map_size = getMapSize();
    }

    private void initTetriList2()
    {
        int [][] tetri_map1 = new int[][] {{1,1},
                {1,1}};
        list.add(new Tetrimino(tetri_map1));
        list.add(new Tetrimino(tetri_map1));
        list.add(new Tetrimino(tetri_map1));
        list.add(new Tetrimino(tetri_map1));
        list.add(new Tetrimino(tetri_map1));
        list.add(new Tetrimino(tetri_map1));
        list.add(new Tetrimino(tetri_map1));
        list.add(new Tetrimino(tetri_map1));
        list.add(new Tetrimino(tetri_map1));
        list.add(new Tetrimino(tetri_map1));
       /* int [][] tetri_map2 = new int[][] {{1,1,1,1}};
        list.add(new Tetrimino(tetri_map2));
        list.add(new Tetrimino(tetri_map2));
        list.add(new Tetrimino(tetri_map2));
        list.add(new Tetrimino(tetri_map2));
        list.add(new Tetrimino(tetri_map2));
        list.add(new Tetrimino(tetri_map2)); */
        int [][] tetri_map6 = new int[][] {{1,1,0},
                {0,1,1}};
        //list.add(new Tetrimino(tetri_map6));
    };

    private void initTetriList1()
    {
        int [][] tetri_map1 = new int[][] {{1},
                                           {1},
                                           {1},
                                           {1}};
        list.add(new Tetrimino(tetri_map1));
        int [][] tetri_map2 = new int[][] {{1,1,1,1}};
        list.add(new Tetrimino(tetri_map2));
        int [][] tetri_map3 = new int[][] {{1,1,1},
                                           {0,0,1}};
        list.add(new Tetrimino(tetri_map3));
        int [][] tetri_map4 = new int[][] {{0,1,1},
                                           {1,1,0}};
        list.add(new Tetrimino(tetri_map4));
        int [][] tetri_map5 = new int[][] {{1,1},
                                           {1,1}};
        list.add(new Tetrimino(tetri_map5));
        int [][] tetri_map6 = new int[][] {{1,1,0},
                                           {0,1,1}};
        list.add(new Tetrimino(tetri_map6));
        int [][] tetri_map7 = new int[][] {{1,1},
                                           {0,1},
                                           {0,1}};
        list.add(new Tetrimino(tetri_map7));
        int [][] tetri_map8 = new int[][] {{1,1,1},
                                           {0,1,0}};
        list.add(new Tetrimino(tetri_map8));
        list.add(new Tetrimino(tetri_map4));
        list.add(new Tetrimino(tetri_map3));
        list.add(new Tetrimino(tetri_map4));
        list.add(new Tetrimino(tetri_map3));
    }

    private boolean checkPosition(Tetrimino tetri, int y,int x) {
        for (int i = 0; i < tetri.y; i++) {
            for (int j = 0; j < tetri.x; j++) {
                if (i + y >= map_size || x + j >= map_size ) {
                    return false;
                }
                if (map[i + y][j + x] != 0 && tetri.map[i][j] != 0) {
                    return false;
                }
            }
        }
        return true;
    }

    private void addTetri(Tetrimino tetri, int y, int x) {
        for (int i = 0; i < tetri.y; i++) {
            for (int j = 0; j < tetri.x; j++) {
                if (tetri.map[i][j] != 0)
                    map[y + i][x + j] = tetri.c;
            }
        }
        printMap();
        System.out.println();
    }

    private void printMap(){
        for (int i = 0; i < map_size; i++) {
            for (int j = 0; j < map_size; j++)
                System.out.print(map[i][j]);
            System.out.println();
        }
    }

    private void removeTetri(Tetrimino tetri) {
        for (int i = 0; i < map_size; i++) {
            for (int j = 0; j < map_size; j++) {
                if (map[i][j] == tetri.c)
                    map[i][j] = 0;
            }
        }
    }

    private boolean solve(int k) {
        if (list.size() > k) {
            Tetrimino tetri = list.get(k);
            for (int i = 0; i <= map_size - tetri.y; i++) {
                for (int j = 0; j <= map_size - tetri.x; j++)
                {
                    if (checkPosition(tetri, i, j))
                    {
                        addTetri(tetri, i, j);
                        if (solve(k + 1))
                            return true;
                        else {
                            removeTetri(tetri);
                        }
                    }
                }
            }
            return false;
        }
        else
            return true;
    }

    private int getMapSize() {
        int i;
        for (i = 2; i * i < list.size() * 4; i++) {}
        return i;
    }

    private char[][] initMap() {
        return new char[map_size][map_size];
    }

    private void start() {
        map = initMap();
        if (!solve(0)) {
            map_size++;
            start();
        }
    }

    private class Tetrimino {
        private int map[][];
        private char c = 'A';
        private int y;
        private int x;

        public Tetrimino(int map[][]) {
            this.map = map;
            c += tetri_count;
            tetri_count++;
            y = map.length;
            x = map[0].length;
        }

        private void printTetri() {
            for (int i = 0; i < y; i++) {
                for (int j = 0; j < x; j++)
                    System.out.print(map[i][j]);
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        long start = System.currentTimeMillis();
        solution.start();
        System.out.println(System.currentTimeMillis() - start);
        solution.printMap();
    }
}
