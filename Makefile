CILPATH=~/obliv-c
OBLIVCC=$(CILPATH)/bin/oblivcc
RUNTIME=$(CILPATH)/_build/libobliv.a
CFLAGS=-g -Wall -D_Float128=double
LOADLIBES=-lm

ACKPATH=~/absentminded-crypto-kit

PORT=1234
REMOTE_HOST=localhost
CONNECTION=$(REMOTE_HOST):$(PORT)

# something like this... (fix "test")
# ./pseudonymize.out: test.oc test.c util.c $(ACKPATH)/build/lib/liback.a $(RUNTIME)
# 	$(OBLIVCC) $(CFLAGS) -I . $(ACKPATH)/src/ test.oc test.c util.c $(LOADLIBES) pseudonymize.oc $(ACKPATH)/src/oaes.oc
# what should I have in my util.c / util.h? maybe the wallClock?

./pseudonymize.out: pseudonymize.oc pseudonymize.c util.c $(ACKPATH)/build/lib/liback.a $(RUNTIME)
	$(OBLIVCC) $(CFLAGS) -I . $(ACKPATH)/src/ pseudonymize.oc pseudonymize.c $(LOADLIBES) $(ACKPATH)/src/oaes.oc

./process.out:

clean:

new_full_data:
	python3 genData.py


# test pseudonymization (run genData.py for new data)
DP_pseudonymize:
	$(./pseudonymize.out)
	./pseudonymize.out $(CONNECTION) 1 $(data.csv)

DPO_pseudonymize:
	$(./pseudonymize.out)
	./pseudonymize.out $(CONNECTION) 2 


# test data processing (run after createing pseudonymized data)
DP_process:
	$(./process.out)
	./process.out $(CONNECTION) 1 $(nonidentifiable.csv) $(pseudonymized.csv) 
	
DPO_process:
	$(./process.out)
	./process.out $(CONNECTION) 2 $(ENCRYPTION_KEY)  
