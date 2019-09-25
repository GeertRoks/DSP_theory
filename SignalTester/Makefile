CXXFLAGS := -Wall -std=c++11
CXXFLAGS += $(patsubst %,-I %, $(MODULES))
LDFLAGS =
LDLIBS =


# the folders where it searches for module.mk files
SUBMODULES := ../Filters

MODULES := DiracPulse Sine plot playsoundfile

# each module will add the source files to this
SRC := main.o

# each module will add the headers to this
HDRS :=

# include the modules from the submodules
include $(patsubst %, %/submodule.mk, $(SUBMODULES))

# include the source and header files for each module
include $(patsubst %, %/module.mk, $(MODULES))

# determine the object files
OBJ := $(patsubst %.cpp,%.o, $(SRC))

all: Test

# link the program
Test: $(OBJ)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS)

# builds given .o files dependend on their corresponding .cpp and .h files
%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm $(OBJ)
	rm Test

.PHONY: all clean


# Print Makefile variable function (Makefile debugger)
# 	Type in the commandline: print-<variablename>
#	and it will display whatever <variablename> is.
print-%  : ; @echo $* = $($*)
