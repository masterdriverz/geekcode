#include "geekcode.h"

const struct stuff dress[] = {
	{1, "d++",	"I tend to wear conservative dress such as a business suit or\n"
			"        worse, a tie."},
	{2, "d+",	"Good leisure-wear. Slacks, button-shirt, etc. No jeans, tennis\n"
			"        shoes, or t-shirts."},
	{3, "d",	"I dress a lot like those found in catalog ads. Bland, boring,\n"
			"        without life or meaning."},
	{4, "d-",	"I'm usually in jeans and a t-shirt."},
	{5, "d--",	"My t-shirts go a step further and have a trendy political\n"
			"        message on them."},
	{6, "d---",	"Punk dresser, including, but not limited to, torn jeans and\n"
			"        shirts, body piercings, and prominent tattoos."},
	{7, "dx",	"Cross dresser."},
	{8, "d?",	"I have no idea what I am wearing now, let alone what I wore yesterday."},
	{9, "!d",	"No clothing. Quite a fashion statement, don't you think?"},
	{10, "dpu",	"I wear the same clothes all the time, no matter the occasion,\n"
			"        forgetting to do laundry between wearings."},
	SENTINEL
};

const struct stuff height[] = {
	{1, "s+++",	"I usually have to duck through doors."},
	{2, "s++",	"I'm a basketball candidate."},
	{3, "s+",	"I'm a little taller than most."},
	{4, "s",	"I'm an average geek."},
	{5, "s-",	"I look up to most people."},
	{6, "s--",	"I look up to damn near everybody."},
	{7, "s---",	"I take a phone book with me when I go out so I can eat dinner."},
	SENTINEL
};

const struct stuff weight[] = {
	{1, "s+++",	"I take up three movie seats."},
	{2, "s++",	"I'm a linebacker candidate."},
	{3, "s+",	"I'm a little rounder than most."},
	{4, "s",	"I'm an average geek."},
	{5, "s-",	"Everybody tells me to gain a few pounds."},
	{6, "s--",	"I tend to have to fight against a strong breeze."},
	{7, "s---",	"My bones are poking through my skin."},
	SENTINEL
};

const struct stuff age[] = {
	{1, "a+++",	"60 and up"},
	{2, "a++",	"50-59"},
	{3, "a+",	"40-49"},
	{4, "a",	"30-39"},
	{5, "a-",	"25-29"},
	{6, "a--",	"20-24"},
	{7, "a---",	"15-19"},
	{8, "a----",	"10-14"},
	{9, "a-----",	"9 and under (Geek in training?)"},
	{10, "a?",	"Immortal"},
	{11, "!a",	"It's none of your business how old I am"},
	SENTINEL
};
