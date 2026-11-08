#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    #ifndef ONLINE_JUDGE
        std::freopen("input.txt", "r", stdin);
        std::freopen("output.txt", "w", stdout);
    #endif

    int n, temp;
    int count = 0;
    int res = 0;
    std::cin >> n;

    // n * 3 is for loop duration
    // temp tracks current decision
    // count resets after n runs
    for (size_t i{}; i < n * 3; ++i) {
        std::cin >> temp;
        if (temp) count++;

        if ((i + 1) % 3 == 0) {
            if (count >= 2) res++;
            count = 0;
        }
    }

    std::cout << res;

    return 0;
}
