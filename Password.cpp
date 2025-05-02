#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}


/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
// bool Password::has_mixed_case(string pass){
//   bool has_upper = false;
//   bool has_lower = false;
//   for (char c : pass) {
//     if (isupper(c)) {
//       has_upper = true;
//     } else if (islower(c)) {
//       has_lower = true;
//     }
//     if (has_upper && has_lower) {
//       return true;
//     }
//   }  

//   return false;
// }

// Implementation A - PASS
// #include <cctype>
// bool Password::has_mixed_case(string str)
// {
//   bool has_lower = false;
//   bool has_upper = false;
//   for (char ch : str)
//   {
//     if (std::islower(ch))
//     {
//       has_lower = true;
//     }
//     else if (std::isupper(ch))
//     {
//       has_upper = true;
//     }
//   }
//   return has_lower && has_upper;
// }

// Implementation B
// FAILED a0_mixed_case
// FAILED 0a_mixed_case
// FAILED middle_space_false_lower_mixed_case
// bool Password::has_mixed_case(string str)
// {
//   int count_lower = 0;
//   for (int i = 0; i < str.length(); i++)
//   {
//     if (str[i] >= 'a' && str[i] <= 'z')
//     {
//       count_lower++;
//     }
//   }
//   return count_lower > 0 && count_lower < str.length();
// }

// Implementation C - PASS
// bool Password::has_mixed_case(string str)
// {
//   bool lower = false;
//   bool upper = false;
//   for (int i = 0; i < str.length(); i++)
//   {
//     if (str[i] >= 'a' && str[i] <= 'z')
//     {
//       lower = true;
//     }
//     else if (str[i] >= 'A' && str[i] <= 'Z')
//     {
//       upper = true;
//     }
//   }
//   return upper && lower;
// }

// Implementation D
// [  FAILED  ] PasswordTest.a0_mixed_case
// [  FAILED  ] PasswordTest.0a_mixed_case
// [  FAILED  ] PasswordTest.middle_space_false_lower_mixed_case
// #include <cctype>
// bool Password::has_mixed_case(string str)
// {
//   bool is_lower = false;
//   bool is_upper = false;
//   for (char c : str)
//   {
//     if (std::islower(c))
//     {
//       is_lower = true;
//     }
//     else
//     {
//       is_upper = true;
//     }
//   }
//   return is_lower && is_upper;
// }

// Implementation E
// [  FAILED  ] PasswordTest.same_letter_lower_Upper_mixed_case
// [  FAILED  ] PasswordTest.diff_letter_lower_Upper_mixed_case
// [  FAILED  ] PasswordTest.trailing_mixed_case
// [  FAILED  ] PasswordTest.0aA_mixed_case
// [  FAILED  ] PasswordTest.special_char_true_mixed_case
// [  FAILED  ] PasswordTest.special_char_true_mixed_case_4
// [  FAILED  ] PasswordTest.special_char_true_mixed_case_5

bool Password::has_mixed_case(string str)
{
  bool found = false;
  for(char c : str){
    if( !found && c >= 'A' && c <= 'Z' ){
      found = true;
    }
    else if( found && c >= 'a' && c <= 'z'){
      return true;
    }
  }
  return false;
}

/*
  Checks if the string contains at least one special character.
  Special characters are defined as non-alphanumeric characters.
*/
bool Password::has_special_char(string pass) {
  for (char c : pass) {
    if (!isalnum(c)) {
      return true;
    }
  }
  return false;
}