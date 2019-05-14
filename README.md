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
* do, if, while, unless, for, foreach etc all there (including at end)
* s/foo/bar/;  and matching if (/abc/) ...  and =~/!~
* string ops
* $_
* range op ..
* file test ops
* chmod, chdir, chop, close, crypt, delete (hashes)
* die EXPR
* eval, exec, exit, exp, fork
* each(HASH) --- e.g. each(ENV)   <== (!)
* eof(handle)
* gmtime
* join, split
* open
* sub
* select
* stat, study
* format
