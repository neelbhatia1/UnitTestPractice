#include "Password.h"
#include <string>

using std::string;

Password::Password() {
    set("ChicoCA-95929");
}

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  if (phrase.empty())
    return 0; // Return 0 for an empty string

  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string word) {
  if (word.empty()) {
    return false; // Return false for an empty string
  }

  bool has_lower = false;
  bool has_upper = false;

  for (char c : word) {
    if (islower(c)) {
      has_lower = true;
    } else if (isupper(c)) {
      has_upper = true;
    }
    // Break the loop if both cases are found
    if (has_lower && has_upper) break;
  }
  // Return true only if both lower and upper cases are found
  return (has_lower && has_upper);
}

bool Password::set(string word) {
    bool valid = true;
    if ( word.length() < 8 || word.length() > 20 ){
        valid = false;
    }
    if ( count_leading_characters(word) > 3 ) {
        valid = false;
    }
    if ( has_mixed_case(word) == false ) {
        valid = false;
    }
    for ( int i = 0; i < pass_history.size(); i++ ){
        if ( pass_history[i] == word ){
            valid = false;
        }
    }
    if ( valid == true ) pass_history.push_back(word);
    return valid;
}

bool Password::authenticate(string word) {
    if ( pass_history.front() == word ){
        return true;
    }
    return false;
}
