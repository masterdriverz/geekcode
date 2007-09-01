#include "geekcode.h"

const struct stuff startrek[] = {
	{1, "t+++",	"It's not just a TV show, it's a religion. I know all about warp field\n"
			"       dynamics and the principles behind the transporter. I have memorized the\n"
			"       TECH manual. I speak Klingon. I go to cons with Vulcan ears on.\n"
			"       I have no life."},
	{2, "t++",	"It's the best show around. I have all the episodes and the movies on\n"
			"       tape and can quote entire scenes verbatim. I've built a few of the model\n"
			"       kits too. But you'll never catch me at one of those conventions. Those\n"
			"       people are kooks."},
	{3, "t+",	"It's a damn fine TV show and is one of the only things good on TV now."},
	{4, "t",	"It's just another TV show."},
	{5, "t-",	"Maybe it is just me, but I have no idea what the big deal with Star Trek\n"
			"       is. Perhaps I'm missing something but I just think it is bad drama."},
	{6, "t--",	"Star Trek is just another Space Opera. William Shatner isn't an actor,\n"
			"       he's a poser! And what's with this Jean-Luc Picard? A Frenchman with a\n"
			"       British accent? Come on. Isn't Voyager just a rehash of Lost in Space?\n"
			"       Has Sisko even breathed in the last two seasons? Come on. I'd only watch\n"
			"       this show if my remote control broke."},
	{7, "t---",	"Star Trek SUCKS! It is the worst crap I have ever seen! Hey, all you\n"
			"       Trekkies out there, GET A LIFE! (William Shatner is a t---)"},
	{8, "t*",	"I identify with Barclay, the greatest of the Trek Geeks."},
	SENTINEL
};

const struct stuff babylon5[] = {
	{1, "5++++",	"I am J. Michael Straczynski"},
	{2, "5+++",	"I am a True Worshipper of the Church of Joe who lives eats breathes and\n"
			"        thinks Babylon 5, and has Evil thoughts about staling Joe's videotape\n"
			"        archives just to see episodes earlier. I am planning to break into the\n"
			"        bank and steal the triple-encoded synopsis of the 5-year arc."},
	{3, "5++",	"Finally a show that shows what a real future would look like. None of\n"
			"        Picardian \"Let's talk about it and be friends\" crap. And what's this?\n"
			"        We finally get to see a bathroom! Over on that Enterprise, they've been\n"
			"        holding it for over seven years!"},
	{4, "5+",	"Babylon 5 certainly presents a fresh perspective in the Sci-Fi\n"
			"        universe. I watch it weekly."},
	{5, "5",	"I've seen it, I am pretty indifferent to it."},
	{6, "5-",	"This show is sub-par. The acting is wooden, the special effects are\n"
			"        obviously poor quality. In general, it seems like a very cheap\n"
			"        Star Trek ripoff."},
	{7, "5--",	"You call this Sci-Fi? That is such a load of crap! This show is just a\n"
			"        a soap with bad actors, piss-poor effects, and lame storylines.\n"
			"        Puh-leese."},
	SENTINEL
};

const struct stuff xfiles[] = {
	{1, "X++++",	"I am Chris Carter"},
	{2, "X+++",	"This is the BEST show on TV, and it's about time. I've seen everything\n"
			"        from David Duchovny and Gillian Anderson have ever done that has been\n"
			"        recorded and I'm a loyal Duchovny/Anderson fan. I've converted at least\n"
			"        10 people. I have every episode at SP, debate the fine details online,\n"
			"        and have a credit for at least 2 YAXAs."},
	{3, "X++",	"This is one of the better shows I've seen. I wish I'd taped everything\n"
			"        from the start at SP, because I'm wearing out my EP tapes. I'll\n"
			"        periodically debate online. I've converted at least 5 people. I've\n"
			"        gotten a YAXA."},
	{4, "X+",	"I've converted my family and watch the show when I remember. It's\n"
			"        really kinda fun."},
	{5, "X",	"Ho hum. Just another FOX show."},
	{6, "X-",	"It's ok if you like paranoia and conspiracy stories, but left's face\n"
			"        it, it's crap."},
	{7, "X--",	"If I wanted to watch this kind of stuff, I'd talk to Oliver Stone."},
	SENTINEL
};

const struct stuff rp[] = {
	{1, "R+++",	"I've written and published my own gaming materials."},
	{2, "R++",	"There is no life outside the roll of the die. I know all the piddly\n"
			"       rules of (chosen game). _MY_ own warped rules scare the rest of the\n"
			"       players."},
	{3, "R+",	"I've got my weekly sessions set up and a character that I know better\n"
			"       than I know myself."},
	{4, "R",	"Role-Playing? That's just something to do to kill a Saturday afternoon."},
	{5, "R-",	"Gosh, what an utter waste of time!"},
	{6, "R--",	"Role-Players are instruments of pure evil."},
	{7, "R---",	"I work for T$R."},
	{8, "R*",	"I thought life WAS role-playing?"},
	SENTINEL
};

const struct stuff television[] = {
	{1, "tv+++",	"There's nothing I can experience 'out there' that I can't see coming\n"
			"        over my satellite dish. I wish there were MORE channels. I live for the\n"
			"        O.J. Trial."},
	{2, "tv++",	"I just leave the TV on, to make sure I don't miss anything."},
	{3, "tv+",	"I watch some TV every day."},
	{4, "tv",	"I watch only the shows that are actually worthwhile, such as those\n"
			"        found on PBS."},
	{5, "tv-",	"I watch TV for the news and 'special programming'."},
	{6, "tv--",	"I turn my TV on during natural disasters."},
	{7, "!tv",	"I do not own a television."},
	SENTINEL
};


const struct stuff books[] = {
	{1, "b++++",	"I read a book a day. I have library cards in three states. I have\n"
			"        discount cards from every major bookstore. I've ordered books from\n"
			"        another country to get my Favorite Author Fix."},
	{2, "b+++",	"I consume a few books a week as part of a staple diet."},
	{3, "b++",	"I find the time to get through at least one new book a month."},
	{4, "b+",	"I enjoy reading, but don't get the time very often."},
	{5, "b",	"I read the newspaper and the occasional book."},
	{6, "b-",	"I read when there is no other way to get the information."},
	{7, "b--",	"I did not actually READ the geek code, I just had someone tell me."},
	SENTINEL
};

const struct stuff dilbert[] = {
	{1, "DI+++++",	"I am Scott Adams"},
	{2, "DI++++",	"I've received mail from Scott Adams. i'm in the DNRC (Dogbert's New\n"
			"          Ruling Class)"},
	{3, "DI+++",	"I am a Dilbert prototype."},
	{4, "DI++",	"I work with people that act a lot like Dilbert and his boss."},
	{5, "DI+",	"I read Dilbert daily, often understanding it."},
	{6, "DI",	"I read Dilbert infrequently, rarely understanding it."},
	{7, "DI-",	"Is that the comic about the engineers?"},
	{8, "DI--",	"Don't read it, but I think the dog is kinda cute."},
	{9, "DI---",	"I don't think it's funny to make fun of managers trying to best run\n"
			"          their organizational units."},
	SENTINEL
};

const struct stuff doom[] = {
	{1, "D++++",	"I work for iD software."},
	{2, "D+++",	"I crank out PWAD files daily, complete with new monsters, weaponry,\n"
			"        sounds, and maps. I'm a Doom god. I can solve the original maps in\n"
			"        nightmare mode with my eyes closed."},
	{3, "D++",	"I've played the shareware version and bought the real one and I'm\n"
			"        actually pretty good at the game. I occasionally download PWAD files\n"
			"        and play them too."},
	{4, "D+",	"It's a fun action game that is a nice diversion on a lazy afternoon."},
	{5, "D",	"I've played the game and I'm pretty indifferent."},
	{6, "D-",	"I've played the game and really didnt' think it was all that impressive"},
	{7, "D--",	"It's an overly-violent game and pure crap."},
	{8, "D---",	"To hell with Doom, I miss Zork."},
	{9, "D----",	"I've seen better on my Atari 2600."},
	SENTINEL
};

const struct stuff geekcode[] = {
	{1, "G+++++",	"I am Robert Hayden"},
	{2, "G++++",	"I have made a suggestion for future versions of the code (note that\n"
			"         making a suggestion just to get a G++++ rating doesn't count, you also\n"
			"         have to at least qualify for a G+++ rating)"},
	{3, "G+++",	"I have memorized the entire geek code, and can decode others' codes in\n"
			"         my head. I know where by heart to find the current version of the code\n"
			"         on the net."},
	{4, "G++",	"I know what each letter means, but sometimes have to look up the\n"
			"         specifics."},
	{5, "G+",	"I was once G++ (or higher), but the new versions are getting too long\n"
			"         and too complicated."},
	{6, "G",	"I know what the Geek Code is and even did up this code."},
	{7, "G-",	"What a tremendous waste of time the Geek code is."},
	{8, "G--",	"Not only a waste of time, but it obviously shows that this Hayden guy\n"
			"         needs a life."},
	SENTINEL
};
