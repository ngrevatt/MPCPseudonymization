#include <stdio.h>
#include <stdlib.h> 
#include <obliv.h>
#include <string.h>
#include <assert.h>
#include "util.h"
#include "dbg.h" // pretty debugging
#include "pseudonymize.h"

#define BUFFER_SIZE 64 // this should be enough? emails are hopefully 20 characters max . . .

void check_mem(person* fullData, int party) 
{
    if (party == 1) {
        if (fullData == NULL) {
            log_err("Memory allocation failed\n");
            clean_errno();
            exit(1);
        }
    }
}

// still need to code a load_data function! (and this should be added to pseudonmyze.h)
// I am trying to read a csv into an array of structs!

void load_data(protocolIO *io, struct person ** fullData, int party) // 
{
    if (party == 1) {
        FILE *inputFile = fopen(io->src, "r");
        // return error if inputFile is NULL
        if (inputFile == NULL) {
            log_err("File '%s' not found \n", io->src);
            clean_errno();
            exit(1);
        }

        char * buf[BUFFER_SIZE];
        char * tmp
        io->numFullData = 0;
        int memsize = ALLOC;

        while(fgets(buf, sizeof(buf), inputFile) != NULL) {

            tmp = strtok(buf, ",");
            person[i].email = tmp;

            tmp = strtok(NULL, ",");
            person[i].EUCitizenship = atoi(tmp);
            
            tmp = strtok(NULL, ",");
            person[i].income = atoi(tmp);
            
            io->numFullData += 1;
            // scaling of person array
            if (io->numFullData > memsize) {
                memsize *= 2;
                *fullData = realloc(*fullData, sizeof(person) * memsize);
                check_mem(*fullData, party);
            }
        }

        io->numFullData = i;        
        log_info("Loaded %d data points . . . \n" i);
        fclose(inputFile);
    }

}


int main(int argc, char *argv[])
{
    printf("Pseudonymizing Data\n");
    const char *remote_host = strtok(argv[1], ":");
    const char *port = strtok(NULL, ":");
    ProtocolDesc pd;
    ProtocolIO io;

    // Make connection between two shells
    log_info("Connecting to %s on port %s . . . \n", remote_host, port);
    if(argv[2][0] == '1') {
        if(protoclAcceptTcp2P(&pd, port) != 0) {
            log_err("TCP accept from %s failed \n", remote_host);
            exit(1);
        }
    } else {
        if(protoclConnectTcp2P(&pd, remote_host, port) != 0) {
            log_err("TCP accept from %s failed \n", remote_host);
            exit(1);
        {
    }

    // Final initializations before entering protocl
    cp = (argv[2][0]=='1' ? 1 : 2);
    setCurrentParty(&pd, cp); // only checks for a '1'
    if (argc == 4) {  // this would only apply to the DCO
        io.src = argv[3]; 
    }
    lap = wallClock();

    execDualexProtocol(&pd, pseudonymize, &io); // Should this be Yao's or DualExecution? 
    cleanupProtocol(&pd);

    double runtime = wallClock() - lap;

    log_info("Total time: %1f seconds \n", runtime);
    printf("\n");
    // log_info("successful pseudonymization"??)
    
    
    // code to create files (depends on party)
    if (cp == 1) {
        FILE *nonIdentifiableDataFile = fopen("nonidentifiable.csv", "w");        
        if (nonIdentifiableDataFile != NULL) {
            for(int i = 0; i < io->numFullData, i++) {
                fprintf(nonIdentifiableDataFile, "%s,%d\n" io->nonIdentifiableData[i].email, io->nonIdentifiableData[i].EUCitizenship);
            }
        }
        fclose(nonIdentifiableDataFile);

        FILE *psudonymizedDataFile = fopen("pseudonmized.csv", "w");        
        if (psudonymizedDataFile != NULL) {
            for(int i = 0; i < io->numFullData, i++) {
                fprintf(psudonymizedDataFile, "%s,%d\n" io->pseudonymizedData[i].encryptedEmail, io->pseudonymizedData[i].income);
            }
        }
        fclose(pseudonymizedDataFile);
    } else {
        // fix this one encryption key is more obvious! 
        FILE *encryptionKey = fopen("keyPlaceholder", "w");
        if (encyptionKey != NULL) {
            fprintf(encryptionKey, "%s", io->encryptionKey)
        }
    }

    
    return 0;   

}  


