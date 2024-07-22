# perl2
My "fork" of the Perl 2 source

This fork was successfully built using Cygwin with gcc, byacc (softlinked to yacc), and make, on a Windows 10 laptop.

I edited three or four files to remove compile errors in the process (just grep 'rje' in the source to see the changes I made).

Here's what Perl2 has:
* scalars and the $ sigil
* arrays of scalars, the @ sigil, array assignment
* associative arrays (there is no %)
* BARE VARIABLES?  e.g. ENV not %ENV....
* interpolation in "" (curly brackets OK) 
* backtick execution
* <handle> reads next line.  <> is ok.  <*.c> is ok (etc).
* @ARGV
* open(handle, file-or-pipe)
* do, if, while, unless, for, foreach, last, redo, etc
* statement end modifiers if, unless, while, until.
* s/foo/bar/;  and matching if (/abc/) or m|abc|...  and =~/!~
* string ops
* $_
* range op ..
* file test ops
* magic autoincrement

* chmod
* chdir
* chop
* close
* crypt
* delete (hashes)
* die EXPR
* do BLOCK
* do SUBROUTINE (LIST)
* do 'file.pl';
* each(HASH) --- e.g. each(ENV)   <== (!)
* eof
* eval
* exec
* exp
* fork
* format
* gmtime
  ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst)
       = gmtime(time);
* hex
* index(STR,SUBSTR)
* int
* join
* keys
* kill
* last
* length
* link(OLDFILE,NEWFILE)
* local
  This operator works by saving the current values of those 
  variables in LIST on a hidden stack and restoring them upon 
  exiting the block, subroutine or eval. The LIST may be assigned 
  to if desired, which allows you to initialize your local 
  variables. Commonly this is used to name the parameters to a 
  subroutine.
* localtime
  ($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst)
       = localtime(time);
* log
* next
* oct
* open
* ord
* pop
* print, printf
* push
* redo
* rename
* reset
* seek(FILEHANDLE,POSITION,WHENCE)
* select
* shift
* sleep
* sort
* split
* sprintf
* sqrt
* stat
  ($dev,$ino,$mode,$nlink,$uid,$gid,$rdev,$size,
       $atime,$mtime,$ctime,$blksize,$blocks)
           = stat($filename);
* study
* substr
* system
* symlink(OLDFILE,NEWFILE)
* tell(FILEHANDLE)
* time
* times
  Returns a four-element array giving the user and system times, in seconds, for this
  process and the children of this process.
    ($user,$system,$cuser,$csystem) = times;
* umask
* unlink
* unshift
* utime
Changes the access and modification times on each file of a list of files.
The first two elements of the list must be the NUMERICAL access and
modification times, in that order.
Returns the number of files successfully changed.
The inode modification time of each file is set to the current time.
Example of a "touch" command:

	#!/usr/bin/perl
	$now = time;
	utime $now,$now,@ARGV;
	
* values
* wait
* write
