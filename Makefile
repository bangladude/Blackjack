#############################################################################
# Makefile for building: app.app/Contents/MacOS/app
# Generated by qmake (2.01a) (Qt 4.8.5) on: Sun Dec 8 14:23:59 2013
# Project:  app.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile app.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -g -gdwarf-2 -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Qt4.8/mkspecs/macx-g++ -I. -I/Library/Frameworks/QtCore.framework/Versions/4/Headers -I/usr/include/QtCore -I/Library/Frameworks/QtGui.framework/Versions/4/Headers -I/usr/include/QtGui -I/usr/include -I. -I. -F/Library/Frameworks
LINK          = g++
LFLAGS        = -headerpad_max_install_names -arch x86_64 -Xarch_x86_64 -mmacosx-version-min=10.5
LIBS          = $(SUBLIBS) -F/Library/Frameworks -L/Library/Frameworks -framework QtGui -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.4

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = blackjack.cpp \
		blackjack_canvas.cpp \
		deck.cpp \
		main.cpp \
		strategy.cpp moc_blackjack.cpp \
		moc_blackjack_canvas.cpp \
		qrc_cards.cpp
OBJECTS       = blackjack.o \
		blackjack_canvas.o \
		deck.o \
		main.o \
		strategy.o \
		moc_blackjack.o \
		moc_blackjack_canvas.o \
		qrc_cards.o
DIST          = /usr/local/Qt4.8/mkspecs/common/unix.conf \
		/usr/local/Qt4.8/mkspecs/common/mac.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-base.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-macx.conf \
		/usr/local/Qt4.8/mkspecs/qconfig.pri \
		/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.8/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.8/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.8/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.8/mkspecs/features/debug.prf \
		/usr/local/Qt4.8/mkspecs/features/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.8/mkspecs/features/shared.prf \
		/usr/local/Qt4.8/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.8/mkspecs/features/qt.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.8/mkspecs/features/moc.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.8/mkspecs/features/resources.prf \
		/usr/local/Qt4.8/mkspecs/features/uic.prf \
		/usr/local/Qt4.8/mkspecs/features/yacc.prf \
		/usr/local/Qt4.8/mkspecs/features/lex.prf \
		/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf \
		app.pro
QMAKE_TARGET  = app
DESTDIR       = 
TARGET        = app.app/Contents/MacOS/app

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-g \
		-arch \
		x86_64 \
		-Xarch_x86_64 \
		-mmacosx-version-min=10.5 \
		-Wall \
		-W


first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile app.app/Contents/PkgInfo app.app/Contents/Resources/empty.lproj app.app/Contents/Info.plist $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) app.app/Contents/MacOS/ || $(MKDIR) app.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: app.pro  /usr/local/Qt4.8/mkspecs/macx-g++/qmake.conf /usr/local/Qt4.8/mkspecs/common/unix.conf \
		/usr/local/Qt4.8/mkspecs/common/mac.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base.conf \
		/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-base.conf \
		/usr/local/Qt4.8/mkspecs/common/g++-macx.conf \
		/usr/local/Qt4.8/mkspecs/qconfig.pri \
		/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Qt4.8/mkspecs/features/qt_functions.prf \
		/usr/local/Qt4.8/mkspecs/features/qt_config.prf \
		/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf \
		/usr/local/Qt4.8/mkspecs/features/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/dwarf2.prf \
		/usr/local/Qt4.8/mkspecs/features/debug.prf \
		/usr/local/Qt4.8/mkspecs/features/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf \
		/usr/local/Qt4.8/mkspecs/features/shared.prf \
		/usr/local/Qt4.8/mkspecs/features/warn_on.prf \
		/usr/local/Qt4.8/mkspecs/features/qt.prf \
		/usr/local/Qt4.8/mkspecs/features/unix/thread.prf \
		/usr/local/Qt4.8/mkspecs/features/moc.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/rez.prf \
		/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf \
		/usr/local/Qt4.8/mkspecs/features/resources.prf \
		/usr/local/Qt4.8/mkspecs/features/uic.prf \
		/usr/local/Qt4.8/mkspecs/features/yacc.prf \
		/usr/local/Qt4.8/mkspecs/features/lex.prf \
		/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf \
		/Library/Frameworks/QtGui.framework/QtGui.prl \
		/Library/Frameworks/QtCore.framework/QtCore.prl
	$(QMAKE) -o Makefile app.pro
/usr/local/Qt4.8/mkspecs/common/unix.conf:
/usr/local/Qt4.8/mkspecs/common/mac.conf:
/usr/local/Qt4.8/mkspecs/common/gcc-base.conf:
/usr/local/Qt4.8/mkspecs/common/gcc-base-macx.conf:
/usr/local/Qt4.8/mkspecs/common/g++-base.conf:
/usr/local/Qt4.8/mkspecs/common/g++-macx.conf:
/usr/local/Qt4.8/mkspecs/qconfig.pri:
/usr/local/Qt4.8/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Qt4.8/mkspecs/features/qt_functions.prf:
/usr/local/Qt4.8/mkspecs/features/qt_config.prf:
/usr/local/Qt4.8/mkspecs/features/exclusive_builds.prf:
/usr/local/Qt4.8/mkspecs/features/default_pre.prf:
/usr/local/Qt4.8/mkspecs/features/mac/default_pre.prf:
/usr/local/Qt4.8/mkspecs/features/mac/dwarf2.prf:
/usr/local/Qt4.8/mkspecs/features/debug.prf:
/usr/local/Qt4.8/mkspecs/features/default_post.prf:
/usr/local/Qt4.8/mkspecs/features/mac/default_post.prf:
/usr/local/Qt4.8/mkspecs/features/mac/x86_64.prf:
/usr/local/Qt4.8/mkspecs/features/mac/objective_c.prf:
/usr/local/Qt4.8/mkspecs/features/shared.prf:
/usr/local/Qt4.8/mkspecs/features/warn_on.prf:
/usr/local/Qt4.8/mkspecs/features/qt.prf:
/usr/local/Qt4.8/mkspecs/features/unix/thread.prf:
/usr/local/Qt4.8/mkspecs/features/moc.prf:
/usr/local/Qt4.8/mkspecs/features/mac/rez.prf:
/usr/local/Qt4.8/mkspecs/features/mac/sdk.prf:
/usr/local/Qt4.8/mkspecs/features/resources.prf:
/usr/local/Qt4.8/mkspecs/features/uic.prf:
/usr/local/Qt4.8/mkspecs/features/yacc.prf:
/usr/local/Qt4.8/mkspecs/features/lex.prf:
/usr/local/Qt4.8/mkspecs/features/include_source_dir.prf:
/Library/Frameworks/QtGui.framework/QtGui.prl:
/Library/Frameworks/QtCore.framework/QtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile app.pro

app.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) app.app/Contents || $(MKDIR) app.app/Contents 
	@$(DEL_FILE) app.app/Contents/PkgInfo
	@echo "APPL????" >app.app/Contents/PkgInfo
app.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) app.app/Contents/Resources || $(MKDIR) app.app/Contents/Resources 
	@touch app.app/Contents/Resources/empty.lproj
	
app.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) app.app/Contents || $(MKDIR) app.app/Contents 
	@$(DEL_FILE) app.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,app,g" -e "s,@TYPEINFO@,????,g" /usr/local/Qt4.8/mkspecs/macx-g++/Info.plist.app >app.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/app1.0.0 || $(MKDIR) .tmp/app1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/app1.0.0/ && $(COPY_FILE) --parents blackjack.h blackjack_canvas.h deck.h strategy.h .tmp/app1.0.0/ && $(COPY_FILE) --parents cards.qrc .tmp/app1.0.0/ && $(COPY_FILE) --parents blackjack.cpp blackjack_canvas.cpp deck.cpp main.cpp strategy.cpp .tmp/app1.0.0/ && (cd `dirname .tmp/app1.0.0` && $(TAR) app1.0.0.tar app1.0.0 && $(COMPRESS) app1.0.0.tar) && $(MOVE) `dirname .tmp/app1.0.0`/app1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/app1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r app.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_blackjack.cpp moc_blackjack_canvas.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_blackjack.cpp moc_blackjack_canvas.cpp
moc_blackjack.cpp: blackjack.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ blackjack.h -o moc_blackjack.cpp

moc_blackjack_canvas.cpp: blackjack_canvas.h
	/Developer/Tools/Qt/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ blackjack_canvas.h -o moc_blackjack_canvas.cpp

compiler_rcc_make_all: qrc_cards.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_cards.cpp
qrc_cards.cpp: cards.qrc \
		images/49.gif \
		images/35.gif \
		images/21.gif \
		images/50.gif \
		images/28.gif \
		images/4.gif \
		images/14.gif \
		images/43.gif \
		images/36.gif \
		images/22.gif \
		images/blank_black.gif \
		images/51.gif \
		images/5.gif \
		images/29.gif \
		images/15.gif \
		images/44.gif \
		images/30.gif \
		images/37.gif \
		images/23.gif \
		images/52.gif \
		images/6.gif \
		images/16.gif \
		images/45.gif \
		images/31.gif \
		images/38.gif \
		images/24.gif \
		images/10.gif \
		images/7.gif \
		images/17.gif \
		images/46.gif \
		images/32.gif \
		images/39.gif \
		images/1.gif \
		images/25.gif \
		images/11.gif \
		images/40.gif \
		images/8.gif \
		images/18.gif \
		images/47.gif \
		images/33.gif \
		images/2.gif \
		images/26.gif \
		images/12.gif \
		images/41.gif \
		images/9.gif \
		images/19.gif \
		images/48.gif \
		images/34.gif \
		images/20.gif \
		images/27.gif \
		images/3.gif \
		images/13.gif \
		images/42.gif
	/Developer/Tools/Qt/rcc -name cards cards.qrc -o qrc_cards.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

blackjack.o: blackjack.cpp blackjack.h \
		blackjack_canvas.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o blackjack.o blackjack.cpp

blackjack_canvas.o: blackjack_canvas.cpp blackjack_canvas.h \
		deck.h \
		strategy.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o blackjack_canvas.o blackjack_canvas.cpp

deck.o: deck.cpp deck.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o deck.o deck.cpp

main.o: main.cpp blackjack.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

strategy.o: strategy.cpp strategy.h \
		deck.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strategy.o strategy.cpp

moc_blackjack.o: moc_blackjack.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_blackjack.o moc_blackjack.cpp

moc_blackjack_canvas.o: moc_blackjack_canvas.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_blackjack_canvas.o moc_blackjack_canvas.cpp

qrc_cards.o: qrc_cards.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_cards.o qrc_cards.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

