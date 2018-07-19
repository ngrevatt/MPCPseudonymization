#ifndef PSEUDONYMIZE_H
#define PSEUDONYMIZE_H

#define ALLOC 20 // there are 20 reccords and this is used in pseudonymize.oc as well

double lap; // used for time keeping
int cp; // computing party

typedef struct {
    char *src; // filename for data read (for the DC)
    int numDataRecords; // could be updated by alloc, but I also do not intend to change alloc? (I should build this functionality in, though)
    struct person fullData[ALLOC]; // change these numbers depending on amount of results
    struct nonIdentifiablePerson nonIdentifiableData[ALLOC];
    struct pseudonymizedPerson pseudonymizedData[ALLOC];
    uint8_t key[16]; //AES Encryption Key (is this what this looks like??)
} protocolIO;


// more structs! to hold the personal data from and for csvs
typedef struct {
    char email[16];
    int EUCitizenship;
    int income;
} person;

typedef struct {
    uint8_t encryptedEmail[16];
    int EUCitizenship;
} nonIdentifiablePerson;

typedef struct {
    uint8_t encryptedEmail[16];
    int income;
} pseudonymizedPerson;

// needed for pseudonymize.oc
typedef struct {
    obliv uint8_t email[16]; // does this need to be longer for encrypted value?
    obliv int EUCitizenship;
    obliv int income;
} operson;


void pseudonymize(void* args);
void load_data(protocolIO *io, struct person ** fullData, int party);
void check_mem(person * fullData, int party)    

#endif
