Summary: Generates your geek code.
Name: geekcode
Version: 1.7.3
Release: 1
Copyright: GPL
Group: Amusements/Games
Source: http://geekcode.sourceforge.net/geekcode-1.7.3.tar.gz
Packager: Chris Gushue <chris@blackplasma.net>

BuildRoot: /var/tmp/geekcode-root

%description
This program will generate a geek code block for you by simply
choosing which codes suit you from the screen.

%prep
%setup -q -n geekcode-1.7.3

%build
make

%install
rm -rf $RPM_BUILD_ROOT
mkdir -p $RPM_BUILD_ROOT/usr/bin

install -m 755 geekcode $RPM_BUILD_ROOT/usr/bin

%clean
rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root)
%doc CHANGES COPYING INSTALL README geekcode.txt
/usr/bin/geekcode

%changelog
* Wed Jun 25 2003 Chris Gushue <chris@blackplasma.net>
- created package for version 1.7.2
* Tue Nov 23 1999 Chris Gushue <seymour@lazygenes.net>
- created new package
* Tue Feb 14 2000 Chris Gushue <seymour@lazygenes.net>
- created package for version 1.6
* Mon Feb 21 2000 Chris Gushue <seymour@lazygenes.net>
- created package for version 1.7

