CXX = g++
CXXFLAGS = -g -Wall -fPIC `root-config --cflags`
ROOTLDFLAGS=`root-config --glibs` -lTreePlayer
INCLUDE += -I$(SENSIROOT)/include -I$(JOYROOTROOT)/include
# for shared libraries
LDFLAGS += -shared -Wl,-install_name
#LDFLAGS += -shared -Wl,-soname

OBJS = mydict.o Asimov.o SepFit.o FC.o SensiUtils.o
MYROOTDICT = mydict.cc
MYROOTDICTPCM = mydict_rdict.pcm
MYROOTDICTHEADERS = $(SENSIROOT)/include/Asimov.hh $(SENSIROOT)/include/SepFit.hh \
 	$(SENSIROOT)/include/FC.hh $(SENSIROOT)/include/SensiUtils.hh


TARGET =libSENSI.so

$(TARGET): $(OBJS) $(MYROOTDICT)
	$(CXX) $(LDFLAGS),$(TARGET) -o $(TARGET) $(OBJS) $(ROOTLDFLAGS)
	if [ ! -d ${SENSIROOT}/lib ]; then mkdir $(SENSIROOT)/lib; fi
	ln -sf $(SENSIROOT)/src/$(TARGET) ${SENSIROOT}/lib/$(TARGET)
	ln -sf $(SENSIROOT)/src/$(MYROOTDICTPCM) ${SENSIROOT}/lib/$(MYROOTDICTPCM)


$(OBJS): %.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(MYROOTDICT): $(MYROOTDICTHEADERS)
	rootcint -f $@ -c $(CXXFLAGS) $(INCLUDE) -p $^

clean:
	rm -f $(SENSIROOT)/lib/$(TARGET)
	rm -f $(SENSIROOT)/lib/$(MYROOTDICTPCM)
	rm -f $(TARGET)
	rm -f $(OBJS)
	rm -f $(MYROOTDICT)
	rm -f $(MYROOTDICTPCM)
