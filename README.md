# CompiledWebDevelopment
Base tech project including test automation for compiled web development with the C programming language.

Hint:
Exact tutorial which external tool have to be in which folder to execute all tests will follow.
Normally just look into the simple bash files to understand what will compile or execute in which order.

Project goals:

* web development in compiled programming languages like the C programming language
* basic set of functions for programming easily a website
* usage of FastCGI or CGI (link)
# CGI and FastCGI are part of most web spaces for just $5 per month
# execute your compiled web sites without the need to have an own web server
*usage of tools and best practices for defensive programming in error-prone programming languages
** unit tests with good equivalence partitioning
** manual test cases with a spreadsheet document
** automated browser tests with Selenium automation tool (link) and the Java programming language
** usage of an address santizer tools to avoid not allowed read or write actions in memory (link to paper from the developers)
** writing own functions with low cyclomatic complexity for easy maintenance (link)
** strict exit during wrong usage of own functions with detailed error logging (origin .c-filename + line number)
** usage of CppCheck (link) and Splint tool (link) for static code analysis
** high code coverage for own functions with lcov tool (link)
* showing the ratio between source code for the production code and unit tests
** ratio 4:1 for the frontend sources
** ratio 1:4 for the core sources
* statistics for the amount of allocation, reallocation and free calls
* "One-file compilation" approach with multi *.c file structure: You compile the whole website with one GCC bash line.
* future plans for porting this project to PHP (link) and the strong-typing Ada programming language (link)

