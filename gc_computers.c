/*
 * Geek Code Generator v2
 * Copyright (C) 2007 Charlie Shepherd <masterdriverz@gentoo.org>
 * License: GPL2
 */

#include "geekcode.h"

const struct stuff gc_computers[] = {
	{1, "C++++",	"I'll be the first in line to get the new cybernetic interface installed\n"
			"        into my skull."},
	{2, "C+++",	"You mean there is life outside of Internet? You're shittin' me!\n"
			"        I haven't dragged myself to class in weeks."},
	{3, "C++",	"Computers are a large part of my existence. When I get up in the\n"
			"        morning the first thing I do is log myself in. I play games or mud on\n"
			"        weekends, but still manage to stay off academic probation."},
	{4, "C+",	"Computers are fun and I enjoy using them. I play a mean game of Doom\n"
			"        and can use a word processor without resorting to the manual too often.\n"
			"        I know that a 3.5\" disk is not a hard disk. I also know that when it\n"
			"        says 'press any key to continue', I don't have to look for a key\n"
			"        labeled ANY"},
	{5, "C",	"Computers are a tool, nothing more. I use it when it serves my purpose."},
	{6, "C-",	"Anything more complicated than my calculator and I'm screwed."},
	{7, "C--",	"Where's the ON switch?"},
	{8, "C---",	"If you even mention computers, I will rip your head off!"},
	SENTINEL
};

const struct stuff gc_unix_type[] = {
	{1, "B",	"BSD (use unless your BSDish system is mentioned below)"},
	{2, "L",	"GNU/Linux"},
	{3, "U",	"Ultrix"},
	{4, "A",	"AIX"},
	{5, "V",	"SysV"},
	{6, "H",	"HPUX"},
	{7, "I",	"IRIX"},
	{8, "O",	"OSF/1 (aka Digital Unix)"},
	{9, "S",	"Sun OS/Solaris"},
	{10, "C",	"SCO Unix"},
	{11, "X",	"NeXT"},
	{12, "*",	"Some other one not listed"},
	SENTINEL
};

const struct stuff gc_unix[] = {
	{1, "U%c++++",	"I am the sysadmin. If you try and crack my machine don't be surprised\n"
			"         if the municipal works department gets an \"accidental\" computer\n"
			"         generated order to start a new landfill on your front lawn or your\n"
			"         quota is reduced to 4Kb."},
	{2, "U%c+++",	"I don't need to crack /etc/passwd because I just modified su so that\n"
			"         it doesn't prompt me. The admin staff doesn't even know I'm here. If\n"
			"         you don't understand what I just said, this category does NOT apply\n"
			"         to you!"},
	{3, "U%c++",	"I've got the entire admin ticked at me because I am always using all\n"
			"         of the CPU time and trying to run programs that I don't have access\n"
			"         to. I'm going to try cracking /etc/passwd next week, just don't tell\n"
			"         anyone."},
	{4, "U%c+",	"I not only have a Unix account, but slam VMS any chance I get."},
	{5, "U%c",	"I have a Unix account to do my stuff in."},
	{6, "U%c-",	"I have a VMS account."},
	{7, "U%c--",	"I've seen Unix and didn't like it. DEC rules!"},
	{8, "U%c---",	"Unix geeks are actually nerds in disguise."},
	SENTINEL
};

const struct stuff gc_perl[] = {
	{1, "P+++++",	"I am Larry Wall, Tom Christiansen, or Randal Schwartz."},
	{2, "P++++",	"I don't write Perl, I speak it. Perl has superseded all other\n"
			"          programming languages. I firmly believe that all programs can be\n"
			"          reduced to a Perl one-liner. I use Perl to achieve U+++ status."},
	{3, "P+++",	"Perl is a very powerful programming tool. Not only do I no longer\n"
			"          write shell scripts, I also no longer use awk or sed. I use Perl for\n"
			"          all programs of less than a thousand lines."},
	{4, "P++",	"Perl is a powerful programming tool. I don't write shell scripts\n"
			"          anymore because I write them in Perl."},
	{5, "P+",	"I know of Perl. I like Perl. I just haven't learned much Perl, but it\n"
			"          is on my agenda."},
	{6, "P",	"I know Perl exists, but that's all."},
	{7, "P-",	"What's Perl got that awk and sed don't have?"},
	{8, "P--",	"Perl users are sick, twisted programmers who are just showing off."},
	{9, "P---",	"Perl combines the power of sh, the clarity of sed, and the\n"
			"          performance of awk, with the simplicity of C. It should be banned."},
	{10, "P!",	"Our paranoid admin won't let us install Perl!\n"
			"          Says it's a 'hacking tool'."},
	SENTINEL
};

const struct stuff gc_linux[] = {
	{1, "L+++++",	"I am Linus, grovel before me."},
	{2, "L++++",	"I am a Linux wizard. I munch C code for breakfast and have enough room\n"
			"         left over for kernel debugging. I have so many patches installed that\n"
			"         I lost track about ten versions ago. Linux newbies consider me a god"},
	{3, "L+++",	"I use Linux exclusively on my system. I monitor comp.os.linux.* and\n"
			"         even answer questions sometimes."},
	{4, "L++",	"I use Linux ALMOST exclusively on my system. I've given up trying to\n"
			"         achieve Linux god status, but welcome the OS as a replacement for DOS\n"
			"         I only boot to DOS to play games."},
	{5, "L+",	"I've managed to get Linux installed and even used it a few times. It\n"
			"         seems like it is just another OS."},
	{6, "L",	"I know what Linux is, but that's about all."},
	{7, "L-",	"I have no desire to use Linux and frankly don't give a rat's patootie\n"
			"         about it. There are other, better, operating systems out there. Like\n"
			"         Mac, DOS, or Amiga-OS. Or, better yet even, would be another free Unix\n"
			"         OS like FreeBSD."},
	{8, "L--",	"Unix sucks. Because Linux = Unix, Linux sucks. I worship Bill Gates."},
	{9, "L---",	"I am Bill Gates."},
	SENTINEL
};

const struct stuff gc_emacs[] = {
	{1, "E+++",	"Emacs is my login shell! M-x doctor is my psychologist! I use Emacs to\n"
			"        control my TV and toaster oven! All you vi people don't know what you\n"
			"        are missing! I read alt.religion.emacs, alt.sex.emacs and comp.os.emacs"},
	{2, "E++",	"I know and use elisp regularly!"},
	{3, "E+",	"Emacs is great! I read my mail and news with it!"},
	{4, "E",	"Yeah, I know what Emacs is, and use it as my regular editor."},
	{5, "E-",	"Emacs is too big and bloated for my tastes."},
	{6, "E--",	"Emacs is just a fancy word processor."},
	{7, "E---",	"Emacs sucks! vi forever!"},
	{8, "E----",	"Emacs sucks! pico forever!"},
	SENTINEL
};

const struct stuff gc_www[] = {
	{1, "W+++",	"I am a WebMaster. Don't even think about trying to view my page without\n"
			"       the latest version of Netscape. When I'm not on my normal net connection\n"
			"       I surf the web using my Newton and a cellular modem."},
	{2, "W++",	"I have a homepage. I surf daily. My homepage is advertised in my .sig"},
	{3, "W+",	"I have the latest version of Netscape, and wander the web only when\n"
			"       there is something specific I'm looking for."},
	{4, "W",	"I have a browser and a connection. Occasionally I'll use them."},
	{5, "W-",	"The web is really a pain. Life was so much easier when you could\n"
			"       transfer information by simple ASCII. Now everyone won't even consider\n"
			"       your ideas unless you spiff them up with bandwidth-consuming pictures\n"
			"       and pointless information links."},
	{6, "W--",	"A pox on the web! It wastes time and bandwidth and just gives the\n"
			"       uneducated morons a reason to clutter the Internet."},
	SENTINEL
};


const struct stuff gc_usenet[] = {
	{1, "N++++",	"I am Tim Pierce."},
	{2, "N+++",	"I read so many newsgroups that the next batch of news comes in before\n"
			"         I finish reading the last batch, and I have to read for about 2 hours\n"
			"         straight before I'm caught up on the morning's news. Then there's the\n"
			"         afternoon..."},
	{3, "N++",	"I read all the news in a select handful of groups."},
	{4, "N+",	"I read news recreationally when I have some time to kill."},
	{5, "N",	"Usenet News? Sure, I read that once."},
	{6, "N-",	"News is a waste of my time and I avoid it completely."},
	{7, "N--",	"News sucks! 'Nuff said."},
	{8, "N---",	"I work for Time magazine."},
	{9, "N----",	"I am a Scientologist."},
	{10, "N*",	"All I do is read news."},
	SENTINEL
};

const struct stuff gc_oracle[] = {
	{1, "o+++++",	"I am Steve Kinzler."},
	{2, "o++++",	"I am an active Priest."},
	{3, "o+++",	"I was a Priest, but have retired."},
	{4, "o++",	"I have made the Best of Oracularities."},
	{5, "o+",	"I have been incarnated at least once."},
	{6, "o",	"I've submitted a question, but it has never been incarnated."},
	{7, "o-",	"I sent my question to the wrong group and I got flamed."},
	{8, "o--",	"Who needs answers from a bunch of geeks anyhow?"},
	SENTINEL
};

const struct stuff gc_kibo[] = {
	{1, "K++++++",	"I am Kibo."},
	{2, "K+++++",	"I've had sex with Kibo."},
	{3, "K++++",	"I've met Kibo."},
	{4, "K+++",	"I've gotten mail from Kibo."},
	{5, "K++",	"I've read Kibo."},
	{6, "K+",	"I like Kibo."},
	{7, "K",	"I know who Kibo is."},
	{8, "K-",	"I don't know who Kibo is."},
	{9, "K--",	"I dislike Kibo."},
	{10, "K---",	"I am currently hunting Kibo down with the intent of ripping his\n"
			"           still-beating heart of out his chest and showing it to him as\n"
			"           he dies."},
	{11, "K----",	"I am Xibo."},
	SENTINEL
};

const struct stuff gc_windows[] = {
	{1, "w+++++",	"I am Bill Gates."},
	{2, "w++++",	"I have Windows, Windows 95, Windows NT, and Windows MT Advanced Server\n"
			"         all running on my SMP RISC machine. I haven't seen daylight in months."},
	{3, "w+++",	"I am a MS Windows programming god. I wrote a VxD driver to allow\n"
			"         MS Windows and DOS to share the use of my waffle iron. P.S. Unix sux."},
	{4, "w++",	"I write MS Windows programs in C and think about using C++ someday.\n"
			"         I've written at least one DLL."},
	{5, "w+",	"I have installed my own custom sounds, wallpaper, and screen savers so\n"
			"         my PC walks and talks like a fun house. Oh yeah, I have a hundred\n"
			"         TrueType(tm) fonts that I've installed but never used. I never lose at\n"
			"         Minesweeper or Solitaire."},
	{6, "w",	"OK, so I use MS Windows, I don't have to like it."},
	{7, "w-",	"I'm still trying to install MS Windows and have at least one\n"
			"         peripheral that never works right."},
	{8, "w--",	"MS Windows is a joke operating system. Hell, it's not even an\n"
			"         operating system. NT is Not Tough enough for me either. 95 is how many\n"
			"         times it will crash an hour."},
	{9, "w---",	"Windows has set back the computing industry by at least 10 years. Bill\n"
			"         Gates should be drawn, quartered, hung, shot, poisoned, disembowelled,\n"
			"         and then REALLY hurt."},
	SENTINEL
};

const struct stuff gc_os2[] = {
	{1, "O+++",	"I live, eat and breathe OS/2. All of my hard drives are HPFS.\n"
			"        I am the Anti-Gates."},
	{2, "O++",	"I use OS/2 for all my computing needs. I use some DOS and Windows\n"
			"        programs, but run them under OS/2. If the program won't run under Os/2,\n"
			"        then obviously I don't need it."},
	{3, "O+",	"I keep a DOS partition on my hard drive 'just in case'. I'm afraid to\n"
			"        try HPFS."},
	{4, "O",	"I finally managed to get OS/2 installed but wasn't terribly impressed."},
	{5, "O-",	"Tried it, didn't like it."},
	{6, "O--",	"I can't even get the thing to install!"},
	{7, "O---",	"Windows RULES! Long live Bill Gates. (See w++++)"},
	{8, "O----",	"I am Bill Gates of Borg. Os/2 is irrelevant."},
	SENTINEL
};

const struct stuff gc_mac[] = {
	{1, "M++",	"I am a Mac guru. Anything those DOS putzes and Unix nerds can do, I can\n"
			"      do better, and if not, I'll write the damn software to do it."},
	{2, "M+",	"A Mac has it's uses and I use it quite often."},
	{3, "M",	"I use a Mac, but I'm pretty indifferent about it."},
	{4, "M-",	"Macs suck. All real geeks have a character prompt."},
	{5, "M--",	"Macs do more than suck. They make a user stupid by allowing them to use\n"
			"      the system without knowing what they are doing. Mac weenies have lower\n"
			"      IQs than the fuzz in my navel."},
	SENTINEL
};

const struct stuff gc_vms[] = {
	{1, "V+++",	"I am a VMS sysadmin. I wield far more power than those Unix admins,\n"
			"       because Unix can be found on any dweeb's desktop. Power through\n"
			"       obscurity is my motto."},
	{2, "V++",	"Unix is a passing fad compared to the real power in the universe,\n"
			"       my VMS system."},
	{3, "V+",	"I tend to like VMS better than Unix."},
	{4, "V",	"I've used VMS."},
	{5, "V-",	"Unix is much better than VMS for my computing needs."},
	{6, "V--",	"I would rather smash my head repeatedly into a brick wall than suffer\n"
			"       the agony of working with VMS. It's reminiscent of a dead and decaying\n"
			"       pile of moose droppings. Unix rules the universe."},
	SENTINEL
};
