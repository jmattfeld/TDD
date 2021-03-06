Instructions for building the book's code for gcc, and Visual Studio users included.

Unzip the code bundle into <BookCodeParent>. Make sure the path contains no spaces.
You should end up with this:
    <BookCodeParent>/code

Before trying to build the book's code, you must first get cpputest from cpputest.org, 
build it and run its tests.  If you run into problems with the cpputest build, the 
good people at the cpputest google group can help.

-------------
For gcc users
-------------
Download and build CppUTest from cpputest.org
  At the time of this update these are the steps. If you have any trouble
  check the cpputest build instructions
  Unzip into ~/tools/cpputest (or similar)
  cd ~/tools/cpputest
  ./configure.sh
  make check
  make tdd

Define CPPUTEST_HOME in your .bash_profile or similar file
  export CPPUTEST_HOME=~/tools/cpputest

Build all examples
    cd <BookCodeParent>/code
    make everything

If there are problems, you will probably want to build only 
one directory at at time.  code/t0 is a good place to start.

Makefiles
	Look over code/Makefile.  It shows you how to make and clean the various projects.
	It has numerous make targets you can select from the command line, or from your 
	development environment.  Also, yuo can just cd to one of the directories under code
  and type make.
	
    code/Makefile - can make everything, by default it makes the top level using 
    CppUTest tests.
    
    code/MakefileUnity.mk - makes examples for chapters 2-4 with Unity tests
    code/MakefileCppUTest.mk - makes examples for chapters 2-4 and beyond with CppUTest tests
    code/SandBox/MakefileUnity.mk 
    code/SandBox/MakefileCppUTest.mk
    code/t0/Makefile - makes code examples in t0
    code/t1/Makefile - makes code examples in t1
    code/t2/Makefile - makes code examples in t2
    code/t3/Makefile - makes code examples in t3
    
    From a command prompt (mac, linux, cygwin) you can make any of these
    individually, for example
    
    	cd <BookCodeParent>/code/t0
    	make
    	
    To clean the same directory
    
    	cd <BookCodeParent>/code/t0
    	make clean
    	
    You can change code/Makefile to by default do a Unity make.  See
    code/Makefile for details.    

----------------
For cygwin users
----------------
	Make sure you add c:\cygwin\bin to your Windows path environment variable, 
	especially if you plan on using eclipse.  If you don't, eclipse won't
	be able to find gcc.

----------------
For mingw users
----------------
	Many people use mingw, though I do not.  So I can't help much.  The good people
  at the cpputest google group can help.

-----------------
For eclipse users
-----------------
    There are eclipse projects the code, CppUTest, SandBox, code/t0, 
    code/t1, code/t2, code/t3 directories.
    
    My projects do not let eclipse manage the makefiles. Mine are manually managed 
    for portability.
      
    Notice that the eclipse project found in the code directory also includes 
    all the sub-directories for the other projects.  
    
    Here's how to load the projects into eclipse:
    
    1) Select the <BookCodeParent> directory as the workspace
    2) You may have to change the perspective from Java to C/C++
    
    3) Import each project using:
        File/Import.../General/Existing Project into Workspace

	These are the eclipse projects and directories:
		Project name	Directory
	    BookCode		<BookCodeParent>/code
	    SandBox			<BookCodeParent>/code/SandBox
		  t0				  <BookCodeParent>/code/t0
		  t1	  			<BookCodeParent>/code/t1
		  t2		  		<BookCodeParent>/code/t2
		  t3			  	<BookCodeParent>/code/t3

	When you are working with BookCode, only have the BookCode 
	project open.  The others can be in the workspace, but closed.
	You can edit the code/Makefile to adjust which makefile runs when you 
	save.  You can change the default build setting from running the
	CppUTests to Unity tests by changing these two make targets:
	
	From:
		all: codeCppUTest
	
		clean: cleanCodeCppUTest
	
	To:
		all: codeUnity
	
		clean: cleanCodeUnity

	If you work on one of the other projects (SandBox, t0, t1, t2, t3) 
	it is best to only have the one project and 'CppUTest' open. Eclipse can 
	get a bit confused with some files being in two projects (remember, BookCode 
	project contains all the other projects as directories). If you open a file
	from under BookCode/t0 and under the t0 project, it is opened twice.
	Though nothing really bad happens, you might not see the right makefile running.
	
	In hindsight, having all the contained projects inside of a another project
	is not a great idea.  A better approach would have been to have the 'code'
	level project as siblings to the sandBox, t0, t1, t2, and t3 directories. Sorry
	for not figuring that out sooner :^)

-----------------------
For visual studio users
-----------------------
	There are Visual C/C++ workspace files for working with CppUTest.  They are from an
  older version of Visual Studio.  If you know Visual Studio you should be able to convert
  then with Visual Studio doing most the work.

  First download CppUTest and build it for your environment using your toolset and
  the current CppUTest instructions.  Once you can build CppUtest and run its tests
  close Visual Studio.

	Before opening book code in Visual Studio, create this environment variable
		CPPUTEST_HOME=<pathTo>/CppUTest

	If you are using a later version of Visual Studio, you can let your version
	convert the workspace and project files.  You may have to tweak the book code, as
  Visual Studio changes.

	Build only for 'Debug'. 'Release' is not supported for any of the projects.

	For each of the book's workspaces, open the dsw file (let later versions of
	VS convert). Build and run without debug.  You will get the command window 
	to linger after the test run if you run without debug.  To keep feedback fast, 
	get used to using control-F5 to save all, build and run the tests.
	
	If you did not define the CPPUTEST_HOME environment variable correctly you will get
	compilation errors about not finding CppUTest include files
	
	These are the Visual Studio workspace files:
    <BookCodeParent>/code/BookCode.dsw
    <BookCodeParent>/code/SandBox/SandBox.dsw
    <BookCodeParent>/code/t0
    <BookCodeParent>/code/t1
    <BookCodeParent>/code/t2
    <BookCodeParent>/code/t3

-------------
For everybody
-------------
When you look at the downloaded code, you will see some distracting comments throughout the code
that look like this:

    /* START: codeIncludeTag */
    ...
    ... code ...
    ...
    /* END: codeIncludeTag */

These allow the code to be kept separate from the book text. This keeps the examples compilable
and avoids book/code conflicts.  The "START: codeIncludeTag" and "END: codeIncludeTag"
tags identify code that is pulled into the book during the automated book build process. 
Try to ignore them.

You will also notice some code that has been turned off using conditional compilation. 
It looks like this:

    #if 0 /* START: IsOnTake1 */
    BOOL LedDriver_IsOn(int ledNumber)
    {
        return TRUE;
    }
    #endif /* END: IsOnTake1 */

Code in the #if 0 block is a snapshot of code that has since evolved. It may or may 
not have code include tags.  In this book, the code is always evolving.  I've left 
the latest version at the top of the file and move the intermediate code snippets 
further down the file.    

Please report any problems on the book's forum: www.pragprog.com/titles/jgade.
