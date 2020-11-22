#------------------------------------------------------
# gcc compiler, nana lib c++
CXX=g++
CXXFLAGS=-I. -I./gemgui/ -I/include/ -std=c++11 
EXTFLAGS=-s -Os -ffunction-sections -fdata-sections
LIBS=-lnana -lX11 -lpthread -lrt -ldl -lfreetype\
 -lXft -lfontconfig -lasound -lpng -lstdc++fs\
 -lgemgui

#------------------------------------------------------
# app name
TARGET= gemGuiSample
# headers
DEPS = 
# objects
OBJ = main.o
#------------------------------------------------------
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
LINK_COLOR  = \033[0;32m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m
COM_STRING  = "Compiling"
#------------------------------------------------------

%.o: %.cpp $(DEPS)
	@printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(<)$(NO_COLOR)\n";
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ)
	@printf "%b" "$(LINK_COLOR)Linking...$(NO_COLOR)\n";
	$(CXX) -o $@ $^ $(CXXFLAGS) $(EXTFLAGS) $(LIBS)
	#upx --best $(TARGET)

#------------------------------------------------------
.PHONY: clean install uninstall

clean:
	@printf "%b" "$(WARN_COLOR)Cleaning...$(NO_COLOR)\n";
	rm -f $(TARGET) *.o
	
install: $(TARGET)
	@printf "%b" "$(WARN_COLOR)Installing...$(NO_COLOR)\n";
	cp $(TARGET) /usr/bin

uninstall: $(TARGET)
	@printf "%b" "$(WARN_COLOR)Uninstalling...$(NO_COLOR)\n";
	rm -f /usr/bin/$(TARGET)
		
#------------------------------------------------------
