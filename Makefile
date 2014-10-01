make:
	gcc $(target).c -o ./bin/$(target) -lm
	make launch target=$(target);

launch: 
	./bin/$(target)

help:
	echo 'Create a binary: make make target=XX; Execute a binary: make launch target=XX'