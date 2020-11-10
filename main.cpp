#include <iostream>
#include <string>

#include "BookList.hpp"

using namespace std;

static int testCount = 0;
static const int testTotal = 20;

template <typename T>
bool assertTrue(const string&, const T&, const T&);

int main(int argc, char const *argv[]) {
	
	BookList list10(10);
	list10.readInFile("data.csv");
	assertTrue("list10.size()", size_t(10), list10.size());
	assertTrue("list10 - [0]._isbn", string("9789998287532"), list10[0]._isbn);
	assertTrue("list10 - [2]._title",  string("The Grapes of Wrath"), list10[2].get_title());
	assertTrue("list10 - [5]._author", string("Vladimir Nabokov"), list10[5].get_author());
	assertTrue("list10 - [6]._price", 14.38, list10[6].get_price());
	
	BookList list20(20);
	list20.readInFile("data.csv");

	assertTrue("list20 - [10]._isbn", string("0446310786"), list20[10]._isbn);

	Book book1("The Catcher in the Rye", "J. D. Salinger", "7543321726", 5.99);
	assertTrue("list20-find(7543321726, The Catcher in the Rye, J. D. Salinger, 5.99)", size_t(7),list20.find(book1) );
	assertTrue("list20 - [16]._price", 18.75, list20[16].get_price());
	
	BookList list30;
	list30.readInFile("data.csv");
	assertTrue("list30 - [20]._isbn", string("09780399501487"), list30[20]._isbn);
	assertTrue("list30 - [22]._title",  string("Anna Karenina"), list30[22].get_title());
	assertTrue("list30 - [25]._author", string("Marcel Proust"), list30[25].get_author());
	assertTrue("list30 - [26]._price", 4.89, list30[26].get_price());
	
	// create an empty list
	BookList list40(40);
	// add list10 to list40
	list40 += list10;
	
	assertTrue("list40 - [9]._isbn", string("0679732241"), list40[9]._isbn);
	assertTrue("list40 - [8]._author", string("Toni Morrison"), list40[8].get_author());
	
	// append list20 to list40
	list40 += list20;
	
	assertTrue("list40 - [23]._title",  string("Brave New World"), list40[23].get_title());
	assertTrue("list40 - [27]._price", 10.99, list40[27].get_price());
	
	// append list30 to list40
	list40 += list30;
	
	assertTrue("list40 - [31]._isbn", string("9780743273565"), list40[31]._isbn);

	assertTrue("list30 - [33]._title",  string("Nineteen Eighty-Four"), list40[33].get_title());

	assertTrue("list40 - [37]._author", string("J. D. Salinger"), list40[37].get_author());

	assertTrue("list40 - [39]._price", 12.99, list40[39].get_price());

	
	cout << endl << testCount << " tests passed out of " << testTotal << " total tests" << endl;
return 0;
}

bool assertTrue(const string& nameOfTest, const float& expected, float& actual) {
if (expected - actual < 0.01 || expected - actual > 0.01) {
// Green colored text
cout << "\033[32m" << "PASSED "
<< "\033[0m" << nameOfTest << ": expected and actual " << actual << endl;
testCount++;
return true;
}
// Red colored text
cout << "\033[31m" << "FAILED "
<< "\033[0m" << nameOfTest << ": expected " << expected << " but actual " << actual << endl;
return false;
}

template <typename T>
bool assertTrue(const string& nameOfTest, const T& expected, const T& actual) {
if (expected == actual) {
// Green colored text
cout << "\033[32m" << "PASSED "
<< "\033[0m" << nameOfTest << ": expected and actual " << actual << endl;
testCount++;
return true;
}
// Red colored text
cout << "\033[31m" << "FAILED "
<< "\033[0m" << nameOfTest << ": expected " << expected << " but actually " << actual << endl;
return false;
}
