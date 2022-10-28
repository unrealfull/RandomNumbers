C=gcc
CXX=g++
RM=rm -f

SRCS=ran0.cpp ran1.cpp ran2.cpp ran3.cpp ran4.cpp psdes.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: random random4

random4: $(OBJS) xran4.o
	$(CXX) $(LDFLAGS) -o random4 $(OBJS) xran4.o $(LDLIBS)
random: $(OBJS) xran.o
	$(CXX) $(LDFLAGS) -o random $(OBJS) xran.o $(LDLIBS)
	

clean:
	$(RM) $(OBJS) xran.o xran4.o random random4

distclean: clean
	$(RM) *~ .depend

csvclean:
	$(RM) *.csv