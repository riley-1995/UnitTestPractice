/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}

TEST(PasswordTest, two_same_lower_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aa");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, two_same_Upper_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("AA");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, two_diff_lower_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ab");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_diff_Upper_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZA");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_same_Upper_lower_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Aa");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_same_lower_Upper_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aA");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, number_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("9");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_same_number_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("99");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_diff_number_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("98");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, space_before_string_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters(" rr");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_spaces_before_string_count_leading)
{
	Password my_password;
	int actual = my_password.count_leading_characters("  ra");
	ASSERT_EQ(1, actual);
}

// Mixed case tests
TEST(PasswordTest, single_letter_Upper_mixed_case)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("J"));
}

TEST(PasswordTest, single_letter_lower_mixed_case)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("j"));
}

TEST(PasswordTest, same_letter_Upper_lower_mixed_case)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Jj"));
}

TEST(PasswordTest, same_letter_lower_Upper_mixed_case)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("jJ"));
}

TEST(PasswordTest, diff_letter_Upper_lower_mixed_case)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Ja"));
}

TEST(PasswordTest, diff_letter_lower_Upper_mixed_case)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aY"));
}

TEST(PasswordTest, leading_mixed_case)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("HEllo"));
}

TEST(PasswordTest, middle_mixed_case)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aYYa"));
}

TEST(PasswordTest, trailing_mixed_case)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aiYN"));
}









// Special char tests
TEST(PasswordTest, one_special_char)
{
	Password my_password;
    ASSERT_TRUE(my_password.has_special_char("P@ssword123"));
}

TEST(PasswordTest, no_special_char)
{
	Password my_password;
    ASSERT_FALSE(my_password.has_special_char("Password123"));
}

TEST(PasswordTest, only_special_char)
{
	Password my_password;
    ASSERT_TRUE(my_password.has_special_char("!@#$%^&*()"));
}

TEST(PasswordTest, empty_special_char)
{
	Password my_password;
    ASSERT_FALSE(my_password.has_special_char(""));
}