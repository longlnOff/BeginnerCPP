
// Exercise 4-7. Implement a program that prompts for the input of a letter. Use a library function
// to determine whether the letter is a vowel and whether it is lowercase or not, and output the
// result. Finally, output the lowercase letter together with its character code as a binary value. As
// a bonus exercise, you could try to do the latter without the use of std::format()?
// Hint: Even though C++ supports binary integral literals (of the form 0b11001010; see
// Chapter 2), C++ streams do not support outputting integral values in binary format. Besides the
// default decimal formatting, they only support hexadecimal and octal formatting (for std::cout,
// for instance, you can use the std::hex and std::oct output manipulators defined in <ios>).
// So, to output a character in binary format without std::format(), you’ll have to write some
// code yourself. It shouldn’t be too hard, though: a char only has eight bits, remember? You can
// just stream these bits one by one, even without knowing loops (see the next chapter). Perhaps
// binary integer literals can be helpful—why else would we have mentioned them at the start of
// this hint?
