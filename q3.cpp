#include <bits/stdc++.h>
using namespace std;

int AcharArea(const vector<vector<int>>& sala, int K) {
    int R = sala.size();
    int C = sala[0].size();
    int min_area = INT_MAX;

    for (int top = 0; top < R; ++top) {
        vector<int> col_sums(C, 0); 

        for (int bottom = top; bottom < R; ++bottom) {
            for (int col = 0; col < C; ++col)
                col_sums[col] += sala[bottom][col];

            int sum = 0, left = 0;
            for (int right = 0; right < C; ++right) {
                sum += col_sums[right];
                while (sum >= K) {
                    int width = right - left + 1;
                    int height = bottom - top + 1;
                    if (width * height < min_area) {
                        min_area = width * height;
                    }
                    sum -= col_sums[left++];
                }
            }
        }
    }

    return min_area;
}

int main() {
    while (true) {
        int R, C, K;
        cin >> R >> C >> K;
        if (R == 0 && C == 0 && K == 0) break;

        vector<vector<int>> sala(R, vector<int>(C));
        char ch;

        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                cin >> ch;
                if (ch == '.') {
                    sala[i][j] = 1;
                } else {
                    sala[i][j] = 0;
                }
            }
        }

        int res = AcharArea(sala, K);
        cout << res << "\n";
    }

    return 0;
}
