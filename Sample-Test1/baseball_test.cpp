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

	void guessResultEqual(const string& guessNumber, GuessResult expected)
	{
		GuessResult result = game.guess(guessNumber);

		EXPECT_TRUE(result.solved == expected.solved);
		EXPECT_EQ(result.strikes, expected.strikes);
		EXPECT_EQ(result.balls, expected.balls);
	}
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
	assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	guessResultEqual("123", { true, 3, 0 });
}

TEST_F(BaseballFixture, Return2Strike0BallResult) {
	guessResultEqual("153", { false, 2, 0 });
}

TEST_F(BaseballFixture, Return0Strike1BallResult) {
	guessResultEqual("862", { false, 0, 1 });
}
