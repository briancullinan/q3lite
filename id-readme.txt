Quake III Arena GPL source release


A short summary of the file layout:

code/			   		Quake III Arena source code ( renderer, game code, OS layer etc. )
code/bspc				bot routes compiler source code
lcc/					the retargetable C compiler ( produces assembly to be turned into qvm bytecode by q3asm )
q3asm/					assembly to qvm bytecode compiler
q3map/					map compiler ( .map -> .bsp ) - this is the version that comes with Q3Radiant 200f
q3radiant/				Q3Radiant map editor build 200f ( common/ and libs/ are support dirs for radiant )

While we made sure we were still able to compile the game on Windows, GNU/Linux
and Mac, this build didn't get any kind of extensive testing so it may not work
completely right. Whenever an id game is released under GPL, several projects
start making the source code more friendly to nowaday's compilers and
environements. If you are picking up this release weeks/months/years after we
uploaded it, you probably want to look around on the net for cleaned up
versions of this codebase as well.
