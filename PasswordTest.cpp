/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, same_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaaaaa");
	ASSERT_EQ(6, actual);
}

TEST(PasswordTest, mixed_leading_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaazzz");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zZzZzZz");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_and_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("abcABCfds");
	ASSERT_EQ(1, actual);
} 

TEST(PasswordTest, mixed_case_and_num_and_sym_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("##abcABCfds");
	ASSERT_EQ(2, actual);
}

//-----------------------------------------------------------------------

TEST(PasswordTest, has_mixed_case_both_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("PassWord");
	ASSERT_TRUE(actual);
}

TEST(PasswordTest, has_mixed_case_upper_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("PASSWORD");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, has_mixed_case_lower_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("password");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, has_mixed_case_empty_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_FALSE(actual);
}

TEST(PasswordTest, has_mixed_case_numbers_and_symbols_password)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("pass123*#%");
	ASSERT_FALSE(actual);
}