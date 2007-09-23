/*
 * Geek Code Generator v2
 * Copyright (C) 2007 Charlie Shepherd <masterdriverz@gentoo.org>
 * License: GPL2
 */

#include "geekcode.h"

const struct stuff gc_education[] = {
	{1, "e+++++",	"I am Stephen Hawking"},
	{2, "e++++",	"Managed to get my Ph.D."},
	{3, "e+++",	"Got a Master degree"},
	{4, "e++",	"Got a Bachelors degree"},
	{5, "e+",	"Got an Associates degree"},
	{6, "e",	"Finished High School"},
	{7, "e-",	"Haven't finished High School"},
	{8, "e--",	"Haven't even entered High School"},
	{9, "e*",	"I learned everything there is to know about life from the\n"
			"         \"Hitchhiker's Trilogy\""},
	SENTINEL
};

const struct stuff gc_housing[] = {
	{1, "h++",	"Living in a cave with 47 computers and an Internet feed, located near a\n"
			"        Dominoes pizza (See !d)"},
	{2, "h+",	"Living alone, get out once a week to buy food, no more than once a\n"
			"        month to do laundry. All surfaces covered."},
	{3, "h",	"Friends come over to visit every once in a while to talk about Geek\n"
			"        things. There is a place for them to sit."},
	{4, "h-",	"Living with one or more registered Geeks."},
	{5, "h--",	"Living with one or more people who know nothing about being a Geek and\n"
			"        refuse to watch Babylon 5."},
	{6, "h---",	"Married, (persons living romantically with someone might as well lab\n"
			"        themselves h---, you're as good as there)"},
	{7, "h----",	"Married with children - Al Bundy can sympathize."},
	{8, "h!",	"I am stuck living with my parents!"},
	{9, "h*",	"I'm not sure where I live anymore. This lab/workplace seems like home"
			"        to me."},
	SENTINEL
};

const struct stuff gc_relationships[] = {
	{1, "r+++",	"Found someone, dated, and am now married."},
	{2, "r++",	"I've dated my current S.O. for a long time."},
	{3, "r+",	"I date frequently, bouncing from one relationship to another."},
	{4, "r",	"I date periodically."},
	{5, "r-",	"I have difficulty maintaining a relationship."},
	{6, "r--",	"People just aren't interested in dating me."},
	{7, "r---",	"I'm beginning to think that I'm a leper or something, the way people\n"
			"        avoid me like the plague."},
	{8, "!r",	"I've never had a relationship."},
	{9, "r*",	"Signifying membership in the SBCA (Sour Bachelor(ette)'s Club of\n"
			"        America). The motto is 'Bitter, but not Desperate'.\n"
			"        First founded at Caltech."},
	{10, "r%%",	"I was going out with someone, but the asshole dumped me."},
	SENTINEL
};

const struct stuff gc_gender[] = {
	{1, "x",	"I am a female"},
	{2, "y",	"I am a male"},
	{3, "z",	"I do not wish to disclose my gender"},
	SENTINEL
};

const struct stuff gc_sex[] = {
	{1, "%c+++++",	"I am Madonna"},
	{2, "%c++++",	"I have a few little rug rats to prove I've been there. Besides, with\n"
			"          kids around, who has time for sex?"},
	{3, "%c+++",	"I'm married, so I can get it (theoretically) whenever I want."},
	{4, "%c++",	"I was once referred to as 'easy'. I have no idea where that might\n"
			"          have come from though."},
	{5, "%c+",	"I've had real, live sex."},
	{6, "%c",	"I've had sex. Oh! You mean with someone else? Then no."},
	{7, "%c-",	"Not having sex by choice."},
	{8, "%c--",	"Not having sex because I just can't get any..."},
	{9, "%c---",	"Not having sex because I'm a nun or priest."},
	{10, "%c*",	"I'm a pervert."},
	{11, "%c**",	"I've been known to make perverts look like angels."},
	{12, "!%c",	"Sex? What's that? I've had no sexual experiences."},
	{13, "%c?",	"It's none of your business what my sex life is like (this is used to\n"
			"          denote your gender only)."},
	{14, "!%c+",	"Sex? What's that? No experience, willing to learn!"},
	SENTINEL
};
