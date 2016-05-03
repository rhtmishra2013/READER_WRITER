all:  one_way.c writer.c reader.c
	gcc -o one_way.o -c one_way.c
	gcc writer.c one_way.o -lpthread -lrt -o writer
	gcc reader.c one_way.o -lpthread -lrt -o reader
	
	

clean: 
	$(RM) writer
	$(RM) reader
	$(RM) one_way.o
	
