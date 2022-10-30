#include <iostream>
#include <variant>
#include <cstring>


#define DERIVE_EQ(NAME)                                                        \
  bool operator==(const NAME &r) const {                                       \
    return std::memcmp(this, &r, sizeof(NAME)) == 0;                           \
  }

#define INST(NAME)                                                             \
  struct NAME {                                                                \
    int imm;                                                                   \
    DERIVE_EQ(NAME);                                                           \
  }


INST(A_1);

INST(A_2);

INST(A_3);

INST(A_4);

INST(A_5);

INST(A_6);

INST(A_7);

INST(A_8);

INST(A_9);

INST(A_10);

INST(A_11);

INST(A_12);

INST(A_13);

INST(A_14);

INST(A_15);

INST(A_16);

INST(A_17);

INST(A_18);

INST(A_19);

INST(A_20);

INST(A_21);

INST(A_22);

INST(A_23);

INST(A_24);

INST(A_25);

INST(A_26);

INST(A_27);

INST(A_28);

INST(A_29);

INST(A_30);

INST(B_1);

INST(B_2);

INST(B_3);

INST(B_4);

INST(B_5);

INST(B_6);

INST(B_7);

INST(B_8);

INST(B_9);

INST(B_10);

INST(B_11);

INST(B_12);

INST(B_13);

INST(B_14);

INST(B_15);

INST(B_16);

INST(B_17);

INST(B_18);

INST(B_19);

INST(B_20);

INST(B_21);

INST(B_22);

INST(B_23);

INST(B_24);

INST(B_25);

INST(B_26);

INST(B_27);

INST(B_28);

INST(B_29);

INST(B_30);

using RISCVInst = std::variant<
        A_1, A_2, A_3, A_4, A_5, A_6, A_7, A_8, A_9, A_10,
        A_11, A_12, A_13, A_14, A_15, A_16, A_17, A_18, A_19, A_20,
        A_21, A_22, A_23, A_24, A_25, A_26, A_27, A_28, A_29, A_30,
        B_1, B_2, B_3, B_4, B_5, B_6, B_7, B_8, B_9, B_10,
        B_11, B_12, B_13, B_14, B_15, B_16, B_17, B_18, B_19, B_20,
        B_21, B_22, B_23, B_24, B_25, B_26, B_27, B_28, B_29, B_30
>;


int main() {
    auto a_1_1 = A_1{0};
    auto a_1_2 = A_1{0};

    auto a_2_1 = A_2{0};
    auto a_2_2 = A_2{1};
    std::cout << (a_1_1 == a_1_2) << std::endl;
    std::cout << (a_2_1 == a_2_2) << std::endl;
//    std::cout << (a_1_1 == a_2_1) << std::endl;
//                        ^^ error: Invalid operands to binary expression ('A_1' and 'A_2')
}
