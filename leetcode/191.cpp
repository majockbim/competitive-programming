class Solution {
public:
    int hammingWeight(int n) {
        std::uint32_t value = static_cast<std::uint32_t>(n);
        int count = 0;

        for (int i = 0; i < 32; ++i) {
            std::uint32_t mask = std::uint32_t{1} << i;

            if ((value & mask) != 0) {
                ++count;
            }
        }

        return count;
    }
};
