#include "pch.h"
#include "../Project11/baseball.cpp"
#include <stdexcept>

using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
	//Baseball game;
	void assertIllegalArgument(string guessNumber) {
		//game.guess() 수행 후, Exception이 발생해야 pass 이다.
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			//PASS
		}
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, Return2Strike0BallResult) {
	GuessResult result = game.guess("153");

	EXPECT_FALSE(result.solved);
	EXPECT_EQ(2, result.strikes);
	EXPECT_EQ(0, result.balls);
}
