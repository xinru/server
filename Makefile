CFLAGS += -Iinc/

ALL: src/main.o src/student.o
	cc -o student src/main.o src/student.o

clean:
	rm student
	rm src/*.o

tmpclean:
	rm ./*~
	rm inc/*~
	rm src/*~

install:
	sudo cp student /usr/bin/student

uninstall:
	sudo rm /usr/bin/student
