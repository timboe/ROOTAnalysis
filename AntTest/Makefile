CXX=g++
CXXFLAGS= -g -Wall
ROOTLIBS=`root-config --libs`
ROOTINC=`root-config --cflags`

BINDIR=bin
OBJDIR=obj
SRCDIR=src
INCDIR=include

OBJECTS  = $(OBJDIR)/Ant.o $(OBJDIR)/AtlasStyle.o $(OBJDIR)/AtlasUtils.o
PROGRAMSOBJ = $(OBJDIR)/Langtons.o
PROGRAMS = $(BINDIR)/LangtonsAnt.exe

all:$(OBJECTS) $(PROGRAMS) $(PROGRAMSOBJ)

$(BINDIR)/LangtonsAnt.exe:$(OBJDIR)/Langtons.o $(OBJECTS) 
	$(CXX) -o $@ $^ $(ROOTLIBS)

$(OBJDIR)/Langtons.o:$(SRCDIR)/Langtons.cxx
	$(CXX) -c $(CXXFLAGS) $< -o $@ -I$(INCDIR) $(ROOTINC)

$(OBJDIR)/Ant.o:$(SRCDIR)/Ant.cxx $(INCDIR)/Ant.h
	$(CXX) -c $(CXXFLAGS) $< -o $@ $(ROOTINC) -I$(INCDIR)/
	
$(OBJDIR)/AtlasStyle.o:$(SRCDIR)/AtlasStyle.cxx $(INCDIR)/AtlasStyle.h
	$(CXX) -c $(CXXFLAGS) $< -o $@ $(ROOTINC) -I$(INCDIR)/
	
$(OBJDIR)/AtlasUtils.o:$(SRCDIR)/AtlasUtils.cxx $(INCDIR)/AtlasUtils.h
	$(CXX) -c $(CXXFLAGS) $< -o $@ $(ROOTINC) -I$(INCDIR)/

clean: 
	rm -vf  $(OBJDIR)/*.o $(BINDIR)/*.exe *~ $(SRCDIR)/*~ $(INCDIR)/*~
