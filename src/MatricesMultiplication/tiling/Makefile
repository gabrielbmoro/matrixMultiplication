
# Gabriel Bronzatti Moro
# gabrielbronzattimoro.es@gmail.com

# FLAGS
FLAGS := -Wall -Wextra -O3

# TARGET RULES
all: main_seq

main_seq.o: MultiplicaMatrizes_seq.c
	gcc $(FLAGS) -o $@ -c $<

main_seq: cmp134.c main_seq.o
	gcc $(FLAGS) -o $@ $+
	
clean:
	rm -f *.o 
	rm main_seq
