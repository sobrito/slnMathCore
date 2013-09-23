RM := rm -rf
#LEX := lex
#YACC := yacc -d
LEX := flex
YACC := bison -d -y

DICTIONARY_PREFFIX := dictionary.latex
DICTIONARY_YACC := dictionary.latex.yacc
DICTIONARY_LEX := dictionary.latex.lex
DICTIONARY_SOURCE := $(DICTIONARY_YACC) $(DICTIONARY_LEX)
DICTIONARY_HEADER := $(DICTIONARY_PREFFIX).tab.h
DICTIONARY_CODE := $(DICTIONARY_PREFFIX).tab.c
DICTIONARY_OBJS := lex.dictionary.latex.c $(DICTIONARY_CODE)

# All Target
all: $(DICTIONARY_OBJS)

lex.dictionary.latex.c: $(DICTIONARY_CODE)
	@echo 'Building file: $<'
	@echo "Invoking: $(LEX) Compiler"
	$(LEX) --outfile=$@ $(DICTIONARY_LEX)
	@echo 'Finished building: $<'
	@echo ''
	
dictionary.latex.tab.c: $(DICTIONARY_SOURCE)
	@echo "Building file: $(DICTIONARY_HEADER) and $(DICTIONARY_CODE)"
	@echo "Invoking: $(YACC) Compiler"
	$(YACC) $(DICTIONARY_YACC) --output-file $@
	@echo 'Finished building: $<'
	@echo ''

# Other Targets
clean:
	$(RM) $(DICTIONARY_OBJS) $(DICTIONARY_CODE) $(DICTIONARY_HEADER)
	