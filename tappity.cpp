#include "tappity.h"
/**
 * Class for tappity
**/

//Constructor sets the reference phrase
tappity::tappity(std::string reference)
{
  m_reference = reference;
}

//Provide the input to be compared to the reference. Before this
//function is called, the input should be considered an empty string
void tappity::entry(std::string input)
{
    m_entry = input;
}

//Compares the length of the reference to that of the input and
//returns the absolute value of the difference, or 0 if they are the
//same length
int tappity::length_difference()
{
  if(m_reference.length() < m_entry.length()){
    return m_entry.length() - m_reference.length();
  }
  return m_reference.length() - m_entry.length();
}

//Compares the content of the reference to that of the input and
//calculates the accuracy of matching characters. If the two strings
//are identical, accuracy should be 100. However, for each
//corresponding character that does not match in the same location,
//the percentage of corresponding characters should be returned.
//For example, if the reference and input have 10 letters and the input
//matches 8 of the corresponding reference characters, the function
//should return 80. When input does not have the same number of
//characters as the reference, the accuracy should represent the percent
//of matching characters between the shorter and longer strings. For
//example, if one string has 8 characters matching the corresponding
//locations in another string that has 16 characters, the accuracy is 50.
double tappity::accuracy()
{
  int counter =0;
  for (int i = 0; i < m_reference.length(); i++) {
    if(m_reference[i] == m_entry[i]){
      counter++;
    }
  }
  if(m_reference.length() < m_entry.length()){
    return (double)counter/m_entry.length()*100;
  }
  return (double)counter/m_reference.length()*100;
}
