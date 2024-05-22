// Exercise 7-3. Write a program that reads a text string of arbitrary length from the keyboard 
// and prompts for entry of a word that is to be found in the string. The program should find 
// and replace all occurrences of this word, regardless of case, by as many asterisks as 
// there are characters in the word. It should then output the new string. Only whole words 
// are to be replaced. For example, if the string is "Our house is at your disposal." and 
// the word that is to be found is "our", then the resultant string should be as follows: 
// "*** house is at your disposal." and not "*** house is at y*** disposal.".

#include <iostream>
#include <string>
#include <format>