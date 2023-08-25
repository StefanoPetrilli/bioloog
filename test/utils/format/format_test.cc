#include "format_test.h"

namespace format_test {
    TEST(ToString, EmptyVectorReturnsEmptyString){
        std::vector<int> empty_vector {};
        EXPECT_EQ(format::ToString(empty_vector), "");
    }

    TEST(ToString, VectorReturnsExpectedString){
        std::vector<int> empty_vector {1, 2, 3, 4};
        EXPECT_EQ(format::ToString(empty_vector), "1 2 3 4");
    }
}