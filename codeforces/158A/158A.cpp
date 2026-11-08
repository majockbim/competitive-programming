#include <iostream>
#include <vector>

int main() {
    // optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // tests
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    // input
    int n, k;
    std::cin >> n >> k; // length, score
    
    int count = 0;
    std::vector<int> a(n);
    int advance_condition;
    for (std::size_t i{}; i < n; ++i) {
        std::cin >> a[i];
        if (i + 1 == k) advance_condition = a[i];
    }

    for (std::size_t i{}; i < n; ++i) {
        if (a[i] >= advance_condition && a[i] > 0) count++;
    }

    std::cout << count;

    return 0;
}
