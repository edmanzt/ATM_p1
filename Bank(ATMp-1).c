#include <stdio.h>

//saeed heydari  404149031
//edman zardosht 404149039

int main() {

    char firstName[20], lastName[20];
    int balance = 0;
    int pin = 1234;
    int isActive = 0;
    int transactions[10];
    int transactionCount = 0;

    int enteredPin, tries;

    // --- bakhsh vorood ramz va kontrol tedad talash ha ---
    for (tries = 0; tries < 3; tries++) {
        printf("ramz ra vared konid: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            break;
        }
        printf("ramz eshtebah!\n");
    }

    if (tries == 3) {
        printf("3 bar eshtebah. Barname khateme miabad...\n");
        return 0;
    }

    int choice;
    do {
        // --- bakhsh namayesh menu asli ---
        printf("\n--- Menu ---\n");
        printf("1. ijad hesab\n");
        printf("2. Variz\n");
        printf("3. Bardasht\n");
        printf("4. Namayesh mojoodi\n");
        printf("5. Namayesh tarakonesh ha\n");
        printf("6. Taghir ramz\n");
        printf("7. Hazf hesab\n");
        printf("8. Khorooj\n");
        printf("Entekhab shoma: ");
        scanf("%d", &choice);

        // --- bakhsh ijad hesab ---
        if (choice == 1) {
            if (isActive == 1) {
                printf("Hesab ghablan sakhte shode!\n");
            } else {
                printf("nam khod ra vared konid: ");
                scanf("%s", firstName);

                printf("nam khanevadegi khod vared konid: ");
                scanf("%s", lastName);

                printf("Mojoodi avalie ra vared konid: ");
                scanf("%d", &balance);

                isActive = 1;
                transactionCount = 0;
                printf("Hesab ba movafaghiat sakhte shod!\n");
            }
        }
        // --- bakhsh variz ---
        else if (choice == 2) {
            if (isActive == 0) {
                printf("Hesab faal nist!\n");
            } else {
                int amount;
                printf("Meghdar variz ra vared konid: ");
                scanf("%d", &amount);

                if (amount > 0) {
                    balance += amount;

                    if (transactionCount < 10) {
                        transactions[transactionCount] = amount;
                        transactionCount++;
                    } else {
                        for (int i = 1; i < 10; i++) {
                            transactions[i-1] = transactions[i];
                        }
                        transactions[9] = amount;
                    }
                    printf("Variz ba movafaghiat anjam shod!\n");
                } else {
                    printf("Meghdar na motabar ast!\n");
                }
            }
        }
        // --- bakhsh bardasht ---
        else if (choice == 3) {
            if (isActive == 0) {
                printf("Hesab faal nist!\n");
            } else {
                int amount;
                printf("Meghdar bardasht ra vared konid: ");
                scanf("%d", &amount);

                if (amount > 0 && amount <= balance) {
                    balance -= amount;

                    if (transactionCount < 10) {
                        transactions[transactionCount] = -amount;
                        transactionCount++;
                    } else {
                        for (int i = 1; i < 10; i++) {
                            transactions[i-1] = transactions[i];
                        }
                        transactions[9] = -amount;
                    }
                    printf("Bardasht ba movafaghiat anjam shod!\n");
                } else {
                    printf("Meghdar na motabar ya mojoodi kafi nist!\n");
                }
            }
        }
        // --- bakhsh namayesh mojoodi ---
        else if (choice == 4) {
            if (isActive == 0) {
                printf("Hesab faal nist!\n");
            } else {
                printf("Mojoodi kononi: %d\n", balance);
            }
        }
        // --- bakhsh namayesh tarakonesh ha ---
        else if (choice == 5) {
            if (isActive == 0) {
                printf("Hesab faal nist!\n");
            } else {
                printf("tarakonesh haye akhir:\n");
                for (int i = 0; i < transactionCount; i++) {
                    printf("%d\n", transactions[i]);
                }
            }
        }

        // --- taghir ramz ---
        else if (choice == 6) {
            int oldPin, newPin;
            printf("ramz feli ra vared konid: ");
            scanf("%d", &oldPin);

            if (oldPin == pin) {
                printf("ramz jadid ra vared konid: ");
                scanf("%d", &newPin);
                pin = newPin;
                printf("ramz ba movafaghiat taghir kard!\n");
            } else {
                printf("ramz eshtebah ast!\n");
            }
        }

        // --- bakhsh hazf hesab ---
        else if (choice == 7) {
            if (isActive == 0) {
                printf("Hesab faal nist!\n");
            } else {
                isActive = 0;
                balance = 0;
                transactionCount = 0;
                printf("Hesab hazf shod!\n");
            }
        }

        // --- khorooj ---
        else if (choice == 8) {
            printf("bedrood!\n");
        }

        else {
            printf("Entekhab na motabar!\n");
        }

    } while (choice != 8);

    return 0;
}
