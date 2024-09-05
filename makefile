LEX_FILE = ass3_22CS30028_22CS10008.l
C_FILE = ass3_22CS30028_22CS10008.c
LEX_OUTPUT = lex.yy.c
EXE = ./a.out
INPUT = ass3_22CS30028_22CS10008_test.c
OUTPUT_FILE = output.txt

all: clean compile run post_clean

clean:
	rm -f $(LEX_OUTPUT) $(EXE)

compile: $(LEX_FILE) $(C_FILE)
	flex $(LEX_FILE)
	gcc $(C_FILE)

run: $(EXE)
	./$(EXE) < $(INPUT)

post_clean:
	rm -f $(LEX_OUTPUT) $(EXE)