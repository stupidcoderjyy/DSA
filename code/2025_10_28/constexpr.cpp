//
// Created by PC on 2025/10/30.
//

constexpr int GetLen() {
    return 10;
}

int main() {
    constexpr int len = 10;
    int nums1[len];
    int nums2[GetLen()];
    return 0;
}