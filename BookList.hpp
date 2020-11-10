#pragma once    // include guard

#include <iostream>
#include <iomanip>
#include <cstddef>      // size_t
#include <string>

class Book
{
	// Friend functions: read and write
	friend std::ostream & operator<<( std::ostream & stream, const Book & book );
	friend std::istream & operator>>( std::istream & stream, Book & book );

public:
	// Constructor (can be the default constructor)
	Book(const std::string & title  = "", const std::string & author = "", const std::string & isbn   = "", const double & price  = 0.0 );

	// Queries or getters
	std::string get_isbn  () const;
	std::string get_title () const;
	std::string get_author() const;
	double      get_price () const;

	// Mutators or setters
	void set_isbn  ( const std::string & newIsbn   );
	void set_title ( const std::string & newTitle  );
	void set_author( const std::string & newAuthor );
	void set_price ( double newPrice  );

//private:
	std::string _isbn;
	std::string _title;
	std::string _author;
	double      _price = 0.0;
};

// Ordinary functions: Relational Operators
bool operator==( const Book & lhs, const Book & rhs );
bool operator!=( const Book & lhs, const Book & rhs );

class BookList
{
	// Friend functions: read and write
	friend std::ostream & operator<<( std::ostream & stream, const BookList & bookList );
	friend std::istream & operator>>( std::istream & stream, BookList & bookList );

public:
	// Types and Exceptions
	enum class Position {TOP, BOTTOM};
	
	// Constructors, destructor, and assignment operators
	BookList(const std::size_t & newCap = 30); //TO DO
	// can be the default constructor
	BookList( const BookList & other ) = default; // copy constructor
	BookList( BookList && other ) = default; // move constructor
	BookList & operator=(const BookList& rhs ) = default; // assignment operator
	BookList & operator+=( const BookList & rhs); 
	// TO DO
	// concatenates the rhs list to the end of this list
	
	~BookList(); // TO DO // destructor
	
	// Queries or getters
	std::size_t size() const; // TO DO
	// returns the number of books in the list
	std::size_t find( const Book & book ) const; // TO DO                                             // returns the (zero-based) offset from top of list where the book is found, or the size of the list if the book is not found
	
	Book operator[](std::size_t index) const;// TO DO
	// returns the book at the specified <index>
	
	// read from a file
	void readInFile(const std::string& filename);
	
private:
	// Instance Attributes
	std::size_t _capacity; // maximum number of books that can be stored in the dynamic array
	std::size_t _books_array_size;  // number of books in the list
	Book * _bookArray; // the dynamic array of books
};
