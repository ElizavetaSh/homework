
#include <gtest/gtest.h>


extern "C" {
#include "hist.h"
}
int*** historgam_point(int** pp, int N);

TEST(HIST_TEST, Assert_1)
{
	int sd = -44;
	int s1d = 45;
	int s2d = 11;
	int* fd = &sd;
	int* p[] = { fd,fd,&s2d,fd,fd,&s1d,&s2d,&s1d };

	int N = sizeof(p) / (2 * sizeof(int));
	int*** result = nullptr;
	result = historgam_point(&*p, N);
	EXPECT_TRUE(result != nullptr);

}

TEST(HIST_TEST, Assert_2)
{
	EXPECT_EQ(7 * 6, 42);

}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

}
