#include "pch.h"
//Task:
/*
Given two non-empty arrays of integers, write a function that determines whether the second array is a subsequence of the first one.
A subsequence of an array is a set of numbers that aren't necessarily adjacent in the array but that are in the same order as they 
appear in the array. For instance, the numbers [1, 3, 4] form a subsequence of the array [1, 2, 3, 4]. So do the numbers [2, 4].
Note that a single number in an array and the array itself are both valid subsequences of the array.
*/
//Solve:
/*
The solve is straight forward. First check an edge case where the subsequence array may be larger than the sequence array. 
Then the for loop checks if the current valeu is equal to the correlating value in the subsequence array, if it is increase the 
sequence count. Then at the end of the loop a check is done to see if the sequence count made it to the end of the subsequence, 
if it did return true. Otherwise the loop will end and the function should return false as no match of the subsequence has been 
found.
*/

//TC = O(n) | SC = O(1) - where n is the length of array 
bool isValidSubsequence(std::vector<int> array, std::vector<int> sequence) {
	// Write your code here.
	int sequenceCount = 0;
	  //edge case check, is the sequence shorter than the array, if it isn't just return false
	if (sequence.size() > array.size())
	{
		return false;
	}
	for (int num : array)//loop through the array
	{
		
		if (num == sequence[sequenceCount])//found the current number
		{
			sequenceCount++;
		}
		if (sequenceCount == sequence.size())//at the end of the sequence array
		{
			return true;
		}
	}

	return false;
}

TEST(ValSeq, TestCaseOne)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 1, 6, -1, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(true, output);
}
TEST(ValSeq, TestCaseTwo)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 1, 22, 25, 6, -1, 8, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(true, output);
}
TEST(ValSeq, TestCaseThree)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 1, 22, 6, -1, 8, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(true, output);
}
TEST(ValSeq, TestCaseFour)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 22, 25, 6 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(true, output);
}
TEST(ValSeq, TestCaseFive)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 1, 6, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(true, output);
}
TEST(ValSeq, TestCaseSix)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 1, 22, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(true, output);
}
TEST(ValSeq, TestCaseSeven)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, -1, 8, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(true, output);
}
TEST(ValSeq, TestCaseEight)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 25 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(true, output);
}
TEST(ValSeq, TestCaseNine)
{
	std::vector<int> array = { 1, 1, 1, 1, 1 };
	std::vector<int> sequence = { 1, 1, 1 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(true, output);
}
TEST(ValSeq, TestCaseTen)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 1, 22, 25, 6, -1, 8, 10, 12 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseEleven)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 4, 5, 1, 22, 25, 6, -1, 8, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseTwelve)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 1, 22, 23, 6, -1, 8, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseThirteen)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 1, 22, 22, 25, 6, -1, 8, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseFourteen)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 1, 22, 22, 6, -1, 8, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseFifteen)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 1, 6, -1, -1 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseSixteen)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 1, 6, -1, -1, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseSeventeen)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 1, 6, -1, -2 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseEighteen)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 26 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseNineteen)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 1, 25, 22, 6, -1, 8, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseTwenty)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 26, 22, 8 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseTwentyOne)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 1, 1, 1, 6 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}
TEST(ValSeq, TestCaseTwentyTwo)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 1, 6, -1, 10, 11, 11, 11, 11 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false , output);
}
TEST(ValSeq, TestCaseTwentyThree)
{
	std::vector<int> array = { 5, 1, 22, 25, 6, -1, 8, 10 };
	std::vector<int> sequence = { 5, 1, 22, 25, 6, -1, 8, 10, 10 };

	bool output = isValidSubsequence(array, sequence);
	ASSERT_EQ(false, output);
}


int main(int argc, char** argv)
{
	
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}