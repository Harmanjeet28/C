/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Harmanjeet Singh Hara
Student ID#: 118624220
Email      : hhara@myseneca.ca
Section    : ZAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"
#include <string.h>


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}




//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}




// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}




// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}




// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i;
    int record = 0;
    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            record = 1;
        }
    }
    if (record == 0)
    {
        printf("*** No records found ***\n\n");
    }
    printf("\n");
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientData(const struct Patient patient[], int max)
{
    int options;
    do
    {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d",&options);
        printf("\n");

        if (options == 1) 
        {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }

        else if (options == 2) 
        {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    

    } while (options != 0);

}



// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void addPatient(struct Patient patient[], int max)
{
    int i, size;
    size = 0;

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            size++;
        }
    }
    if (max > size) {
        patient[size].patientNumber = nextPatientNumber(patient, max);
        inputPatient(patient + size);
        printf("*** New patient record added ***\n\n");
        clearInputBuffer();
    }
    else {
        printf("ERROR: Patient listing is FULL!\n\n");
    }

}



// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void editPatient(struct Patient patient[], int max)
{
    int patientNo, result;
    
    
    printf("Enter the patient number: ");
    scanf("%d", &patientNo);
    printf("\n");

    if (findPatientIndexByPatientNum(patientNo, patient, max) != -1) {
        result = findPatientIndexByPatientNum(patientNo, patient, max);
        menuPatientEdit(patient + result);
    }
    else {
        printf("ERROR: Patient record not found!\n");
    }
    
}



// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void removePatient(struct Patient patient[], int max)
{
    int patientNo, result;
    char conferm;

    printf("Enter the patient number: ");
    scanf("%d", &patientNo);
    printf("\n");
    result = findPatientIndexByPatientNum(patientNo, patient, max);
        
    if (result == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
        clearInputBuffer();
    }
    else
    {
        printf("Name  : %s\n", patient[result].name);
        printf("Number: %05d\n", patient[result].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[result].phone.number);
        printf(" (%s)", patient[result].phone.description);
        printf("\n\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");

        scanf(" %c", &conferm);

        if (conferm == 'y' || conferm == 'Y')
        {
            patient[result].patientNumber = 0;
            printf("Patient record has been removed!\n\n");
            clearInputBuffer();
        }
        else
        {
            printf("Operation aborted.\n\n");
            clearInputBuffer();
        }
    }

}



//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void searchPatientByPatientNumber(const struct Patient patient[], int max) {
    int pNumber, index;
    printf("Search by patient number: ");
    scanf("%d", &pNumber);
    printf("\n");

    // Checking if patient number exists
    if (findPatientIndexByPatientNum(pNumber, patient, max) != -1) {
        index = findPatientIndexByPatientNum(pNumber, patient, max);
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)", patient[index].phone.description);
        printf("\n\n");
    }

    else {
        printf("*** No records found ***\n\n");
    }
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
    int i, match = 0;
    char phoneNumber[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    scanf("%[^\n]s",phoneNumber);
    printf("\n");

    displayPatientTableHeader();

    for (i = 0; i < max + 1; i++) {
        if (strcmp(patient[i].phone.number, phoneNumber) == 0) {
            printf("%05d %-15s ", patient[i].patientNumber, patient[i].name);
            displayFormattedPhone(patient[i].phone.number);
            printf(" (%s)\n", patient[i].phone.description);
            match++;
        }
    }
    printf("\n");

    if (match == 0) {
        printf("*** No records found ***\n\n");
    }
}


// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int nextPatientNumber(const struct Patient patient[], int max) {
    int nextNum, maxNum = patient[0].patientNumber, i;

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > maxNum) {
            maxNum = patient[i].patientNumber;
        }
    }

    nextNum = maxNum + 1;
    return nextNum;
}


// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    
    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == patientNumber) {
            return i;
        }
    }
    
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPatient(struct Patient* patient)
{
    int i;
    char name[NAME_LEN + 1];

    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");

    scanf("%[^\n]s", name);

    for (i = 0; i < strlen(name); i++)
    {
        patient->name[i] = name[i];
    }

    printf("\n");
    inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)

void inputPhoneData(struct Phone* phone) {
    int options, i;
    char phnumber[PHONE_LEN + 1];
    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &options);
    printf("\n");

    if (options == 1)
    {
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);

        printf("Contact: %s\n", phone->description);

        clearInputBuffer();
        printf("Number : ");
        scanf("%[^\n]s", phnumber);

        for (i = 0; i < PHONE_LEN + 1; i++) {
            phone->number[i] = phnumber[i];
        }

        printf("\n");
    }

    else if (options == 2)
    {
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);

        printf("Contact: %s\n", phone->description);

        clearInputBuffer();
        printf("Number : ");
        scanf("%[^\n]s", phnumber);

        for (i = 0; i < PHONE_LEN + 1; i++) {
            phone->number[i] = phnumber[i];
        }

        printf("\n");
    }

    else if (options == 3)
    {
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);

        printf("Contact: %s", phone->description);
        printf("\n");

        clearInputBuffer();
        printf("Number : ");
        scanf("%[^\n]s", phnumber);

        for (i = 0; i < PHONE_LEN + 1; i++) {
            phone->number[i] = phnumber[i];
        }

        printf("\n");
    }
    else if (options == 4)
    {
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);

        *phone->number = 0;
    }
    else
    {
        printf("Error:\n");
    }
}
