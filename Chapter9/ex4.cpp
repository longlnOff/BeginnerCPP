// Exercise 9-4. Whenever you either read or write code, “What if?” should be your 
// number one go-to question. For instance, consider the largest() function of Ex9_03. 
// It starts by accessing data[0]. But what if data is empty? In cases such as this, you 
// have several options.
// First: You could add a code comment specifying that data may not be empty. This 
// is called a precondition. Violating a precondition as a caller by definition results in 
// undefined behavior. All bets are off when you violate a precondition—or, as Ellie 
// Goulding would put it: anything could happen (including a crash).
// Second: You could come up with a reasonable behavior for such corner cases. Come up 
// with some result the function could compute for empty input. Say, a not-number value 
// for the largest() of an empty array?
// Both can at times be viable options. But can you, in the spirit of this chapter, work out a 
// third alternative?