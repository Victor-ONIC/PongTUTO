CXX = g++
TARGET = pongtuto2

# Dossiers
SRCDIR = src
BINDIR = bin

# Fichiers
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(BINDIR)/%.o)
INCLUDE = -I SFML/include -I src/headers
LIB = -L SFML/lib -l sfml-graphics -l sfml-window -l sfml-system

# Commandes
all: $(BINDIR)/$(TARGET)

$(OBJECTS): $(BINDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CXX) $(INCLUDE) -c $< -o $@
	@echo "Compiled "$<" successfully !"

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(CXX) -o $@ $^ $(LIB)
	@echo "Linking complete !"

# Pour Windows
clean:
	@del /q $(BINDIR)
	@echo "Removal complete !"