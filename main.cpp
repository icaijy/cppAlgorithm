#include <iostream>
using namespace std;
#include <vector>


class Snow {
    int rMax = 0;
    int cMax = 0;
    int xue[100][100] = {0};
    int ji[100][100] = {0};

    int deep = 0;

public:
    int snowHelper(int r, int c, int ci, int m) {
        int q = snow(r,c, ci);
        if (q>m){
            m = q;
        }
        return m;
    }
    int snow(int r,int c,int ci){
        deep++;

        if (ji[r][c]!=0){
//    		cout << "deep: " << deep-- << " num: " << xue[r][c] << "  ji[r][c] " << ji[r][c] << endl;
            return ji[r][c]+ci;
        }
    //	cout << xue[r][c] << endl;
        ci++;
        int m = 0;
        bool yes = false;
        if (r - 1 >= 0 && xue[r - 1][c] < xue[r][c]){
            yes = true;
            m = snowHelper(r - 1, c, ci, m);
        }
        if (r + 1 < rMax && xue[r + 1][c] < xue[r][c]){
            m = snowHelper(r + 1, c, ci, m);
            yes = true;
        }
        if (c - 1 >= 0 && xue[r][c - 1] < xue[r][c]){
            m = snowHelper(r, c - 1, ci, m);
            yes = true;
        }
        if (c + 1 < cMax && xue[r][c + 1] < xue[r][c]){
            m = snowHelper(r, c + 1, ci, m);
            yes = true;
        }
        if (yes==false){
//    		cout << "deep: " << deep-- << " num: " << xue[r][c] << "  ci " << ci << endl;
            ji[r][c] = 1;
            return ci;
        }
//        cout << "deep: " << deep-- << " num: " << xue[r][c] << "  m " << m << endl;
        ji[r][c] = m-ci+1;
        return m;
    }

    int snow2(int r,int c,int ci){
        deep++;

        int m,q;

        if (ji[r][c]!=0){
//    		cout << "deep: " << deep-- << " num: " << xue[r][c] << "  ji[r][c] " << ji[r][c] << endl;
            return ji[r][c]+ci;
        }
        //	cout << xue[r][c] << endl;
        ci++;
        m = 0;
        bool yes = false;
        if (r - 1 >= 0 && xue[r - 1][c] < xue[r][c]){
            yes = true;
            q = snow(r-1,c, ci);
            if (q>m){
                m = q;
            }
        }
        if (r + 1 < rMax && xue[r + 1][c] < xue[r][c]){
            q = snow(r+1,c, ci);
            yes = true;
            if (q>m){
                m = q;
            }
        }
        if (c - 1 >= 0 && xue[r][c - 1] < xue[r][c]){
            q = snow(r,c-1,ci);
            yes = true;
            if (q>m){
                m = q;
            }
        }
        if (c + 1 < cMax && xue[r][c + 1] < xue[r][c]){
            q = snow(r,c+1,ci);
            yes = true;
            if (q>m){
                m = q;
            }
        }
        if (yes==false){
//    		cout << "deep: " << deep-- << " num: " << xue[r][c] << "  ci " << ci << endl;
            return ci;
        }

        ji[r][c] = m-ci+1;

//        cout << "deep: " << deep-- << " num: " << xue[r][c] << "  m " << m << endl;
        return m;
    }

    int run(){
        cin >> rMax >> cMax;
        for (int i = 0; i < rMax; i++)
        {
            for (int j = 0; j < cMax; j++)
            {

                scanf("%d",&xue[i][j]);
            }
        }
        int m = 0;
        for (int r = 0; r < rMax; r++){
            for (int c = 0;c < cMax; c++){
                int temp = snow(r,c,0);
                if (m < temp){
                    m = temp;
                }
            }
        }
        cout << m;
        return 0;
    }
};
//////////////////////////////////////


class DFS {
    int a[10] = {0,0,0,0,0,0,0,0,0,0};
    int c[10] = {0,0,0,0,0,0,0,0,0,0};
    int b = 2;
public:
    void dfs(int n){
        if (n==b){
            for (int i = 0;i<b;i++){
                cout << c[i];
            }
            cout << endl;
            return;
        }
        for (int i=0;i<b;i++){
            if (a[i]==0){
                c[n] = i+1;
                a[i] = 1;
                dfs(n+1);
                a[i] = 0;
            }
        }
        return;
    }
};

int main(){

    Snow().run();
    return 0;

    DFS().dfs(0);

}
