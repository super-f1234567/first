objects=main.o printfresult.o

edit:$(objects)
	cc -o edit $(objects)
main.o:main.c 
	cc -c main.c 
printfresult.o:printfresult.c
	cc -c printfresult.c
.PHONY:clean
clean:
	rm edit $(objects)
