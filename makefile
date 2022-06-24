all: parallel.c serial.c reduce.c
	make parallel
	make serial
	make reduce
parallel: parallel.c
	mpicc parallel.c -o parallel
serial: serial.c
	mpicc serial.c -o serial
reduce: reduce.c
	mpicc reduce.c -o reduce
runr: reduce
	mpirun --allow-run-as-root -np $(process) --oversubscribe ./reduce
clean: serial parallel reduce
	rm serial parallel reduce
