## tuxtype.spec.in - process with configure to fill in current
## PACKAGE and VERSION strings
#
#
# spec file for package tuxtype
#
# This file and all modifications and additions to the pristine
# package are under the same license as the package itself.
#

# norootforbuild

Name:           tuxtype
Version:        1.8.3
Obsoletes:      tuxtype_preview <= 1.8.3
Provides:       tuxtype_preview = 1.8.3
%define         realname tuxtype
%define         progname tuxtype

Summary:        Typing tutor for children
Url:            http://alioth.debian.org/projects/tux4kids/
License:        GNU General Public License (GPL) v2, Creative Commons Attribution ShareAlike 3.0, Public Domain
Group:          Amusements/Teaching/Language
Release:        1
Vendor:         openSUSE-Education

Source:         %realname-%version.tar.bz2

BuildRequires:  SDL_image-devel >= 1.2.2
#BuildRequires:  SDL_ttf-devel > 2.0.8
BuildRequires:  SDL-devel
BuildRequires:  SDL_mixer-devel
#BuildRequires:  SDL_net-devel
BuildRequires:  SDL_Pango-devel
#BuildRequires:  librsvg2-devel
BuildRequires:  ImageMagick

%if 0%{?suse_version}
BuildRequires:  update-desktop-files  
BuildRequires:  fdupes
%endif

%if 0%{?fedora_version}
BuildRequires:  desktop-file-utils
%endif

%if 0%{?mandriva_version}
BuildRequires:  desktop-file-utils
Requires(post): desktop-file-utils
Requires(postun): desktop-file-utils
%endif
%if 0%{?mandriva_version} >= 2009
BuildRequires: pulseaudio-esound-compat
%endif  

BuildRoot:      %{_tmppath}/%{progname}-%{version}-build


%description
Tux Typing is an educational typing tutor game starring Tux, the Linux
penguin. It is designed to be entertaining for children, but can be used
by all ages to improve typing skills. Tux Typing includes two video game-style activities that give practice typing individual characters and words.  There
is also a phrase typing activity that provides practice with phrases and sentences, with on-screen display of accuracy and typing speed.

Tux Typing supports all commonly used desktop platforms, and is packaged with translation files and word lists for many (human) languages. The program is capable of displaying essentially the entire Unicode character set.

Authors:
--------
    Current maintainer and programming lead:
    David Bruce <davidstuartbruce@gmail.com>

    Holger Levsen <holger@debian.org>
    Jesse Andrews <jdandr2@uky.edu>
    Calvin Arndt <calarndt@tux4kids.org>
    Sam Hart <hart@geekcomix.com>
    Jacob Greig <bombastic@firstlinux.net>
    Sreyas Kurumanghat <k.sreyas@gmail.com>
    Sreerenj Balachandran <bsreerenj@gmail.com>
    Vimal Ravi <vimal_ravi@rediff.com>
    Prince K. Antony <prince.kantony@gmail.com>
    Mobin Mohan <mobinmohan@gmail.com>
    Matthew Trey <tux4kids@treyhome.com>
    Sarah Frisk <ssfrisk@gmail.com>
    Caroline Ford <secretlondon@googlemail.com>


# prep section: ---------------------------------------------------------

%prep
%setup -q -n %realname-%version
rm -rf $(find . -type d -name CVS)
rm -rf $(find . -type d -name .svn)
rm -rf $(find . -type d -name .xvpics)



# build section: ---------------------------------------------------------

%build
%configure --disable-rpath \
           --prefix=%_prefix \
           --localstatedir=%_localstatedir/games \
           --sysconfdir=%_sysconfdir \
           --without-rsvg
make %{?jobs:-j %jobs}



# install section: ---------------------------------------------------------

%install
install -d %buildroot/%_bindir
install -d %buildroot/%_datadir/pixmaps
install -d %buildroot/%_datadir/applications
install -d %buildroot/%_datadir/%progname
install -d %buildroot/%_defaultdocdir/%progname

make DESTDIR=%{buildroot} install
install -m 644 data/images/icons/icon.png %buildroot%_datadir/pixmaps/%progname.png

%if 0%{?suse_version}
# handle special docdir path
mv %buildroot/%_datadir/doc/%progname/* %buildroot/%_defaultdocdir/%progname/
rm -rf %buildroot/%_datadir/doc/%progname
# install desktop file
%suse_update_desktop_file -i %progname Education Languages
%fdupes -s %buildroot
%endif
%if 0%{?fedora_version}
# install desktop file
desktop-file-install --vendor="%{vendor}" \
  --dir=%buildroot/%_datadir/applications \
  %progname.desktop
%endif
%if 0%{?mandriva_version}
desktop-file-install --vendor="%{vendor}" \
  --dir=%buildroot/%_datadir/applications \
  %progname.desktop
%endif
# remove invalid locale directories
rm -rf %buildroot/%{_datadir}/locale/en@*
%find_lang %progname

%if 0%{?mandriva_version}
%post
%{update_menus}

%postun
%{clean_menus}
%endif

%clean
rm -rf %buildroot



# files section: ---------------------------------------------------------

%files -f %progname.lang

%defattr(-,root,root)
%doc %_defaultdocdir/%progname
%_bindir/*
%_datadir/pixmaps/*
%_datadir/applications/*
%_datadir/%progname
%attr(755, root, root) %_sysconfdir/%progname

# create game state directories modifiable by members of "games" group:
#%attr(2755, root, games) %_localstatedir/games/%progname
# Perhaps only the words dir needs to have the non-default permissions:
%_localstatedir/games/%progname
%attr(2755, root, games) %_localstatedir/games/%progname/words


%changelog
