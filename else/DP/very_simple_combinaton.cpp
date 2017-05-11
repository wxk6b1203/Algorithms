#include <iostream>
using namespace std;
int M[11][11];
int Find (int st, int nd);
int main(void)
{
    int a,b;
    std::cin >> a >> b;
    Find(a, b);
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            M[i][j] = -1;
	    M[0][i] = 1;
	    M[1][i] = i;
	    M[i][i] = 1;
        }
    }
    std::cout << Find(a,b) << std::endl;
    return 0;
}

int Find(int st, int nd) {
    if (M[st][nd] < 0) {
        M[st][nd] = Find(st,nd-1) + Find(st-1,nd - 1);
    }
    return M[st][nd];
}
