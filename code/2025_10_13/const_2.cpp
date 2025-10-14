//
// Created by PC on 2025/10/14.
//

int num = 0;

const int& ConstRef() {
    return num;
}

const int* ConstPtr() {
    return &num;
}