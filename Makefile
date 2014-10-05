CFLAGS += -Iinc/

objects = src/main.o src/student.o

ALL: $(objects)
	cc -o student $(objects)

.PHONY: clean tmpclean install uninstall
clean: 
	-rm -f student
	-rm -f src/*.o

tmpclean:
	-rm -f ./*~
	-rm -f inc/*~
	-rm -f src/*~

install:
	sudo cp student /usr/bin/student

uninstall:
	sudo rm /usr/bin/student
